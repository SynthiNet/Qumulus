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

#include "PackageShape.h"

#include <QtCore/QXmlStreamWriter>
#include <QtGui/QBrush>
#include <QtGui/QPainter>

#include <Uml/Kernel/Package.h>

QUML_BEGIN_NAMESPACE_GD

PackageShape::PackageShape(QuUK::Element* e,
        DiagramElement* p) :
        SelectableShape(e, p) {
    constexpr int kPackageZOrdering = -2;
    setZValue(kPackageZOrdering);
    updateSizeConstraints();
    resize(0, 0);
}

PackageShape::PackageShape(const PackageShape& c) :
        SelectableShape(c) {}

QuUK::Package* PackageShape::modelElement() const {
    return dynamic_cast<QuUK::Package*>(SelectableShape::modelElement());
}

void PackageShape::updateSizeConstraints() {
    setMinimumSize({10 + std::max(packageNameWidth(), 90), 50});
}

void PackageShape::resize(double w, double h) {
    w = minimumSize().width() == -1 ? w : std::max(w, minimumSize().width());
    h = minimumSize().height() == -1 ? h : std::max(h, minimumSize().height());

    setSize({w, h});
}

void PackageShape::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
        QWidget* widget) {
    updateSizeConstraints();
    resize(size());

    painter->setBrush(Qt::white);

    painter->drawRect(0, 0, 30, 10);
    painter->drawRect(0, 10, width(), height() - 10);

    QFont font = sharedStyle()->font();
    font.setBold(true);
    painter->setFont(font);
    painter->drawText(0, 12, width(), height(),
            Qt::AlignTop | Qt::AlignHCenter,
            modelElement()->name());

    SelectableShape::paint(painter, option, widget);
}

int PackageShape::packageNameWidth() const {
    QFont font = sharedStyle()->font();
    font.setBold(true);

    QFontMetrics m(font);
    return m.width(modelElement()->name());
}

void PackageShape::writeXml(QXmlStreamWriter& writer) const {
    writer.writeStartElement("Package");
    writer.writeAttribute("id", uniqueId());
    writer.writeAttribute("x", QString::number(pos().x()));
    writer.writeAttribute("y", QString::number(pos().y()));
    writer.writeAttribute("width", QString::number(width()));
    writer.writeAttribute("height", QString::number(height()));
    writer.writeAttribute("modelelement", modelElement()->uniqueId());
    writer.writeAttribute("visible", isVisible() ? "true" : "false");

    writer.writeEndElement();
}

QUML_END_NAMESPACE_GD

