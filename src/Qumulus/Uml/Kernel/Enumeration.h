/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_ENUMERATION_H_
#define UML_KERNEL_ENUMERATION_H_

#include "internal_base.h"

#include "DataType.h"
#include "EnumerationLiteral.h"

QUML_BEGIN_NAMESPACE_UK

struct EnumerationGraphics;

class Enumeration : public DataType {
    friend struct EnumerationGraphics;
public:
    Enumeration();
    Enumeration(QString name, Namespace* p = 0);
    ~Enumeration();

    const QList<EnumerationLiteral*>& ownedLiterals() const { 
        return mOwnedLiterals;
    }

    void addLiteral(EnumerationLiteral* l);
    void removeLiteral(EnumerationLiteral* l);

    void updateDiagramElement(QuUD::Diagram*) override;

    QUML_CLONABLE(Enumeration);
private:
    QList<EnumerationLiteral*> mOwnedLiterals;
    EnumerationGraphics* mGraphics;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_ENUMERATION_H_ */

