/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_ENUMERATIONLITERAL_H_
#define UML_CORE_CONSTRUCTS_ENUMERATIONLITERAL_H_

#include "internal_base.h"

#include <Uml/Core/Abstractions/NamedElement.h>

QUML_BEGIN_NAMESPACE_UCC

class Enumeration;

class EnumerationLiteral : public QuUCA::NamedElement {
public:
    EnumerationLiteral(Enumeration* o = nullptr);

    Enumeration* enumeration() const { return mEnumeration; }
    void setEnumeration(Enumeration* e) { mEnumeration = e; }

    QUML_CLONABLE(EnumerationLiteral);
private:
    Enumeration* mEnumeration;
};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_ENUMERATIONLITERAL_H_ */

