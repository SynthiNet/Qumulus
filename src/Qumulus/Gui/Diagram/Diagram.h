/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_DIAGRAM_H_
#define UML_DIAGRAM_DIAGRAM_H_


#include "internal_base.h"

#include "DiagramElement.h"

#include <Gui/Widgets/internal_base.h>

class QGraphicsScene;

QUML_BEGIN_NAMESPACE_UK

class Package;
class Comment;
class Class;
class PrimitiveType;
class Enumeration;

QUML_END_NAMESPACE_UK

QUML_BEGIN_NAMESPACE_GW

class EditorView;

QUML_END_NAMESPACE_GW

QUML_BEGIN_NAMESPACE_GD

class PackageShape;
class CommentShape;
class PrimitiveShape;
class ClassShape;
class EnumShape;

class Diagram : public DiagramElement {
public:
    Diagram(QString name = "", double resolution = 300);
    Diagram(const Diagram&);
    ~Diagram();

    const QString& name() const { return mName; }
    void setName(const QString& n) { mName = n; }

    double resolution() const { return mResolution; }
    void setResolution(double r) { mResolution = r; }

    PackageShape* createShape(QuUK::Package*);
    CommentShape* createShape(QuUK::Comment*);
    PrimitiveShape* createShape(QuUK::PrimitiveType*);
    ClassShape* createShape(QuUK::Class*);
    EnumShape* createShape(QuUK::Enumeration*);

    void addElement(DiagramElement* e);
    void removeElement(DiagramElement* e);
    
    void setScene(QGraphicsScene* e);
    QGraphicsScene* scene() const { return mScene; }
    QuGW::EditorView* editorView() const;

    unsigned nextCounter() { return mCounter++; }

    QUML_CLONABLE(Diagram);
private:
    QString mName;
    double mResolution;
    QList<DiagramElement*> mElements;
    QGraphicsScene* mScene = nullptr;
    unsigned mCounter = 1;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_DIAGRAM_H_ */

