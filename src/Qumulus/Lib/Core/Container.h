/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef LIB_CORE_CONTAINER_H_
#define LIB_CORE_CONTAINER_H_

#include <unordered_set>
#include <unordered_map>
#include <list>

template<class T>
using uset = std::unordered_set<T>;

template<class T, class U>
using umap = std::unordered_map<T,U>;

using std::list;

#endif /* LIB_CORE_CONTAINER_H_ */

