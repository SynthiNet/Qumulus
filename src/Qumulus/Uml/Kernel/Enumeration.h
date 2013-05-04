/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_ENUMERATION_H_
#define UML_KERNEL_ENUMERATION_H_

#include "internal_base.h"

#include "DataType.h"
#include "EnumerationLiteral.h"

QUML_BEGIN_NAMESPACE_UK

class Enumeration : public DataType {
public:

    const std::list<EnumerationLiteral*>& ownedLiterals() const { 
        return mOwnedLiterals;
    }

    QUML_CLONABLE(Enumeration);
private:
    std::list<EnumerationLiteral*> mOwnedLiterals;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_ENUMERATION_H_ */

