/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "ToolBarItem.h"

#include "ToolBar.h"

QUML_BEGIN_NAMESPACE_GW

ToolBarItem::ToolBarItem(ToolBar* parent) {
    mLayout = new QHBoxLayout(this);
    mButton = new QPushButton(this);
    mDropdown = new QPushButton(this);

    mButton->setFlat(true);
    mDropdown->setFlat(true);

    mButton->setIconSize({32,32});

    mButton->setMaximumSize({32,32});
    mDropdown->setMaximumSize({9,32});

    mDropdown->setIcon(QIcon(":/data/img/toolbar/dropdown.png"));

    mLayout->addWidget(mButton);
    mLayout->addWidget(mDropdown);
    mLayout->setContentsMargins(2,2,2,2);
    mLayout->setSpacing(2);
    setLayout(mLayout);
}

void ToolBarItem::setIcon(const QIcon& icon) {
    mButton->setIcon(icon);
}

void ToolBarItem::setText(const QString& text) {
    mText = text;
    mButton->setToolTip(text);
}

const QString& ToolBarItem::text() const {
    return mText;
}

void ToolBarItem::setMenu(QMenu* menu) {
    mDropdown->setMenu(menu);
}

QUML_END_NAMESPACE_GW

