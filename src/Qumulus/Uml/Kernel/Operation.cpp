/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "Operation.h"

#include <Uml/Kernel/Class.h>

#include "Parameter.h"

#include "Class.h"

QUML_BEGIN_NAMESPACE_UK

Operation::Operation(QString name, Class* c) : 
        mClass(c), 
        mQuery(false) {
    setName(name);
    if(c) c->addOperation(this);
}

Parameter* Operation::returnResult() const {
    for(auto&& p : parameters()) {
        if(p->direction() == ParameterDirectionKind::Return)
            return p;
    }
    return nullptr;
}

Type* Operation::type() const {
    return returnResult()->type();
}

QuUD::Label* Operation::diagramElement() const {
    return static_cast<QuUD::Label*>(mDiagramElement);
}

void Operation::updateDiagramElement(QuUD::Diagram*, QSizeF) {
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

    str += "(";

    for(Parameter* p : parameters()) {
        if(p->direction() == ParameterDirectionKind::Return) continue;
        
        // Parameter name
        str += *(p->name());

        // Parameter type
        if(p->type()) {
            str += " : ";
            str += *(p->type()->name());
        }

        // Parameter multiplicity
        if(p->multiplicityString() != "") {
            str += " ";
            str += p->multiplicityString();
        }

        // Parameter default
        if(p->defaultValue()) {
            str += " = ";
            str += *(p->defaultValue());
        }

        if(p != *(parameters().end()-1)) {
            str += ", ";
        }
    }

    str += ")";

    if(type()) {
        str += " : ";
        str += *(type()->name());
    }

    if(isQuery()) {
        str += " {query}";
    }

    d->setText(str);

    if(isStatic()) {
        d->setHtml(QString("<u>")+str+"</u>");
    }
    
    d->resize(static_cast<QuUD::Shape*>(
                mClass->diagramElement())->width(), 0);
}

QUML_END_NAMESPACE_UK
