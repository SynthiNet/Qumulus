/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
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

