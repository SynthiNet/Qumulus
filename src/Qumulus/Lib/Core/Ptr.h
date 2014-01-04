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

