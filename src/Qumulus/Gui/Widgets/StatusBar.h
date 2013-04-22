/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_STATUSBAR_H_
#define GUI_WIDGETS_STATUSBAR_H_

#include "internal_base.h"
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QSpacerItem>
#include <Gui/Widgets/StyleType.h>
#include <Gui/Widgets/ZoomSlider.h>
#include <Gui/Widgets/Spacer.h>

QUML_BEGIN_NAMESPACE_GW

class MainWindow;

class StatusBar : public QStatusBar {
    Q_OBJECT

public:
    StatusBar(QWidget* parent = 0);
    MainWindow* window();
    ZoomSlider* slider() { return mZoom; }

#ifdef Q_OS_MAC
    void setStyleType(StyleType s);
#endif

private:
    ZoomSlider* mZoom;
    Spacer* mSpacer;
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_STATUSBAR_H_ */

