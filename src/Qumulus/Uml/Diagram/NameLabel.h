/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_NAMELABEL_H_
#define UML_DIAGRAM_NAMELABEL_H_

#include "internal_base.h"

#include "Label.h"

QUML_BEGIN_NAMESPACE_UD

class NameLabel : public Label {
public:
    NameLabel(QuUK::Element* e = 0, DiagramElement* p = 0);
    NameLabel(const QString& t, QuUK::Element* e = 0, DiagramElement* p = 0);
    NameLabel(const NameLabel& l);

    void setText(const QString& s) override;

    QUML_CLONABLE(NameLabel);
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_NAMELABEL_H_ */

