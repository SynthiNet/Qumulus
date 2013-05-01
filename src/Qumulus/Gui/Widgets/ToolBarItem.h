/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_TOOLBARITEM_H_
#define GUI_WIDGETS_TOOLBARITEM_H_

#include "internal_base.h"
#include <QtCore/QString>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMenu>
#include <QtGui/QIcon>
#include <Gui/Widgets/ElementItem.h>
#include <Lib/Core/Ptr.h>
#ifdef Q_OS_MAC
#include <QtMacExtras/QMacNativeWidget>
#endif

QUML_BEGIN_NAMESPACE_GW

class MainWindow;
class ToolBar;

class ToolBarItem : public QWidget {
    Q_OBJECT

public:
    ToolBarItem(ElementItem item);
    void setMenu(QMenu* menu);
    const QString text() const;

private:
    QHBoxLayout* mLayout;
    QPushButton* mButton;
    QPushButton* mDropdown;
    ElementItem mElementItem;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_TOOLBARITEM_H_ */

