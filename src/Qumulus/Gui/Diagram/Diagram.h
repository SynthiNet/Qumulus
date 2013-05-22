/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_DIAGRAM_H_
#define UML_DIAGRAM_DIAGRAM_H_


#include "internal_base.h"

#include "DiagramElement.h"

class QGraphicsScene;

QUML_BEGIN_NAMESPACE_GD

class Diagram : public DiagramElement {
public:
    Diagram(QString name = "", double resolution = 300);
    Diagram(const Diagram&);
    ~Diagram();

    const QString& name() const { return mName; }
    void setName(const QString& n) { mName = n; }

    double resolution() const { return mResolution; }
    void setResolution(double r) { mResolution = r; }

    void addElement(DiagramElement* e);
    void removeElement(DiagramElement* e);
    
    void setScene(QGraphicsScene* e);

    QUML_CLONABLE(Diagram);
private:
    QString mName;
    double mResolution;
    QList<DiagramElement*> mElements;
    QGraphicsScene* mScene = nullptr;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_DIAGRAM_H_ */

