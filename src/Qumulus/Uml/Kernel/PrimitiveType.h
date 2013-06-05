/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_PRIMITIVETYPE_H_
#define UML_KERNEL_PRIMITIVETYPE_H_

#include "internal_base.h"

#include "DataType.h"

QUML_BEGIN_NAMESPACE_UK

class PrimitiveType : public DataType {
public:
    PrimitiveType();
    PrimitiveType(QString name, Package* p = 0) : DataType(name, p) {}

    size_t size() const override { return 0; }
    Element* operator[](size_t) const override { return nullptr; }

    QString sidebarIcon() const override { return "primitive"; }

    void writeXml(QXmlStreamWriter& writer) const override;

    QUML_CLONABLE(PrimitiveType);
private:
};

QUML_END_NAMESPACE_UK


#endif /* UML_KERNEL_PRIMITIVETYPE_H_ */

