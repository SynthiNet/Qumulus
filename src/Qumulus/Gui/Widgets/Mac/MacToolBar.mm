/*
 * Qumulus UML editor
 * Copyright (c) 2014 Frank Erens <frank@synthi.net>
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
 */

#include "MacToolBar.h"

#include <Gui/Widgets/MainWindow.h>

#include <QtCore/QString>
#include <QtCore/QDebug>
#include <QtWidgets/QMacNativeWidget>

#include <Cocoa/Cocoa.h>

using QuGW::Mac::MacToolBar;

NSString* QString2NSString(const QString& ref) {
    return [NSString stringWithUTF8String: ref.toUtf8().data()];
}

QString NSString2QString(NSString* ptr) {
    return [ptr UTF8String];
}

@interface ToolbarController : NSWindowController <NSToolbarDelegate> {
    void* macToolBar;
}

    - (void) setMacToolBar: (void*)bar;
@end

@implementation ToolbarController
    
- (void) setMacToolBar: (void*)bar {
    macToolBar = bar;
}


- (NSToolbarItem *)toolbarItemWithIdentifier: (NSString*)identifier
        label: (NSString*)label
        toolTip: (NSString*)toolTip
        paletteLabel: (NSString*)paletteLabel
        view: (NSView*)view {
    NSToolbarItem* item = [[[NSToolbarItem alloc] 
        initWithItemIdentifier: identifier] autorelease];

    [item setLabel: label];
    [item setPaletteLabel: paletteLabel];
    [item setToolTip: toolTip];

    [item setView: view];

    return item;
}

- (NSToolbarItem*) toolbar:(NSToolbar*) toolbar 
        itemForItemIdentifier:(NSString*) itemIdentifier
        willBeInsertedIntoToolbar:(BOOL) flag {
    (void)toolbar;
    (void)flag;

    NSToolbarItem* item = nil;

    for(auto i : static_cast<MacToolBar*>(macToolBar)->toolBarItems()) {

        if(NSString2QString(itemIdentifier) == i->text()) {
            QMacNativeWidget* w = new QMacNativeWidget();
            w->resize(1,1);

            QHBoxLayout* l = new QHBoxLayout(w);
            l->setMargin(0);
            l->setSpacing(0);
            l->addWidget(i);

            w->show();

            return [self
                toolbarItemWithIdentifier: itemIdentifier
                label: itemIdentifier
                toolTip: itemIdentifier
                paletteLabel: itemIdentifier
                view: w->nativeView()];
        }

    }

    return item;
}

- (NSArray*) toolbarDefaultItemIdentifiers:(NSToolbar*) toolbar {
    (void)toolbar;

    NSMutableArray* array = [NSMutableArray arrayWithObjects: nil];

    for(auto i : static_cast<MacToolBar*>(macToolBar)->toolBarItems()) {
        [array addObject: QString2NSString(i->text())];
    }

    return array;
}

- (NSArray*) toolbarAllowedItemIdentifiers:(NSToolbar*) toolbar {
    (void)toolbar;

    std::cerr << "Here!" << std::endl;

    NSMutableArray* array = [NSMutableArray arrayWithObjects:
        NSToolbarSpaceItemIdentifier,
        NSToolbarFlexibleSpaceItemIdentifier,
        NSToolbarPrintItemIdentifier,
        NSToolbarShowColorsItemIdentifier,
        nil];

    for(auto i : static_cast<MacToolBar*>(macToolBar)->toolBarItems()) {
        qDebug() << "Allowed:" << i->text();
        [array addObject: QString2NSString(i->text())];
    }

    return array;
}

- (BOOL) validateToolbarItem:(NSToolbarItem*) theItem {
    (void)theItem;
    return YES;
}

@end

QUML_BEGIN_NAMESPACE_GW

namespace Mac {

MacToolBar::MacToolBar(QObject* parent) : ToolBar(parent) {

}

MacToolBar::~MacToolBar() {

}

void MacToolBar::showInWindow(MainWindow* w) {
    NSWindow* win = [(NSView*)w->winId() window];

    NSToolbar* toolbar = [[[NSToolbar alloc] initWithIdentifier: @"Qumulus"]
        autorelease];
    [toolbar setAllowsUserCustomization: YES];
    [toolbar setAutosavesConfiguration: YES];

    [win setToolbar: toolbar];

    ToolbarController* controller = 
            [[ToolbarController alloc] initWithWindow: win];
    [controller setMacToolBar: this];

    [toolbar setDelegate: controller];
}

void MacToolBar::addWidget(ToolBarItem* item) {
    mToolBarItems.append(item);
}

void MacToolBar::addSeparator() {

}

}

QUML_END_NAMESPACE_GW
