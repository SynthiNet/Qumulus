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

#ifndef GUI_WIDGETS_TOOLBAR_H_
#define GUI_WIDGETS_TOOLBAR_H_

#include "internal_base.h"
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtWidgets/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QToolBar>
#include <Lib/Core/Ptr.h>
#include <Gui/Widgets/ToolBarItem.h>

QUML_BEGIN_NAMESPACE_GW

class MainWindow;

class ToolBar : public QObject {
    Q_OBJECT

public:
    ToolBar(QObject* parent = 0);
    void showInWindow(MainWindow* w);
    MainWindow* window();

    // TODO: make this return QAction*
    void addWidget(ToolBarItem* item);
    void addSeparator();

#ifdef Q_OS_MAC_disabled
    void addFlexibleSpace();
    NSToolbar* nativeToolbar() const { return mToolBar->nativeToolbar(); }
#endif

private:
#ifdef Q_OS_MAC_disabled
    uptr<QMacNativeToolBar> mToolBar;
#else
    uptr<QToolBar> mToolBar;
#endif
    MainWindow* mWindow;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_TOOLBAR_H_ */

