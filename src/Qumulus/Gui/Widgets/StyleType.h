/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_STYLETYPE_H_
#define GUI_WIDGETS_STYLETYPE_H_

#include "internal_base.h"

QUML_BEGIN_NAMESPACE_GW

#ifdef Q_OS_MAC
enum class StyleType {
    Active,
    Inactive
};
#endif

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_STYLETYPE_H_ */

