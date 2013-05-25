/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_COMMENT_H_
#define UML_KERNEL_COMMENT_H_

#include "internal_base.h"

#include "Element.h"

// #include <Uml/Diagram/CommentShape.h>

QUML_BEGIN_NAMESPACE_UK

class Comment : public Element {
    friend struct CommentGraphics;
public:
    Comment(const QString& body = "");
    ~Comment();

    const QString& body() const { return mBody; }
    void setBody(const QString& b) { mBody = b; }

    QUML_CLONABLE(Comment);
private:
    QString mBody;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_COMMENT_H_ */

