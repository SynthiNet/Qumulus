/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_STYLE_H_
#define UML_DIAGRAM_STYLE_H_

#include "internal_base.h"

#include <QtCore/QHash>

QUML_BEGIN_NAMESPACE_UD

class Style : public QHash<QString, QString> {

};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_STYLE_H_ */

