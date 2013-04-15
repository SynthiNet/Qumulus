/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "QumulusApplication.h"

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

}

QUML_END_NAMESPACE_GC

