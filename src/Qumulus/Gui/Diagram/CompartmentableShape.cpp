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

#include "CompartmentableShape.h"

#include <QtGui/QPainter>

QUML_BEGIN_NAMESPACE_GD

CompartmentableShape::CompartmentableShape(QuUK::Element* e,
        DiagramElement* p) :
        SelectableShape(e, p) {}

CompartmentableShape::CompartmentableShape(const CompartmentableShape& c) :
        SelectableShape(c) {

}

Compartment* CompartmentableShape::compartment(unsigned i) {
    return mCompartments[i];
}

void CompartmentableShape::addCompartment(Compartment* c) {
    mCompartments.append(c);
}

void CompartmentableShape::resize(double w, double h) {
    w = minimumSize().width() == -1 ? w : std::max(w, minimumSize().width());
    h = minimumSize().height() == -1 ? h : std::max(h, minimumSize().height());

    unsigned totalh = 0;
    for(int i = 0; i < compartments().size(); ++i) {
        unsigned newh = h / (compartments().size() - i);

        compartment(i)->setHeight(newh);
        unsigned actualh = compartment(i)->height();

        // if(i < compartments().size() - 1)
        //     compartment(i + 1)->setPos(0, compartment(i)->pos().y() + actualh);

        h -= actualh;
        totalh += actualh;
    }

    setSize({w, totalh});
}

void CompartmentableShape::updateSizeConstraints() {

}

void CompartmentableShape::paint(QPainter* painter,
        const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setBrush(Qt::white);

    float h = 0;
    for(auto& c : compartments()) {
        painter->drawRect(0, h, width(), c->height());
        h += c->height();
    }

    SelectableShape::paint(painter, option, widget);
}

QUML_END_NAMESPACE_GD
