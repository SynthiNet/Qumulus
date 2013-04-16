/*
 * Qumulus UML editor
 * Author: Randy Thiemann
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
}

void QumulusApplication::setMainWindow(QuGW::MainWindow* m) {
    mMainWindow = m;
}

QuGW::MainWindow* QumulusApplication::mainWindow() {
    return mMainWindow;
}

void QumulusApplication::onFocusChanged(QWidget* old, QWidget* now) {
#ifdef Q_OS_MAC
    QuGW::SideBar* sideBar = mainWindow()->sideBar();
    QuGW::StatusBar* statusBar = mainWindow()->statusBar();

    if(old == nullptr) {
        statusBar->setStyleType(QuGW::StyleType::Active);
        sideBar->setStyleType(QuGW::StyleType::Active);
    } else if(now == nullptr) {
        statusBar->setStyleType(QuGW::StyleType::Inactive);
        sideBar->setStyleType(QuGW::StyleType::Inactive);
    }
#endif
}

QUML_END_NAMESPACE_GC

