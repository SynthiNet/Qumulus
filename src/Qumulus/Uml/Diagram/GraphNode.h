/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_GRAPHNODE_H_
#define UML_DIAGRAM_GRAPHNODE_H_

#include "internal_base.h"

#include "GraphElement.h"

#include <QtCore/QSize>

QUML_BEGIN_NAMESPACE_UD

class GraphNode : public GraphElement {
public:
    QSize size() const { return mSize; }
    void setSize(QSize s) { mSize = s; }
private:
    QSize mSize;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_GRAPHNODE_H_ */

