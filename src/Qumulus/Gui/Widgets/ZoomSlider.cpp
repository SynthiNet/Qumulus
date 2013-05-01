/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "ZoomSlider.h"

QUML_BEGIN_NAMESPACE_GW

constexpr double kZoomMap[] = {.25, .50, .75, 1, 2, 3, 4};

ZoomSlider::ZoomSlider(QWidget* parent) : QSlider(parent) {
    setStyleSheet("QSlider {"
            "border: 5px solid transparent; background: transparent;}");
    setOrientation(Qt::Horizontal);
    setMaximumWidth(150);
    setMinimum(0);
    setMaximum(6);
    setSliderPosition(3);
    connect(this, &ZoomSlider::valueChanged, [&](int value){
            emit zoomChanged(kZoomMap[value]);});
}

QUML_END_NAMESPACE_GW

