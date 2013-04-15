/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "ToolBar.h"
#include <Gui/Widgets/MainWindow.h>

QUML_BEGIN_NAMESPACE_GW

#ifdef Q_OS_MAC
ToolBar::ToolBar() : mToolBar(new QMacUnifiedToolBar()) {}
#else
ToolBar::ToolBar() : mToolBar(new QToolBar()) {}
#endif

void ToolBar::showInWindow(MainWindow* w) {
    mWindow = w;
#ifdef Q_OS_MAC
    mToolBar->showInWindowForWidget(w);
#else
    w->addToolBar(mToolBar.get());
#endif
}

QuGW::MainWindow* ToolBar::window() {
    return mWindow;
}

QAction* ToolBar::addAction(const QIcon& icon, const QString& text) {
    return mToolBar->addAction(icon, text);
}

void ToolBar::addSeparator() {
    mToolBar->addSeparator();
}

#ifdef Q_OS_MAC
void ToolBar::addFlexibleSpace() {
    mToolBar->addStandardItem(QMacToolButton::FlexibleSpace);
}
#endif

QUML_END_NAMESPACE_GW

