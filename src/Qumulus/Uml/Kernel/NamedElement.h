/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_NAMEDELEMENT_H_
#define UML_KERNEL_NAMEDELEMENT_H_

#include "internal_base.h"

#include "Element.h"
#include "VisibilityKind.h"

#include <Lib/Core/Optional.h>

#include <QtCore/QString>

QUML_BEGIN_NAMESPACE_UK

class NamedElement : public virtual Element {
public:
    NamedElement();
    NamedElement(QString name);

    QString separator() const {
        // TODO: do not assume C++.
        return "::";
    }

    virtual QString qualifiedName() const = 0;

    // bool isDistinguishableFrom(NamedElement* n) const;

    const QString& name() const { return mName; }
    void setName(const QString& n) { mName = n; elementChanged(); }

    VisibilityKind visibility() const { return mVisibility; }
    // TODO: 2013-06-11 Frank Erens
    // This should be called setVisibility. Oops.
    void setVisiblity(VisibilityKind v) { mVisibility = v; elementChanged(); }

    QUML_CLONABLE_ABSTRACT(NamedElement)
private:
    QString mName;
    VisibilityKind mVisibility;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_NAMEDELEMENT_H_ */

