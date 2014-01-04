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

#ifndef LIB_CORE_UNLIMITED_H_
#define LIB_CORE_UNLIMITED_H_

#include "internal_base.h"

#include "Exception.h"

#include <climits>

#include <QtCore/QString>

QUML_BEGIN_NAMESPACE_LC

class Unlimited {
    friend bool unltd(const Unlimited&);
public:
    Unlimited() : mValue(0), mUnlimited(false) {}
    Unlimited(unsigned value) : mValue(value), mUnlimited(false) {}

    Unlimited(const char c[2]) : Unlimited() {
        if(c[0] == '*' && c[1] == '\0') {
            mUnlimited = true;
        } else {
            throw ArgumentException("Unlimited requires '*' as argument.");
        }
    }

    explicit Unlimited(const QString& s) : Unlimited() {
        if(s == "*") {
            mUnlimited = true;
        } else {
            bool ok = false;
            mValue = s.toUInt(&ok);
            if(!ok)
                throw ArgumentException(qPrintable("Invalid numeral: "+s));
        }
    }

    operator unsigned() const {
        if(mUnlimited)
            return UINT_MAX;
        return mUnlimited? UINT_MAX : mValue;
    }

    explicit operator QString() const {
        return mUnlimited ? "*" : QString::number(mValue);
    }

private:
    unsigned mValue;
    bool mUnlimited;
};

inline bool unltd(const Unlimited& u) {
    return u.mUnlimited;
}

QUML_END_NAMESPACE_LC

#endif /* LIB_CORE_UNLIMITED_H_ */

