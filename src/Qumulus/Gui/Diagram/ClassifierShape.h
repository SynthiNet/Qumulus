/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_CLASSIFIERSHAPE_H_
#define UML_DIAGRAM_CLASSIFIERSHAPE_H_

#include "internal_base.h"

#include "CompartmentableShape.h"

QUML_BEGIN_NAMESPACE_UD

class ClassifierShape : public CompartmentableShape {
public:
    ClassifierShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    ClassifierShape(const ClassifierShape&);

    bool indentForVisibility() const { return mIndentForVisibilty; }
    void setIndentForVisibility(bool b) { mIndentForVisibilty = b; }

    QUML_CLONABLE(ClassifierShape);
private:
    bool mIndentForVisibilty = false;
};

QUML_END_NAMESPACE_UD


#endif /* UML_DIAGRAM_CLASSIFIERSHAPE_H_ */

