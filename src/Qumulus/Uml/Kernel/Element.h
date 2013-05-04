/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef QUMULUS_UML_KERNEL_ELEMENT_H_
#define QUMULUS_UML_KERNEL_ELEMENT_H_

#include "internal_base.h"

#include <Lib/Core/Clonable.h>
#include <Lib/Core/Ptr.h>
#include <Lib/Core/Hash.h>
#include <Lib/Core/Container.h>
#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UK

class Comment;

class Element : public QuLC::Clonable {
public:
    Element() = default;

    Element(const Element& other);
    Element(Element&& other);
    
    virtual bool mustBeOwned() const {
        return true;
    }

    const uset<uptr<Element>>& ownedElements() const {
        return mOwnedElements;
    }

    const uset<Comment*>& ownedComments() const {
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
    uset<uptr<Element>> mOwnedElements;
    uset<Comment*> mOwnedComments;
};

QUML_END_NAMESPACE_UK

#endif /* QUMULUS_UML_KERNEL_ELEMENT_H_ */

