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

#include "ToolBar.h"
#include <Gui/Widgets/MainWindow.h>

QUML_BEGIN_NAMESPACE_GW

#ifdef Q_OS_MAC_disabled
ToolBar::ToolBar(QObject* parent) : QObject(parent),
        mToolBar(new QMacNativeToolBar()) {
}
#else
ToolBar::ToolBar(QObject* parent) : QObject(parent),
        mToolBar(new QToolBar()) {
    mToolBar->setFloatable(false);
    mToolBar->setMovable(false);
}
#endif

void ToolBar::showInWindow(MainWindow* w) {
    mWindow = w;
#ifdef Q_OS_MAC_disabled
    mToolBar->showInWindowForWidget(w);
    mToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
#else
    w->addToolBar(mToolBar.get());
    mToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
#endif
}

QuGW::MainWindow* ToolBar::window() {
    return mWindow;
}

// #ifndef Q_OS_MAC
void ToolBar::addWidget(ToolBarItem* item) {
    mToolBar->addWidget(item);
}
// #endif

void ToolBar::addSeparator() {
    mToolBar->addSeparator();
}

#ifdef Q_OS_MAC_disabled
void ToolBar::addFlexibleSpace() {
    mToolBar->addStandardItem(QMacToolButton::FlexibleSpace);
}
#endif

QUML_END_NAMESPACE_GW

