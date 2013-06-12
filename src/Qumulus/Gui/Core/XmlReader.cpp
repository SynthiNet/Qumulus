/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "XmlReader.h"

#include <Lib/Core/XmlModelReader.h>

#include <Gui/Diagram/Diagram.h>
#include <Gui/Diagram/ClassShape.h>
#include <Gui/Diagram/PrimitiveShape.h>
#include <Gui/Diagram/EnumShape.h>
#include <Gui/Diagram/CommentShape.h>
#include <Gui/Diagram/PackageShape.h>

#include <QtCore/QFile>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_GC

XmlReader::XmlReader() {

}

void XmlReader::loadFromXml(QuGD::Diagram* diagram, const QString& path)
        throw(QuLC::ParseException) {
    QFile file(path);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
         throw QuLC::ParseException(qPrintable("Error while reading file " +
                path + ": " + file.errorString()));
    }

    QString errorStr;
    int errorLine;
    int errorColumn;

    QDomDocument doc;
    if (!doc.setContent(&file, false, &errorStr, &errorLine,
                        &errorColumn)) {
        throw QuLC::ParseException(qPrintable(
                "Error while loading file: XML Parse error at " +
                 QString::number(errorLine) + ":" +
                 QString::number(errorColumn) + ": " +
                 errorStr));
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != "quml") {
        throw QuLC::ParseException("File is not a Qumulus UML diagram");
    }

    if(root.attribute("version", "0") != "1") {
        throw QuLC::ParseException(
            "File is from a different version of Qumulus");
    }

    QDomElement modelElem = root.firstChild().toElement();
    QDomElement diagElem = modelElem.nextSibling().toElement();

    if(modelElem.isNull() || diagElem.isNull() ||
            modelElem.tagName() != "model" ||
            diagElem.tagName() != "diagram") {
        throw QuLC::ParseException("File contents invalid");
    }

    QuLC::XmlModelReader r(modelElem);

    r.loadFromXml();

    diagram->setRootPackage(r.rootPackage());
    diagram->setComments(r.comments());

    readDiagram(diagram, diagElem);

}

void XmlReader::readDiagram(QuGD::Diagram* diagram, QDomElement e)
        throw(QuLC::ParseException) {
    QDomNodeList children = e.childNodes();
    for(int i = 0; i < children.size(); ++i) {
        QDomElement node = children.at(i).toElement();
        QuGD::DiagramElement* diagelem = nullptr;

        if(node.tagName() == "Class") {
            auto m = dynamic_cast<QuUK::Class*>(
                    QuUK::Element::byId(node.attribute("modelelement")));
            diagelem = new QuGD::ClassShape(m, diagram);
        } else if(node.tagName() == "Enumeration") {
            auto m = dynamic_cast<QuUK::Enumeration*>(
                    QuUK::Element::byId(node.attribute("modelelement")));
            diagelem = new QuGD::EnumShape(m, diagram);
        } else if(node.tagName() == "PrimitiveType") {
            auto m = dynamic_cast<QuUK::PrimitiveType*>(
                    QuUK::Element::byId(node.attribute("modelelement")));
            diagelem = new QuGD::PrimitiveShape(m, diagram);
        } else if(node.tagName() == "Comment") {
            auto m = dynamic_cast<QuUK::Comment*>(
                    QuUK::Element::byId(node.attribute("modelelement")));
            diagelem = new QuGD::CommentShape(m, diagram);
        } else if(node.tagName() == "Package") {
            auto m = dynamic_cast<QuUK::Package*>(
                    QuUK::Element::byId(node.attribute("modelelement")));
            diagelem = new QuGD::PackageShape(m, diagram);
        }

        if(auto s = dynamic_cast<QuGD::Shape*>(diagelem)) {
            s->setPos(node.attribute("x").toFloat(),
                    node.attribute("y").toFloat());
            s->resize(node.attribute("width").toFloat(),
                    node.attribute("height").toFloat());
            s->setVisible(node.attribute("visible") == "true");
        }

        if(!diagelem)
            throw QuLC::ParseException(qPrintable("Unknown diagram element " +
                    node.tagName()));

        diagram->addElement(diagelem);
    }
}
QUML_END_NAMESPACE_GC
