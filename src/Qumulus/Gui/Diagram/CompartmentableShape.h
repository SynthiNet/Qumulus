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

#ifndef UML_DIAGRAM_COMPARTMENTABLESHAPE_H_
#define UML_DIAGRAM_COMPARTMENTABLESHAPE_H_

#include "internal_base.h"

#include "SelectableShape.h"

#include "Compartment.h"

class QPainter;

QUML_BEGIN_NAMESPACE_GD

class CompartmentableShape : public SelectableShape {
public:
    CompartmentableShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    CompartmentableShape(const CompartmentableShape&);

    Compartment* compartment(unsigned i);
    const QList<Compartment*> compartments() const { return mCompartments; }

    void addCompartment(Compartment* c);

    using Shape::resize;
    void resize(double, double) override;
    void updateSizeConstraints() override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
            QWidget* widget) override;

    QUML_CLONABLE_ABSTRACT(CompartmentableShape);
private:
    QList<Compartment*> mCompartments;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_COMPARTMENTABLESHAPE_H_ */

