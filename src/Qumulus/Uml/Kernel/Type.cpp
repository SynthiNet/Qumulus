/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Type.h"

QUML_BEGIN_NAMESPACE_UK

QList<Type*> Type::mTypeList;

Type::Type() {
    mTypeList.append(this);
}

Type::Type(QString name, Package* p) :
        PackageableElement(name, p) {
    mTypeList.append(this);
}

Type::~Type() {
    mTypeList.removeAll(this);
}

QUML_END_NAMESPACE_UK
