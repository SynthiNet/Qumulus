/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Package.h"

#include "Type.h"

#include <QtWidgets/QGraphicsRectItem>

#include <QtCore/QXmlStreamWriter>

QUML_BEGIN_NAMESPACE_UK

Package::Package() {}

Package::Package(QString name, Package* p) :
        PackageableElement(name, p) {
}

Package::~Package() {
    for(auto& x : mPackagedElements) {
        delete x;
    }
}

size_t Package::size() const {
    return mPackagedElements.size();
}

Element* Package::operator[](size_t idx) const {
    return mPackagedElements[idx];
}

void Package::addPackagedElement(PackageableElement* e) {
    if(mPackagedElements.contains(e)) return;
    mPackagedElements.append(e);

    elementChanged();
}

void Package::removePackagedElement(PackageableElement* e) {
    if(mPackagedElements.contains(e)) {
        mPackagedElements.removeAll(e);
        elementChanged();
    }
}

void Package::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Package");
    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("name", name());

    for(auto& x : mPackagedElements) {
        x->writeXml(writer);
    }

    writer.writeEndElement();
}

void Package::readXml(QDomNode node, QuLC::XmlModelReader& reader) {
    (void)node;
    (void)reader;

    NYI();
}

QUML_END_NAMESPACE_UK
