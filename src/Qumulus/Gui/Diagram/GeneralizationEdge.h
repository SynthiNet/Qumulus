/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef UML_DIAGRAM_GENERALIZATIONEDGE_H_
#define UML_DIAGRAM_GENERALIZATIONEDGE_H_

#include "internal_base.h"

#include "Edge.h"

QUML_BEGIN_NAMESPACE_GD

class GeneralizationEdge : public Edge {
public:
    GeneralizationEdge(QuUK::Element* e = 0, DiagramElement* p = 0);
    GeneralizationEdge(const GeneralizationEdge&);

    void writeXml(QXmlStreamWriter&) const override;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

    QUML_CLONABLE(GeneralizationEdge);
private:
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_GENERALIZATIONEDGE_H_ */

