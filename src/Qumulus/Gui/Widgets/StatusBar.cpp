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

#include "StatusBar.h"
#include <Gui/Widgets/MainWindow.h>

#include <QtGui/QMouseEvent>

QUML_BEGIN_NAMESPACE_GW

StatusBar::StatusBar(QWidget* parent) : QStatusBar(parent),
#ifdef Q_OS_MAC
    mZoom(new ZoomSlider()), mZoomBox(new QComboBox()),
    mSpacer(new QWidget(this)) {
    setSizeGripEnabled(false);
    setStyleType(StyleType::Active);

    mSpacer->setStyleSheet("border: 0; background: transparent;");
    mSpacer->setMinimumWidth(5);
#else
    mZoom(new ZoomSlider()), mZoomBox(new QComboBox(this)) {
#endif
    setFixedHeight(24);
    addPermanentWidget(mZoomBox);
    mZoomBox->addItems({"25 %", "50 %", "75 %", "100 %",
            "200 %", "300 %", "400 %"});
    mZoomBox->setCurrentIndex(3);
    mZoomBox->setMaximumWidth(75);
    addPermanentWidget(mZoom);
#ifdef Q_OS_MAC
    addPermanentWidget(mSpacer);
#endif

    connect(mZoomBox,
            static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            [&](int value){mZoom->setValue(value);});
    connect(mZoom,
            &ZoomSlider::valueChanged,
            [&](int value){mZoomBox->setCurrentIndex(value);});
}

MainWindow* StatusBar::window() {
    return static_cast<MainWindow*>(parent());
}

#ifdef Q_OS_MAC
void StatusBar::setStyleType(StyleType s) {
    switch(s) {
    case StyleType::Active:
        setStyleSheet(
            "QStatusBar {"
            "border-top: 1px solid #828282;"
            "background-color: qlineargradient("
                    "x1: 0, y1: 0, x2: 0, y2: 1,"
                    "stop: 0 rgb(212, 212, 212),"
                    "stop: 1 rgb(176, 176, 176));}"
        );
        break;
    case StyleType::Inactive:
        setStyleSheet(
            "QStatusBar {"
            "border-top: 1px solid #B2B2B2;"
            "background-color: qlineargradient("
                    "x1: 0, y1: 0, x2: 0, y2: 1,"
                    "stop: 0 rgb(237, 237, 237),"
                    "stop: 1 rgb(224, 224, 224));}"
        );
        break;
    }
}
#endif

#ifdef Q_OS_MAC
void StatusBar::mouseMoveEvent(QMouseEvent *event) {
     if(event->buttons() & Qt::LeftButton) {
         window()->move(event->globalPos() - mDragPosition);
         event->accept();
     }
}

void StatusBar::mousePressEvent(QMouseEvent *event) {
     if(event->button() == Qt::LeftButton) {
         mDragPosition = event->globalPos() -
                window()->frameGeometry().topLeft();
         event->accept();
     }
}

#endif

QUML_END_NAMESPACE_GW

