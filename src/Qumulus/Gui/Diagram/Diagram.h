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
#include <Lib/Core/Exception.h>

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
    Diagram();
    Diagram(const Diagram&);
    ~Diagram();

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

    bool saveToXml(const QString& file) const;
    void loadFromXml(const QString& file) throw(QuLC::ParseException);

    void writeXml(QXmlStreamWriter&) const override {}

    QUML_CLONABLE(Diagram);
private:
    QList<DiagramElement*> mElements;
    QGraphicsScene* mScene = nullptr;
    QuUK::Package* mRootPackage;
    QList<QuUK::Comment*> mComments; 
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_DIAGRAM_H_ */

