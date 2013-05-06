/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_DIAGRAM_H_
#define UML_DIAGRAM_DIAGRAM_H_


#include "internal_base.h"

#include "Shape.h"

QUML_BEGIN_NAMESPACE_UD

class Diagram : public Shape {
public:
    Diagram(QString name = "", double resolution = 300);

    const QString& name() const { return mName; }
    void setName(const QString& n) { mName = n; }

    double resolution() const { return mResolution; }
    void setResolution(double r) { mResolution = r; }
private:
    QString mName;
    double mResolution;
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_DIAGRAM_H_ */

