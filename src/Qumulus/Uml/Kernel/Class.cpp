/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "Class.h"

#include "Property.h"
#include "Operation.h"

#include <Uml/Diagram/ClassifierShape.h>
#include <Uml/Diagram/NameLabel.h>

QUML_BEGIN_NAMESPACE_UK

struct ClassGraphics {
    ClassGraphics(Class* e);
    ~ClassGraphics();

    QuUD::Compartment* mHeadCompartment = 0;
    QuUD::Compartment* mAttributesCompartment = 0;
    QuUD::Compartment* mOperationsCompartment = 0;
    QuUD::NameLabel* mNameLabel = 0;
};

Class::Class() {

}

Class::Class(QString name, Namespace* p) :
        Classifier(name, p) {

}


void Class::addNestedClassifier(Classifier* c) {
    mNestedClassifiers.append(c);
    addOwnedMember(c);
}

void Class::removeNestedClassifier(Classifier* c) {
    mNestedClassifiers.removeAll(c);
    removeOwnedMember(c);
}

void Class::addOperation(Operation* c) {
    mOwnedOperations.append(c);
    addFeature(c);
}

void Class::removeOperation(Operation* c) {
    mOwnedOperations.append(c);
    removeFeature(c);
}

void Class::addSuperClass(Class* c) {
    mSuperClasses.insert(c);
    addGeneralization(c);
}

void Class::removeSuperClass(Class* c) {
    mSuperClasses.remove(c);
    removeGeneralization(c);
}

void Class::updateDiagramElement(QuUD::Diagram* diagram, QSizeF newsize) {
    if(!mDiagramElement) {
        mDiagramElement = new QuUD::ClassifierShape(this, diagram);
        mGraphics = new ClassGraphics(this);

        for(Operation* l : ownedOperations()) {
            l->updateDiagramElement(diagram);
            mGraphics->mOperationsCompartment->addToGroup(l->diagramElement());
        }

        for(Property* l : attributes()) {
            l->updateDiagramElement(diagram);
            mGraphics->mAttributesCompartment->addToGroup(l->diagramElement());
        }
    }



    auto g = mGraphics;
    auto d = static_cast<QuUD::CompartmentableShape*>(mDiagramElement);

    d->setVisible(false);

    if(!newsize.isValid()) {
        newsize = d->size();
    }

    auto size = g->mHeadCompartment->minimumSize();
    size.setWidth(std::max(g->mNameLabel->fullTextWidth(), 190) + 10);
    g->mHeadCompartment->setMinimumSize(size);
    g->mHeadCompartment->setMaximumSize({newsize.width(), 20});
    g->mHeadCompartment->resize(0, 0);
    d->resize(newsize);

    g->mNameLabel->setPos(0, 0);
    g->mNameLabel->resize(d->width(), 0);

    double offset = 0;
    int textwidth = 0;

    for(Operation* l : ownedOperations()) {
        l->updateDiagramElement(diagram);
        l->diagramElement()->setPos(0, offset);
        textwidth = std::max(textwidth, l->diagramElement()->fullTextWidth());
        offset += l->diagramElement()->sharedStyle()->fontHeight();
    }

    g->mOperationsCompartment->setMinimumSize({200, offset + 10});

    int oldoffset = offset;
    offset = 0;

    for(Property* l : attributes()) {
        l->updateDiagramElement(diagram);
        l->diagramElement()->setPos(0, offset);
        textwidth = std::max(textwidth, l->diagramElement()->fullTextWidth());
        offset += l->diagramElement()->sharedStyle()->fontHeight();
    }

    g->mAttributesCompartment->setMinimumSize({200, offset + 10});
    d->setSizeHint({std::max(textwidth + 20, 200), oldoffset + offset + 50});

    d->resize(newsize);
}

ClassGraphics::ClassGraphics(Class* e) :
        mHeadCompartment(new QuUD::Compartment(
                static_cast<QuUD::CompartmentableShape*>(e->diagramElement()))),
        mAttributesCompartment(new QuUD::Compartment(
                static_cast<QuUD::CompartmentableShape*>(e->diagramElement()))),
        mOperationsCompartment(new QuUD::Compartment(
                static_cast<QuUD::CompartmentableShape*>(e->diagramElement()))),
        mNameLabel(new QuUD::NameLabel(*(e->name()), e, mHeadCompartment)) {
    mNameLabel->setWidth(200);
    mHeadCompartment->setMinimumSize(QSize(200, 20));
    mHeadCompartment->setMaximumSize(QSize(200, 20));
    mAttributesCompartment->setMinimumSize(QSize(200, 40));
    mOperationsCompartment->setMinimumSize(QSize(200, 40));

    static_cast<QuUD::CompartmentableShape*>(
            e->diagramElement())->setMinimumSize({0, 100});
}

ClassGraphics::~ClassGraphics() {
    delete mNameLabel;
    delete mHeadCompartment;
    delete mAttributesCompartment;
    delete mOperationsCompartment;
}

QUML_END_NAMESPACE_UK
