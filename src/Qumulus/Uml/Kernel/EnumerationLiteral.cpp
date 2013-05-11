/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "EnumerationLiteral.h"

#include "Enumeration.h"

#include <Uml/Diagram/Label.h>

QUML_BEGIN_NAMESPACE_UK

EnumerationLiteral::EnumerationLiteral() {}
EnumerationLiteral::EnumerationLiteral(QString name, Enumeration* o) :
        NamedElement(name),
        mEnumeration(o) {
    if(o) o->addLiteral(this);
}

void EnumerationLiteral::updateDiagramElement(QuUD::Diagram*) {
    if(!mDiagramElement) {
        mDiagramElement = new QuUD::Label(*name(), this, 
                mEnumeration->diagramElement());
    }
    
    auto d = static_cast<QuUD::Label*>(mDiagramElement);

    d->setText(*name());
    d->setHtml("• "+*name());

    d->resize(static_cast<QuUD::Shape*>(
                mEnumeration->diagramElement())->width(), 0);
}

QUML_END_NAMESPACE_UK
