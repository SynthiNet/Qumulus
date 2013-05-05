/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_NAMESPACE_H_
#define UML_KERNEL_NAMESPACE_H_

#include "internal_base.h"

#include "NamedElement.h"


QUML_BEGIN_NAMESPACE_UK

class Namespace : public virtual NamedElement {
public:
    Namespace() = default;
    Namespace(const Namespace& n);

    const QSet<NamedElement*>& ownedMembers() const {
        return mOwnedMembers;
    }

    void addOwnedMember(NamedElement* e);
    void removeOwnedMember(NamedElement* e);

    QUML_CLONABLE_ABSTRACT(Namespace)
private:
    QSet<NamedElement*> mOwnedMembers;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_NAMESPACE_H_ */

