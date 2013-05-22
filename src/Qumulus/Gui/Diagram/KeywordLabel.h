/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_KEYWORDLABEL_H_
#define UML_DIAGRAM_KEYWORDLABEL_H_

#include "internal_base.h"

#include "Label.h"

QUML_BEGIN_NAMESPACE_GD

class KeywordLabel : public Label {
public:
    KeywordLabel(QuUK::Element* e = 0, DiagramElement* p = 0);
    KeywordLabel(const QString& t, QuUK::Element* e = 0, DiagramElement* p = 0);
    KeywordLabel(const KeywordLabel&);

    void setText(const QString& s) override;

    void resize(double, double) override;

    QUML_CLONABLE(KeywordLabel);
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_KEYWORDLABEL_H_ */

