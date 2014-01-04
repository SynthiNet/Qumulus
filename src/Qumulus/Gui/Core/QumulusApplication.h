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

#ifndef GUI_CORE_QUMULUSAPPLICATION_H_
#define GUI_CORE_QUMULUSAPPLICATION_H_

#include "internal_base.h"
#include <QtWidgets/QApplication>
#include <Gui/Widgets/MainWindow.h>

#ifdef qApp
#undef qApp
#endif
#define qApp static_cast<QuGC::QumulusApplication*>(QCoreApplication::instance())

QUML_BEGIN_NAMESPACE_GC

class QumulusApplication : public QApplication {
    Q_OBJECT

public:
    QumulusApplication(int& argc, char** argv);
    QuGW::MainWindow* mainWindowForWidget(QWidget* w) const;

    QuGW::MainWindow* activeWindow() const;

public slots:
    void onFocusChanged(QWidget* old, QWidget* now);

private:
    QuGW::MainWindow* mMainWindow;
    QuGW::MainWindow* mActiveWindow;
};

QUML_END_NAMESPACE_GC

#endif /* GUI_CORE_QUMULUSAPPLICATION_H_ */

