/*
 * Qumulus UML editor
 * Author: Frank Erens
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

