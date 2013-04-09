/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_ABSTRACTIONS_NAMESPACE_H_
#define UML_CORE_ABSTRACTIONS_NAMESPACE_H_

#include "internal_base.h"

#include "NamedElement.h"

QUML_BEGIN_NAMESPACE_UCA

class Namespace : public NamedElement {
public:

    QUML_CLONABLE(Namespace)
private:
};

QUML_END_NAMESPACE_UCA

#endif /* UML_CORE_ABSTRACTIONS_NAMESPACE_H_ */

