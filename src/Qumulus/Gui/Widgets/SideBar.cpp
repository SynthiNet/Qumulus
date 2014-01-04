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

#include "SideBar.h"
#include <Gui/Widgets/MainWindow.h>

#include <QtWidgets/QHeaderView>

#include <iostream>

QUML_BEGIN_NAMESPACE_GW

SideBar::SideBar(MainWindow* parent, QuGD::Diagram* d) :
        QTreeView(parent),
        mDiagram(d),
        mModel(new QuGC::SideBarModel(mDiagram)){
#ifdef Q_OS_MAC
    setStyleType(StyleType::Active);
    setAttribute(Qt::WA_MacShowFocusRect, false);
#endif
    setMinimumWidth(100);
    QSizePolicy sideBarSizePolicy = sizePolicy();
    sideBarSizePolicy.setHorizontalPolicy(QSizePolicy::Minimum);
    setSizePolicy(sideBarSizePolicy);
    setModel(mModel);
    header()->close();

    mDiagram->diagramChanged += [this] {
        collapseAll();
        expandAll();
    };
}

SideBar::~SideBar() {
    delete mModel;
}

MainWindow* SideBar::window() {
    return static_cast<MainWindow*>(parent());
}

#ifdef Q_OS_MAC
void SideBar::setStyleType(StyleType s) {
    switch(s) {
    case StyleType::Active:
        setStyleSheet(
            "background-color: qlineargradient("
                    "spread:pad, x1:0, y1:0, x2:0, y2:1,"
                    "stop:0 rgba(232, 236, 241, 255),"
                    "stop:1 rgba(209,216,226, 255));"
            "selection-color: white;"
            "selection-background-color: qlineargradient("
                    "x1: 0, y1: 0, x2: 0, y2: 1,"
                    "stop: 0 rgb(110, 165, 218),"
                    "stop: 1 rgb(33, 108, 183));"
            "border-top: 1px solid silver;"
            "border-bottom: 1px solid silver;"
            "font-size: 11pt;"
        );
        break;
    case StyleType::Inactive:
        setStyleSheet(
            "background-color: qlineargradient("
            "spread:pad, x1:0, y1:0, x2:0, y2:1,"
            "stop:0 rgba(247, 247, 247, 255),"
            "stop:1 rgba(235, 235, 235, 255));"
            "selection-color: white;"
            "selection-background-color: qlineargradient("
                    "x1: 0, y1: 0, x2: 0, y2: 1,"
                    "stop: 0 rgb(110, 165, 218),"
                    "stop: 1 rgb(33, 108, 183));"
            "border-top: 1px solid silver;"
            "border-bottom: 1px solid silver;"
            "font-size: 11pt;"
        );
        break;
    }

}
#endif

QUML_END_NAMESPACE_GW

