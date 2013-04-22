/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_ZOOMSLIDER_H_
#define GUI_WIDGETS_ZOOMSLIDER_H_

#include "internal_base.h"
#include <QtWidgets/QSlider>

QUML_BEGIN_NAMESPACE_GW

class ZoomSlider : public QSlider {
    Q_OBJECT

public:
    ZoomSlider(QWidget* parent = 0);
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_ZOOMSLIDER_H_ */

