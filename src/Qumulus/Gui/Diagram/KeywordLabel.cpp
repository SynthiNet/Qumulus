/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "KeywordLabel.h"

QUML_BEGIN_NAMESPACE_GD


KeywordLabel::KeywordLabel(QuUK::Element* e, DiagramElement* p) :
        Label(e, p) {
    setText("");
}

KeywordLabel::KeywordLabel(const QString& t, QuUK::Element* e, 
        DiagramElement* p) :
        Label(t, e, p) {
    setText(t);
}

KeywordLabel::KeywordLabel(const KeywordLabel& l) :
        Label(l) {
    setText(l.text());
}

void KeywordLabel::setText(const QString& s) {
    Label::setText(s);
    setHtml("<center>&laquo; "+s+" &raquo;</center>");
}

void KeywordLabel::resize(double w, double) {
    setTextWidth(w);
}

QUML_END_NAMESPACE_GD
