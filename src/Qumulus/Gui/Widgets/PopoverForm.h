/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_POPOVERFORM_H_
#define GUI_WIDGETS_POPOVERFORM_H_

#include "internal_base.h"
#include <Gui/Diagram/internal_base.h>

QUML_BEGIN_NAMESPACE_GD

class Shape;

QUML_END_NAMESPACE_GD

QUML_BEGIN_NAMESPACE_GW

class PopoverForm {
public:
    virtual void setupUi() = 0;
    virtual bool isInFocus() = 0;
    virtual void bindModel(QuGD::Shape*) = 0;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_POPOVERFORM_H_ */

