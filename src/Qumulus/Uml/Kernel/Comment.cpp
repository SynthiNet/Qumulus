/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
 * Copyright (c) 2014 Randy Thiemann <uselinuxnow@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
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

