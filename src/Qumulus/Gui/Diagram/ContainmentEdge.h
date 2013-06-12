/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef UML_DIAGRAM_CONTAINMENTEDGE_H_
#define UML_DIAGRAM_CONTAINMENTEDGE_H_

#include "internal_base.h"

#include "Edge.h"

QUML_BEGIN_NAMESPACE_GD

class ContainmentEdge : public Edge {
public:
    ContainmentEdge(QuUK::Element* e = 0, DiagramElement* p = 0);
    ContainmentEdge(const ContainmentEdge&);

    void writeXml(QXmlStreamWriter&) const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

    QUML_CLONABLE(ContainmentEdge);
private:
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_CONTAINMENTEDGE_H_ */

