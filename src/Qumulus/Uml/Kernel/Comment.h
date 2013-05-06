/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_KERNEL_COMMENT_H_
#define UML_KERNEL_COMMENT_H_

#include "internal_base.h"

#include "Element.h"

QUML_BEGIN_NAMESPACE_UK

class Comment : public Element {
public:
    Comment(const QString& body = "", 
            QSet<Element*> annotated = {});

    const QString& body() const { return mBody; }
    void setBody(const QString& b) { mBody = b; }

    QSet<Element*> annotatedElements() { 
        return mAnnotatedElements;
    }
    
    const QSet<Element*> annotatedElements() const { 
        return mAnnotatedElements;
    }
    
    void updateDiagramElement() override;

    QUML_CLONABLE(Comment);
private:
    QString mBody;
    QSet<Element*> mAnnotatedElements;
};

QUML_END_NAMESPACE_UK

#endif /* UML_KERNEL_COMMENT_H_ */

