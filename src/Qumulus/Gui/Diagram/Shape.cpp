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

#include "Shape.h"
#include <libavoid/shape.h>
#include <libavoid/router.h>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_GD

Shape::Shape(QuUK::Element* e, DiagramElement* p) :
        DiagramElement(e, p),
        QGraphicsItemGroup(dynamic_cast<Shape*>(p)),
        mRoutingBox({0, 0}, {1, 1}) {
    setVisible(false);
}

Shape::Shape(const Shape& s) :
        DiagramElement(s),
        mRoutingBox(s.mRoutingBox){}


Shape::~Shape() {
    if(mRouter && mShapeRef) {
        mRouter->deleteShape(mShapeRef);
    }
}

double Shape::width() const {
    return mSize.width();
}

double Shape::height() const {
    return mSize.height();
}

void Shape::setWidth(double w) {
    resize(w, height());
}

void Shape::setHeight(double h) {
    resize(width(), h);
}

void Shape::passRouter(Avoid::Router* r) {
    mRouter = r;
    mShapeRef = new Avoid::ShapeRef(mRouter, mRoutingBox);
    new Avoid::ShapeConnectionPin(mShapeRef, 1,
            Avoid::ATTACH_POS_CENTRE, Avoid::ATTACH_POS_CENTRE);
    setSize(mSize, true);
}

void Shape::setSize(QSizeF s, bool overrideCall) {
    if(!overrideCall) {
        if(mSize == s && mPrevPos == pos())
            return;
    }

    mSize = s;

    if(mRouter && mShapeRef) {
        mRoutingBox = {{pos().x()-10, pos().y()-10},
                {pos().x() + width()+20, pos().y() + height()+20}};
        mRouter->moveShape(mShapeRef, mRoutingBox);
        mRouter->processTransaction();
    }

    mPrevPos = pos();
}

QSizeF Shape::optimalSize() const {
    return mSizeHint.isValid() ? mSizeHint : minimumSize();
}

void Shape::setOwningElement(DiagramElement* e) {
    DiagramElement::setOwningElement(e);
    if(Shape* p = dynamic_cast<Shape*>(e))
        setParentItem(p);
}

QUML_END_NAMESPACE_GD
