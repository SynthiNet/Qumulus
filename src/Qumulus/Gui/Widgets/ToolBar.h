/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_TOOLBAR_H_
#define GUI_WIDGETS_TOOLBAR_H_

#include "internal_base.h"
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtWidgets/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QToolBar>
#include <Lib/Core/Ptr.h>
#include <Gui/Widgets/ToolBarItem.h>

QUML_BEGIN_NAMESPACE_GW

class MainWindow;

class ToolBar : public QObject {
    Q_OBJECT

public:
    ToolBar(QObject* parent = 0);
    void showInWindow(MainWindow* w);
    MainWindow* window();

    // TODO: make this return QAction*
    void addWidget(ToolBarItem* item);
    void addSeparator();

#ifdef Q_OS_MAC_disabled
    void addFlexibleSpace();
    NSToolbar* nativeToolbar() const { return mToolBar->nativeToolbar(); }
#endif

private:
#ifdef Q_OS_MAC_disabled
    uptr<QMacNativeToolBar> mToolBar;
#else
    uptr<QToolBar> mToolBar;
#endif
    MainWindow* mWindow;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_TOOLBAR_H_ */

