/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "QumulusApplication.h"

#include <Gui/Widgets/SideBar.h>

QUML_BEGIN_NAMESPACE_GC

QumulusApplication::QumulusApplication(int& argc, char** argv) : 
    QApplication(argc, argv)  {
    connect(this, &QumulusApplication::focusChanged, 
            this, &QumulusApplication::onFocusChanged);
}

void QumulusApplication::setMainWindow(QuGW::MainWindow* m) {
    mMainWindow = m;
}

QuGW::MainWindow* QumulusApplication::mainWindow() {
    return mMainWindow;
}

void QumulusApplication::onFocusChanged(QWidget* old, QWidget* now) {
    QuGW::SideBar* s = mainWindow()->sideBar();

    if(old == nullptr) {
        s->setStyleType(QuGW::SideBar::StyleType::Active);
    } else if(now == nullptr) {
        s->setStyleType(QuGW::SideBar::StyleType::Inactive);
    }
}

QUML_END_NAMESPACE_GC

