/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#ifndef UML_DIAGRAM_STYLE_H_
#define UML_DIAGRAM_STYLE_H_

#include "internal_base.h"

#include <QtCore/QHash>
#include <QtCore/QString>

QUML_BEGIN_NAMESPACE_UD

class Style : public QHash<QString, QString> {
    QString fontName() const { return (*this)["fontName"]; }
    void setFontName(QString s) { (*this)["fontName"] = s; }

    double fontSize() const { return (*this)["fontSize"].toDouble(); }
    void setFontSize(double d) { (*this)["fontSize"] = QString::number(d); }
};

QUML_END_NAMESPACE_UD

#endif /* UML_DIAGRAM_STYLE_H_ */

