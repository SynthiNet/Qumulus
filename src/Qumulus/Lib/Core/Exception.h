/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
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

    virtual ~Exception() noexcept {
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
QUML_CREATE_EXCEPTION(ParseException);

QUML_END_NAMESPACE_LC

#endif /* QUMULUS_LIB_CORE_EXCEPTION_H_ */

