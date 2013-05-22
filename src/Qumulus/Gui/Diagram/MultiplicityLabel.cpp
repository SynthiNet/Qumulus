/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "MultiplicityLabel.h"

QUML_BEGIN_NAMESPACE_GD

MultiplicityLabel::MultiplicityLabel(QuUK::Element* e, DiagramElement* p) :
        Label(e, p) {

}

MultiplicityLabel::MultiplicityLabel(const QString& t, QuUK::Element* e, 
        DiagramElement* p) :
        Label(t, e, p) {

}

MultiplicityLabel::MultiplicityLabel(const MultiplicityLabel& l) :
        Label(l) {
}

QUML_END_NAMESPACE_GD

