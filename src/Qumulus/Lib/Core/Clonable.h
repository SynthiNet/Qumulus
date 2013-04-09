/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef QUMULUS_LIB_CORE_CLONABLE_H_
#define QUMULUS_LIB_CORE_CLONABLE_H_

#include "internal_base.h"

QUML_BEGIN_NAMESPACE_LC

class Clonable {
public:
    Clonable() {}
    virtual ~Clonable() {}

    virtual Clonable* clone() const = 0;
};

#define QUML_CLONABLE(Class) \
    virtual Class* clone() const override { \
        return new Class(*this); \
    }

QUML_END_NAMESPACE_LC

#endif /* QUMULUS_LIB_CORE_CLONABLE_H_ */

