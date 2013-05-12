/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Parameter.h"

#include "Operation.h"

QUML_BEGIN_NAMESPACE_UK

Parameter::Parameter(QString name, Operation* o) :
    mDirection(ParameterDirectionKind::In) {
    setOperation(o);
    if(o) o->addParameter(this);
    setName(name);
}

void Parameter::setOperation(Operation* o) {
    mOperation = o;
    setNameSpace(o);
}

void Parameter::updateDiagramElement(QuUD::Diagram*, QSizeF) {

}

QUML_END_NAMESPACE_UK
