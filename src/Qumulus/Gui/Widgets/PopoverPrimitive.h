/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_POPOVERPRIMITIVE_H_
#define GUI_WIDGETS_POPOVERPRIMITIVE_H_

#include "internal_base.h"
#include "PopoverForm.h"
#include <Gui/Diagram/PrimitiveShape.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QUML_BEGIN_NAMESPACE_GW

class PopoverPrimitive : public QWidget, public PopoverForm {
public:
    QVBoxLayout* verticalLayout_4;
    QFormLayout* formLayout;
    QLabel* nameLabel;
    QLineEdit* nameField;

    void setupUi() {
        if(objectName().isEmpty())
            setObjectName(QStringLiteral("Form"));

        resize(277, 48);
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


        retranslateUi();

        QMetaObject::connectSlotsByName(this);
    }

    void retranslateUi() {
        setWindowTitle(QApplication::translate("Form", "Form", 0));
        nameLabel->setText(QApplication::translate("Form", "Name", 0));
    }

    bool isInFocus() override {
        return nameField->hasFocus();
    }

    void bindModel(QuGD::Shape* s) {
        s = dynamic_cast<QuGD::PrimitiveShape*>(s);
        nameField->setText(dynamic_cast<QuUK::NamedElement*>(
                               s->modelElement())->name());
        connect(nameField, &QLineEdit::textEdited, [s](const QString& str){
                dynamic_cast<QuUK::NamedElement*>(
                    s->modelElement())->setName(str);
                s->update();
                });
    }
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_POPOVERPRIMITIVE_H_ */

