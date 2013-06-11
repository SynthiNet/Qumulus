/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_POPOVERATTRIBUTE_H_
#define GUI_WIDGETS_POPOVERATTRIBUTE_H_

#include "internal_base.h"
#include "PopoverForm.h"
#include <Uml/Kernel/Property.h>
#include <Gui/Diagram/ClassShape.h>
#include <Uml/Kernel/Type.h>
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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtGui/QRegExpValidator>
#include <QtCore/QRegExp>

QUML_BEGIN_NAMESPACE_GW

class PopoverAttribute : public QWidget, public PopoverForm {
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QRadioButton *publicButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *protectedButton;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QRadioButton *privateButton;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QFrame *line;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *nameField;
    QComboBox *typeBox;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *multiLowField;
    QLabel *label_8;
    QLineEdit *multiHighField;
    QLabel *label_9;
    QSpacerItem *verticalSpacer;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *staticBox;
    QCheckBox *leafBox;
    QCheckBox *readonlyBox;
    QButtonGroup *visibilityGroup;

    void setupUi() {
        if (objectName().isEmpty())
            setObjectName(QStringLiteral("Form"));
        resize(277, 216);
        verticalLayout_4 = new QVBoxLayout(this);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 6, -1, 12);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding,
                QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        publicButton = new QRadioButton(this);
        visibilityGroup = new QButtonGroup(this);
        visibilityGroup->setObjectName(QStringLiteral("visibilityGroup"));
        visibilityGroup->setExclusive(true);
        visibilityGroup->addButton(publicButton);
        publicButton->setObjectName(QStringLiteral("publicButton"));

