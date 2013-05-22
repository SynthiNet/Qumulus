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

#include <QtGui/QFont>
#include <QtGui/QFontMetrics>

QUML_BEGIN_NAMESPACE_GD

class Style : public QHash<QString, QString> {
public:
    QString fontName() const { return (*this)["fontName"]; }
    void setFontName(QString s) { (*this)["fontName"] = s; }

    double fontSize() const { return (*this)["fontSize"].toDouble(); }
    void setFontSize(double d) { (*this)["fontSize"] = QString::number(d); }

    QFont font() const { return QFont(fontName(), fontSize()); }
};

QUML_END_NAMESPACE_GD

#endif /* UML_DIAGRAM_STYLE_H_ */

