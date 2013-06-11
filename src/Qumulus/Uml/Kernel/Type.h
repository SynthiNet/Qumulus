/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_TYPE_H_
#define UML_KERNEL_TYPE_H_

#include "internal_base.h"

#include "PackageableElement.h"

QUML_BEGIN_NAMESPACE_UK

class Type : public PackageableElement {
public:
    Type();
    Type(QString name, Package* p = nullptr);
    ~Type();

    static const QList<Type*>& typeList() { return mTypeList; }

    QUML_CLONABLE_ABSTRACT(Type);
private:
    static QList<Type*> mTypeList;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_TYPE_H_ */

