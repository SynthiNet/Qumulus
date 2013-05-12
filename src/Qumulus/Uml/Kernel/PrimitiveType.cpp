/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "PrimitiveType.h"

#include <Uml/Diagram/ClassifierShape.h>
#include <Uml/Diagram/KeywordLabel.h>
#include <Uml/Diagram/NameLabel.h>

#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_UK

struct PrimitiveTypeGraphics {
    PrimitiveTypeGraphics(PrimitiveType* p);
    ~PrimitiveTypeGraphics();

    QuUD::Compartment* mCompartment = 0;
    QuUD::KeywordLabel* mKeywordLabel = 0;
    QuUD::NameLabel* mNameLabel = 0;
};

PrimitiveType::PrimitiveType() :
        mGraphics(0) {

}

PrimitiveType::~PrimitiveType() {
    delete mGraphics;
}

void PrimitiveType::updateDiagramElement(QuUD::Diagram* diagram, 
        QSizeF newsize) {
    if(!mDiagramElement) {
        mDiagramElement = new QuUD::ClassifierShape(this, diagram);
        mGraphics = new PrimitiveTypeGraphics(this);
    }

    auto g = mGraphics;
    auto d = static_cast<QuUD::CompartmentableShape*>(mDiagramElement);

    d->setVisible(false);

    if(!newsize.isValid()) {
        newsize = d->size();
    }

    auto size = g->mCompartment->minimumSize();
    size.setWidth(std::max(g->mNameLabel->fullTextWidth(), 90) + 10);
    g->mCompartment->setMinimumSize(size);
    g->mCompartment->resize(newsize);
    d->resize(newsize);

    float hheight = d->height() / 2;
    int fheight = d->sharedStyle()->fontHeight();

    g->mKeywordLabel->setPos(0, hheight - fheight * 1.2);
    g->mKeywordLabel->resize(d->width(), 0);

    g->mNameLabel->setPos(0, hheight - fheight * 0.2);
    g->mNameLabel->resize(d->width(), 0);
}
    

PrimitiveTypeGraphics::PrimitiveTypeGraphics(PrimitiveType* p) : 
        mCompartment(new QuUD::Compartment(
                static_cast<QuUD::CompartmentableShape*>(p->diagramElement()))),
        mKeywordLabel(new QuUD::KeywordLabel("primitive", p, mCompartment)),
        mNameLabel(new QuUD::NameLabel(*(p->name()), p, mCompartment)) {
    mKeywordLabel->setWidth(100);
    mNameLabel->setWidth(100);
    mCompartment->setMinimumSize(QSize(100, 40));

    static_cast<QuUD::CompartmentableShape*>(p->diagramElement())->resize(0, 0);
}

PrimitiveTypeGraphics::~PrimitiveTypeGraphics() {
    delete mCompartment;
    delete mKeywordLabel;
    delete mNameLabel;
}
QUML_END_NAMESPACE_UK
