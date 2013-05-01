/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_CORE_ABSTRACTIONS_COMMENT_H_
#define UML_CORE_ABSTRACTIONS_COMMENT_H_

#include "internal_base.h"

#include "Element.h"

QUML_BEGIN_NAMESPACE_UCA

class Comment : public Element {
public:
    Comment(const QString& body = "", 
            std::unordered_set<Element*> annotated = {});

    const QString& body() const { return mBody; }
    void setBody(const QString& b) { mBody = b; }

    std::unordered_set<Element*> annotatedElements() { 
        return mAnnotatedElements;
    }
    
    const std::unordered_set<Element*> annotatedElements() const { 
        return mAnnotatedElements;
    }
    
private:
    QString mBody;
    std::unordered_set<Element*> mAnnotatedElements;
};

QUML_END_NAMESPACE_UCA

#endif /* UML_CORE_ABSTRACTIONS_COMMENT_H_ */

