/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef GUI_CORE_RESIZEUNDOCOMMAND_H_
#define GUI_CORE_RESIZEUNDOCOMMAND_H_

#include "internal_base.h"

#include <QtWidgets/QUndoCommand>

#include <Gui/Diagram/SelectableShape.h>

QUML_BEGIN_NAMESPACE_GC

class ResizeUndoCommand : public QUndoCommand {
public:
    // Fixme: make this work with multiselect
    ResizeUndoCommand(QuGD::SelectableShape* shape, 
            QPointF old, QPointF now, QSizeF oldsize, QSizeF newsize);

    void undo() override;
    void redo() override;
    int id() const override;
    bool mergeWith(const QUndoCommand* command) override;
private:
    QuGD::SelectableShape* mShape;
    QPointF mOldPoint;
    QPointF mNewPoint;
    QSizeF mOldSize;
    QSizeF mNewSize;
};

QUML_END_NAMESPACE_GC

#endif /* GUI_CORE_RESIZEUNDOCOMMAND_H_ */

