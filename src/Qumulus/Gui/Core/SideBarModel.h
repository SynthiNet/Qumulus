/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
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

