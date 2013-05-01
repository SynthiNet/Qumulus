/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "GraphConnector.h"

QUML_BEGIN_NAMESPACE_UD

GraphConnector(GraphElement* e) :
        mGraphElement(e),
        mFirstEdge(nullptr),
        mSecondEdge(nullptr) {

}

QUML_END_NAMESPACE_UD
