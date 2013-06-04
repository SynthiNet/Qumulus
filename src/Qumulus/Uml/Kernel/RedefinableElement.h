/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_REDEFINABLEELEMENT_H_
#define UML_KERNEL_REDEFINABLEELEMENT_H_

#include "internal_base.h"

#include "NamedElement.h"

#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UK

class Classifier;

class RedefinableElement : public virtual NamedElement {
    Q_OBJECT
public:
    RedefinableElement();

    bool leaf() const { return mLeaf; }
    void setLeaf(bool l) { mLeaf = l; }

    QUML_CLONABLE_ABSTRACT(RedefinableElement);
private:
    bool mLeaf;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_REDEFINABLEELEMENT_H_ */

