/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef GUI_CORE_XMLREADER_H_
#define GUI_CORE_XMLREADER_H_

#include "internal_base.h"

#include <Lib/Core/Exception.h>
#include <Gui/Diagram/internal_base.h>

#include <QtCore/QString>
#include <QtXml/QDomElement>

QUML_BEGIN_NAMESPACE_GD
class Diagram;
QUML_END_NAMESPACE_GD

QUML_BEGIN_NAMESPACE_GC

class XmlReader {
public:
    XmlReader();

    void loadFromXml(QuGD::Diagram* diagram, const QString& path)
            throw(QuLC::ParseException);

    void readDiagram(QuGD::Diagram* diagram, QDomElement e)
            throw(QuLC::ParseException);
private:
};

QUML_END_NAMESPACE_GC

#endif /* GUI_CORE_XMLREADER_H_ */

