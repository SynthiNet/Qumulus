/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "NameLabel.h"

QUML_BEGIN_NAMESPACE_UD

NameLabel::NameLabel(QuUK::Element* e, DiagramElement* p) :
        Label(e, p) {

}

NameLabel::NameLabel(const QString& t, QuUK::Element* e, 
        DiagramElement* p) :
        Label(t, e, p) {

}

QUML_END_NAMESPACE_UD

