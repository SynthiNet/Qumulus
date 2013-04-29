/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "ToolBar.h"
#include <Gui/Widgets/MainWindow.h>

QUML_BEGIN_NAMESPACE_GW

#ifdef Q_OS_MAC_disabled
ToolBar::ToolBar(QObject* parent) : QObject(parent),
        mToolBar(new QMacNativeToolBar()) {
}
#else
ToolBar::ToolBar(QObject* parent) : QObject(parent),
        mToolBar(new QToolBar()) {
    mToolBar->setFloatable(false);
    mToolBar->setMovable(false);
}
#endif

void ToolBar::showInWindow(MainWindow* w) {
    mWindow = w;
#ifdef Q_OS_MAC_disabled
    mToolBar->showInWindowForWidget(w);
    mToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
#else
    w->addToolBar(mToolBar.get());
    mToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
#endif
}

QuGW::MainWindow* ToolBar::window() {
    return mWindow;
}

// #ifndef Q_OS_MAC
void ToolBar::addWidget(ToolBarItem* item) {
    mToolBar->addWidget(item);
}
// #endif

void ToolBar::addSeparator() {
    mToolBar->addSeparator();
}

#ifdef Q_OS_MAC_disabled
void ToolBar::addFlexibleSpace() {
    mToolBar->addStandardItem(QMacToolButton::FlexibleSpace);
}
#endif

QUML_END_NAMESPACE_GW

