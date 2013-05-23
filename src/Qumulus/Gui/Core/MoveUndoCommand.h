/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef GUI_CORE_MOVEUNDOCOMMAND_H_
#define GUI_CORE_MOVEUNDOCOMMAND_H_

#include "internal_base.h"

#include <QtWidgets/QUndoCommand>

#include <Gui/Diagram/SelectableShape.h>

QUML_BEGIN_NAMESPACE_GC

class MoveUndoCommand : public QUndoCommand {
public:
    // Fixme: make this work with multiselect
    MoveUndoCommand(QuGD::SelectableShape* shape, QPointF old, QPointF now);

    void undo() override;
    void redo() override;
    int id() const override;
    bool mergeWith(const QUndoCommand* command) override;
private:
    QuGD::SelectableShape* mShape;
    QPointF mOld;
    QPointF mNew;
    bool mUsed = false;
};

QUML_END_NAMESPACE_GC

#endif /* GUI_CORE_MOVEUNDOCOMMAND_H_ */

