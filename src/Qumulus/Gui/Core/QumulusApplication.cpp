/*
 * Qumulus UML editor
 * Author: Frank Erens
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
// TODO: implement proper multi-document support on OS X.
// #ifdef Q_OS_MAC
//     setQuitOnLastWindowClosed(false);
// #endif
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

