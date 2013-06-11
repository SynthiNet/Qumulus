/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "XmlModelReader.h"

#include <Uml/Kernel/Package.h>
#include <Uml/Kernel/Comment.h>
#include <Uml/Kernel/PrimitiveType.h>
#include <Uml/Kernel/Class.h>
#include <Uml/Kernel/Operation.h>
#include <Uml/Kernel/Property.h>
#include <Uml/Kernel/Enumeration.h>
#include <Uml/Kernel/EnumerationLiteral.h>
#include <Uml/Kernel/Generalization.h>
#include <Uml/Kernel/Association.h>

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

        // LOAD ELEMENT HERE?
    }
}

QDomElement XmlModelReader::elementById(QDomElement e, QString id) const {
    QDomNodeList children = e.childNodes();
    for(int i = 0; i < children.size(); ++i) {
        if(children.at(i).isElement()) {
            auto x = children.at(i).toElement();
            if(x.hasAttribute("id") && x.attribute("id") == id) {
                return x;
            } else if(e.hasChildNodes()) {
                auto y = elementById(e, id);
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
    } else if(tn == "Attribute") {
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

    if(!element)
        throw QuLC::ParseException(qPrintable("Unknown diagram element " +
                node.tagName()));

    element->readXml(e, *this);

    return element;
}

bool XmlModelReader::isPackagable(QString name) const {
    return name == "Package" ||
        name == "Primitive" ||
        name == "Enumeration" ||
        name == "Class";
}

QUML_END_NAMESPACE_LC
