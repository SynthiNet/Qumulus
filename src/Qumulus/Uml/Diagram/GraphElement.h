/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_GRAPHELEMENT_H_
#define UML_DIAGRAM_GRAPHELEMENT_H_

#include "internal_base.h"

#include "DiagramElement.h"
#include "GraphConnector.h"

#include <QtCore/QPoint>

#include <list>

QUML_BEGIN_NAMESPACE_UD

class Diagram;

class GraphElement : public DiagramElement {
public:
    GraphElement(Diagram* d = 0) : mDiagram(d) {}

    const QPoint& position() const { return mPosition; }
    void setPosition(const QPoint& p) { mPosition = p; }

    std::list<DiagramElement*>& contained() { return mContained; }
    const std::list<DiagramElement*>& contained() const { return mContained; }

    Diagram* diagram() const { return mDiagram; }
    void setDiagram(Diagram* d) { mDiagram = d; }

    std::list<GraphConnector>& anchorage() { return mAnchorage; }
    const std::list<GraphConnector>& anchorage() const { return mAnchorage; }
private:
    QPoint mPosition;
    std::list<DiagramElement*> mContained;
    Diagram* mDiagram;
    std::list<GraphConnector> mAnchorage; 
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_GRAPHELEMENT_H_ */

