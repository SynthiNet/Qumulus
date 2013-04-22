/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_STATUSBAR_H_
#define GUI_WIDGETS_STATUSBAR_H_

#include "internal_base.h"
#include <QtWidgets/QStatusBar>
#include <Gui/Widgets/StyleType.h>

QUML_BEGIN_NAMESPACE_GW

class MainWindow;

class StatusBar : public QStatusBar {
    Q_OBJECT

public:
    StatusBar(QWidget* parent = 0);
    MainWindow* window();

#ifdef Q_OS_MAC
    void setStyleType(StyleType s);
#endif
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_STATUSBAR_H_ */