        horizontalLayout->addWidget(publicButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding,
                QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(this);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding,
                QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        protectedButton = new QRadioButton(this);
        visibilityGroup->addButton(protectedButton);
        protectedButton->setObjectName(QStringLiteral("protectedButton"));

        horizontalLayout_2->addWidget(protectedButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding,
                QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_2 = new QLabel(this);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding,
                QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        privateButton = new QRadioButton(this);
        visibilityGroup->addButton(privateButton);
        privateButton->setObjectName(QStringLiteral("privateButton"));

        horizontalLayout_3->addWidget(privateButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding,
                QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_3);

        label_3 = new QLabel(this);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        line = new QFrame(this);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label_4 = new QLabel(this);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(this);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        nameField = new QLineEdit(this);
        nameField->setObjectName(QStringLiteral("nameField"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameField);

        typeBox = new QComboBox(this);
        typeBox->setObjectName(QStringLiteral("typeBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(typeBox->sizePolicy().hasHeightForWidth());
        typeBox->setSizePolicy(sizePolicy);
        typeBox->setEditable(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, typeBox);

        label_6 = new QLabel(this);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, 0, -1);
        label_7 = new QLabel(this);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        multiLowField = new QLineEdit(this);
        multiLowField->setObjectName(QStringLiteral("multiLowField"));

        horizontalLayout_6->addWidget(multiLowField);

        label_8 = new QLabel(this);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        multiHighField = new QLineEdit(this);
        multiHighField->setObjectName(QStringLiteral("multiHighField"));

        horizontalLayout_6->addWidget(multiHighField);

        label_9 = new QLabel(this);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum,
                QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::FieldRole, verticalSpacer);


        verticalLayout_4->addLayout(formLayout);

        line_2 = new QFrame(this);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        staticBox = new QCheckBox(this);
        staticBox->setObjectName(QStringLiteral("staticBox"));

        horizontalLayout_5->addWidget(staticBox);

        leafBox = new QCheckBox(this);
        leafBox->setObjectName(QStringLiteral("leafBox"));

        horizontalLayout_5->addWidget(leafBox);

        readonlyBox = new QCheckBox(this);
        readonlyBox->setObjectName(QStringLiteral("readonlyBox"));

        horizontalLayout_5->addWidget(readonlyBox);


        verticalLayout_4->addLayout(horizontalLayout_5);


        retranslateUi();

        QMetaObject::connectSlotsByName(this);
    }

    void retranslateUi() {
        setWindowTitle(QApplication::translate("Form", "Form", 0));
        publicButton->setText(QString());
        label->setText(QApplication::translate("Form", "public (+)", 0));
        protectedButton->setText(QString());
        label_2->setText(QApplication::translate("Form", "protected (#)", 0));
        privateButton->setText(QString());
        label_3->setText(QApplication::translate("Form", "private (-)", 0));
        label_4->setText(QApplication::translate("Form", "Name", 0));
        label_5->setText(QApplication::translate("Form", "Type", 0));
        label_6->setText(QApplication::translate("Form", "Multiplicity", 0));
        label_7->setText(QApplication::translate("Form", "[", 0));
        multiLowField->setText(QApplication::translate("Form", "1", 0));
        label_8->setText(QApplication::translate("Form", "..", 0));
        multiHighField->setText(QApplication::translate("Form", "1", 0));
        label_9->setText(QApplication::translate("Form", "]", 0));
        staticBox->setText(QApplication::translate("Form", "static", 0));
        leafBox->setText(QApplication::translate("Form", "leaf", 0));
        readonlyBox->setText(QApplication::translate("Form", "readonly", 0));
    }

    bool isInFocus() override {
        return
            publicButton->hasFocus() ||
            label->hasFocus() ||
            protectedButton->hasFocus() ||
            label_2->hasFocus() ||
            privateButton->hasFocus() ||
            label_3->hasFocus() ||
            line->hasFocus() ||
            label_4->hasFocus() ||
            label_5->hasFocus() ||
            nameField->hasFocus() ||
            typeBox->hasFocus() ||
            typeBox->view()->hasFocus() ||
            label_6->hasFocus() ||
            label_7->hasFocus() ||
            multiLowField->hasFocus() ||
            label_8->hasFocus() ||
            multiHighField->hasFocus() ||
            label_9->hasFocus() ||
            line_2->hasFocus() ||
            staticBox->hasFocus() ||
            leafBox->hasFocus() ||
            readonlyBox->hasFocus();
    }

    void bindModel(QuGD::Shape* s) {
        QuGD::ClassShape* c = dynamic_cast<QuGD::ClassShape*>(s);
        QuUK::Property* a = c->highlightedAttribute();

        switch(a->visibility()) {
        case QuUK::VisibilityKind::Public:
            publicButton->setChecked(true);
            break;
        case QuUK::VisibilityKind::Protected:
            protectedButton->setChecked(true);
            break;
        case QuUK::VisibilityKind::Private:
            privateButton->setChecked(true);
            break;
        }

        connect(visibilityGroup,
                static_cast<void (QButtonGroup::*)(QAbstractButton*)>(
                    &QButtonGroup::buttonClicked),
                    [s,a,this](QAbstractButton* button){
                        if(button == this->publicButton)
                            a->setVisiblity(QuUK::VisibilityKind::Public);
                        else if(button == this->privateButton)
                            a->setVisiblity(QuUK::VisibilityKind::Private);
                        else if(button == this->protectedButton)
                            a->setVisiblity(QuUK::VisibilityKind::Protected);
                        s->update();});

        nameField->setText(a->name());
        connect(nameField, &QLineEdit::textEdited, [a,s](const QString& str){
                a->setName(str);
                s->update();});

        typeBox->addItem("");
        for(auto i : QuUK::Type::typeList()) {
            typeBox->addItem(i->qualifiedName());
        }
        typeBox->setCurrentText(a->type() ? a->type()->qualifiedName() : "");
        connect(typeBox, static_cast<void (QComboBox::*)(int)>(
                    &QComboBox::currentIndexChanged),
                [s,a,this](int i){
                if(i == 0) {
                    a->setType(nullptr);
                } else {
                    a->setType(QuUK::Type::typeList()[i-1]);
                }
                s->update();});

        multiLowField->setValidator(new QRegExpValidator(QRegExp("\\d*")));
        multiLowField->setText(QString::number(a->lowerBound()));
        connect(multiLowField, &QLineEdit::textEdited, [a,s](const QString& str){
                a->setLowerBound(str.toInt());
                s->update();});

        multiHighField->setValidator(new QRegExpValidator(QRegExp("(\\d*|\\*)")));
        multiHighField->setText(unltd(a->upperBound()) ? "*" :
                QString::number(a->upperBound()));
        connect(multiHighField, &QLineEdit::textEdited, [a,s](const QString& str){
                if(str == "*")
                    a->setUpperBound("*");
                else
                    a->setUpperBound(str.toInt());
                s->update();});

        staticBox->setCheckState(a->isStatic() ? Qt::Checked : Qt::Unchecked);
        connect(staticBox, &QCheckBox::stateChanged, [a,s](int state){
                a->setStatic(state == Qt::Checked);
                s->update();});

        leafBox->setCheckState(a->leaf() ? Qt::Checked : Qt::Unchecked);
        connect(leafBox, &QCheckBox::stateChanged, [a,s](int state){
                a->setLeaf(state == Qt::Checked);
                s->update();});

        readonlyBox->setCheckState(a->readOnly() ? Qt::Checked : Qt::Unchecked);
        connect(readonlyBox, &QCheckBox::stateChanged, [a,s](int state){
                a->setReadOnly(state == Qt::Checked);
                s->update();});
    }
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_POPOVERATTRIBUTE_H_ */

