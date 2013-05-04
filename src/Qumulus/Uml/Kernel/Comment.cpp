/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Comment.h"

QUML_BEGIN_NAMESPACE_UK

Comment::Comment(const QString& body, uset<Element*> annotated) :
        mBody(body), 
        mAnnotatedElements(annotated) {

}

QUML_END_NAMESPACE_UK

