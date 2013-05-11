/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "NameLabel.h"

QUML_BEGIN_NAMESPACE_UD

NameLabel::NameLabel(QuUK::Element* e, DiagramElement* p) :
        Label(e, p) {
    setText("");
}

NameLabel::NameLabel(const QString& t, QuUK::Element* e, 
        DiagramElement* p) :
        Label(t, e, p) {
    setText(t);
}

NameLabel::NameLabel(const NameLabel& l) :
        Label(l) {
    setText(l.text());
}

void NameLabel::setText(const QString& s) {
    Label::setText(s);
    setHtml("<center><b>"+s+"</b></center>");
}

QUML_END_NAMESPACE_UD

