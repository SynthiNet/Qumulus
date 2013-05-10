/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_MULTIPLICITYLABEL_H_
#define UML_DIAGRAM_MULTIPLICITYLABEL_H_

#include "internal_base.h"

#include "Label.h"

QUML_BEGIN_NAMESPACE_UD

class MultiplicityLabel : public Label {
public:
    MultiplicityLabel(QuUK::Element* e = 0, DiagramElement* p = 0);
    MultiplicityLabel(const QString& t, QuUK::Element* e = 0, 
            DiagramElement* p = 0);
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_MULTIPLICITYLABEL_H_ */

