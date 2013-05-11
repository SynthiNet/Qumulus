/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "PrimitiveType.h"

#include <Uml/Diagram/ClassifierShape.h>
#include <Uml/Diagram/KeywordLabel.h>
#include <Uml/Diagram/NameLabel.h>

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

void PrimitiveType::updateDiagramElement(QuUD::Diagram* diagram) {
    if(!mDiagramElement) {
        mDiagramElement = new QuUD::ClassifierShape(this, diagram);
        mGraphics = new PrimitiveTypeGraphics(this);
    }

    auto g = mGraphics;
    auto d = mDiagramElement;

    d->setVisible(false);

    g->mNameLabel->setPos(0, d->sharedStyle()->fontSize() * 1.3);
}
    

PrimitiveTypeGraphics::PrimitiveTypeGraphics(PrimitiveType* p) : 
        mCompartment(new QuUD::Compartment(
                static_cast<QuUD::CompartmentableShape*>(p->diagramElement()))),
        mKeywordLabel(new QuUD::KeywordLabel("primitive", p, mCompartment)),
        mNameLabel(new QuUD::NameLabel(*(p->name()), p, mCompartment)) {
    mKeywordLabel->setWidth(100);
    mNameLabel->setWidth(100);
}

PrimitiveTypeGraphics::~PrimitiveTypeGraphics() {
    delete mCompartment;
    delete mKeywordLabel;
    delete mNameLabel;
}
QUML_END_NAMESPACE_UK
