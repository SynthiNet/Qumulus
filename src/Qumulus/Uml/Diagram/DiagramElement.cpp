/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "DiagramElement.h"

QUML_BEGIN_NAMESPACE_UD

DiagramElement::DiagramElement(QuUK::Element* m, DiagramElement* p) : 
        QGraphicsItemGroup(p), 
        mModelElement(m),
        mLocalStyle(0),
        mIcon(false) {

}

DiagramElement* DiagramElement::owningElement() const {
    return dynamic_cast<DiagramElement*>(parentItem());
}

Style* DiagramElement::sharedStyle() const {
    if(mLocalStyle)
        return mLocalStyle;
    else
        return owningElement()->sharedStyle();
}



QUML_END_NAMESPACE_UD
