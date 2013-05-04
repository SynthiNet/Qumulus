/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef LIB_CORE_CONTAINER_H_
#define LIB_CORE_CONTAINER_H_

#include "internal_base.h"

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

template<class T>
using uset = std::unordered_set<T>;

template<class T, class U>
using umap = std::unordered_map<T,U>;

QUML_BEGIN_NAMESPACE_LC

template<class T>
void add(std::vector<T>& v, T&& t) {
    v.push_back(std::forward<T>(t));
}

template<class T>
void add(std::unordered_set<T>& s, T&& t) {
    s.insert(std::forward<T>(t));
}

template<class T>
void remove(std::vector<T>& v, const T& t) {
    auto it = std::find(v.begin(), v.end(), t);
    v.erase(it); 
}

template<class T>
void remove(std::unordered_set<T>& v, const T& t) {
    v.erase(t);
}

QUML_END_NAMESPACE_UK

#endif /* LIB_CORE_CONTAINER_H_ */

