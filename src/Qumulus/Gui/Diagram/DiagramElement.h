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

#include <Uml/Kernel/internal_base.h>

QUML_BEGIN_NAMESPACE_UK
class Element;
QUML_END_NAMESPACE_UK

QUML_BEGIN_NAMESPACE_GD

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

    DiagramElement* owningElement() const { return mOwningElement; }
    virtual void setOwningElement(DiagramElement* e) { mOwningElement = e; }

    QUML_CLONABLE_ABSTRACT(DiagramElement);
private:
    QuUK::Element* mModelElement;
    Style* mLocalStyle;
    DiagramElement* mOwningElement;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_DIAGRAMELEMENT_H_ */

