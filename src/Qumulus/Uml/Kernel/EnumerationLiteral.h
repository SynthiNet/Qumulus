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
    int index() const override;

    size_t size() const override { return 0; }
    Element* operator[](size_t) const override { return nullptr; }

    Enumeration* enumeration() const { return mEnumeration; }
    void setEnumeration(Enumeration* e) { mEnumeration = e; }

    QString qualifiedName() const override;

    QString sidebarIcon() const override { return "literal"; }
    QString sidebarText() const override { return name(); }

    void writeXml(QXmlStreamWriter& writer) const override;
    void readXml(QDomNode node, QuLC::XmlModelReader& reader) override;

    QUML_CLONABLE(EnumerationLiteral);
private:
    Enumeration* mEnumeration;
    EnumerationLiteralGraphics* mGraphics = nullptr;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_ENUMERATIONLITERAL_H_ */

