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

#include "Edge.h"
#include <QtGui/QPainter>
#include <libavoid/connend.h>
#include <libavoid/router.h>
#include <libavoid/connector.h>

#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_GD

static void grow(QRectF& r, int i) {
    r.adjust(-i, -i, i, i);
}

Edge::Edge(QuUK::Element* e, DiagramElement* p) :
        DiagramElement(e, p),
        QGraphicsItemGroup(dynamic_cast<Shape*>(p)) {
    setVisible(false);
    setZValue(-9001);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
}

Edge::Edge(const Edge& e) :
        DiagramElement(e) {}

QRectF Edge::boundingRect() const {
    return shape().boundingRect();
}

void Edge::calcShape() {
    QPainterPath p;

    auto route = mConnectionReference->displayRoute();
    std::vector<QRectF> v;
    for(size_t i = 0; i < route.size() - 1; ++i) {
        QPointF p1(route.at(i).x, route.at(i).y);
        QPointF p2(route.at(i+1).x, route.at(i+1).y);
        QRectF r(p1, p2);
        grow(r, 10);
        v.push_back(r);
    }

    QPolygonF poly;
    for(auto r : v) {
        poly = poly.united(r);
    }

    p.addPolygon(poly);
    p.closeSubpath();
    mShape = p;
}

QPainterPath Edge::shape() const {
    return mShape;
}

void Edge::paint(QPainter* p, const QStyleOptionGraphicsItem*, QWidget*) {
    if(!mConnectionReference)
        return;

    if(isSelected())
        p->setPen(Qt::blue);

    if(isSelected() || mConnectionReference->needsRepaint()) {
        auto route = mConnectionReference->displayRoute();
        for(size_t i = 1; i < route.size(); ++i) {
            p->drawLine(route.at(i-1).x, route.at(i-1).y,
                    route.at(i).x, route.at(i).y);
        }

        if(route.size() < 2)
            return;

        // Set source exit.
        if(route.at(0).x < route.at(1).x) {
            mSourceExit = Direction::Right;
        } else if(route.at(0).x > route.at(1).x) {
            mSourceExit = Direction::Left;
        } else if(route.at(0).y < route.at(1).y) {
            mSourceExit = Direction::Down;
        } else {
            mSourceExit = Direction::Up;
        }

        // Set target entry.
        size_t i = route.size() - 1;
        if(route.at(i-1).x < route.at(i).x) {
            mTargetEntry = Direction::Left;
        } else if(route.at(i-1).x > route.at(i).x) {
            mTargetEntry = Direction::Right;
        } else if(route.at(i-1).y < route.at(i).y) {
            mTargetEntry = Direction::Up;
        } else {
            mTargetEntry = Direction::Down;
        }

        calcShape();
    }
}

void Edge::updateSizeConstraints() {}

void Edge::setTarget(Shape* e) {
    mTarget = e;
    if(mEnd == nullptr)
        mEnd = new Avoid::ConnEnd(e->shapeRef(), 1);
}

void Edge::setSource(Shape* e) {
    mSource = e;
    if(mSrc == nullptr)
        mSrc = new Avoid::ConnEnd(e->shapeRef(), 1);
}

void Edge::connect() {
    mConnectionReference = new Avoid::ConnRef(mRouter, *mSrc, *mEnd);
    mRouter->processTransaction();
}

QUML_END_NAMESPACE_GD
