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

