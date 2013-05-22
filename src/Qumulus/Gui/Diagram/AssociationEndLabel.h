/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_ASSOCIATIONENDLABEL_H_
#define UML_DIAGRAM_ASSOCIATIONENDLABEL_H_

#include "internal_base.h"

#include "Label.h"

QUML_BEGIN_NAMESPACE_GD

class AssociationEndLabel : public Label {
public:
    AssociationEndLabel(QuUK::Element* e = 0, DiagramElement* p = 0);
    AssociationEndLabel(const QString& t, QuUK::Element* e = 0, 
            DiagramElement* p = 0);
    AssociationEndLabel(const AssociationEndLabel&);

    QUML_CLONABLE(AssociationEndLabel);
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_ASSOCIATIONENDLABEL_H_ */

