/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Parameter.h"

#include "Operation.h"
#include "Type.h"

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

QString Parameter::toString() const {
    QString str;

    // Parameter direction
    if(direction() == ParameterDirectionKind::Out) {
        str += "out ";
    }

    if(direction() == ParameterDirectionKind::InOut) {
        str += "inout ";
    }

    // XXX: This is normally not used (instead, append return type to
    // operation)
    if(direction() == ParameterDirectionKind::Return) {
        str += "return ";
    }

    // Parameter name
    str += name();

    // Parameter type
    if(type()) {
        str += " : ";
        str += type()->name();
    }

    // Parameter multiplicity
    if(multiplicityString() != "") {
        str += " ";
        str += multiplicityString();
    }

    // Parameter default
    if(defaultValue() != "") {
        str += " = ";
        str += defaultValue();
    }

    return str;
}

QUML_END_NAMESPACE_UK
