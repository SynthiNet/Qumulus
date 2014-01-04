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

#ifndef UML_DIAGRAM_DIAGRAMELEMENT_H_
#define UML_DIAGRAM_DIAGRAMELEMENT_H_

#include "internal_base.h"

#include "Style.h"

#include <QtCore/QObject>
#include <Lib/Core/Clonable.h>
#include <Lib/Core/UniqueId.h>

#include <Uml/Kernel/internal_base.h>

class QXmlStreamWriter;

QUML_BEGIN_NAMESPACE_UK
class Element;
QUML_END_NAMESPACE_UK

QUML_BEGIN_NAMESPACE_GD

class Diagram;

class DiagramElement {
public:
    DiagramElement(QuUK::Element* m = 0, DiagramElement* p = 0);
    DiagramElement(const DiagramElement&);

    virtual ~DiagramElement();

    virtual QuUK::Element* modelElement() const { return mModelElement; }
    virtual void setModelElement(QuUK::Element* e) { mModelElement = e; }

    Style* localStyle() const { return mLocalStyle; }
    void setLocalStyle(Style* s) { mLocalStyle = s; }

    Style* sharedStyle() const;

    Diagram* diagram() const;

    DiagramElement* owningElement() const { return mOwningElement; }
    virtual void setOwningElement(DiagramElement* e) { mOwningElement = e; }

    QString uniqueId() const;
    void setUniqueId(const QString& s);
    static DiagramElement* byId(const QString& s);

    virtual void writeXml(QXmlStreamWriter& writer) const = 0;

    QUML_CLONABLE_ABSTRACT(DiagramElement);
private:
    QuUK::Element* mModelElement;
    Style* mLocalStyle;
    DiagramElement* mOwningElement;
    QuLC::UniqueId mUniqueId;
    static QHash<QString, DiagramElement*> mElementsById;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_DIAGRAMELEMENT_H_ */

