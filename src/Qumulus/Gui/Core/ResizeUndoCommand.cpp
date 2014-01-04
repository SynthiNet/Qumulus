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

#include "ResizeUndoCommand.h"

#include <QtCore/QDebug>

#include <Gui/Diagram/Diagram.h>
#include <Gui/Widgets/EditorView.h>

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

    mShape->diagram()->editorView()->updateButtonsPosition();
}

void ResizeUndoCommand::redo() {
    mShape->setFlag(QGraphicsItem::ItemSendsGeometryChanges, false);
    mShape->setPos(mNewPoint);
    mShape->resize(mNewSize);
    mShape->prepareGeometryChange();
    mShape->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    mShape->diagram()->editorView()->updateButtonsPosition();
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
