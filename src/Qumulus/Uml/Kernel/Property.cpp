/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "Property.h"

#include <Uml/Kernel/Class.h>
#include <Lib/Core/Nyi.h>

QUML_BEGIN_NAMESPACE_UK

Property::Property(QString name, Class* c) : 
        mAggregation(AggregationKind::None),
        mClass(c),
        mAssociation(0) {
    if(c) c->addAttribute(this);
    setName(name);
}

Property* Property::opposite() const {
    NYI();
    return nullptr;
}


Association* Property::owningAssociation() const {
    NYI();
    return nullptr;
}

QSet<Property*> Property::redefinedProperties() const {
    NYI();
    return QSet<Property*>();
}

QSet<Property*> Property::subsettedProperties() const {
    NYI();
    return QSet<Property*>();
}

QuUD::Label* Property::diagramElement() const {
    return static_cast<QuUD::Label*>(mDiagramElement);
}

void Property::updateDiagramElement(QuUD::Diagram*, QSizeF) {
    if(!mDiagramElement) {
        mDiagramElement = new QuUD::Label(*name(), this, 
                mClass->diagramElement());
    }
    
    auto d = static_cast<QuUD::Label*>(mDiagramElement);
    QString str = "";

    if(visibility()) {
        str += QString(QuUK::toChar(*visibility()));
        str += " ";
        str += *name();
    } else {
        str += *name();
    }

    if(type()) {
        str += " : ";
        str += *(type()->name());
    }

    if(multiplicityString() != "") {
        str += " ";
        str += multiplicityString();
    }

    if(getDefault()) {
        str += " = ";
        str += *(getDefault());
    }

    if(readOnly()) {
        str += " {readOnly}";
    }

    d->setText(str);

    if(isStatic()) {
        d->setHtml(QString("<u>")+str+"</u>");
    }

    d->resize(static_cast<QuUD::Shape*>(
                mClass->diagramElement())->width(), 0);
}

QUML_END_NAMESPACE_UK

