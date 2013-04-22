/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "StatusBar.h"
#include <Gui/Widgets/MainWindow.h>

QUML_BEGIN_NAMESPACE_GW

StatusBar::StatusBar(QWidget* parent) : QStatusBar(parent) {
#ifdef Q_OS_MAC
    setSizeGripEnabled(false);
    setStyleType(StyleType::Active);
#endif
}

MainWindow* StatusBar::window() {
    return static_cast<MainWindow*>(parent());
}

#ifdef Q_OS_MAC
void StatusBar::setStyleType(StyleType s) {
    switch(s) {
    case StyleType::Active:
        setStyleSheet(
            "border-top: 1px solid #828282;"
            "background-color: qlineargradient("
                    "x1: 0, y1: 0, x2: 0, y2: 1,"
                    "stop: 0 rgb(212, 212, 212),"
                    "stop: 1 rgb(176, 176, 176));"
        );
        break;
    case StyleType::Inactive:
        setStyleSheet(
            "border-top: 1px solid #B2B2B2;"
            "background-color: qlineargradient("
                    "x1: 0, y1: 0, x2: 0, y2: 1,"
                    "stop: 0 rgb(237, 237, 237),"
                    "stop: 1 rgb(224, 224, 224));"
        );
        break;
    }
}
#endif

QUML_END_NAMESPACE_GW

