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

#ifndef GUI_WIDGETS_POPOVERCOMMENT_H_
#define GUI_WIDGETS_POPOVERCOMMENT_H_

#include "internal_base.h"
#include "PopoverForm.h"
#include <Uml/Kernel/Comment.h>
#include <Gui/Diagram/CommentShape.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QUML_BEGIN_NAMESPACE_GW

class PopoverComment : public QWidget, public PopoverForm {
public:
    QVBoxLayout* verticalLayout_4;
    QPlainTextEdit* commentField;

    void setupUi() {
        if(objectName().isEmpty())
            setObjectName(QStringLiteral("Form"));

        resize(349, 218);
        verticalLayout_4 = new QVBoxLayout(this);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 12);
        commentField = new QPlainTextEdit(this);
        commentField->setObjectName(QStringLiteral("commentField"));

        verticalLayout_4->addWidget(commentField);


        retranslateUi();

        QMetaObject::connectSlotsByName(this);
    }

    void retranslateUi() {
        setWindowTitle(QApplication::translate("Form", "Form", 0));
        commentField->setPlainText(QString());
    }

    bool isInFocus() override {
        return commentField->hasFocus();
    }

    void bindModel(QuGD::Shape* s) {
        s = dynamic_cast<QuGD::CommentShape*>(s);
        commentField->setPlainText(dynamic_cast<QuUK::Comment*>(
                    s->modelElement())->body());
        connect(commentField, &QPlainTextEdit::textChanged, [s,this]{
            dynamic_cast<QuUK::Comment*>(
                s->modelElement())->setBody(this->commentField->toPlainText());
            s->update();
        });
    }
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_POPOVERCOMMENT_H_ */

