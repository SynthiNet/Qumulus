/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#ifndef UML_DIAGRAM_COMPARTMENT_H_
#define UML_DIAGRAM_COMPARTMENT_H_

#include "internal_base.h"

#include "DiagramElement.h"

class QGraphicsRectItem;

QUML_BEGIN_NAMESPACE_GD

class CompartmentableShape;

class Compartment : public DiagramElement {
    friend class CompartmentableShape;
public:
    Compartment(CompartmentableShape* p = 0);
    Compartment(const Compartment&);

    CompartmentableShape* compartmentableShape() const;
    void setCompartimentableShape(CompartmentableShape* s);

    float height() const { return mHeight; }
    void setHeight(float f);
    float minimumHeight() const { return mMinimumHeight; }
    void setMinimumHeight(float f) { mMinimumHeight = f; }
    float maximumHeight() const { return mMaximumHeight; }
    void setMaximumHeight(float f) { mMaximumHeight = f; }

    void writeXml(QXmlStreamWriter&) const override {}

    QUML_CLONABLE(Compartment);
private:
    QGraphicsRectItem* mRectItem;
    float mHeight = 0;
    float mMinimumHeight = -1;
    float mMaximumHeight = -1;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_COMPARTMENT_H_ */

