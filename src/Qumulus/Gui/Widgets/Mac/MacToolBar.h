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

#ifndef GUI_WIDGETS_MAC_MACTOOLBAR_H_
#define GUI_WIDGETS_MAC_MACTOOLBAR_H_

#include <Gui/Widgets/ToolBar.h>

#include <QtCore/QList.h>

QUML_BEGIN_NAMESPACE_GW

namespace Mac {

class MacToolBar : public ToolBar {
public:
    MacToolBar(QObject* o);
    ~MacToolBar();

    void showInWindow(MainWindow* w) override;

    void addWidget(ToolBarItem* item) override;
    void addSeparator() override;

    const QList<ToolBarItem*>& toolBarItems() const { return mToolBarItems; }
private:
    QList<ToolBarItem*> mToolBarItems;
};

};

QUML_END_NAMESPACE_GW


#endif /* GUI_WIDGETS_MAC_MACTOOLBAR_H_ */

