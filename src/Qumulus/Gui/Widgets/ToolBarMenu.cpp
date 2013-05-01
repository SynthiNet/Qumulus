/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "ToolBarMenu.h"
#include <QtWidgets/QAction>

QUML_BEGIN_NAMESPACE_GW

void ToolBarMenu::addItem(ElementItem el) {
    QAction* action = new QAction(el.icon(), el.text(), this);
    action->setShortcuts({el.shortcut()});
    action->setIconVisibleInMenu(true);
    addAction(action);

    connect(action, &QAction::triggered, el.slot());
}

QUML_END_NAMESPACE_GW

