/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "EnumShape.h"
#include "Diagram.h"

#include <QtGui/QPainter>
#include <QtGui/QCursor>
#include <QtCore/QDebug>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsSceneHoverEvent>


QUML_BEGIN_NAMESPACE_GD

EnumShape::EnumShape(QuUK::Element* e, DiagramElement* p) : 
        CompartmentableShape(e, p), mHeader(new Compartment()),
        mBody(new Compartment()) {
    addCompartment(mHeader);
    addCompartment(mBody);
    updateSizeConstraints();
    resize(0, 0);
    setAcceptHoverEvents(true);
}

EnumShape::EnumShape(const EnumShape& s) :
        CompartmentableShape(s) {

}

QuUK::Enumeration* EnumShape::modelElement() const {
    return dynamic_cast<QuUK::Enumeration*>(
            CompartmentableShape::modelElement());
}

void EnumShape::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, 
        QWidget* widget) {
    updateSizeConstraints();
    resize(size());

    CompartmentableShape::paint(painter, option, widget);

    QFont stereotypeFont = sharedStyle()->font();
    stereotypeFont.setItalic(true);
    painter->setFont(stereotypeFont);
    painter->drawText(0, 0, width(), mHeader->height() / 2,
            Qt::AlignHCenter | Qt::AlignBottom,
            "\u00AB enumeration \u00BB");

    QFont nameFont = sharedStyle()->font();
    nameFont.setBold(true);
    painter->setFont(nameFont);
    painter->drawText(0, mHeader->height() / 2, width(), mHeader->height(), 
            Qt::AlignHCenter | Qt::AlignTop,
            modelElement()->name());

    QFont literalFont = sharedStyle()->font();
    QFontMetrics met(literalFont);

    float th = mHeader->height();
    float delta = met.height() * 1.2;
    painter->setFont(literalFont);

    for(auto& a : modelElement()->ownedLiterals()) {
        if(a == highlightedLiteral()) {
            painter->fillRect(1, th + 1, width() - 2, delta - 2, 
                    QColor(200, 240, 255));
        }

        painter->drawText(2, th, width() - 2, delta,
                Qt::AlignLeft | Qt::AlignVCenter,
                met.elidedText("\u2022 " + a->name(), Qt::ElideRight, width() - 4));
        th += delta;
    }
}

void EnumShape::updateSizeConstraints() {
    float fheight = QFontMetrics(sharedStyle()->font()).height() * 1.2; 
    float bheight = std::max(30.0f, 
            modelElement()->ownedLiterals().size() * fheight) + 10;

    setMinimumSize({std::max(190, enumNameWidth()) + 10, bheight});
    mHeader->setMinimumHeight(40);
    mHeader->setMaximumHeight(40);
    mBody->setMinimumHeight(bheight);
}

int EnumShape::enumNameWidth() const {
    QFont font = sharedStyle()->font();
    font.setBold(true);

    QFontMetrics m(font);
    return m.width(modelElement()->name());
}

QuUK::EnumerationLiteral* EnumShape::highlightedLiteral() const {
    return mHighlightedLiteral;
}

void EnumShape::hoverMoveEvent(QGraphicsSceneHoverEvent* event) {
    if(!isSelected()) {
        mHighlightedLiteral = nullptr;
    } else {
        QRectF rect(0, 40, width(), mBody->height());

        if(!rect.contains(event->pos())) {
            mHighlightedLiteral = nullptr;
        } else {
            float y = event->pos().y() - 40;
            y /= (QFontMetrics(sharedStyle()->font()).height() * 1.2);

            int yi = (unsigned)y;

            if(yi >= modelElement()->ownedLiterals().size()) {
                mHighlightedLiteral = nullptr;
            } else {
                auto x = modelElement()->ownedLiterals()[yi];
                mHighlightedLiteral = x;
                update();
            }
        }
    }

    SelectableShape::hoverMoveEvent(event);
}

QUML_END_NAMESPACE_GD
