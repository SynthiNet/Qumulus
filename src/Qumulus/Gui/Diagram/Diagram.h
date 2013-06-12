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
#include <Lib/Core/Signal.h>
#include <libavoid/router.h>

class QGraphicsScene;

QUML_BEGIN_NAMESPACE_UK

class Package;
class Comment;
class Class;
class PrimitiveType;
class Enumeration;
class Association;
class Generalization;

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
class Shape;

class AssociationEdge;
class GeneralizationEdge;
class ContainmentEdge;

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

    AssociationEdge* createEdge(QuUK::Association*, Shape*, Shape*);
    GeneralizationEdge* createEdge(QuUK::Generalization*, Shape*, Shape*);
    ContainmentEdge* createPackageContainment(Shape*, Shape*);

    void addElement(DiagramElement* e);
    void removeElement(DiagramElement* e);

    QuUK::Package* rootPackage() const { return mRootPackage; }
    void setRootPackage(QuUK::Package* r);
    const QList<QuUK::Comment*>& comments() const { return mComments; }
    void setComments(const QList<QuUK::Comment*>& c);

    const QList<QuUK::Association*>& associations() const {
        return mAssociations;
    }
    void setAssociations(const QList<QuUK::Association*>& a);

    void setScene(QGraphicsScene* e);
    QGraphicsScene* scene() const { return mScene; }
    QuGW::EditorView* editorView() const;

    unsigned nextCounter() { return mCounter++; }

    bool saveToXml(const QString& file) const;

    void writeXml(QXmlStreamWriter&) const override {}

    void clearModified() { mIsModified = false; }
    void setModified() { mIsModified = true; }
    bool isModified() { return mIsModified; }

    QUML_CLONABLE(Diagram);
public:
    QuLC::Signal<void()> diagramChanged;
private:
    QList<DiagramElement*> mElements;
    QGraphicsScene* mScene = nullptr;
    unsigned mCounter = 1;
    bool mIsModified = false;
    QuUK::Package* mRootPackage;
    QList<QuUK::Comment*> mComments;
    QList<QuUK::Association*> mAssociations;
    Avoid::Router* mRouter;
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_DIAGRAM_H_ */

