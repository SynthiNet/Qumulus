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

#ifndef GUI_WIDGETS_MESSAGEBOX_H_
#define GUI_WIDGETS_MESSAGEBOX_H_

#include "internal_base.h"

#include <QtWidgets/QMessageBox>

QUML_BEGIN_NAMESPACE_GW

namespace MessageBox {
    void critical(QWidget* parent, const QString& title, const QString& text);
    void info(QWidget* parent, const QString& title, const QString& text);
    void warning(QWidget* parent, const QString& title, const QString& text);
}

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_MESSAGEBOX_H_ */

