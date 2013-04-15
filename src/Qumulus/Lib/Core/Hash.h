/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef LIB_CORE_HASH_H_
#define LIB_CORE_HASH_H_

#include "internal_base.h"

#include <QtCore/QString>
#include <QtCore/QHash>

#include <functional>

namespace std {
    template<>
    struct hash<QString> {
        size_t operator()(const QString& s) const noexcept {
            return qHash(s);
        }
    };
}

#endif /* LIB_CORE_HASH_H_ */

