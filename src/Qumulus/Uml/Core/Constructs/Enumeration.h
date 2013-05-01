/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_ENUMERATION_H_
#define UML_CORE_CONSTRUCTS_ENUMERATION_H_

#include "internal_base.h"

#include "DataType.h"
#include "EnumerationLiteral.h"

QUML_BEGIN_NAMESPACE_UCC

class Enumeration : public DataType {
public:

    const std::list<EnumerationLiteral*>& ownedLiterals() const { 
        return mOwnedLiterals;
    }

    QUML_CLONABLE(Enumeration);
private:
    std::list<EnumerationLiteral*> mOwnedLiterals;
};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_ENUMERATION_H_ */

