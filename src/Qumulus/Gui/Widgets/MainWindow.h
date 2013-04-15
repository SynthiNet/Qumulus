/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_MAINWINDOW_H_
#define GUI_WIDGETS_MAINWINDOW_H_

#include "internal_base.h"
#include <QtWidgets/QMainWindow>
#include <Gui/Widgets/ToolBar.h>
#include <Lib/Core/Ptr.h>

QUML_BEGIN_NAMESPACE_GW

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

private:
    uptr<ToolBar> mToolBar;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_MAINWINDOW_H_ */

