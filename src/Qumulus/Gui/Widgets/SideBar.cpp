/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#include "SideBar.h"
#include <Gui/Widgets/MainWindow.h>

QUML_BEGIN_NAMESPACE_GW

SideBar::SideBar(QWidget* parent) : QTreeView(parent) {}
    
void SideBar::setWindow(MainWindow* w) {
    mWindow = w;
}
    
MainWindow* SideBar::window() {
    return mWindow;
}

#ifdef Q_OS_MAC
void SideBar::setStyleType(StyleType s) {
    switch(s) {
    case StyleType::Active:
        setStyleSheet(
            "background-color: qlineargradient("
                    "spread:pad, x1:0, y1:0, x2:0, y2:1,"
                    "stop:0 rgba(232, 236, 241, 255),"
                    "stop:1 rgba(209,216,226, 255));"
            "selection-color: white;"
            "selection-background-color: qlineargradient("
                    "x1: 0, y1: 0, x2: 0, y2: 1,"
                    "stop: 0 rgb(110, 165, 218),"
                    "stop: 1 rgb(33, 108, 183));"
            "border-top: 1px solid silver;"
            "border-bottom: 1px solid silver;"
        );
        break;
    case StyleType::Inactive:
        setStyleSheet(
            "background-color: qlineargradient("
            "spread:pad, x1:0, y1:0, x2:0, y2:1,"
            "stop:0 rgba(247, 247, 247, 255),"
            "stop:1 rgba(235, 235, 235, 255));"
            "selection-color: white;"
            "selection-background-color: qlineargradient("
                    "x1: 0, y1: 0, x2: 0, y2: 1,"
                    "stop: 0 rgb(110, 165, 218),"
                    "stop: 1 rgb(33, 108, 183));"
            "border-top: 1px solid silver;"
            "border-bottom: 1px solid silver;"
        );
        break;
    }
}
#endif

QUML_END_NAMESPACE_GW

