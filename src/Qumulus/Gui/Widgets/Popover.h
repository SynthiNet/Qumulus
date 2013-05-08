/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_POPOVER_H_
#define GUI_WIDGETS_POPOVER_H_

#include "internal_base.h"
#include <QtWidgets/QWidget>

QUML_BEGIN_NAMESPACE_GW

class Popover : public QWidget {
    Q_OBJECT

public:
    Popover(QWidget* parent = 0, QPoint pos = QPoint(0, 0));

protected:
    void resizeEvent(QResizeEvent* event) override;
    
private:
    void generateMask();

private:
    QBitmap* mMask;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_POPOVER_H_ */

