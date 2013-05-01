/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_PRIMITIVETYPE_H_
#define UML_CORE_CONSTRUCTS_PRIMITIVETYPE_H_

#include "internal_base.h"

#include "DataType.h"

QUML_BEGIN_NAMESPACE_UCC

class PrimtiveType : public DataType {
public:
    QUML_CLONABLE(PrimtiveType);
};

QUML_END_NAMESPACE_UCC


#endif /* UML_CORE_CONSTRUCTS_PRIMITIVETYPE_H_ */

