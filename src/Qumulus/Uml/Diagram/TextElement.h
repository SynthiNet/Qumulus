/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_TEXTELEMENT_H_
#define UML_DIAGRAM_TEXTELEMENT_H_

#include "internal_base.h"

#include "LeafElement.h"

QUML_BEGIN_NAMESPACE_UD

class TextElement : public LeafElement {
public:
    const QString& text() const { return mText; }
    void setText(const QString& s) { mText = s; }
private:
    QString mText;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_TEXTELEMENT_H_ */

