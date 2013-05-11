/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Comment.h"

#include <Uml/Diagram/CommentShape.h>

#include <QtWidgets/QGraphicsTextItem>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_UK

struct CommentGraphics {
    CommentGraphics(Comment* c);
    ~CommentGraphics();

    QGraphicsTextItem* mText = nullptr;
};

Comment::Comment(const QString& body, QSet<Element*> annotated) :
        mBody(body), 
        mAnnotatedElements(annotated) {

}

Comment::~Comment() {
    delete mGraphics;
}

QuUD::CommentShape* Comment::diagramElement() const {
    return static_cast<QuUD::CommentShape*>(mDiagramElement);
}

void Comment::updateDiagramElement(QuUD::Diagram* diagram) {
    if(!mDiagramElement) {
        mDiagramElement = new QuUD::CommentShape(this, diagram);
        mGraphics = new CommentGraphics(this);
    }

    auto g = mGraphics;
    auto d = static_cast<QuUD::CommentShape*>(mDiagramElement);

    d->setVisible(false);

    d->setMinimumSize({100, 60});
    d->resize(d->size());

    g->mText->setPlainText(mBody);
    g->mText->setTextWidth(d->width());
    g->mText->setPos(0, 10);

    qDebug() << g->mText->boundingRect();

    d->setMinimumSize({100, 
            std::max(60.0, g->mText->boundingRect().height()) + 10.0});
    d->resize(d->size());
}

CommentGraphics::CommentGraphics(Comment* c) :
        mText(new QGraphicsTextItem(c->diagramElement())){

}

CommentGraphics::~CommentGraphics() {
    delete mText;
}

QUML_END_NAMESPACE_UK

