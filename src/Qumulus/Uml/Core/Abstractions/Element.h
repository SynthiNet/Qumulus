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

#include <set>

QUML_BEGIN_NAMESPACE_UCA

class Element : public QuLC::Clonable {
public:
    Element(const Element& other);
    
    virtual bool mustBeOwned() const {
        return true;
    }

    const std::set<uptr<Element>>& ownedElements() const {
        return mOwnedElements;
    }

    QUML_CLONABLE(Element)
private:
    std::set<uptr<Element>> mOwnedElements;
};

QUML_END_NAMESPACE_UCA

#endif /* QUMULUS_UML_CORE_ABSTRACTIONS_ELEMENT_H_ */

