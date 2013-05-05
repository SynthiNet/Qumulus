/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_FEATURE_H_
#define UML_KERNEL_FEATURE_H_

#include "internal_base.h"

#include "RedefinableElement.h"

#include "NamedElement.h"


QUML_BEGIN_NAMESPACE_UK

class Classifier;

class Feature : 
        public virtual NamedElement,
        public RedefinableElement {
public:
private:
    QSet<Classifier*> mFeaturingClassifiers;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_FEATURE_H_ */

