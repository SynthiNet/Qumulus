/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_SHAPE_H_
#define UML_DIAGRAM_SHAPE_H_

#include "internal_base.h"

#include "DiagramElement.h"

#include <QtWidgets/QGraphicsItemGroup>
#include <libavoid/geomtypes.h>

namespace Avoid {
    class ShapeRef;
    class Router;
}

QUML_BEGIN_NAMESPACE_GD

class Shape : public DiagramElement, public QGraphicsItemGroup {
public:
    Shape(QuUK::Element* e = 0, DiagramElement* p = 0);
    Shape(const Shape&);
    ~Shape();

    QSizeF size() const { return mSize; }

    double width() const;
    double height() const;
    void setWidth(double);
    void setHeight(double);

    void resize(QSizeF s) { resize(s.width(), s.height()); }
    virtual void resize(double w, double h) = 0;
    virtual void updateSizeConstraints() = 0;
    void passRouter(Avoid::Router* r);

    QSizeF minimumSize() const { return mMinimumSize; }
    void setMinimumSize(QSizeF s) { mMinimumSize = s; }

    QSizeF maximumSize() const { return mMaximumSize; }
    void setMaximumSize(QSizeF s) { mMaximumSize = s; }

    QSizeF optimalSize() const;
    void setSizeHint(QSizeF s) { mSizeHint = s; }

    virtual bool acceptsAssociationSource() { return false; }
    virtual bool acceptsAssociationTarget() { return false; }
    virtual bool acceptsGeneralizationSource() { return false; }
    virtual bool acceptsGeneralizationTarget() { return false; }

    Avoid::ShapeRef* shapeRef() { return mShapeRef; }

    void setOwningElement(DiagramElement* e);

    QUML_CLONABLE_ABSTRACT(Shape);

protected:
    void setSize(QSizeF s, bool overrideCall = false);

private:
    QSizeF mSize = QSizeF();
    QPointF mPrevPos = QPointF();
    QSizeF mMinimumSize = QSizeF();
    QSizeF mMaximumSize = QSizeF();
    QSizeF mSizeHint = QSizeF();
    Avoid::Rectangle mRoutingBox;
    Avoid::ShapeRef* mShapeRef = nullptr;
    Avoid::Router* mRouter = nullptr;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_SHAPE_H_ */

