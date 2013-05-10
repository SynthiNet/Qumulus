/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "UniqueId.h"

#include <cstdlib>

QUML_BEGIN_NAMESPACE_LC

static constexpr char kMapping[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', 
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 
        'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
        'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 
        'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 
        'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
        'U', 'V', 'W', 'X', 'Y', 'Z'
    };

static QString genUniqueId() {
    QString toReturn;
    for(size_t i = 0; i < 8; ++i) {
        toReturn += kMapping[std::rand() % 62];
    }

    return toReturn;
}

UniqueId::UniqueId() : mValue(genUniqueId()) {

}

UniqueId::UniqueId(const UniqueId&) : mValue(genUniqueId()) {

}

UniqueId::UniqueId(UniqueId&& u) : mValue(u.mValue) {

}

UniqueId::UniqueId(const QString& s) : mValue(s) {

}

UniqueId& UniqueId::operator=(const UniqueId&) {
    mValue = genUniqueId();
    return *this;
}

UniqueId& UniqueId::operator=(UniqueId&& u) {
    mValue = u.mValue;
    return *this;
}

UniqueId& UniqueId::operator=(const QString& s) {
    mValue = s;
    return *this;
}

bool UniqueId::operator==(const UniqueId& u) const {
    return u.mValue == mValue;
}

bool UniqueId::operator==(const QString& s) const {
    return mValue == s;
}
QUML_END_NAMESPACE_LC

uint qHash(const QuLC::UniqueId& u) {
    return qHash(u.toString());
}
