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
#include <QtWidgets/QComboBox>
#include <Gui/Widgets/StyleType.h>
#include <Gui/Widgets/ZoomSlider.h>

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

protected:
#ifdef Q_OS_MAC
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
#endif

private:
    ZoomSlider* mZoom;
    QComboBox* mZoomBox;
    
#ifdef Q_OS_MAC
    QWidget* mSpacer;
    QPoint mDragPosition;
#endif
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_STATUSBAR_H_ */

