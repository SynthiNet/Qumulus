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

#ifndef GUI_WIDGETS_POPOVERCLASS_H_
#define GUI_WIDGETS_POPOVERCLASS_H_

#include "internal_base.h"
#include "PopoverForm.h"
#include <Uml/Kernel/NamedElement.h>
#include <Gui/Diagram/ClassShape.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QUML_BEGIN_NAMESPACE_GW

class PopoverClass : public QWidget, public PopoverForm {
public:
    QVBoxLayout* verticalLayout_4;
    QFormLayout* formLayout;
    QLabel* nameLabel;
    QLineEdit* nameField;
    QFrame* line_2;
    QHBoxLayout* horizontalLayout_5;
    QCheckBox* abstractButton;
    QCheckBox* finalButton;

    void setupUi() {
        if(objectName().isEmpty())
            setObjectName(QStringLiteral("Form"));

        resize(277, 81);
        verticalLayout_4 = new QVBoxLayout(this);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 12);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        nameLabel = new QLabel(this);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameField = new QLineEdit(this);
        nameField->setObjectName(QStringLiteral("nameField"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameField);


        verticalLayout_4->addLayout(formLayout);

        line_2 = new QFrame(this);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        abstractButton = new QCheckBox(this);
        abstractButton->setObjectName(QStringLiteral("abstractButton"));

        horizontalLayout_5->addWidget(abstractButton);

        finalButton = new QCheckBox(this);
        finalButton->setObjectName(QStringLiteral("finalButton"));

        horizontalLayout_5->addWidget(finalButton);


        verticalLayout_4->addLayout(horizontalLayout_5);


        retranslateUi();

        QMetaObject::connectSlotsByName(this);
    }

    void retranslateUi() {
        setWindowTitle(QApplication::translate("Form", "Form", 0));
        nameLabel->setText(QApplication::translate("Form", "Name", 0));
        abstractButton->setText(QApplication::translate("Form", "abstract", 0));
        finalButton->setText(QApplication::translate("Form", "final", 0));
    }

    bool isInFocus() override {
        return
            nameLabel->hasFocus() ||
            nameField->hasFocus() ||
            line_2->hasFocus() ||
            abstractButton->hasFocus() ||
            finalButton->hasFocus();
    }

    void bindModel(QuGD::Shape* s) {
        s = dynamic_cast<QuGD::ClassShape*>(s);
        nameField->setText(dynamic_cast<QuUK::NamedElement*>(
                    s->modelElement())->name());
        connect(nameField, &QLineEdit::textEdited, [s](const QString& str){
                dynamic_cast<QuUK::NamedElement*>(
                    s->modelElement())->setName(str);
                    s->update();
                });

        abstractButton->setCheckState(dynamic_cast<QuUK::Class*>(
                    s->modelElement())->abstract() ? Qt::Checked : Qt::Unchecked);
        connect(abstractButton, &QCheckBox::stateChanged, [s](int state){
                dynamic_cast<QuUK::Class*>(
                    s->modelElement())->setAbstract(state == Qt::Checked);
                    s->update();
                });

        finalButton->setCheckState(dynamic_cast<QuUK::Class*>(
                    s->modelElement())->final() ? Qt::Checked : Qt::Unchecked);
        connect(finalButton, &QCheckBox::stateChanged, [s](int state){
                dynamic_cast<QuUK::Class*>(
                    s->modelElement())->setFinal(state == Qt::Checked);
                    s->update();
                });
    }
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_POPOVERCLASS_H_ */

