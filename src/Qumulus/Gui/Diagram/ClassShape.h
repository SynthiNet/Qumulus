/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_CLASSSHAPE_H_
#define UML_DIAGRAM_CLASSSHAPE_H_

#include "internal_base.h"

#include "CompartmentableShape.h"

QUML_BEGIN_NAMESPACE_GD

class ClassShape : public CompartmentableShape {
public:
    ClassShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    ClassShape(const ClassShape&);

    bool indentForVisibility() const { return mIndentForVisibilty; }
    void setIndentForVisibility(bool b) { mIndentForVisibilty = b; }
    void updateSizeConstraints() override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
            QWidget* widget) override;

    QUML_CLONABLE(ClassShape);
private:
    bool mIndentForVisibilty = false;
};

QUML_END_NAMESPACE_GD


#endif /* UML_DIAGRAM_CLASSSHAPE_H_ */

