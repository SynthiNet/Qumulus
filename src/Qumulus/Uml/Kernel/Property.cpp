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
        mClass(c),
        mAssociation(0) {
    if(c) c->addAttribute(this);
    setName(name);
}

QString Property::qualifiedName() const {
    if(!mClass) return "";
    QString s = mClass->qualifiedName();
    return s == "" ? s : s + separator() + name(); 
}

QString Property::toString() const {
    QString str = "";

    str += QString(QuUK::toChar(visibility()));
    str += " ";
    str += name();

    if(type()) {
        str += " : ";
        str += type()->name();
    }

    if(multiplicityString() != "") {
        str += " ";
        str += multiplicityString();
    }

    if(getDefault() != "") {
        str += " = ";
        str += getDefault();
    }

    if(readOnly()) {
        str += " {readOnly}";
    }

    return str;
}

#if 0
QuUD::FeatureLabel* Property::diagramElement() const {
    return static_cast<QuUD::FeatureLabel*>(mDiagramElement);
}

void Property::updateDiagramElement(QuUD::Diagram*, QSizeF) {
    if(!mDiagramElement) {
        mDiagramElement = new QuUD::FeatureLabel(*name(), this, 
                mClass->diagramElement());
    }
    
    auto d = static_cast<QuUD::FeatureLabel*>(mDiagramElement);
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

    d->setStatic(isStatic());

    d->setText(str);

    d->resize(static_cast<QuUD::Shape*>(
                mClass->diagramElement())->width(), 0);
}
#endif

QUML_END_NAMESPACE_UK

