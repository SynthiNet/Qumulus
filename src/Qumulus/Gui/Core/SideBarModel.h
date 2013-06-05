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
    ~SideBarModel();

    QVariant data(const QModelIndex& index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
            int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
            const QModelIndex& parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex& index) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    bool isRootNode(const QModelIndex& node) const;
private:
    QuGD::Diagram* mDiagram;
};

QUML_END_NAMESPACE_GC

#endif /* GUI_CORE_SIDEBARMODEL_H_ */

