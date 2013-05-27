/*
 * Qumulus UML editor
 * Author: Frank Erens
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

#include <Lib/Core/Nyi.h>

#include <Uml/Kernel/Package.h>
#include <Uml/Kernel/Comment.h>
#include <Uml/Kernel/PrimitiveType.h>
#include <Uml/Kernel/Class.h>
#include <Uml/Kernel/Enumeration.h>

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
        mRootPackage(new QuUK::Package()){
    auto s = new Style;
    setLocalStyle(s);
    s->setFontName("sans-serif");
    s->setFontSize(kFontSize);
    mRootPackage->setRootPackage(true);
}

Diagram::Diagram(const Diagram& d) :
        DiagramElement(d) {

}

Diagram::~Diagram() {
    for(auto& p : mElements) {
        delete p;
    }
}

void Diagram::addElement(DiagramElement* e) {
    mElements.append(e);
    if(Shape* p = dynamic_cast<Shape*>(e))
        mScene->addItem(p);
}

void Diagram::removeElement(DiagramElement* e) {
    mElements.removeAll(e);
    if(Shape* p = dynamic_cast<Shape*>(e))
        mScene->removeItem(p);
}

void Diagram::setScene(QGraphicsScene* e) {
    mScene = e;
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

    writer.writeEndElement();

    writer.writeStartElement("diagram");

    for(auto& x : mElements) {
        x->writeXml(writer);
    }

    writer.writeEndElement();

    writer.writeEndElement();

    return true;
}

void Diagram::loadFromXml(const QString& file) throw(QuLC::ParseException) {
    (void)file;
}

QUML_END_NAMESPACE_GD
