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

#include "XmlModelReader.h"

#include <Uml/Kernel/Package.h>
#include <Uml/Kernel/Comment.h>
#include <Uml/Kernel/PrimitiveType.h>
#include <Uml/Kernel/Class.h>
#include <Uml/Kernel/Operation.h>
#include <Uml/Kernel/Parameter.h>
#include <Uml/Kernel/Property.h>
#include <Uml/Kernel/Enumeration.h>
#include <Uml/Kernel/EnumerationLiteral.h>
#include <Uml/Kernel/Generalization.h>
#include <Uml/Kernel/Association.h>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_LC

XmlModelReader::XmlModelReader(const QDomElement& rootNode) :
        mRootNode(rootNode),
        mRootPackage(new QuUK::Package()){
    mRootPackage->setRootPackage(true);
}

void XmlModelReader::loadFromXml() throw(QuLC::ParseException) {
    QDomNodeList children = mRootNode.childNodes();
    for(int i = 0; i < children.size(); ++i) {
        if(children.at(i).isElement()) {
            auto x = children.at(i).toElement();
            QuUK::Element* e = loadElement(x);

            if(isPackagable(x.tagName())) {
                dynamic_cast<QuUK::PackageableElement*>(e)->setPackage(
                        mRootPackage);
            } else {
                if(x.tagName() == "Comment") {
                    mComments.append(static_cast<QuUK::Comment*>(e));
                } else if(x.tagName() == "Association") {
                    mAssociations.append(static_cast<QuUK::Association*>(e));
                } else {
                    throw QuLC::ParseException(
                            qPrintable("Unknown tag " + x.tagName()));
                }
            }
        }
    }
}

void XmlModelReader::ensureLoaded(QString uniqueid) {
    if(uniqueid == "") return;

    if(!QuUK::Element::byId(uniqueid)) {
        auto x = elementById(mRootNode, uniqueid);
        ensureLoaded(x.parentNode().toElement().attribute("id"));
        loadElement(x.toElement());
    }
}

QDomElement XmlModelReader::elementById(QDomElement e, QString id) const {
    QDomNodeList children = e.childNodes();
    for(int i = 0; i < children.size(); ++i) {
        if(children.at(i).isElement()) {
            auto x = children.at(i).toElement();
            if(x.hasAttribute("id") && x.attribute("id") == id) {
                return x;
            } else if(x.hasChildNodes()) {
                auto y = elementById(x, id);
                if(!y.isNull()) return y;
            }
        }
    }

    return QDomElement();
}

QuUK::Element* XmlModelReader::loadElement(QDomElement e) {
    QString tn = e.tagName();
    QuUK::Element* element = nullptr;

    if(tn == "Package") {
        element = new QuUK::Package();
    } else if(tn == "Comment") {
        element = new QuUK::Comment();
    } else if(tn == "PrimitiveType") {
        element = new QuUK::PrimitiveType();
    } else if(tn == "Class") {
        element = new QuUK::Class();
    } else if(tn == "Operation") {
        element = new QuUK::Operation("");
    } else if(tn == "Parameter") {
        element = new QuUK::Parameter("");
    } else if(tn == "Property") {
        element = new QuUK::Property("");
    } else if(tn == "Enumeration") {
        element = new QuUK::Enumeration();
    } else if(tn == "Literal") {
        element = new QuUK::EnumerationLiteral();
    } else if(tn == "Generalization") {
        element = new QuUK::Generalization();
    } else if(tn == "Association") {
        element = new QuUK::Association();
    }

    if(element == nullptr)
        throw QuLC::ParseException(qPrintable("Unknown diagram element " +
                e.tagName()));

    element->readXml(e, *this);

    return element;
}

bool XmlModelReader::isPackagable(QString name) const {
    return name == "Package" ||
        name == "PrimitiveType" ||
        name == "Enumeration" ||
        name == "Class";
}

QUML_END_NAMESPACE_LC
