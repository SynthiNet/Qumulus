/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "MoveUndoCommand.h"

#include <QtCore/QDebug>

#include <Gui/Diagram/Diagram.h>
#include <Gui/Widgets/EditorView.h>

QUML_BEGIN_NAMESPACE_GC

MoveUndoCommand::MoveUndoCommand(QList<QGraphicsItem*> selectedItems,
        QuGD::SelectableShape* shape, 
        QPointF old, QPointF now) :
        QUndoCommand("Move"),
        mSelectedItems(selectedItems) {
    mUndoData[shape] = { old, now };
}

void MoveUndoCommand::undo() {
    for(auto it = mUndoData.begin(); it != mUndoData.end(); ++it) {
        it.key()->setFlag(QGraphicsItem::ItemSendsGeometryChanges, false);
    }

    for(auto it = mUndoData.begin(); it != mUndoData.end(); ++it) {
        it.key()->setPos(it->mOld);
    }

    for(auto it = mUndoData.begin(); it != mUndoData.end(); ++it) {
        it.key()->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    }

    mUndoData.begin().key()->diagram()->editorView()->updateButtonsPosition();
}

void MoveUndoCommand::redo() {
    if(!mUsed) {
        mUsed = true;
        return;
    }

    for(auto it = mUndoData.begin(); it != mUndoData.end(); ++it) {
        it.key()->setFlag(QGraphicsItem::ItemSendsGeometryChanges, false);
    }

    for(auto it = mUndoData.begin(); it != mUndoData.end(); ++it) {
        it.key()->setPos(it->mNew);
    }

    for(auto it = mUndoData.begin(); it != mUndoData.end(); ++it) {
        it.key()->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    }

    mUndoData.begin().key()->diagram()->editorView()->updateButtonsPosition();
}

int MoveUndoCommand::id() const {
    return 314159;
}

bool MoveUndoCommand::mergeWith(const QUndoCommand* command) {
    auto c = static_cast<const MoveUndoCommand*>(command);

    if(command->id() != id()) {
        return false;
    }
    if(mSelectedItems != c->mSelectedItems) {
        return false;
    }

    for(auto it = c->mUndoData.begin(); it != c->mUndoData.end(); ++it) {
        if(mUndoData.contains(it.key()))
            mUndoData[it.key()].mNew = it.value().mNew;
        else
            mUndoData[it.key()] = it.value();
    }

    mUsed = true;
    return true;
}

QUML_END_NAMESPACE_GC
