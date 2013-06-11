/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "XmlReader.h"

#include <Lib/Core/XmlModelReader.h>
#include <Gui/Diagram/Diagram.h>

#include <QtCore/QFile>

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
}

QUML_END_NAMESPACE_GC
