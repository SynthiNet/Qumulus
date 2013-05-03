/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_CLASSIFIER_H_
#define UML_CORE_CONSTRUCTS_CLASSIFIER_H_

#include "internal_base.h"

#include <Lib/Core/Nyi.h>
#include <Uml/Core/Abstractions/Namespace.h>
#include "Type.h"

#include <list>

QUML_BEGIN_NAMESPACE_UCC

class Property;

class Classifier : public Type, public QuUCA::Namespace {
public:

    // void allFeatures() const { NYI(); }
    // void parents() const { NYI(); }
    // void allParents() const { NYI(); }
    // bool conformsTo(Classifier* other) const { NYI(); return false; }
    // bool hasVisibilityOf(QuUCA::NamedElement* m) const { NYI(); return false; }
    // void inherit() { NYI(); }
    // bool maySpecializeType(Classifier* c) const { NYI(); return false; }

    // bool abstract() const { return mAbstract; }
    // void setAbstract(bool a) { mAbstract = a; }

    // bool final() const { return mFinal; }
    // void setFinal(bool f) { mFinal = f; }

    const std::list<Property*>& attributes() const {
        return mAttributes;
    }

    QUML_CLONABLE_ABSTRACT(Classifier);

private:
    bool mAbstract;
    bool mFinal;
    std::list<Property*> mAttributes;

};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_CLASSIFIER_H_ */

