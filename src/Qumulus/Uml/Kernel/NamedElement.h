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

class Namespace;

class NamedElement : public virtual Element {
public:
    NamedElement() = default;

    QString separator() const {
        // TODO: do not assume C++.
        return "::";
    }

    QString qualifiedName() const;

    bool isDistinguishableFrom(const uptr<NamedElement>& n, 
            const Namespace* ns) const;

    const Namespace* nameSpace() const { return mNameSpace; }
    void setNameSpace(Namespace* n) { mNameSpace = n; }

    const QuLC::Optional<QString>& name() const { return mName; }
    void setName(const QuLC::Optional<QString>& n) { mName = n; }

    QuLC::Optional<VisibilityKind> visibility() const { return mVisibility; }
    void setVisiblity(QuLC::Optional<VisibilityKind> v) { mVisibility = v; }

    QUML_CLONABLE(NamedElement)
private:
    QuLC::Optional<QString> mName;
    QuLC::Optional<VisibilityKind> mVisibility;
    Namespace* mNameSpace;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_NAMEDELEMENT_H_ */

