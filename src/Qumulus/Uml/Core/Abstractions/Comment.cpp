/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Comment.h"

QUML_BEGIN_NAMESPACE_UCA

Comment::Comment(const QString& body, std::unordered_set<Element*> annotated) :
        mBody(body), 
        mAnnotatedElements(annotated) {

}

QUML_END_NAMESPACE_UCA

