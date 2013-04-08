/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "Nyi.h"

#include <QtWidgets/QMessageBox>

QuLC::NyiHandler* QuLC::NyiHandler::gDefaultNyiHandler = 
        new QuGC::GuiNyiHandler;

QUML_BEGIN_NAMESPACE_GC

void GuiNyiHandler::handleNyi(const char* file, unsigned line, 
        const char* func) const {
    QMessageBox::warning(0, QString("Not Yet Implemented"), 
            QString("%1 @ %2:%3")
                .arg(func)
                .arg(file)
                .arg(line)
            );
}

QUML_END_NAMESPACE_GC
