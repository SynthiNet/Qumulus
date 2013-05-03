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

class Comment;

class Element : public QuLC::Clonable {
public:
    Element() = default;

    Element(const Element& other);
    Element(Element&& other);
    
    virtual bool mustBeOwned() const {
        return true;
    }

    const std::unordered_set<uptr<Element>>& ownedElements() const {
        return mOwnedElements;
    }

    const std::unordered_set<Comment*>& ownedComments() const {
        return mOwnedComments;
    }

    QUML_CLONABLE(Element)
protected:
    void addElement(uptr<Element> other);
    void removeElement(const uptr<Element>& other);

    std::size_t numElements() const;
    void clearElements();

    bool contains(const uptr<Element>& other) const;
    bool containsRecursive(const uptr<Element>& other) const;
private:
    std::unordered_set<uptr<Element>> mOwnedElements;
    std::unordered_set<Comment*> mOwnedComments;
};

QUML_END_NAMESPACE_UCA

#endif /* QUMULUS_UML_CORE_ABSTRACTIONS_ELEMENT_H_ */

