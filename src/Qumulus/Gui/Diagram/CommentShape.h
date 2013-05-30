/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#ifndef UML_DIAGRAM_COMMENTSHAPE_H_
#define UML_DIAGRAM_COMMENTSHAPE_H_

#include "internal_base.h"

#include "SelectableShape.h"

#include <Uml/Kernel/Comment.h>

QUML_BEGIN_NAMESPACE_GD

class CommentShape : public SelectableShape {
public:
    CommentShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    CommentShape(const CommentShape&);

    QuUK::Comment* modelElement() const override;

    using Shape::resize;
    void resize(double, double) override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
            QWidget* widget) override;
    void updateSizeConstraints() override;

    void writeXml(QXmlStreamWriter& writer) const override;

    QUML_CLONABLE(CommentShape);
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_COMMENTSHAPE_H_ */

