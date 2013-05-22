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

#include <QtWidgets/QGraphicsScene>

QUML_BEGIN_NAMESPACE_GD

constexpr static float kFontSize =
#ifdef Q_OS_MAC
        12.0;
#else
        10.0;
#endif

Diagram::Diagram(QString name, double resolution) :
        mName(name),
        mResolution(resolution) {
    auto s = new Style;
    setLocalStyle(s);
    s->setFontName("sans-serif");
    s->setFontSize(kFontSize);
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
    return pshape;
}

CommentShape* Diagram::createShape(QuUK::Comment* c) {
    auto cshape = new CommentShape(c, this);
    addElement(cshape);
    return cshape;
}

PrimitiveShape* Diagram::createShape(QuUK::PrimitiveType* p) {
    auto pshape = new PrimitiveShape(p, this);
    addElement(pshape);
    return pshape;
}

ClassShape* Diagram::createShape(QuUK::Class* c) {
    auto cshape = new ClassShape(c, this);
    addElement(cshape);
    return cshape;
}

EnumShape* Diagram::createShape(QuUK::Enumeration* e) {
    auto eshape = new EnumShape(e, this);
    addElement(eshape);
    return eshape;
}

QUML_END_NAMESPACE_GD
