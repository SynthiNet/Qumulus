/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "AssociationEndLabel.h"

QUML_BEGIN_NAMESPACE_UD

AssociationEndLabel::AssociationEndLabel(QuUK::Element* e, 
        DiagramElement* p) :
        Label(e, p) {

}
AssociationEndLabel::AssociationEndLabel(const QString& t, QuUK::Element* e, 
        DiagramElement* p) : 
        Label(t, e, p) {

}

QUML_END_NAMESPACE_UD
