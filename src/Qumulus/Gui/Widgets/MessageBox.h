/*
 * Qumulus UML editor
 * Author: Frank Erens
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

