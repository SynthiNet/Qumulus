/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef GUI_CORE_SIDEBARMODEL_H_
#define GUI_CORE_SIDEBARMODEL_H_

#include "internal_base.h"

#include <Gui/Diagram/Diagram.h>

#include <QtCore/QAbstractItemModel>

QUML_BEGIN_NAMESPACE_GD

class Diagram;

QUML_END_NAMESPACE_GD

QUML_BEGIN_NAMESPACE_GC

class SideBarModel : public QAbstractItemModel {
    Q_OBJECT;
public:
    SideBarModel(QuGD::Diagram* diagram);
private:
    QuGD::Diagram* mDiagram;
};

QUML_END_NAMESPACE_GC

#endif /* GUI_CORE_SIDEBARMODEL_H_ */

