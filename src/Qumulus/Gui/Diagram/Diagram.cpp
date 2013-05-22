/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Diagram.h"
#include "Style.h"

#include "Shape.h"
#include "PackageShape.h"

#include <Lib/Core/Nyi.h>

#include <Uml/Kernel/Package.h>

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

CommentShape* Diagram::createShape(QuUK::Comment*) {
    NYI();
    return nullptr;
}

PrimitiveShape* Diagram::createShape(QuUK::PrimitiveType*) {
    NYI();
    return nullptr;
}

ClassShape* Diagram::createShape(QuUK::Class*) {
    NYI();
    return nullptr;
}

EnumShape* Diagram::createShape(QuUK::Enumeration*) {
    NYI();
    return nullptr;
}

QUML_END_NAMESPACE_GD
