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

#ifndef LIB_CORE_FUNCTIONAL_H_
#define LIB_CORE_FUNCTIONAL_H_

#include "internal_base.h"

#include <QtCore/QList>
#include <QtCore/QString>
#include <functional>

QUML_BEGIN_NAMESPACE_LC

template<class T, class U>
QList<U> map(const QList<T>& l, std::function<U(const T&)> f) {
    QList<U> toReturn;
    for(const T& t : l) {
        toReturn.append(f(t));
    }

    return toReturn;
}

template<class T, class U>
QSet<U> map(const QSet<T>& l, std::function<U(const T&)> f) {
    QSet<U> toReturn;
    for(const T& t : l) {
        toReturn.insert(f(t));
    }

    return toReturn;
}

template<class T, class U>
QList<T> mapto(const QList<U>& l) {
    QList<T> toReturn;
    for(const U& u : l) {
        if(T t = static_cast<T>(u))
            toReturn.append(t);
    }

    return toReturn;
}

template<class T, class U>
QSet<T> mapto(const QSet<U>& l) {
    QSet<T> toReturn;
    for(const U& u : l) {
        if(T t = static_cast<T>(u))
            toReturn.insert(t);
    }

    return toReturn;
}

template<class T, class U>
QList<T> dynmapto(const QList<U>& l) {
    QList<T> toReturn;
    for(const U& u : l) {
        if(T t = dynamic_cast<T>(u))
            toReturn.append(t);
    }

    return toReturn;
}

template<class T, class U>
QSet<T> dynmapto(const QSet<U>& l) {
    QSet<T> toReturn;
    for(const U& u : l) {
        if(T t = dynamic_cast<T>(u))
            toReturn.insert(t);
    }

    return toReturn;
}

template<class T>
QList<T> filter(const QList<T>& l, std::function<bool(const T&)> f) {
    QList<T> toReturn;
    for(const T& t : l) {
        if(f(t)) toReturn.append(t);
    }

    return toReturn;
}

template<class T>
QSet<T> filter(const QSet<T>& l, std::function<bool(const T&)> f) {
    QSet<T> toReturn;
    for(const T& t : l) {
        if(f(t)) toReturn.insert(t);
    }

    return toReturn;
}

template<class T>
bool forall(const QList<T>& l, std::function<bool(const T&)> f) {
    for(const T& t : l) {
        if(!f(t)) return false;
    }

    return true;
}

template<class T>
bool forall(const QSet<T>& l, std::function<bool(const T&)> f) {
    for(const T& t : l) {
        if(!f(t)) return false;
    }

    return true;
}

template<class T>
bool forany(const QList<T>& l, std::function<bool(const T&)> f) {
    for(const T& t : l) {
        if(f(t)) return true;
    }

    return false;
}

template<class T>
bool forany(const QSet<T>& l, std::function<bool(const T&)> f) {
    for(const T& t : l) {
        if(f(t)) return true;
    }

    return false;
}

QUML_END_NAMESPACE_LC

#endif /* LIB_CORE_FUNCTIONAL_H_ */

