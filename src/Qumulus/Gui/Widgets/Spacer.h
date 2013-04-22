/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_SPACER_H_
#define GUI_WIDGETS_SPACER_H_

#include "internal_base.h"
#include <QtWidgets/QWidget>

QUML_BEGIN_NAMESPACE_GW

class Spacer : public QWidget {
    Q_OBJECT

public:
    Spacer(QWidget* parent = 0);
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_SPACER_H_ */

