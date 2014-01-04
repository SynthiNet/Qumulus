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

#ifndef GUI_WIDGETS_TOOLBARITEM_H_
#define GUI_WIDGETS_TOOLBARITEM_H_

#include "internal_base.h"
#include <QtCore/QString>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMenu>
#include <QtGui/QIcon>
#include <Gui/Widgets/ElementItem.h>
#include <Gui/Widgets/ToolBarMenu.h>
#include <Lib/Core/Ptr.h>

QUML_BEGIN_NAMESPACE_GW

class MainWindow;
class ToolBar;

class ToolBarItem : public QWidget {
    Q_OBJECT

public:
    ToolBarItem(ElementItem item);
    void setMenu(ToolBarMenu* menu);
    const QString text() const;

private:
    QHBoxLayout* mLayout;
    QPushButton* mButton;
    QPushButton* mDropdown;
    ToolBarMenu* mMenu;
    ElementItem mElementItem;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_TOOLBARITEM_H_ */

