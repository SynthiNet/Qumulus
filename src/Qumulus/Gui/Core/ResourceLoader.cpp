/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "ResourceLoader.h"
#include <QtCore/QCoreApplication>

QUML_BEGIN_NAMESPACE_GC

QString getResource(const QString& s) {
#ifdef Q_OS_WIN32
    return QCoreApplication::applicationDirPath() + "/resources/" + s;
#elif defined(Q_OS_MAC)
    return QCoreApplication::applicationDirPath() + "../Resources/" + s;
#else
    return QCoreApplication::applicationDirPath() + "../share/" + s;
#endif
}

QUML_END_NAMESPACE_GC

