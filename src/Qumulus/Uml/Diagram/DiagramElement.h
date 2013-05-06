/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_DIAGRAMELEMENT_H_
#define UML_DIAGRAM_DIAGRAMELEMENT_H_

#include "internal_base.h"

#include <QtWidgets/QGraphicsItemGroup>
#include <Lib/Core/Clonable.h>

#include <Uml/Kernel/internal_base.h>

QUML_BEGIN_NAMESPACE_UK
class Element;
QUML_END_NAMESPACE_UK

QUML_BEGIN_NAMESPACE_UD

class Style;

class DiagramElement : public QGraphicsItemGroup {
public:
    DiagramElement(QuUK::Element* m, DiagramElement* p = 0);

    QuUK::Element* modelElement() { return mModelElement; }

    Style* localStyle() const { return mStyle; }
    void setLocalStyle(Style* s) { mStyle = s; }

    Style* sharedStyle() const;

    DiagramElement* owningElement() const;

    QUML_CLONABLE_ABSTRACT(DiagramElement);
private:
    QuUK::Element* mModelElement;
    Style* mLocalStyle;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_DIAGRAMELEMENT_H_ */

