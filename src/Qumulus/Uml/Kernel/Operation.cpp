/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Operation.h"

#include "Parameter.h"

QUML_BEGIN_NAMESPACE_UK

Operation::Operation(Class* c) : 
        mClass(c), 
        mQuery(false) {}

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

void Operation::updateDiagramElement(QuUD::Diagram*) {

}

QUML_END_NAMESPACE_UK
