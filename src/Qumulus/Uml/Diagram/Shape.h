/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_SHAPE_H_
#define UML_DIAGRAM_SHAPE_H_

#include "internal_base.h"

#include "DiagramElement.h"

QUML_BEGIN_NAMESPACE_UD

class Shape : public DiagramElement {
public:
    Shape(QuUK::Element* e = 0, DiagramElement* p = 0);
    Shape(const Shape&);

    QSizeF size() const { return mSize; }

    double width() const;
    double height() const;
    void setWidth(double);
    void setHeight(double);

    void resize(QSizeF s) { resize(s.width(), s.height()); }
    virtual void resize(double w, double h) = 0;

    QSizeF minimumSize() const { return mMinimumSize; }
    void setMinimumSize(QSizeF s) { mMinimumSize = s; }

    QSizeF maximumSize() const { return mMaximumSize; }
    void setMaximumSize(QSizeF s) { mMaximumSize = s; }

protected:
    void setSize(QSizeF s) { mSize = s; }

private:
    QSizeF mSize = QSizeF();
    QSizeF mMinimumSize = QSizeF();
    QSizeF mMaximumSize = QSizeF();
    QSizeF mSizeHint = QSizeF();
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_SHAPE_H_ */

