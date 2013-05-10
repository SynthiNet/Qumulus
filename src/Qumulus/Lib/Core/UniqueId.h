/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef LIB_CORE_UNIQUEID_H_
#define LIB_CORE_UNIQUEID_H_

#include "internal_base.h"

#include <QtCore/QString>
#include <QtCore/QHash>

QUML_BEGIN_NAMESPACE_LC

class UniqueId {
public:
    /**
     * Creates a new unique id.
     */
    UniqueId();

    /**
     * UniqueIds need to be unique, so copying one will generate a new ID.
     */
    UniqueId(const UniqueId&);

    /**
     * Moves the UniqueId. Does not generate a new ID.
     */
    UniqueId(UniqueId&&);

    /**
     * Creates a UniqueId from a given String.
     */
    explicit UniqueId(const QString&);

    UniqueId& operator=(const UniqueId&);
    UniqueId& operator=(UniqueId&&);
    UniqueId& operator=(const QString&);

    bool operator==(const UniqueId&) const;
    bool operator==(const QString&) const;

    bool operator!=(const UniqueId& u) const { return !(*this == u); }
    bool operator!=(const QString& s) const { return !(*this == s); }

    /**
     * Returns a String representation of this UniqueId.
     *
     * @return String representing this UniqueId.
     */
    const QString& toString() const { return mValue; }
private:
    QString mValue;
};

inline bool operator==(const QString& s, const UniqueId& u) { return u == s; }
inline bool operator!=(const QString& s, const UniqueId& u) { return u != s; }

QUML_END_NAMESPACE_LC

uint qHash(const QuLC::UniqueId&);


#endif /* LIB_CORE_UNIQUEID_H_ */

