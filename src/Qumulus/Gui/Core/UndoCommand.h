/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_CORE_UNDOCOMMAND_H_
#define GUI_CORE_UNDOCOMMAND_H_

#include "internal_base.h"
#include <QtWidgets/QUndoCommand>
#include <functional>

QUML_BEGIN_NAMESPACE_GC

class UndoCommand : public QUndoCommand {
public:
    UndoCommand(const QString& text, 
            std::function<void()> undo, std::function<void()> redo) : 
        QUndoCommand(text), mUndo(undo), mRedo(redo) {}
    void undo() override { mUndo(); }
    void redo() override { mRedo(); }

private:
    std::function<void()> mUndo;
    std::function<void()> mRedo;
};

QUML_END_NAMESPACE_GC

#endif /* GUI_CORE_UNDOCOMMAND_H_ */

