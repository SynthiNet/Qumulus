/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_CONSTRUCTS_OPERATION_H_
#define UML_CORE_CONSTRUCTS_OPERATION_H_

#include "internal_base.h"

#include "BehavioralFeature.h"

QUML_BEGIN_NAMESPACE_UCC

class Class;
class Parameter;

class Operation : public BehavioralFeature {
public:
    Operation(Class* c = 0);

    // Parameter* returnResult() const;

    // bool isQuery() const { return mQuery; }
    // void setQuery(bool b) { mQuery = b; }

    Class* getClass() const { return mClass; }
    void setClass(Class* c) { mClass = c; }

    QUML_CLONABLE(Operation);
private:
    Class* mClass;
    // std::unordered_set<Operation*> mRedefinedOperations;
    // bool mQuery;

};

QUML_END_NAMESPACE_UCC

#endif /* UML_CORE_CONSTRUCTS_OPERATION_H_ */

