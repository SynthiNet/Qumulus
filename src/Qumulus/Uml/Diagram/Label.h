/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_LABEL_H_
#define UML_DIAGRAM_LABEL_H_

#include "internal_base.h"

#include "Shape.h"

QUML_BEGIN_NAMESPACE_UD

class Label : public Shape {
public:
    Label(QuUK::Element* e = 0, DiagramElement* p = 0);
    Label(const QString& t, QuUK::Element* e = 0, DiagramElement* p = 0);
    Label(const Label&);

    const QString& text() const { return mText; }
    void setText(const QString& s) { mText = s; }

    QUML_CLONABLE(Label);
private:
    QString mText;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_LABEL_H_ */

