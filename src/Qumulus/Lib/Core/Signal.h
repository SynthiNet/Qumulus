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

#ifndef LIB_CORE_SIGNAL_H_
#define LIB_CORE_SIGNAL_H_

#include "internal_base.h"

#include <QtCore/QList>
#include <functional>

QUML_BEGIN_NAMESPACE_LC

template<class... A>
class Signal;

template<class... A>
class Signal<void(A...)> {
public:
    void operator()(A&&... a) const {
        for(auto& x : mSlots) {
            x(std::forward<A>(a)...);
        }
    }

    Signal<void(A...)>& operator+=(std::function<void(A...)> f) {
        mSlots.append(f);
        return *this;
    }
private:
    QList<std::function<void(A...)>> mSlots;
};

QUML_END_NAMESPACE_LC

#endif /* LIB_CORE_SIGNAL_H_ */

