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

class Enumeration : public DataType {
    Q_OBJECT
public:
    Enumeration();
    Enumeration(QString name, Package* p = 0);
    ~Enumeration();

    const QList<EnumerationLiteral*>& literals() const { 
        return mOwnedLiterals;
    }

    /**
     * @note This function takes ownership
     */
    void addLiteral(EnumerationLiteral* l);
    void removeLiteral(EnumerationLiteral* l);
    
    QString sidebarIcon() const override { return "enumeration"; }
    
    void writeXml(QXmlStreamWriter& writer) const override;

    QUML_CLONABLE(Enumeration);
private:
    QList<EnumerationLiteral*> mOwnedLiterals;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_ENUMERATION_H_ */

