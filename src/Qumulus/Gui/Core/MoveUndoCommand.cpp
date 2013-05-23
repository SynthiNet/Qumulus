/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "MoveUndoCommand.h"

#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_GC

MoveUndoCommand::MoveUndoCommand(QuGD::SelectableShape* shape, 
        QPointF old, QPointF now) :
        QUndoCommand("Move"),
        mShape(shape),
        mOld(old),
        mNew(now) {

}

void MoveUndoCommand::undo() {
    mShape->setFlag(QGraphicsItem::ItemSendsGeometryChanges, false);
    mShape->setPos(mOld);
    mShape->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

void MoveUndoCommand::redo() {
    if(!mUsed) {
        mUsed = true;
        return;
    }
    mShape->setFlag(QGraphicsItem::ItemSendsGeometryChanges, false);
    mShape->setPos(mNew);
    mShape->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

int MoveUndoCommand::id() const {
    return 314159;
}

bool MoveUndoCommand::mergeWith(const QUndoCommand* command) {
    if(command->id() != id()) {
        return false;
    }

    mNew = static_cast<const MoveUndoCommand*>(command)->mNew;
    mUsed = true;
    return true;
}

QUML_END_NAMESPACE_GC
