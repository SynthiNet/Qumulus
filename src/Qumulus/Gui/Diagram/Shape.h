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

#ifndef UML_DIAGRAM_SHAPE_H_
#define UML_DIAGRAM_SHAPE_H_

#include "internal_base.h"

#include "DiagramElement.h"

#include <QtWidgets/QGraphicsItemGroup>
#include <libavoid/geomtypes.h>

namespace Avoid {
    class ShapeRef;
    class Router;
}

QUML_BEGIN_NAMESPACE_GD

class Shape : public DiagramElement, public QGraphicsItemGroup {
public:
    Shape(QuUK::Element* e = 0, DiagramElement* p = 0);
    Shape(const Shape&);
    ~Shape();

    QSizeF size() const { return mSize; }

    double width() const;
    double height() const;
    void setWidth(double);
    void setHeight(double);

    void resize(QSizeF s) { resize(s.width(), s.height()); }
    virtual void resize(double w, double h) = 0;
    virtual void updateSizeConstraints() = 0;
    void passRouter(Avoid::Router* r);

    QSizeF minimumSize() const { return mMinimumSize; }
    void setMinimumSize(QSizeF s) { mMinimumSize = s; }

    QSizeF maximumSize() const { return mMaximumSize; }
    void setMaximumSize(QSizeF s) { mMaximumSize = s; }

    QSizeF optimalSize() const;
    void setSizeHint(QSizeF s) { mSizeHint = s; }

    virtual bool acceptsAssociationSource() { return false; }
    virtual bool acceptsAssociationTarget() { return false; }
    virtual bool acceptsGeneralizationSource() { return false; }
    virtual bool acceptsGeneralizationTarget() { return false; }

    Avoid::ShapeRef* shapeRef() { return mShapeRef; }

    void setOwningElement(DiagramElement* e);

    QUML_CLONABLE_ABSTRACT(Shape);

protected:
    void setSize(QSizeF s, bool overrideCall = false);

private:
    QSizeF mSize = QSizeF();
    QPointF mPrevPos = QPointF();
    QSizeF mMinimumSize = QSizeF();
    QSizeF mMaximumSize = QSizeF();
    QSizeF mSizeHint = QSizeF();
    Avoid::Rectangle mRoutingBox;
    Avoid::ShapeRef* mShapeRef = nullptr;
    Avoid::Router* mRouter = nullptr;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_SHAPE_H_ */

