/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#ifndef UML_KERNEL_PROPERTY_H_
#define UML_KERNEL_PROPERTY_H_

#include "internal_base.h"

#include <Lib/Core/Nyi.h>
// #include <Uml/Diagram/FeatureLabel.h>

#include "StructuralFeature.h"
#include "Type.h"
#include "AggregationKind.h"

QUML_BEGIN_NAMESPACE_UK

class Class;
class Association;

class Property : public StructuralFeature {
public:
    Property(QString name, Class* c = 0);

    Element* parent() const override;
    int index() const override;

    Class* getClass() const { return mClass; }
    void setClass(Class* c) { mClass = c; elementChanged(); }

    Association* association() const { return mAssociation; }
    void setAssociation(Association* a) { mAssociation = a; elementChanged(); }

    const QString& getDefault() const { return mDefault; }
    void setDefault(const QString& d) { mDefault = d; elementChanged(); }

    QString qualifiedName() const override;

    QString sidebarIcon() const override { return "property"; }
    QString sidebarText() const override { return toString(); }

    void writeXml(QXmlStreamWriter& writer) const override;

    QString toString() const;

    QUML_CLONABLE(Property);
private:
    Class* mClass;
    Association* mAssociation;
    QString mDefault;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_PROPERTY_H_ */

