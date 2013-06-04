/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_ENUMERATIONLITERAL_H_
#define UML_KERNEL_ENUMERATIONLITERAL_H_

#include "internal_base.h"

#include "NamedElement.h"

QUML_BEGIN_NAMESPACE_UK

class Enumeration;
struct EnumerationLiteralGraphics;

class EnumerationLiteral : public NamedElement {
public:
    EnumerationLiteral();
    EnumerationLiteral(QString name, Enumeration* o = nullptr);

    Element* parent() const override;

    Enumeration* enumeration() const { return mEnumeration; }
    void setEnumeration(Enumeration* e) { mEnumeration = e; }

    QString qualifiedName() const override;

    QString sidebarIcon() const override { return "literal"; }
    QString sidebarText() const override { return name(); }

    void writeXml(QXmlStreamWriter& writer) const override;

    QUML_CLONABLE(EnumerationLiteral);
private:
    Enumeration* mEnumeration;
    EnumerationLiteralGraphics* mGraphics = nullptr;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_ENUMERATIONLITERAL_H_ */

