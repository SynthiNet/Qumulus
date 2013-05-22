/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "FeatureLabel.h"

QUML_BEGIN_NAMESPACE_UD

FeatureLabel::FeatureLabel(QuUK::Element* e, DiagramElement* p) :
        Label(e, p) {
    setText("");
}

FeatureLabel::FeatureLabel(const QString& t, QuUK::Element* e, 
        DiagramElement* p) :
        Label(t, e, p) {
    setText(t);
}

FeatureLabel::FeatureLabel(const FeatureLabel& l) :
        Label(l) {
    setText(l.text());
}

void FeatureLabel::setText(const QString& s) {
    Label::setText(s);
    if(mStatic)
        setHtml("<u>"+s+"</u>");
    else
        setHtml(s);
}

void FeatureLabel::resize(double w, double) {
    QString elided = sharedStyle()->fontMetrics().elidedText(
            mTextItem->toPlainText(), Qt::ElideRight, w - 10);
    if(mStatic)
        setHtml("<u>"+elided+"</u>");
    else
        setHtml(elided);
    setTextWidth(w);
}

QUML_END_NAMESPACE_UD
