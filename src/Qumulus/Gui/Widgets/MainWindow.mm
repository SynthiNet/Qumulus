#include "MainWindow.h"

#include <QtGui/QGuiApplication>
#include <qpa/qplatformnativeinterface.h>

#import <AppKit/AppKit.h>

QUML_BEGIN_NAMESPACE_GW

void MainWindow::setContentBorderOnMac() {
    NSWindow* macWindow = static_cast<NSWindow*>(
        QGuiApplication::platformNativeInterface()->nativeResourceForWindow(
            "nswindow", this->windowHandle()));

    [macWindow setContentBorderThickness: 16 forEdge: NSMinYEdge];
}

QUML_END_NAMESPACE_GW

// vim: ft=objcpp
