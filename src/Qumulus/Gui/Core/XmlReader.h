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

