/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "MainWindow.h"

QUML_BEGIN_NAMESPACE_GW

MainWindow::MainWindow() : mToolBar(new ToolBar()) {
    mToolBar->showInWindow(this);
}

QUML_END_NAMESPACE_GW

