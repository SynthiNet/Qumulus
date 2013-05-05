/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_ENUMERATIONLITERAL_H_
#define UML_KERNEL_ENUMERATIONLITERAL_H_

#include "internal_base.h"

#include "NamedElement.h"

QUML_BEGIN_NAMESPACE_UK

class Enumeration;

class EnumerationLiteral : public NamedElement {
public:
    EnumerationLiteral();
    EnumerationLiteral(QString name, Enumeration* o = nullptr);

    Enumeration* enumeration() const { return mEnumeration; }
    void setEnumeration(Enumeration* e) { mEnumeration = e; }

    QUML_CLONABLE(EnumerationLiteral);
private:
    Enumeration* mEnumeration;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_ENUMERATIONLITERAL_H_ */

