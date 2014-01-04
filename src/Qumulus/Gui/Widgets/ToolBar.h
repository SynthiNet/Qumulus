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
    constexpr static const char* kToolBarName = "QumulusToolBar";

public:
    ToolBar(QObject* parent = 0) : QObject(parent) {}
    virtual ~ToolBar() {}
    virtual void showInWindow(MainWindow* w) = 0;
    MainWindow* window() const { return mWindow; }

    // TODO: make this return QAction*
    virtual void addWidget(ToolBarItem* item) = 0;
    virtual void addSeparator() = 0;

protected:
    MainWindow* mWindow;
};

class QtToolBar : public ToolBar {
    Q_OBJECT
public:
    QtToolBar(QObject* parent = 0);
    ~QtToolBar() {}
    void showInWindow(MainWindow* w) override;

    void addWidget(ToolBarItem* item) override;
    void addSeparator() override;
private:
    QToolBar* mToolBar;

};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_TOOLBAR_H_ */

