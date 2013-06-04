/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_DIRECTEDRELATIONSHIP_H_
#define UML_KERNEL_DIRECTEDRELATIONSHIP_H_

#include "internal_base.h"

#include "Element.h"

QUML_BEGIN_NAMESPACE_UK

class DirectedRelationship : public Element {
public:
    DirectedRelationship() = default;
    DirectedRelationship(Element* source, Element* target) : 
            mSource(source),
            mTarget(target) {

    }

    QString sidebarIcon() const override { return ""; }
    QString sidebarText() const override { return ""; }

    Element* source() const { return mSource; }
    void setSource(Element* s) { mSource = s; }

    Element* target() const { return mTarget; }
    void setTarget(Element* s) { mTarget = s; }

    QUML_CLONABLE_ABSTRACT(DirectedRelationship);
private:
    Element* mSource = nullptr;
    Element* mTarget = nullptr;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_DIRECTEDRELATIONSHIP_H_ */

