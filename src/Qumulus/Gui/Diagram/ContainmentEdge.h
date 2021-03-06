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

#ifndef UML_DIAGRAM_CONTAINMENTEDGE_H_
#define UML_DIAGRAM_CONTAINMENTEDGE_H_

#include "internal_base.h"

#include "Edge.h"

QUML_BEGIN_NAMESPACE_GD

class ContainmentEdge : public Edge {
public:
    ContainmentEdge(QuUK::Element* e = 0, DiagramElement* p = 0);
    ContainmentEdge(const ContainmentEdge&);

    void writeXml(QXmlStreamWriter&) const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

    QUML_CLONABLE(ContainmentEdge);
private:
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_CONTAINMENTEDGE_H_ */

