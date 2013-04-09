/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef QUMULUS_LIB_CORE_OPTIONAL_H_
#define QUMULUS_LIB_CORE_OPTIONAL_H_

#include "internal_base.h"

#include "Exception.h"

#include <cstddef>
#include <utility>

QUML_BEGIN_NAMESPACE_LC

template<class T>
class AlignedStorage {
public:
    const void* operator&() const { return &data; }
    void* operator&() { return &data; }
private:
    unsigned char data[sizeof(T)] alignas(alignof(T));
};

template<class T>
class Optional {
public:
    Optional() noexcept : 
        mInitialized(false) {}
    Optional(std::nullptr_t) noexcept :
        mInitialized(false) {}

    Optional(const T& t) : mInitialized(true) {
        new(&mStorage) T(t);
    }

    Optional(T&& t) : mInitialized(true) {
        new(&mStorage) T(t);
    }

    template<class... A>
    explicit Optional(A&&... a) : mInitialized(true) {
        new(&mStorage) T(std::forward<A>(a)...);
    }

    Optional(const Optional<T>& o) : mInitialized(o.mInitialized) {
        if(mInitialized)
            new(&mStorage) T(*o);
    }

    ~Optional() {
        if(mInitialized)
            static_cast<T*>(&mStorage)->~T();
    }

    T& operator*() throw(NullException) {
        if(!mInitialized) throw NullException();
        return *static_cast<T*>(&mStorage);
    }

    const T& operator*() const throw(NullException) {
        if(!mInitialized) throw NullException();
        return *static_cast<T*>(&mStorage);
    }

    T& operator->() throw(NullException) { return **this; }
    const T& operator->() const throw(NullException) { return **this; }

    Optional<T>& operator=(const Optional<T>& other) {
        if(!mInitialized) {
            if(other.mInitialized) {
                new(&mStorage) T(*other);
            }
        } else {
            if(other.mInitialized) {
                **this = *other;
            } else {
                static_cast<T*>(&mStorage)->~T();
            }
        }
        
        mInitialized = other.mInitialized;

        return *this;
    }

    Optional<T>& operator=(const T& other) {
        if(!mInitialized) {
            new(&mStorage) T(other);
        } else {
            **this = other;
        }

        mInitialized = true;

        return *this;
    }

    Optional<T>& operator=(T&& other) {
        if(!mInitialized) {
            new(&mStorage) T(other);
        } else {
            **this = other;
        }

        mInitialized = true;

        return *this;
    }

    Optional<T>& operator=(std::nullptr_t) {
        if(mInitialized)
            static_cast<T*>(&mStorage)->~T();

        mInitialized = false;
    }

    Optional<T>& operator==(const Optional<T>& o) const {
        return (!*this && !o) || **this == *o;
    }

    explicit operator bool() const {
        return mInitialized;
    }

private:
    bool mInitialized;
    AlignedStorage<T> mStorage;
};

template<class T>
bool operator==(const Optional<T>& o, const T& t) {
    return o && *o == t;
}

template<class T>
bool operator==(const T& t, const Optional<T>& o) {
    return o && t == *o;
}

template<class T>
bool operator!=(const Optional<T>& t1, const Optional<T>& t2) { 
    return !(t1 == t2);
}

template<class T>
bool operator!=(const T& t1, const Optional<T>& t2) { 
    return !(t1 == t2);
}

template<class T>
bool operator!=(const Optional<T>& t1, const T& t2) { 
    return !(t1 == t2);
}

template<class T>
bool operator!=(const T& t1, const T& t2) { 
    return !(t1 == t2);
}
QUML_END_NAMESPACE_LC

#endif /* QUMULUS_LIB_CORE_OPTIONAL_H_ */

