/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "SideBarModel.h"

#include <Uml/Kernel/Element.h>
#include <Uml/Kernel/Package.h>

#include <QtCore/QDebug>
#include <QtGui/QIcon>

QUML_BEGIN_NAMESPACE_GC

SideBarModel::SideBarModel(QuGD::Diagram* diagram) :
        mDiagram(diagram) {
}

SideBarModel::~SideBarModel() {
}

QVariant SideBarModel::data(const QModelIndex& index, int role) const {
    auto node = static_cast<QuUK::Element*>(index.internalPointer());

    if(node == nullptr) {
        // Display text for root node
        switch(role) {
        case Qt::DisplayRole:
            return tr("Class Diagram");
        default:
            return QVariant();
        }
    } else {
        switch(role) {
        case Qt::DisplayRole:
            return node->sidebarText();
        case Qt::DecorationRole:
            return QIcon(":/data/img/sidebar/" + node->sidebarIcon() + ".png");
        default:
            return QVariant();
        }
    }
}

Qt::ItemFlags SideBarModel::flags(const QModelIndex& index) const {
    if(!index.isValid())
        return 0;

    return QAbstractItemModel::flags(index);
}

QVariant SideBarModel::headerData(int section, Qt::Orientation orientation,
        int role) const {
    // No headers
    (void)section;
    (void)orientation;
    (void)role;
    return QVariant();
}

QModelIndex SideBarModel::index(int row, int column,
        const QModelIndex& parent) const {
    if(!parent.isValid()) {
        // Return the root node
        return createIndex(row, column, nullptr);
    } else if(parent.internalPointer() == nullptr) {
        if((size_t)row < mDiagram->rootPackage()->size()) {
            // Return the element of the root package
            return createIndex(row, column, (*mDiagram->rootPackage())[row]);
        } else {
            // Return a comment
            return createIndex(row, column, mDiagram->comments()[
                    row - mDiagram->rootPackage()->size()]);
        }
    } else {
        return createIndex(row, column,
                (*static_cast<QuUK::Element*>(parent.internalPointer()))[row]);
    }
}

QModelIndex SideBarModel::parent(const QModelIndex& index) const {
    if(!index.isValid()) {
        return QModelIndex();
    }

    auto node = static_cast<QuUK::Element*>(index.internalPointer());

    if(node == nullptr) {
        // Root node
        return QModelIndex();
    } else if(node->parent() == nullptr ||
            node->parent() == static_cast<QuUK::Element*>(
                mDiagram->rootPackage())) {
        // Return the root node.
        return createIndex(0, 0, nullptr);
    } else {
        // Return the parent
        return createIndex(node->parent()->index(), 0, node->parent());
    }

}

int SideBarModel::rowCount(const QModelIndex& parent) const {
    if(!parent.isValid()) {
        // Are we trying to render the root node? If so, there is only one.
        return 1;
    } else if(parent.internalPointer() == nullptr) {
        // This is the root node. Return the number of comments
        return mDiagram->rootPackage()->size() + mDiagram->comments().size();
    } else {
        // Not the root node
        return static_cast<QuUK::Element*>(parent.internalPointer())->size();
    }
}

int SideBarModel::columnCount(const QModelIndex& parent) const {
    (void)parent;
    // We don't have columns
    return 1;
}

QUML_END_NAMESPACE_GC
