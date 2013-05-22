/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#ifndef UML_DIAGRAM_COMPARTMENT_H_
#define UML_DIAGRAM_COMPARTMENT_H_

#include "internal_base.h"

#include "Shape.h"

class QGraphicsRectItem;

QUML_BEGIN_NAMESPACE_GD

class CompartmentableShape;

class Compartment : public Shape {
    friend class CompartmentableShape;
public:
    Compartment(CompartmentableShape* p = 0);
    Compartment(const Compartment&);

    CompartmentableShape* compartmentableShape() const;
    void setCompartimentableShape(CompartmentableShape* s);

    using Shape::resize;

    /**
     * @note: This should never be called directly. Use
     * CompartmentableShape::resize() instead.
     */
    void resize(double, double) override;

    // These are not used -- all drawing is done by CompartmentableShape
    QRectF boundingRect() const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

    QUML_CLONABLE(Compartment);
private:
    QGraphicsRectItem* mRectItem;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_COMPARTMENT_H_ */

