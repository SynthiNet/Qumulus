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

#include "Compartment.h"
#include "CompartmentableShape.h"

#include <QtWidgets/QGraphicsRectItem>
#include <QtGui/QBrush>

QUML_BEGIN_NAMESPACE_GD

Compartment::Compartment(CompartmentableShape* p) :
        DiagramElement(0, p) {}

Compartment::Compartment(const Compartment& c) :
        DiagramElement(c) {}

CompartmentableShape* Compartment::compartmentableShape() const {
    return static_cast<CompartmentableShape*>(owningElement());
}

void Compartment::setCompartimentableShape(CompartmentableShape* s) {
    setOwningElement(s);
}

void Compartment::setHeight(float h) {
    h = mMinimumHeight == -1 ? h : std::max(h, mMinimumHeight);
    h = mMaximumHeight == -1 ? h : std::min(h, mMaximumHeight);

    mHeight = h;
}

QUML_END_NAMESPACE_GD
