/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Enumeration.h"

#include <Uml/Diagram/ClassifierShape.h>
#include <Uml/Diagram/KeywordLabel.h>
#include <Uml/Diagram/NameLabel.h>

QUML_BEGIN_NAMESPACE_UK

struct EnumerationGraphics {
    EnumerationGraphics(Enumeration* e);
    ~EnumerationGraphics();

    QuUD::Compartment* mHeadCompartment = 0;
    QuUD::Compartment* mLiteralsCompartment = 0;
    QuUD::KeywordLabel* mKeywordLabel = 0;
    QuUD::NameLabel* mNameLabel = 0;
};

Enumeration::Enumeration() :
        mGraphics(0) {

}

Enumeration::Enumeration(QString name, Namespace* p) :
        DataType(name, p),
        mGraphics(0) {

}

Enumeration::~Enumeration() {
    delete mGraphics;
}

void Enumeration::addLiteral(EnumerationLiteral* l) {
    mOwnedLiterals.append(l);
    addOwnedMember(l);
}

void Enumeration::removeLiteral(EnumerationLiteral* l) {
    mOwnedLiterals.removeAll(l);
    removeOwnedMember(l);
}

void Enumeration::updateDiagramElement(QuUD::Diagram* diagram, QSizeF newsize) {
    if(!mDiagramElement) {
        mDiagramElement = new QuUD::ClassifierShape(this, diagram);
        mGraphics = new EnumerationGraphics(this);

        for(EnumerationLiteral* l : ownedLiterals()) {
            l->updateDiagramElement(diagram);
            mGraphics->mLiteralsCompartment->addToGroup(l->diagramElement());
        }
    }



    auto g = mGraphics;
    auto d = static_cast<QuUD::CompartmentableShape*>(mDiagramElement);

    d->setVisible(false);

    if(!newsize.isValid()) {
        newsize = d->size();
    }

    auto size = g->mHeadCompartment->minimumSize();
    size.setWidth(std::max(g->mNameLabel->fullTextWidth(), 140) + 10);
    g->mHeadCompartment->setMinimumSize(size);
    g->mHeadCompartment->setMaximumSize({newsize.width(), 40});
    g->mHeadCompartment->resize(0, 0);
    d->resize(newsize);

    float hheight = g->mHeadCompartment->height() / 2;
    int fheight = g->mHeadCompartment->sharedStyle()->fontHeight();

    g->mKeywordLabel->setPos(0, hheight - fheight * 1.2);
    g->mKeywordLabel->resize(d->width(), 0);

    g->mNameLabel->setPos(0, hheight - fheight * 0.2);
    g->mNameLabel->resize(d->width(), 0);

    double offset = 0;
    int textwidth = 0;
    for(EnumerationLiteral* l : ownedLiterals()) {
        l->updateDiagramElement(diagram);
        l->diagramElement()->setPos(0, offset);
        textwidth = std::max(textwidth, l->diagramElement()->fullTextWidth());
        offset += l->diagramElement()->sharedStyle()->fontHeight();
    }

    g->mLiteralsCompartment->setMinimumSize({150, offset + 10});
    d->setSizeHint({std::max(textwidth + 20, 150), offset + 50});

    d->resize(newsize);
}

EnumerationGraphics::EnumerationGraphics(Enumeration* e) :
        mHeadCompartment(new QuUD::Compartment(
                static_cast<QuUD::CompartmentableShape*>(e->diagramElement()))),
        mLiteralsCompartment(new QuUD::Compartment(
                static_cast<QuUD::CompartmentableShape*>(e->diagramElement()))),
        mKeywordLabel(new QuUD::KeywordLabel("enumeration", e, mHeadCompartment)),
        mNameLabel(new QuUD::NameLabel(*(e->name()), e, mHeadCompartment)) {
    mKeywordLabel->setWidth(150);
    mNameLabel->setWidth(150);
    mHeadCompartment->setMinimumSize(QSize(150, 40));
    mHeadCompartment->setMaximumSize(QSize(150, 40));
    mLiteralsCompartment->setMinimumSize(QSize(150, 40));

    static_cast<QuUD::CompartmentableShape*>(
            e->diagramElement())->setMinimumSize({0, 80});
}

EnumerationGraphics::~EnumerationGraphics() {
    delete mKeywordLabel;
    delete mNameLabel;
    delete mHeadCompartment;
    delete mLiteralsCompartment;
}

QUML_END_NAMESPACE_UK
