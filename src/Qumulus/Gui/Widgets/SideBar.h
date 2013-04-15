/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_SIDEBAR_H_
#define GUI_WIDGETS_SIDEBAR_H_

#include "internal_base.h"
#include <QtWidgets/QTreeView>
#include <Lib/Core/Ptr.h>

QUML_BEGIN_NAMESPACE_GW

class MainWindow;

class SideBar : public QTreeView {
    Q_OBJECT

#ifdef Q_OS_MAC
public:
    enum class StyleType {
        Active,
        Inactive
    };
#endif

public:
    SideBar(QWidget* parent = 0);
    void setWindow(MainWindow* w);
    MainWindow* window();

#ifdef Q_OS_MAC
    void setStyleType(StyleType s);
#endif

private:
    MainWindow* mWindow;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_SIDEBAR_H_ */

