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

#ifndef UML_DIAGRAM_CLASSSHAPE_H_
#define UML_DIAGRAM_CLASSSHAPE_H_

#include "internal_base.h"

#include "CompartmentableShape.h"

#include <Uml/Kernel/Class.h>

QUML_BEGIN_NAMESPACE_GD

class ClassShape : public CompartmentableShape {
public:
    ClassShape(QuUK::Element* e = 0, DiagramElement* p = 0);
    ClassShape(const ClassShape&);

    QuUK::Class* modelElement() const override;

    bool indentForVisibility() const { return mIndentForVisibilty; }
    void setIndentForVisibility(bool b) { mIndentForVisibilty = b; }
    void updateSizeConstraints() override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
            QWidget* widget) override;

    void hoverMoveEvent(QGraphicsSceneHoverEvent* event) override;
    QVariant itemChange(GraphicsItemChange change,
            const QVariant & value) override;
    QuUK::Property* highlightedAttribute() const;
    QuUK::Operation* highlightedOperation() const;

    virtual bool acceptsAssociationSource() override { return true; }
    virtual bool acceptsAssociationTarget() override { return true; }
    virtual bool acceptsGeneralizationSource() override { return true; }
    virtual bool acceptsGeneralizationTarget() override { return true; }

    void writeXml(QXmlStreamWriter& writer) const override;

    QUML_CLONABLE(ClassShape);
private:
    int classNameWidth() const;
private:
    bool mIndentForVisibilty = false;
    Compartment* mHeadCompartment;
    Compartment* mAttributeCompartment;
    Compartment* mOperationCompartment;
    QuUK::Property* mHighlightedAttribute = nullptr;
    QuUK::Operation* mHighlightedOperation = nullptr;
};

QUML_END_NAMESPACE_GD


#endif /* UML_DIAGRAM_CLASSSHAPE_H_ */

