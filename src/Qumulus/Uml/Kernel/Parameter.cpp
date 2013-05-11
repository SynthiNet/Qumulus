/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Parameter.h"

#include "Operation.h"

QUML_BEGIN_NAMESPACE_UK

Parameter::Parameter(Operation* o) :
    mDirection(ParameterDirectionKind::In) {
    setOperation(o);
}

void Parameter::setOperation(Operation* o) {
    mOperation = o;
    setNameSpace(o);
}

void Parameter::updateDiagramElement(QuUD::Diagram*) {

}

QUML_END_NAMESPACE_UK
