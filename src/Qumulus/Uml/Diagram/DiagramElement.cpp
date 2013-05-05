/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "DiagramElement.h"

QUML_BEGIN_NAMESPACE_UD

DiagramElement::DiagramElement() : mVisible(true) {

}

QString DiagramElement::property(const QString& key) const {
    return mProperties[key];
}

QString& DiagramElement::property(const QString& key) {
    return mProperties[key];
}

QUML_END_NAMESPACE_UD

