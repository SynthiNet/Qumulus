/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_COMMENT_H_
#define UML_KERNEL_COMMENT_H_

#include "internal_base.h"

#include "Element.h"

#include <Uml/Diagram/CommentShape.h>

QUML_BEGIN_NAMESPACE_UK

struct CommentGraphics;

class Comment : public Element {
    friend struct CommentGraphics;
public:
    Comment(const QString& body = "", Element* annotated = 0);
    ~Comment();

    const QString& body() const { return mBody; }
    void setBody(const QString& b) { mBody = b; }

    Element* annotatedElement() const { return mAnnotatedElement; }
    void setAnnotatedElement(Element* e) { mAnnotatedElement = e; }
    

    QuUD::CommentShape* diagramElement() const override;
    
    void updateDiagramElement(QuUD::Diagram*, QSizeF s = QSizeF()) override;

    QUML_CLONABLE(Comment);
private:
    QString mBody;
    Element* mAnnotatedElement = nullptr;

    CommentGraphics* mGraphics = nullptr;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_COMMENT_H_ */

