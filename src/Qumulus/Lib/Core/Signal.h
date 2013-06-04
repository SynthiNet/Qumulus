/*
 * Qumulus UML editor
 * Author: Frank Erens
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

