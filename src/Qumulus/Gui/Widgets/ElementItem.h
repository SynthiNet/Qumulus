/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_ELEMENTITEM_H_
#define GUI_WIDGETS_ELEMENTITEM_H_

#include "internal_base.h"
#include <QtCore/QString>
#include <QtGui/QIcon>
#include <QtGui/QKeySequence>

QUML_BEGIN_NAMESPACE_GW

class ElementItem {
public:
    ElementItem() {}
    ElementItem(QString text, QIcon icon, QKeySequence shortcut) :
        mText(text), mIcon(icon), mShortcut(shortcut) {}
    void setText(QString s) { mText = s; }
    QString text() const { return mText; }
    void setIcon(QIcon i) { mIcon = i; }
    QIcon icon() const { return mIcon; }
    void setShortcut(QKeySequence k) { mShortcut = k; }
    QKeySequence shortcut() const { return mShortcut; }

private:
    QString mText;
    QIcon mIcon;
    QKeySequence mShortcut;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_ELEMENTITEM_H_ */

