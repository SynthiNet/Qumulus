/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_NAMESPACE_H_
#define UML_KERNEL_NAMESPACE_H_

#include "internal_base.h"

#include "NamedElement.h"

#include <unordered_map>

QUML_BEGIN_NAMESPACE_UK

class Namespace : public virtual NamedElement {
public:
    Namespace() = default;
    Namespace(const Namespace& n);

    const std::unordered_map<QString, NamedElement*>& 
            ownedMembers() const {
        return mOwnedMembers;
    }

    void addMember(uptr<NamedElement> e);


    QUML_CLONABLE(Namespace)
private:
    std::unordered_map<QString, NamedElement*> mOwnedMembers;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_NAMESPACE_H_ */

