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

