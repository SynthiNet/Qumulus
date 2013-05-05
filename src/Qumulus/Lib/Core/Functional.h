/*
 * Qumulus UML editor
 * Author: Frank Erens
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
QList<T> dynmapto(const QList<U>& l) {
    QList<U> toReturn;
    for(const U& u : l) {
        if(T t = dynamic_cast<T>(u))
            toReturn.append(t);
    } 

    return toReturn;
}

template<class T, class U>
QSet<T> dynmapto(const QSet<U>& l) {
    QSet<U> toReturn;
    for(const U& u : l) {
        if(T t = dynamic_cast<T>(u))
            toReturn.insert(t);
    } 

    return toReturn;
}

template<class T>
QList<T> filter(const QList<T>& l, std::function<bool(const T&)> f) {
    QList<U> toReturn;
    for(const T& t : l) {
        if(f(t)) toReturn.append(t);
    } 

    return toReturn;
}

template<class T>
QSet<T> filter(const QSet<T>& l, std::function<bool(const T&)> f) {
    QSet<U> toReturn;
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

