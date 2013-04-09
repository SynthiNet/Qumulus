/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef LIB_CORE_UNLIMITED_H_
#define LIB_CORE_UNLIMITED_H_

#include "internal_base.h"

#include "Exception.h"

#include <climits>

#include <QtCore/QString.h>

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
        return mUnlimited ? "*" : QString(mValue);
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

