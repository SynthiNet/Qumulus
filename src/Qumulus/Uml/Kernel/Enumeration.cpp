/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Enumeration.h"

#include <QtCore/QXmlStreamWriter>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_UK

Enumeration::Enumeration() {

}

Enumeration::~Enumeration() {
    for(auto& x : mOwnedLiterals) {
        delete x;
    }
}

Enumeration::Enumeration(QString name, Package* p) :
        DataType(name, p) {

}

size_t Enumeration::size() const {
    return mOwnedLiterals.size();
}

Element* Enumeration::operator[](size_t idx) const {
    return mOwnedLiterals[idx];
}

void Enumeration::addLiteral(EnumerationLiteral* l) {
    mOwnedLiterals.append(l);

    elementChanged();
}

void Enumeration::removeLiteral(EnumerationLiteral* l) {
    if(mOwnedLiterals.contains(l)) {
        mOwnedLiterals.removeAll(l);
        elementChanged();
    }
}

void Enumeration::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Enumeration");

    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("name", name());

    for(auto& l : literals()) {
        l->writeXml(writer);
    }

    writer.writeEndElement();
}

void Enumeration::readXml(QDomElement node, QuLC::XmlModelReader& reader) {
    (void)reader;

    qDebug() << "Load: " << node.tagName() << "[id=" <<
        node.attribute("id", "") << "] name: " << node.attribute("name", "");

    setUniqueId(node.attribute("id"));
    setName(node.attribute("name"));

    // LOAD LITERALS
    QDomNodeList children = node.childNodes();

    for(int i = 0; i < children.size(); ++i) {
        auto e = children.at(i).toElement();

        if(e.tagName() == "Literal") {
            auto p = reader.loadElement(e);
            addLiteral(dynamic_cast<EnumerationLiteral*>(p));
        } else {
            throw QuLC::ParseException(qPrintable(
                        "Enumerations cannot contain a"+e.tagName()));
        }
    }

}

QUML_END_NAMESPACE_UK
