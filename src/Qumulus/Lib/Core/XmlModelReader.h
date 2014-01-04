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

#ifndef LIB_CORE_XMLMODELREADER_H_
#define LIB_CORE_XMLMODELREADER_H_

#include "internal_base.h"

#include "Exception.h"

#include <Uml/Kernel/internal_base.h>

#include <QtCore/QList>
#include <QtXml/QDomElement>
#include <QtXml/QDomNode>

QUML_BEGIN_NAMESPACE_UK

class Element;
class Package;
class Comment;
class Association;

QUML_END_NAMESPACE_UK

QUML_BEGIN_NAMESPACE_LC

class XmlModelReader {
public:
    XmlModelReader(const QDomElement& rootNode);

    void loadFromXml() throw(QuLC::ParseException);

    void ensureLoaded(QString uniqueid);

    QuUK::Package* rootPackage() const { return mRootPackage; }
    QList<QuUK::Comment*> comments() const { return mComments; }
    QList<QuUK::Association*> associations() const { return mAssociations; }

    QuUK::Element* loadElement(QDomElement e);
private:
    QDomElement elementById(QDomElement parent, QString id) const;

    bool isPackagable(QString name) const;

private:
    QDomElement mRootNode;
    QuUK::Package* mRootPackage;
    QList<QuUK::Comment*> mComments;
    QList<QuUK::Association*> mAssociations;
};

QUML_END_NAMESPACE_LC

#endif /* LIB_CORE_XMLMODELREADER_H_ */

