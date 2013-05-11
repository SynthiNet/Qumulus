/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Label.h"

#include <Lib/Core/Nyi.h>

#include <QtWidgets/QGraphicsTextItem>
#include <QtGui/QFont>

QUML_BEGIN_NAMESPACE_UD

Label::Label(QuUK::Element* e, DiagramElement* p) :
        Shape(e, p),
        mTextItem(new QGraphicsTextItem(this)),
        mText("") {
    addToGroup(mTextItem);
    mTextItem->setFont(QFont(sharedStyle()->fontName(), 
                sharedStyle()->fontSize()));
    setText("");
}

Label::Label(const QString& t, QuUK::Element* e, DiagramElement* p) :
        Shape(e, p),
        mTextItem(new QGraphicsTextItem(this)),
        mText(t) {
    addToGroup(mTextItem);
    mTextItem->setFont(QFont(sharedStyle()->fontName(), 
                sharedStyle()->fontSize()));
    setText(t);
}

Label::Label(const Label& l) : 
        Shape(l) {
    NYI();
    setText(l.mText);
}

void Label::setText(const QString& s) {
    mText = s;
    setHtml(s);
}

void Label::setHtml(const QString& s) {
    mTextItem->setHtml(s);
}

void Label::setWidth(double w) {
    mTextItem->setTextWidth(w);
}

QUML_END_NAMESPACE_UD
