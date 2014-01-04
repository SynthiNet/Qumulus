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

