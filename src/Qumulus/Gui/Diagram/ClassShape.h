/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_CLASSSHAPE_H_
#define UML_DIAGRAM_CLASSSHAPE_H_

#include "internal_base.h"

#include "CompartmentableShape.h"

#include <Uml/Kernel/Class.h>

QUML_BEGIN_NAMESPACE_GD

class ClassShape : public CompartmentableShape {
public:
    ClassShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    ClassShape(const ClassShape&);

    QuUK::Class* modelElement() const override; 

    bool indentForVisibility() const { return mIndentForVisibilty; }
    void setIndentForVisibility(bool b) { mIndentForVisibilty = b; }
    void updateSizeConstraints() override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
            QWidget* widget) override;

    void hoverMoveEvent(QGraphicsSceneHoverEvent* event) override;
    QVariant itemChange(GraphicsItemChange change, 
            const QVariant & value) override;
    QuUK::Property* highlightedAttribute() const;
    QuUK::Operation* highlightedOperation() const;

    void writeXml(QXmlStreamWriter& writer) const override;

    QUML_CLONABLE(ClassShape);
private: 
    int classNameWidth() const;
private:
    bool mIndentForVisibilty = false;
    Compartment* mHeadCompartment;
    Compartment* mAttributeCompartment;
    Compartment* mOperationCompartment;
    QuUK::Property* mHighlightedAttribute = nullptr;
    QuUK::Operation* mHighlightedOperation = nullptr;
};

QUML_END_NAMESPACE_GD


#endif /* UML_DIAGRAM_CLASSSHAPE_H_ */

