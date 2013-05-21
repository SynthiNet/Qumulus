/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#ifndef UML_DIAGRAM_PACKAGESHAPE_H_
#define UML_DIAGRAM_PACKAGESHAPE_H_

#include "internal_base.h"

#include "SelectableShape.h"

#include <QtWidgets/QGraphicsRectItem>

QUML_BEGIN_NAMESPACE_UD

class PackageShape : public SelectableShape {
public:
    PackageShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    PackageShape(const PackageShape&);

    using Shape::resize;
    void resize(double, double) override;

    QUML_CLONABLE(PackageShape);
private:
    QGraphicsRectItem* mTabItem;
    QGraphicsRectItem* mBodyItem;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_PACKAGESHAPE_H_ */
