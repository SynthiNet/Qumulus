/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "Class.h"

#include "Property.h"
#include "Operation.h"

#include <Lib/Core/Functional.h>
#include <QtCore/QXmlStreamWriter>

QUML_BEGIN_NAMESPACE_UK

Class::Class() {

}

Class::Class(QString name, Package* p) :
        Classifier(name, p) {

}

Class::~Class() {
    for(auto& x : mOwnedAttributes) {
        delete x;
    }

    for(auto& x : mOwnedOperations) {
        delete x;
    }
}

// void Class::addNestedClassifier(Classifier* c) {
//     mNestedClassifiers.append(c);
// }

// void Class::removeNestedClassifier(Classifier* c) {
//     mNestedClassifiers.removeAll(c);
// }

size_t Class::size() const {
    return mOwnedAttributes.size() + mOwnedOperations.size();
}

Element* Class::operator[](size_t idx) const {
    if(idx >= (size_t)mOwnedAttributes.size()) {
        return mOwnedOperations[idx - mOwnedAttributes.size()];
    } else {
        return mOwnedAttributes[idx];
    }
}

void Class::addAttribute(Property* p) {
    mOwnedAttributes.append(p);

    elementChanged();
}

void Class::removeAttribute(Property* p) {
    if(mOwnedAttributes.contains(p)) {
        mOwnedAttributes.removeAll(p);
        elementChanged();
    }
}

void Class::addOperation(Operation* c) {
    mOwnedOperations.append(c);

    elementChanged();
}

void Class::removeOperation(Operation* c) {
    if(mOwnedOperations.contains(c)) {
        mOwnedOperations.append(c);
        elementChanged();
    }
}

void Class::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Class");
    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("name", name());
    writer.writeAttribute("abstract", abstract() ? "true" : "false");
    writer.writeAttribute("final", final() ? "true" : "false");

    for(auto& g : generalizations()) {
        g->writeXml(writer);
    }

    for(auto& a : attributes()) {
        a->writeXml(writer);
    }

    for(auto& o : operations()) {
        o->writeXml(writer);
    }

    writer.writeEndElement();
}

void Class::readXml(QDomNode node, QuLC::XmlModelReader& reader) {
    (void)node;
    (void)reader;

    NYI();
}

QUML_END_NAMESPACE_UK
