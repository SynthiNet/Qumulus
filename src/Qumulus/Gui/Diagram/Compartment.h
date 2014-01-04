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

#ifndef UML_DIAGRAM_COMPARTMENT_H_
#define UML_DIAGRAM_COMPARTMENT_H_

#include "internal_base.h"

#include "DiagramElement.h"

class QGraphicsRectItem;

QUML_BEGIN_NAMESPACE_GD

class CompartmentableShape;

class Compartment : public DiagramElement {
    friend class CompartmentableShape;
public:
    Compartment(CompartmentableShape* p = 0);
    Compartment(const Compartment&);

    CompartmentableShape* compartmentableShape() const;
    void setCompartimentableShape(CompartmentableShape* s);

    float height() const { return mHeight; }
    void setHeight(float f);
    float minimumHeight() const { return mMinimumHeight; }
    void setMinimumHeight(float f) { mMinimumHeight = f; }
    float maximumHeight() const { return mMaximumHeight; }
    void setMaximumHeight(float f) { mMaximumHeight = f; }

    void writeXml(QXmlStreamWriter&) const override {}

    QUML_CLONABLE(Compartment);
private:
    QGraphicsRectItem* mRectItem;
    float mHeight = 0;
    float mMinimumHeight = -1;
    float mMaximumHeight = -1;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_COMPARTMENT_H_ */

