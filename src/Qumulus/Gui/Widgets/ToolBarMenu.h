/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_TOOLBARMENU_H_
#define GUI_WIDGETS_TOOLBARMENU_H_

#include "internal_base.h"
#include <QtWidgets/QMenu>
#include <Gui/Widgets/ElementItem.h>
#include <functional>

QUML_BEGIN_NAMESPACE_GW

class ToolBarMenu : public QMenu {
    Q_OBJECT

public:
    void addItem(ElementItem el);
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_TOOLBARMENU_H_ */

