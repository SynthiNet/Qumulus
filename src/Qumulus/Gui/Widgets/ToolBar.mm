#include "ToolBar.h"

#include <QtMacExtras/QMacNativeWidget>

#include <QtGui/QGuiApplication>
#include <qpa/qplatformnativeinterface.h>

#import <AppKit/AppKit.h>

QUML_BEGIN_NAMESPACE_GW

QAction* ToolBar::addWidget(ToolBarItem* item) {
//    QMacNativeWidget widget = new QMacNativeWidget();
//    NSView* view = static_cast<NSView*>(
//            QGuiApplication::platformNativeInterface()->nativeResourceForWindow(
//            "nsview", );

}

QUML_END_NAMESPACE_GW

// vim: ft=objcpp
