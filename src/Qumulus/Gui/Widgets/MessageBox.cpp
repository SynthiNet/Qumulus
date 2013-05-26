/*
 * Qumulus UML editor
 * Author: Frank Erens
 *
 */

#include "MessageBox.h"

QUML_BEGIN_NAMESPACE_GW

namespace MessageBox {

void critical(QWidget* parent, const QString& title, const QString& text) {
#ifdef Q_OS_MAC
    QMessageBox box(QMessageBox::Critical, "", title, 
            QMessageBox::Ok, parent);
    box.setInformativeText(text);
    box.exec();
#else
    QMessageBox box(QMessageBox::Critical, title, text, 
            QMessageBox::Ok, parent);
    box.exec();
#endif
}

void info(QWidget* parent, const QString& title, const QString& text) {
#ifdef Q_OS_MAC
    QMessageBox box(QMessageBox::Information, "", title, 
            QMessageBox::Ok, parent);
    box.setInformativeText(text);
    box.exec();
#else
    QMessageBox box(QMessageBox::Information, title, text, 
            QMessageBox::Ok, parent);
    box.exec();
#endif
}

void warning(QWidget* parent, const QString& title, const QString& text) {
#ifdef Q_OS_MAC
    QMessageBox box(QMessageBox::Warning, "", title, 
            QMessageBox::Ok, parent);
    box.setInformativeText(text);
    box.exec();
#else
    QMessageBox box(QMessageBox::Warning, title, text, 
            QMessageBox::Ok, parent);
    box.exec();
#endif
}

}

QUML_END_NAMESPACE_GW


