/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef QUMULUS_UML_CORE_ABSTRACTIONS_ELEMENT_H_
#define QUMULUS_UML_CORE_ABSTRACTIONS_ELEMENT_H_

#include "internal_base.h"

#include <Lib/Core/Clonable.h>
#include <Lib/Core/Ptr.h>
#include <Lib/Core/Hash.h>

#include <unordered_set>

QUML_BEGIN_NAMESPACE_UCA

class Element : public QuLC::Clonable {
public:
    Element(const Element& other);
    Element(Element&& other);
    
    virtual bool mustBeOwned() const {
        return true;
    }

    const std::unordered_set<uptr<Element>>& ownedElements() const {
        return mOwnedElements;
    }

    void addElement(uptr<Element> other);
    void removeElement(const uptr<Element>& other);

    std::size_t size() const;
    void clear();

    bool contains(const uptr<Element>& other) const;
    bool containsRecursive(const uptr<Element>& other) const;

    QUML_CLONABLE(Element)
private:
    std::unordered_set<uptr<Element>> mOwnedElements;
};

QUML_END_NAMESPACE_UCA

#endif /* QUMULUS_UML_CORE_ABSTRACTIONS_ELEMENT_H_ */

