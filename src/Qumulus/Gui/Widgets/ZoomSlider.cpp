/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "ZoomSlider.h"

QUML_BEGIN_NAMESPACE_GW

ZoomSlider::ZoomSlider(QWidget* parent) : QSlider(parent) {
    setStyleSheet("QSlider {"
            "border: 5px solid transparent; background: transparent;}");
    setOrientation(Qt::Horizontal);
    setMaximumWidth(150);
    setMinimum(25);
    setMaximum(400);
    setSliderPosition(100);
}

QUML_END_NAMESPACE_GW

