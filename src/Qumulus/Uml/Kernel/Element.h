/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef QUMULUS_UML_KERNEL_ELEMENT_H_
#define QUMULUS_UML_KERNEL_ELEMENT_H_

#include "internal_base.h"

#include <Lib/Core/Clonable.h>
#include <Lib/Core/Nyi.h>
#include <Lib/Core/Functional.h>
#include <Lib/Core/UniqueId.h>

#include <QtCore/QSet>
#include <QtCore/QList>
#include <QtCore/QString>

QUML_BEGIN_NAMESPACE_UK

class Comment;

class Element : public QuLC::Clonable {
public:
    Element();
    Element(const Element& other);

    virtual ~Element();
    
    virtual bool isTopLevel() const { return false; };
    virtual QString sidebarIcon() const = 0;
    virtual QString sidebarText() const = 0;

    QString uniqueId() const;
    void setUniqueId(const QString& s);
    static Element* byId(const QString& s);

    QUML_CLONABLE_ABSTRACT(Element)
private:
    static QHash<QString, Element*> mElementsById;
    QuLC::UniqueId mUniqueId;
};

QUML_END_NAMESPACE_UK

#endif /* QUMULUS_UML_KERNEL_ELEMENT_H_ */

