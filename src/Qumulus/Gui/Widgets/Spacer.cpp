/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "Spacer.h"

QUML_BEGIN_NAMESPACE_GW

Spacer::Spacer(QWidget* parent) : QWidget(parent) {
    setStyleSheet("Spacer {border: 0; background: transparent;}");
    setMinimumWidth(5);
}

QUML_END_NAMESPACE_GW

