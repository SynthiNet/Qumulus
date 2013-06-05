/*
 * Qumulus UML editor
 * Author: Frank Erens
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_SIDEBAR_H_
#define GUI_WIDGETS_SIDEBAR_H_

#include "internal_base.h"
#include <QtWidgets/QTreeView>
#include <Gui/Core/SideBarModel.h>
#include <Gui/Widgets/StyleType.h>
#include <Gui/Diagram/Diagram.h>
#include <Lib/Core/Ptr.h>

QUML_BEGIN_NAMESPACE_GW

class MainWindow;

class SideBar : public QTreeView {
    Q_OBJECT

public:
    SideBar(MainWindow* w, QuGD::Diagram* diagram);
    ~SideBar();
    MainWindow* window();
    QuGD::Diagram* diagram() const { return mDiagram; }

#ifdef Q_OS_MAC
    void setStyleType(StyleType s);
#endif
private:
    QuGD::Diagram* mDiagram;
    QuGC::SideBarModel* mModel;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_SIDEBAR_H_ */

