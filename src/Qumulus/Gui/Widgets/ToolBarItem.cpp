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

    mDropdown->setIcon(QIcon(":/data/img/toolbar/dropdown.png"));

    mLayout->addWidget(mButton);
    mLayout->addWidget(mDropdown);
    setLayout(mLayout);
}

void ToolBarItem::setIcon(const QIcon& icon) {
    mButton->setIcon(icon);
}

void ToolBarItem::setText(const QString& text) {
    mButton->setText(text);
}

void ToolBarItem::setMenu(QMenu* menu) {
    mDropdown->setMenu(menu);
}

QUML_END_NAMESPACE_GW

