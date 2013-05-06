/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Label.h"

QUML_BEGIN_NAMESPACE_UD

Label::Label(QuUK::Element* e, DiagramElement* p) :
        Shape(e, p),
        mText("") {

}

Label::Label(const QString& t, QuUK::Element* e, DiagramElement* p) :
        Shape(e, p),
        mText(t) {

}


QUML_END_NAMESPACE_UD
