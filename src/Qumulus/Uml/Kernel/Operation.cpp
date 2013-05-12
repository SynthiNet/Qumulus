/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Operation.h"

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

void Operation::updateDiagramElement(QuUD::Diagram*, QSizeF) {

}

QUML_END_NAMESPACE_UK
