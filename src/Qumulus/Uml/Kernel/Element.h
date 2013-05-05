/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef QUMULUS_UML_KERNEL_ELEMENT_H_
#define QUMULUS_UML_KERNEL_ELEMENT_H_

#include "internal_base.h"

#include <Lib/Core/Clonable.h>
#include <Lib/Core/Nyi.h>
#include <Lib/Core/Functional.h>

#include <QtCore/QSet>
#include <QtCore/QList>
#include <QtCore/QString>

QUML_BEGIN_NAMESPACE_UK

class Comment;

class Element : public QuLC::Clonable {
public:
    Element() = default;
    Element(const Element& other);

    virtual ~Element();
    
    virtual bool mustBeOwned() const {
        return true;
    }

    const QSet<Element*>& ownedElements() const {
        return mOwnedElements;
    }

    const QSet<Comment*>& ownedComments() const {
        return mOwnedComments;
    }

    /**
     * @note This function takes over ownership.
     */
    void addComment(Comment* c);
    void removeComment(Comment* c);

    QUML_CLONABLE(Element)
protected:
    /**
     * @note This function takes over ownership.
     */
    void addElement(Element* other);

    void removeElement(Element* other);

private:
    QSet<Element*> mOwnedElements;
    QSet<Comment*> mOwnedComments;
};

QUML_END_NAMESPACE_UK

#endif /* QUMULUS_UML_KERNEL_ELEMENT_H_ */

