/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "KeywordLabel.h"

QUML_BEGIN_NAMESPACE_UD


KeywordLabel::KeywordLabel(QuUK::Element* e, DiagramElement* p) :
        Label(e, p) {

}

KeywordLabel::KeywordLabel(const QString& t, QuUK::Element* e, 
        DiagramElement* p) :
        Label(t, e, p) {

}

QUML_END_NAMESPACE_UD
