/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_GRAPHCONNECTOR_H_
#define UML_DIAGRAM_GRAPHCONNECTOR_H_

#include "internal_base.h"

#include <QtCore/QPoint>

QUML_BEGIN_NAMESPACE_UD

class GraphElement;
class GraphEdge;

class GraphConnector {
public:
    GraphConnector(GraphElement* e);

    GraphEdge* firstEdge() const { return mFirstEdge; }
    GraphEdge* secondEdge() const { return mSecondEdge; }
private:
    QPoint mPosition;
    GraphElement* mGraphElement; 
    GraphEdge* mFirstEdge;
    GraphEdge* mSecondEdge;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_GRAPHCONNECTOR_H_ */

