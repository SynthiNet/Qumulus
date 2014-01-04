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

#ifndef UML_KERNEL_DIRECTEDRELATIONSHIP_H_
#define UML_KERNEL_DIRECTEDRELATIONSHIP_H_

#include "internal_base.h"

#include "Element.h"

QUML_BEGIN_NAMESPACE_UK

class DirectedRelationship : public Element {
public:
    DirectedRelationship() = default;
    DirectedRelationship(Element* source, Element* target) :
            mSource(source),
            mTarget(target) {

    }

    int index() const override { return -1; }
    size_t size() const override { return 0; }
    Element* operator[](size_t) const override { return nullptr; }

    QString sidebarIcon() const override { return ""; }
    QString sidebarText() const override { return ""; }

    Element* source() const { return mSource; }
    void setSource(Element* s) { mSource = s; }

    Element* target() const { return mTarget; }
    void setTarget(Element* s) { mTarget = s; }

    QUML_CLONABLE_ABSTRACT(DirectedRelationship);
private:
    Element* mSource = nullptr;
    Element* mTarget = nullptr;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_DIRECTEDRELATIONSHIP_H_ */

