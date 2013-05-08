/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_PRIMITIVETYPE_H_
#define UML_KERNEL_PRIMITIVETYPE_H_

#include "internal_base.h"

#include "DataType.h"

QUML_BEGIN_NAMESPACE_UK

class PrimitiveType : public DataType {
public:
    void updateDiagramElement() override;

    QUML_CLONABLE(PrimitiveType);
};

QUML_END_NAMESPACE_UK


#endif /* UML_KERNEL_PRIMITIVETYPE_H_ */

