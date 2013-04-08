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

#endif /* QUMULUS_LIB_CORE_PTR_H_ */

