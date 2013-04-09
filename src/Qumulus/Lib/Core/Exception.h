/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef QUMULUS_LIB_CORE_EXCEPTION_H_
#define QUMULUS_LIB_CORE_EXCEPTION_H_

#include "internal_base.h"

#include <cstring>
#include <exception>

QUML_BEGIN_NAMESPACE_LC

class Exception : public std::exception {
public:
    Exception(const char* reason = "") noexcept {
        mReason = new char[std::strlen(reason) + 1];
        std::strcpy(mReason, reason);
    }

    virtual ~Exception() {
        delete mReason;
    }

    const char* what() const noexcept {
        return mReason;
    }

    virtual const char* name() const noexcept {
        return "Exception";
    }

private:
    char* mReason;
};

#define QUML_CREATE_EXCEPTION(Class) \
class Class : public ::QuLC::Exception { \
public: \
    Class(const char * r = "") noexcept : ::QuLC::Exception(r) { \
    } \
    virtual const char* name() const noexcept {\
        return #Class ; \
    }\
}

#define QUML_CREATE_EXCEPTION2(Class, Base) \
class Class : public Base { \
public: \
    Class(const char * r = "") noexcept : Base(r) { \
    } \
    virtual const char* name() const noexcept {\
        return #Class ; \
    }\
}

QUML_CREATE_EXCEPTION(ArgumentException);
QUML_CREATE_EXCEPTION(NullException);
QUML_CREATE_EXCEPTION(StateException);

QUML_END_NAMESPACE_LC

#endif /* QUMULUS_LIB_CORE_EXCEPTION_H_ */

