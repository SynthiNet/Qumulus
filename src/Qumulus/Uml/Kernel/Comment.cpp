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
    writer.writeTextElement("Comment", body());
}

void Comment::readXml(QDomElement node, QuLC::XmlModelReader& reader) {
    (void)reader;

    qDebug() << "Load: " << node.tagName() << "[id=" <<
        node.attribute("id", "") << "] name: " << node.attribute("name", "");

    setBody(node.toElement().text());
}

QUML_END_NAMESPACE_UK

