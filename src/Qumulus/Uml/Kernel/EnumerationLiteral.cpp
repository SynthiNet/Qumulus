/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "EnumerationLiteral.h"

#include "Enumeration.h"

QUML_BEGIN_NAMESPACE_UK

EnumerationLiteral::EnumerationLiteral() {}
EnumerationLiteral::EnumerationLiteral(QString name, Enumeration* o) :
        NamedElement(name),
        mEnumeration(o) {
    if(o) o->addLiteral(this);
}

QString EnumerationLiteral::qualifiedName() const {
    if(!mEnumeration) return "";
    QString s = mEnumeration->qualifiedName();
    return s == "" ? s : s + separator() + name(); 
}

QUML_END_NAMESPACE_UK
