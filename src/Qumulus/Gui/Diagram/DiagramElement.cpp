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

#include "DiagramElement.h"
#include "Diagram.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_GD

QHash<QString, DiagramElement*> DiagramElement::mElementsById;

DiagramElement::DiagramElement(QuUK::Element* m, DiagramElement* p) :
        mModelElement(m),
        mLocalStyle(0),
        mOwningElement(p) {
    mElementsById.insert(uniqueId(), this);
}

DiagramElement::DiagramElement(const DiagramElement& d) {
    NYI();
    (void)d;
    mElementsById.insert(uniqueId(), this);
}

DiagramElement::~DiagramElement() {
    mElementsById.remove(uniqueId());
    delete mLocalStyle;
}

Style* DiagramElement::sharedStyle() const {
    if(mLocalStyle)
        return mLocalStyle;
    else
        return owningElement()->sharedStyle();
}


Diagram* DiagramElement::diagram() const {
    DiagramElement* p = const_cast<DiagramElement*>(this);

    while(!dynamic_cast<Diagram*>(p)) {
        p = p->owningElement();
    }

    return static_cast<Diagram*>(p);
}

QString DiagramElement::uniqueId() const {
    return mUniqueId.toString();
}

void DiagramElement::setUniqueId(const QString& s) {
    mElementsById.remove(uniqueId());
    mUniqueId = s;
    mElementsById.insert(s, this);
}

DiagramElement* DiagramElement::byId(const QString& s) {
    auto it = mElementsById.find(s);
    return it == mElementsById.end() ? nullptr : *it;
}

QUML_END_NAMESPACE_GD
