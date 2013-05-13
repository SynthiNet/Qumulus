/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Diagram.h"
#include "Style.h"

#include "Shape.h"

#include <QtWidgets/QGraphicsScene>

QUML_BEGIN_NAMESPACE_UD

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

QUML_END_NAMESPACE_UD
