/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_DIAGRAM_H_
#define UML_DIAGRAM_DIAGRAM_H_

#include "internal_base.h"

#include "GraphNode.h"

QUML_BEGIN_NAMESPACE_UD

class Diagram : public GraphNode {
public:
    const QString& name() const { return mName; }
    void setName(const QString& s) { mName = s; }
    
    double zoom() const { return mZoom; }
    void setZoom(double z) { mZoom = z; }

    QPoint viewport() const { return mViewport; }
    void setViewport(QPoint p) { mViewport = p; }
private:
    QString mName;
    double mZoom;
    QPoint mViewport;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_DIAGRAM_H_ */

