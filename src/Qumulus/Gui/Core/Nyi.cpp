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

#include "Nyi.h"

#include <QtWidgets/QMessageBox>

QuLC::NyiHandler* QuLC::NyiHandler::gDefaultNyiHandler =
        new QuGC::GuiNyiHandler;

QUML_BEGIN_NAMESPACE_GC

void GuiNyiHandler::handleNyi(const char* file, unsigned line,
        const char* func) const {
#ifdef Q_OS_MAC
    QMessageBox warning(QMessageBox::Warning, "", "Not Yet Implemented");

    warning.setInformativeText(
            QString("%1 @ %2:%3")
                .arg(func)
                .arg(file)
                .arg(line)
            );
    warning.exec();
#else
    QMessageBox::warning(0, QString("Not Yet Implemented"),
            QString("%1 @ %2:%3")
                .arg(func)
                .arg(file)
                .arg(line)
            );
#endif
}

QUML_END_NAMESPACE_GC
