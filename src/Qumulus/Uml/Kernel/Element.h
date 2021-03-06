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

#ifndef QUMULUS_UML_KERNEL_ELEMENT_H_
#define QUMULUS_UML_KERNEL_ELEMENT_H_

#include "internal_base.h"

#include <Lib/Core/Clonable.h>
#include <Lib/Core/Nyi.h>
#include <Lib/Core/Functional.h>
#include <Lib/Core/UniqueId.h>
#include <Lib/Core/Signal.h>
#include <Lib/Core/XmlModelReader.h>

#include <QtCore/QSet>
#include <QtCore/QList>
#include <QtCore/QString>
#include <QtCore/QObject>

class QXmlStreamWriter;

QUML_BEGIN_NAMESPACE_UK

class Comment;

/**
 * Element is the base class for all UML elements
 */
class Element : public QuLC::Clonable {
public:
    Element();
    Element(const Element& other);

    virtual ~Element();

    /**
     * Returns the parent element, or @c nullptr if there is no parent.
     *
     * Individual subclasses of Element give meaning to what their parent is.
     */
    virtual Element* parent() const { return nullptr; }

    /**
     * Gets the index relative to the parent, or -1 if there is no parent
     */
    virtual int index() const = 0;

    /**
     * Returns the amount of children this Element has
     *
     * @return The amount of children of this element.
     */
    virtual size_t size() const = 0;

    /**
     * Returns the child at the given index.
     *
     * @return The child at the given index.
     */

    virtual Element* operator[](size_t idx) const = 0;

    /**
     * Returns whether this element is top-level (and therefore has no parent).
     */
    virtual bool isTopLevel() const { return false; };

    /**
     * Returns the icon to be displayed in the sidebar.
     */
    virtual QString sidebarIcon() const = 0;

    /**
     * Returns the text to be displayed in the sidebar.
     */
    virtual QString sidebarText() const = 0;

    /**
     * Returns the unique ID associated with this Element.
     */
    QString uniqueId() const;

    /**
     * Sets the unique ID of this element.
     *
     * This is an internal function and should not be called from user code!
     */
    void setUniqueId(const QString& s);

    /**
     * Returns the Element with a given unique ID.
     */
    static Element* byId(const QString& s);

    virtual void writeXml(QXmlStreamWriter& writer) const = 0;
    virtual void readXml(QDomElement node, QuLC::XmlModelReader& reader) = 0;

    QUML_CLONABLE_ABSTRACT(Element)
public:

    /**
     * Emitted whenever the element changes.
     */
    QuLC::Signal<void()> elementChanged;

    /**
     * Emitted whenever the element or any of its children changes.
     */
    QuLC::Signal<void()> childElementChanged;
private:
    static QHash<QString, Element*> mElementsById;
    QuLC::UniqueId mUniqueId;
};

QUML_END_NAMESPACE_UK

#endif /* QUMULUS_UML_KERNEL_ELEMENT_H_ */

