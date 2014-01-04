/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
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

