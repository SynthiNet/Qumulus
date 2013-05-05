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

class Feature : public RedefinableElement {
public:
    Feature(Classifier* c = 0);

    bool isStatic() const { return mStatic; }
    void setStatic(bool s) { mStatic = s; }

    Classifier* featuringClassifier() const { return mFeaturingClassifier; }
    void setFeaturingClassifier(Classifier* c) { mFeaturingClassifier = c; }

    QUML_CLONABLE_ABSTRACT(Feature);
private:
    Classifier* mFeaturingClassifier;
    bool mStatic;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_FEATURE_H_ */

