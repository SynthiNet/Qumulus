/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "DiagramElement.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UD

DiagramElement::DiagramElement(QuUK::Element* m, DiagramElement* p) : 
        QGraphicsItemGroup(p), 
        mModelElement(m),
        mLocalStyle(0),
        mIcon(false) {
    setVisible(false);
}

DiagramElement::DiagramElement(const DiagramElement& d) {
    NYI();
    (void)d;
}

DiagramElement::~DiagramElement() {
    delete mLocalStyle;
}

DiagramElement* DiagramElement::owningElement() const {
    return dynamic_cast<DiagramElement*>(parentItem());
}

void DiagramElement::setOwningElement(DiagramElement* e) {
    setParentItem(e);
}

Style* DiagramElement::sharedStyle() const {
    if(mLocalStyle)
        return mLocalStyle;
    else
        return owningElement()->sharedStyle();
}



QUML_END_NAMESPACE_UD
