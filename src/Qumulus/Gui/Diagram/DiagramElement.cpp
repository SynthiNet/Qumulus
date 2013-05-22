/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "DiagramElement.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_GD

DiagramElement::DiagramElement(QuUK::Element* m, DiagramElement* p) : 
        mModelElement(m),
        mLocalStyle(0), 
        mOwningElement(p) {
}

DiagramElement::DiagramElement(const DiagramElement& d) {
    NYI();
    (void)d;
}

DiagramElement::~DiagramElement() {
    delete mLocalStyle;
}

Style* DiagramElement::sharedStyle() const {
    if(mLocalStyle)
        return mLocalStyle;
    else
        return owningElement()->sharedStyle();
}



QUML_END_NAMESPACE_GD
