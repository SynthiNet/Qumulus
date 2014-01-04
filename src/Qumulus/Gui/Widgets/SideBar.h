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

#ifndef GUI_WIDGETS_SIDEBAR_H_
#define GUI_WIDGETS_SIDEBAR_H_

#include "internal_base.h"
#include <QtWidgets/QTreeView>
#include <Gui/Core/SideBarModel.h>
#include <Gui/Widgets/StyleType.h>
#include <Gui/Diagram/Diagram.h>
#include <Lib/Core/Ptr.h>

QUML_BEGIN_NAMESPACE_GW

class MainWindow;

class SideBar : public QTreeView {
    Q_OBJECT

public:
    SideBar(MainWindow* w, QuGD::Diagram* diagram);
    ~SideBar();
    MainWindow* window();
    QuGD::Diagram* diagram() const { return mDiagram; }

#ifdef Q_OS_MAC
    void setStyleType(StyleType s);
#endif
private:
    QuGD::Diagram* mDiagram;
    QuGC::SideBarModel* mModel;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_SIDEBAR_H_ */

