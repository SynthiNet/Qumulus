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

#include "QumulusApplication.h"
#include <Gui/Widgets/StyleType.h>
#include <Gui/Widgets/SideBar.h>
#include <Gui/Widgets/StatusBar.h>

QUML_BEGIN_NAMESPACE_GC

QumulusApplication::QumulusApplication(int& argc, char** argv) :
    QApplication(argc, argv)  {
    connect(this, &QumulusApplication::focusChanged,
            this, &QumulusApplication::onFocusChanged);
// TODO: implement proper multi-document support on OS X.
// #ifdef Q_OS_MAC
//     setQuitOnLastWindowClosed(false);
// #endif
}

QuGW::MainWindow* QumulusApplication::activeWindow() const {
    return dynamic_cast<QuGW::MainWindow*>(QApplication::activeWindow());
}

QuGW::MainWindow* QumulusApplication::mainWindowForWidget(QWidget* w) const {
    QuGW::MainWindow* mw;
    while(w != nullptr) {
        w = w->parentWidget();
        if((mw = dynamic_cast<QuGW::MainWindow*>(w)))
            return mw;
    }

    return nullptr;
}


void QumulusApplication::onFocusChanged(QWidget* old, QWidget* now) {
#ifdef Q_OS_MAC
    QuGW::MainWindow* w1 = mainWindowForWidget(old);
    QuGW::MainWindow* w2 = mainWindowForWidget(now);

    if(w1 == w2) return;

    if(w1 != nullptr) {
        w1->sideBar()->setStyleType(QuGW::StyleType::Inactive);
        w1->statusBar()->setStyleType(QuGW::StyleType::Inactive);
    }

    if(w2 != nullptr) {
        w2->sideBar()->setStyleType(QuGW::StyleType::Active);
        w2->statusBar()->setStyleType(QuGW::StyleType::Active);
    }

    mActiveWindow = w2;
#endif
}

QUML_END_NAMESPACE_GC

