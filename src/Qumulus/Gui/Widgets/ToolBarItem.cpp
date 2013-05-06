/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "ToolBarItem.h"

#include "ToolBar.h"

QUML_BEGIN_NAMESPACE_GW

ToolBarItem::ToolBarItem(ElementItem elementItem) : mElementItem(elementItem) {
    mLayout = new QHBoxLayout(this);
    mButton = new QPushButton(this);
    mDropdown = new QPushButton(this);

    mButton->setFlat(true);
    mDropdown->setFlat(true);

    mButton->setIconSize({32,32});

    mButton->setMaximumSize({32,32});
    mDropdown->setMaximumSize({9,32});

    mButton->setIcon(mElementItem.icon());
    mButton->setToolTip(mElementItem.text() + " [" + 
            mElementItem.shortcut().toString() + "]");
    mButton->setShortcut(mElementItem.shortcut());
    mDropdown->setIcon(QIcon(":/data/img/toolbar/dropdown.png"));

    mLayout->addWidget(mButton);
    mLayout->addWidget(mDropdown);
    mLayout->setContentsMargins(2,2,2,2);
    mLayout->setSpacing(2);
    setLayout(mLayout);
    mDropdown->hide();

    connect(mButton, &QPushButton::clicked, mElementItem.slot());
}

const QString ToolBarItem::text() const {
    return mElementItem.text();
}

void ToolBarItem::setMenu(ToolBarMenu* menu) {
    mDropdown->addActions(menu->actions());
    mMenu = menu;
    connect(mDropdown, &QPushButton::clicked, [&]{
            mMenu->exec(mButton->mapToGlobal({-2, 34}));});
    mDropdown->show();
}

QUML_END_NAMESPACE_GW

