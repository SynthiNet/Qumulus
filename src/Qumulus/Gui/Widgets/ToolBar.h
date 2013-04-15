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
#ifdef Q_OS_MAC
#include <QtMacExtras/QMacUnifiedToolBar>
#else
#include <QtWidgets/QToolBar>
#endif
#include <Lib/Core/Ptr.h>

QUML_BEGIN_NAMESPACE_GW

class MainWindow;

class ToolBar : public QObject {
    Q_OBJECT

public:
    ToolBar(QObject* parent = 0);
    void showInWindow(MainWindow* w);
    MainWindow* window();
    QAction* addAction(const QIcon& icon, const QString& text);
    void addSeparator();
#ifdef Q_OS_MAC
    void addFlexibleSpace();
#endif

private:
#ifdef Q_OS_MAC
    uptr<QMacUnifiedToolBar> mToolBar;
#else
    uptr<QToolBar> mToolBar;
#endif
    MainWindow* mWindow;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_TOOLBAR_H_ */

