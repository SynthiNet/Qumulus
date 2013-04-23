#include "ToolBar.h"

#import <AppKit/AppKit.h>

QUML_BEGIN_NAMESPACE_GW

#if 0
void ToolBar::addWidget(ToolBarItem* item) {
    NSToolbar* macToolbar = nativeToolbar();
    NSView* macView = item->nativeView();

    NSToolBarItem* item = [[NSToolBarItem alloc] autorelease];
    [item setView: macView];
}
#endif

QUML_END_NAMESPACE_GW

// vim: ft=objcpp
