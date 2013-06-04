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

void Package::addPackagedElement(PackageableElement* e) {
    mPackagedElements.append(e);
}

void Package::removePackagedElement(PackageableElement* e) {
    mPackagedElements.removeAll(e);
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

QUML_END_NAMESPACE_UK
