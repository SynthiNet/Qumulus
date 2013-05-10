/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "MultiplicityLabel.h"

QUML_BEGIN_NAMESPACE_UD

MultiplicityLabel::MultiplicityLabel(QuUK::Element* e, DiagramElement* p) :
        Label(e, p) {

}

MultiplicityLabel::MultiplicityLabel(const QString& t, QuUK::Element* e, 
        DiagramElement* p) :
        Label(t, e, p) {

}

QUML_END_NAMESPACE_UD
