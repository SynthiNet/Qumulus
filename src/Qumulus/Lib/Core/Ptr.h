/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef QUMULUS_LIB_CORE_PTR_H_
#define QUMULUS_LIB_CORE_PTR_H_

#include "internal_base.h"

#include <memory>

template<class T>
using uptr = std::unique_ptr<T>;

template<class T>
using sptr = std::shared_ptr<T>;

template<class T>
using wptr = std::weak_ptr<T>;

template<class T, class... A>
uptr<T> make_unique(A&&... a) {
    return uptr<T>(new T(std::forward(a)...));
}

template<class T, class... A>
sptr<T> make_shared(A&&... a) {
    return sptr<T>(new T(std::forward(a)...));
}

#endif /* QUMULUS_LIB_CORE_PTR_H_ */

