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
