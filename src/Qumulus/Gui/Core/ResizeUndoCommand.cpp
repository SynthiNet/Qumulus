/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "ResizeUndoCommand.h"

#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_GC

ResizeUndoCommand::ResizeUndoCommand(QuGD::SelectableShape* shape, 
            QPointF old, QPointF now, QSizeF oldsize, QSizeF newsize) :
        QUndoCommand("Resize"),
        mShape(shape),
        mOldPoint(old),
        mNewPoint(now),
        mOldSize(oldsize),
        mNewSize(newsize) {

}

void ResizeUndoCommand::undo() {
    mShape->setFlag(QGraphicsItem::ItemSendsGeometryChanges, false);
    mShape->setPos(mOldPoint);
    mShape->resize(mOldSize);
    mShape->prepareGeometryChange();
    mShape->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

void ResizeUndoCommand::redo() {
    mShape->setFlag(QGraphicsItem::ItemSendsGeometryChanges, false);
    mShape->setPos(mNewPoint);
    mShape->resize(mNewSize);
    mShape->prepareGeometryChange();
    mShape->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

int ResizeUndoCommand::id() const {
    return 271828;
}

bool ResizeUndoCommand::mergeWith(const QUndoCommand* command) {
    auto c = static_cast<const ResizeUndoCommand*>(command);

    if(command->id() != id()) {
        return false;
    }
    if(mShape != c->mShape) {
        return false;
    }

    mNewPoint = c->mNewPoint;
    mNewSize = c->mNewSize;
    return true;
}

QUML_END_NAMESPACE_GC
