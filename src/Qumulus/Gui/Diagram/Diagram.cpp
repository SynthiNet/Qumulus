/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 */

#include "Diagram.h"
#include "Style.h"

#include "Shape.h"

#include "PackageShape.h"
#include "CommentShape.h"
#include "PrimitiveShape.h"
#include "ClassShape.h"
#include "EnumShape.h"
#include "AssociationEdge.h"
#include "GeneralizationEdge.h"
#include "ContainmentEdge.h"

#include <Lib/Core/Nyi.h>

#include <Uml/Kernel/Package.h>
#include <Uml/Kernel/Comment.h>
#include <Uml/Kernel/PrimitiveType.h>
#include <Uml/Kernel/Class.h>
#include <Uml/Kernel/Enumeration.h>
#include <Uml/Kernel/Association.h>
#include <Uml/Kernel/Generalization.h>

#include <Gui/Widgets/EditorView.h>

#include <QtCore/QTextStream>
#include <QtCore/QXmlStreamWriter>
#include <QtWidgets/QGraphicsScene>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>


QUML_BEGIN_NAMESPACE_GD

constexpr static float kFontSize =
#ifdef Q_OS_MAC
        12.0;
#else
        10.0;
#endif

Diagram::Diagram() :
        mRootPackage(new QuUK::Package()),
        mRouter(new Avoid::Router(Avoid::OrthogonalRouting)) {
    auto s = new Style;
    setLocalStyle(s);
    s->setFontName("sans-serif");
    s->setFontSize(kFontSize);
    mRootPackage->setRootPackage(true);
    mRouter->setRoutingOption(Avoid::penaliseOrthogonalSharedPathsAtConnEnds, true);
    mRouter->setRoutingPenalty(Avoid::fixedSharedPathPenalty, 9999);
    mRouter->setRoutingPenalty(Avoid::crossingPenalty, 9999);
    mRootPackage->childElementChanged += [this] {
        diagramChanged();
    };
}

Diagram::Diagram(const Diagram& d) :
        DiagramElement(d) {

}

Diagram::~Diagram() {
    for(auto& p : mElements) {
        delete p;
    }
    delete mRouter;
}

void Diagram::addElement(DiagramElement* e) {
    mElements.append(e);

    if(Shape* p = dynamic_cast<Shape*>(e)) {
        mScene->addItem(p);
        p->passRouter(mRouter);
    }

    if(Edge* p = dynamic_cast<Edge*>(e)) {
        mScene->addItem(p);
        p->passRouter(mRouter);
    }

    diagramChanged();
    mIsModified = true;
}

void Diagram::removeElement(DiagramElement* e) {
    mElements.removeAll(e);
    if(Shape* p = dynamic_cast<Shape*>(e))
        mScene->removeItem(p);
    if(Edge* p = dynamic_cast<Edge*>(e))
        mScene->removeItem(p);
    diagramChanged();
    mIsModified = true;
}

void Diagram::setScene(QGraphicsScene* e) {
    mScene = e;
}

void Diagram::setRootPackage(QuUK::Package* r) {
    delete mRootPackage;
    mRootPackage = r;
}

void Diagram::setComments(const QList<QuUK::Comment*>& c) {
    mComments = c;
}

void Diagram::setAssociations(const QList<QuUK::Association*>& a) {
    mAssociations = a;
}

PackageShape* Diagram::createShape(QuUK::Package* p) {
    auto pshape = new PackageShape(p, this);
    addElement(pshape);
    p->setPackage(mRootPackage);
    return pshape;
}

CommentShape* Diagram::createShape(QuUK::Comment* c) {
    auto cshape = new CommentShape(c, this);
    addElement(cshape);
    mComments.append(c);
    return cshape;
}

PrimitiveShape* Diagram::createShape(QuUK::PrimitiveType* p) {
    auto pshape = new PrimitiveShape(p, this);
    addElement(pshape);
    p->setPackage(mRootPackage);
    return pshape;
}

ClassShape* Diagram::createShape(QuUK::Class* c) {
    auto cshape = new ClassShape(c, this);
    addElement(cshape);
    c->setPackage(mRootPackage);
    return cshape;
}

EnumShape* Diagram::createShape(QuUK::Enumeration* e) {
    auto eshape = new EnumShape(e, this);
    addElement(eshape);
    e->setPackage(mRootPackage);
    return eshape;
}

GeneralizationEdge* Diagram::createEdge(QuUK::Generalization* a, Shape* src,
        Shape* dst) {
    auto gedge = new GeneralizationEdge(a, this);
    addElement(gedge);
    gedge->setSource(src);
    gedge->setTarget(dst);
    gedge->connect();
    return gedge;
}

AssociationEdge* Diagram::createEdge(QuUK::Association* a, Shape* src,
        Shape* dst) {
    auto aedge = new AssociationEdge(a, this);
    addElement(aedge);
    aedge->setSource(src);
    aedge->setTarget(dst);
    aedge->connect();
    mAssociations.append(a);
    return aedge;
}

ContainmentEdge* Diagram::createPackageContainment(Shape* src, Shape* dst) {
    auto cedge = new ContainmentEdge(nullptr, this);
    addElement(cedge);
    cedge->setSource(src);
    cedge->setTarget(dst);
    cedge->connect();
    return cedge;
}

QuGW::EditorView* Diagram::editorView() const {
    return dynamic_cast<QuGW::EditorView*>(scene()->views()[0]);
}


bool Diagram::saveToXml(const QString& file) const {
    QDomDocument doc;

    QFile outFile(file);
    if(!outFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QXmlStreamWriter writer(&outFile);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();

    writer.writeStartElement("quml");
    writer.writeAttribute("version", "1");

    writer.writeStartElement("model");

    for(auto& x : mRootPackage->packagedElements()) {
        x->writeXml(writer);
    }

    for(auto& x : mComments) {
        x->writeXml(writer);
    }

    for(auto& x : mAssociations) {
        x->writeXml(writer);
    }

    writer.writeEndElement();

    writer.writeStartElement("diagram");

    for(auto& x : mElements) {
        x->writeXml(writer);
    }

    writer.writeEndElement();

    writer.writeEndElement();

    return true;
}

QUML_END_NAMESPACE_GD
