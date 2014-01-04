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

#include "Element.h"

#include "Comment.h"

QUML_BEGIN_NAMESPACE_UK

QHash<QString, Element*> Element::mElementsById;

Element::Element() {
    mElementsById.insert(uniqueId(), this);

    elementChanged += [=] {
        this->childElementChanged();
        if(this->parent())
            this->parent()->childElementChanged();
    };
}

Element::Element(const Element&) {
    NYI();
    mElementsById.insert(uniqueId(), this);
}

Element::~Element() {
    mElementsById.remove(uniqueId());
}

QString Element::uniqueId() const {
    return mUniqueId.toString();
}

void Element::setUniqueId(const QString& s) {
    mElementsById.remove(uniqueId());
    mUniqueId = s;
    mElementsById.insert(s, this);
}

Element* Element::byId(const QString& s) {
    auto it = mElementsById.find(s);
    return it == mElementsById.end() ? nullptr : *it;
}

QUML_END_NAMESPACE_UK
