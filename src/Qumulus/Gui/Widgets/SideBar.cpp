/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#include "SideBar.h"
#include <Gui/Widgets/MainWindow.h>

#include <QtWidgets/QHeaderView>

#include <iostream>

QUML_BEGIN_NAMESPACE_GW

SideBar::SideBar(MainWindow* parent, QuGD::Diagram* d) :
        QTreeView(parent),
        mDiagram(d),
        mModel(new QuGC::SideBarModel(mDiagram)){
#ifdef Q_OS_MAC
    setStyleType(StyleType::Active);
    setAttribute(Qt::WA_MacShowFocusRect, false);
    setAnimated(true);
#endif
    setMinimumWidth(100);
    QSizePolicy sideBarSizePolicy = sizePolicy();
    sideBarSizePolicy.setHorizontalPolicy(QSizePolicy::Minimum);
    setSizePolicy(sideBarSizePolicy);
    setModel(mModel);
    header()->close();
}

SideBar::~SideBar() {
    delete mModel;
}

MainWindow* SideBar::window() {
    return static_cast<MainWindow*>(parent());
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
            "font-size: 11pt;"
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
            "font-size: 11pt;"
        );
        break;
    }

}
#endif

QUML_END_NAMESPACE_GW

