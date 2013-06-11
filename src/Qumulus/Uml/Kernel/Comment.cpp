/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Comment.h"
#include <QtCore/QXmlStreamWriter>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_UK

Comment::Comment(const QString& body) :
        mBody(body) {

}

Comment::~Comment() {
}

void Comment::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Comment");
    writer.writeAttribute("id", uniqueId());
    writer.writeCharacters(body());
    writer.writeEndElement();
}

void Comment::readXml(QDomElement node, QuLC::XmlModelReader& reader) {
    (void)reader;

    qDebug() << "Load: " << node.tagName() << "[id=" <<
        node.attribute("id", "") << "] body: " << node.text();

    setUniqueId(node.attribute("id"));
    setBody(node.text());
}

QUML_END_NAMESPACE_UK

