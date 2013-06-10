/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Comment.h"
#include <QtCore/QXmlStreamWriter>

QUML_BEGIN_NAMESPACE_UK

Comment::Comment(const QString& body) :
        mBody(body) {

}

Comment::~Comment() {
}

void Comment::writeXml(QXmlStreamWriter& writer) const {
    writer.writeTextElement("Comment", body());
}

void Comment::readXml(QDomNode node, QuLC::XmlModelReader& reader) {
    (void)reader;

    setBody(node.toElement().text());
}

QUML_END_NAMESPACE_UK

