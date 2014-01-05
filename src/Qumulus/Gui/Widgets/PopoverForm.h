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

#ifndef GUI_WIDGETS_POPOVERFORM_H_
#define GUI_WIDGETS_POPOVERFORM_H_

#include "internal_base.h"
#include <Gui/Diagram/internal_base.h>

// TODO: figure out where to put this
#ifdef Q_OS_MAC
constexpr double kFontMacFactor = 1.0;
#else
constexpr double kFontMacFactor = 1.3;
#endif

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

