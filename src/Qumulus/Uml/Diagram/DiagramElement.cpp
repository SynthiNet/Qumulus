/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "DiagramElement.h"

QUML_BEGIN_NAMESPACE_UD

DiagramElement::DiagramElement() : mVisible(true) {

}

const QString& DiagramElement::property(const QString& key) const {
    return mProperties.at(key);
}

QString& DiagramElement::property(const QString& key) {
    return mProperties.at(key);
}

QUML_END_NAMESPACE_UD

