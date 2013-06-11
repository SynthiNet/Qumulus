/*
 * Qumulus UML editor
 * Author: Randy Thiemann
 *
 */

#ifndef GUI_WIDGETS_POPOVEROPERATION_H_
#define GUI_WIDGETS_POPOVEROPERATION_H_

#include "internal_base.h"
#include "PopoverForm.h"
#include <Uml/Kernel/Operation.h>
#include <Uml/Kernel/Parameter.h>
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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtGui/QRegExpValidator>
#include <QtCore/QRegExp>
#include <QtCore/QDebug>

QUML_BEGIN_NAMESPACE_GW

class PopoverOperation : public QWidget, public PopoverForm {
public:
    QVBoxLayout* verticalLayout_4;
    QHBoxLayout* horizontalLayout_4;
    QVBoxLayout* verticalLayout;
    QHBoxLayout* horizontalLayout;
    QSpacerItem* horizontalSpacer;
    QRadioButton* publicButton;
    QSpacerItem* horizontalSpacer_2;
    QLabel* label;
    QVBoxLayout* verticalLayout_2;
    QHBoxLayout* horizontalLayout_2;
    QSpacerItem* horizontalSpacer_3;
    QRadioButton* protectedButton;
    QSpacerItem* horizontalSpacer_4;
    QLabel* label_2;
    QVBoxLayout* verticalLayout_3;
    QHBoxLayout* horizontalLayout_3;
    QSpacerItem* horizontalSpacer_6;
    QRadioButton* privateButton;
    QSpacerItem* horizontalSpacer_5;
    QLabel* label_3;
    QFrame* line;
    QFormLayout* formLayout;
    QLabel* label_4;
    QLabel* label_5;
    QLineEdit* nameField;
    QComboBox* typeBox;
    QFrame* line_2;
    QHBoxLayout* horizontalLayout_5;
    QCheckBox* staticBox;
    QCheckBox* leafBox;
    QCheckBox* queryBox;
    QFrame* line_3;
    QLabel* label_6;
    QTableWidget* parameterTable;
    QHBoxLayout* horizontalLayout_6;
    QSpacerItem* horizontalSpacer_7;
    QPushButton* addButton;
    QPushButton* removeButton;
    QButtonGroup* buttonGroup;
    int counter = 0;

    void setupUi() {
        if(objectName().isEmpty())
            setObjectName(QStringLiteral("Form"));

        resize(308, 440);
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
        buttonGroup = new QButtonGroup(this);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(publicButton);
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
        buttonGroup->addButton(protectedButton);
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
        buttonGroup->addButton(privateButton);
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

        queryBox = new QCheckBox(this);
        queryBox->setObjectName(QStringLiteral("queryBox"));

        horizontalLayout_5->addWidget(queryBox);


        verticalLayout_4->addLayout(horizontalLayout_5);

        line_3 = new QFrame(this);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

        label_6 = new QLabel(this);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_6);

        parameterTable = new QTableWidget(this);

        if(parameterTable->columnCount() < 3)
            parameterTable->setColumnCount(3);

        QTableWidgetItem* __qtablewidgetitem = new QTableWidgetItem();
        parameterTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem* __qtablewidgetitem1 = new QTableWidgetItem();
        parameterTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem* __qtablewidgetitem2 = new QTableWidgetItem();
        parameterTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        parameterTable->setObjectName(QStringLiteral("parameterTable"));
        parameterTable->setRowCount(0);
        parameterTable->horizontalHeader()->setDefaultSectionSize(100);
        parameterTable->horizontalHeader()->setStretchLastSection(true);
        parameterTable->verticalHeader()->setVisible(false);

        verticalLayout_4->addWidget(parameterTable);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding,
                                             QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        addButton = new QPushButton(this);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setText(QStringLiteral("+"));
        addButton->setFlat(false);

        horizontalLayout_6->addWidget(addButton);

        removeButton = new QPushButton(this);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setBaseSize(QSize(17, 0));
        removeButton->setText(QStringLiteral("-"));
        removeButton->setCheckable(false);

        horizontalLayout_6->addWidget(removeButton);


        verticalLayout_4->addLayout(horizontalLayout_6);


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
        staticBox->setText(QApplication::translate("Form", "static", 0));
        leafBox->setText(QApplication::translate("Form", "leaf", 0));
        queryBox->setText(QApplication::translate("Form", "query", 0));
        label_6->setText(QApplication::translate("Form", "Parameters", 0));
        QTableWidgetItem* ___qtablewidgetitem =
            parameterTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Form", "Name", 0));
        QTableWidgetItem* ___qtablewidgetitem1 =
            parameterTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Form", "Type", 0));
        QTableWidgetItem* ___qtablewidgetitem2 =
            parameterTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Form",
                                      "Direction", 0));
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
            line_2->hasFocus() ||
            staticBox->hasFocus() ||
            leafBox->hasFocus() ||
            queryBox->hasFocus() ||
            line_3->hasFocus() ||
            label_6->hasFocus() ||
            parameterTable->hasFocus() ||
            addButton->hasFocus() ||
            removeButton->hasFocus();
    }

    void bindModel(QuGD::Shape* s) {
        QuUK::Operation* o =
            dynamic_cast<QuGD::ClassShape*>(s)->highlightedOperation();

        switch(o->visibility()) {
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

        connect(buttonGroup,
                static_cast<void (QButtonGroup::*)(QAbstractButton*)>(
                    &QButtonGroup::buttonClicked),
                    [s,o,this](QAbstractButton* button){
                        if(button == this->publicButton)
                            o->setVisiblity(QuUK::VisibilityKind::Public);
                        else if(button == this->privateButton)
                            o->setVisiblity(QuUK::VisibilityKind::Private);
                        else if(button == this->protectedButton)
                            o->setVisiblity(QuUK::VisibilityKind::Protected);
                        s->update();});

        nameField->setText(o->name());
        connect(nameField, &QLineEdit::textEdited, [o,s](const QString& str){
                o->setName(str);
                s->update();});

        // typeBox
        typeBox->addItem("");
        for(auto i : QuUK::Type::typeList()) {
            typeBox->addItem(i->qualifiedName());
        }
        typeBox->setCurrentText(o->type() ? o->type()->qualifiedName() : "");
        connect(typeBox, static_cast<void (QComboBox::*)(int)>(
                    &QComboBox::currentIndexChanged),
                [s,o,this](int i){
                if(i == 0) {
                    for(auto p : o->parameters()) {
                        if(p->direction() == QuUK::ParameterDirectionKind::Return) {
                            o->removeParameter(p);
                            delete p;
                            break;
                        }
                    }
                } else {
                    bool isSet = false;
                    for(auto p : o->parameters()) {
                        if(p->direction() == QuUK::ParameterDirectionKind::Return) {
                            p->setType(QuUK::Type::typeList()[i-1]);
                            isSet = true;
                            break;
                        }
                    }

                    if(!isSet) {
                        auto param = new QuUK::Parameter("", o);
                        param->setDirection(QuUK::ParameterDirectionKind::Return);
                        param->setType(QuUK::Type::typeList()[i-1]);
                        o->addParameter(param);
                    }
                }
                s->update();});


        staticBox->setCheckState(o->isStatic() ? Qt::Checked : Qt::Unchecked);
        connect(staticBox, &QCheckBox::stateChanged, [o,s](int state){
                o->setStatic(state == Qt::Checked);
                s->update();});

        leafBox->setCheckState(o->leaf() ? Qt::Checked : Qt::Unchecked);
        connect(leafBox, &QCheckBox::stateChanged, [o,s](int state){
                o->setLeaf(state == Qt::Checked);
                s->update();});

        queryBox->setCheckState(o->isQuery() ? Qt::Checked : Qt::Unchecked);
        connect(queryBox, &QCheckBox::stateChanged, [o,s](int state){
                o->setQuery(state == Qt::Checked);
                s->update();});

        for(auto p : o->parameters()) {
            if(p->direction() == QuUK::ParameterDirectionKind::Return)
                continue;

            auto name = new QTableWidgetItem(p->name(), 0);
            name->setToolTip(name->text());
            auto type = new QTableWidgetItem(p->type() ?
                    p->type()->qualifiedName() : "", 1);
            type->setToolTip(type->text());
            QTableWidgetItem* direction = nullptr;
            switch(p->direction()){
            case QuUK::ParameterDirectionKind::In:
                direction = new QTableWidgetItem("In", 2);
                break;
            case QuUK::ParameterDirectionKind::Out:
                direction = new QTableWidgetItem("Out", 2);
                break;
            case QuUK::ParameterDirectionKind::InOut:
                direction = new QTableWidgetItem("InOut", 2);
                break;
            default:;
            }
            direction->setToolTip(direction->text());
            parameterTable->setRowCount(parameterTable->rowCount() + 1);
            parameterTable->setItem(parameterTable->rowCount()-1,0,name);
            parameterTable->setItem(parameterTable->rowCount()-1,1,type);
            parameterTable->setItem(parameterTable->rowCount()-1,2,direction);
        }

        connect(parameterTable, &QTableWidget::cellChanged, [this,o,s](int r, int c){
                QString paramName = parameterTable->item(r, 0)->toolTip();
                QString origVal = parameterTable->item(r, c)->toolTip();
                QString currVal = parameterTable->item(r, c)->text();
                switch(c) {
                case 0: // Name
                    for(auto p : o->parameters()) {
                        if(p->name() == paramName) {
                            p->setName(currVal);
                            parameterTable->item(r, c)->setToolTip(currVal);
                        }
                    }
                    break;
                case 1: // Type
                    if(currVal == "") {
                        for(auto p : o->parameters()) {
                            if(p->name() == paramName) {
                                p->setType(nullptr);
                                parameterTable->item(r, c)->setToolTip(currVal);
                            }
                        }
                    } else {
                        QuUK::Type* t = nullptr;
                        for(auto type : QuUK::Type::typeList()) {
                            if(type->qualifiedName() == currVal) {
                                t = type;
                                break;
                            }
                        }

                        if(t) {
                            for(auto p : o->parameters()) {
                                if(p->name() == paramName) {
                                    p->setType(t);
                                    parameterTable->item(r, c)->setToolTip(currVal);
                                }
                            }
                        } else {
                            parameterTable->item(r, c)->setText(origVal);
                            return;
                        }
                    }
                    break;
                case 2: // Direction
                    QuUK::ParameterDirectionKind dir;
                    if(currVal == "In") {
                        dir = QuUK::ParameterDirectionKind::In;
                    } else if(currVal == "Out") {
                        dir = QuUK::ParameterDirectionKind::Out;
                    } else if(currVal == "InOut") {
                        dir = QuUK::ParameterDirectionKind::InOut;
                    } else {
                        parameterTable->item(r, c)->setText(origVal);
                        return;
                    }

                    for(auto p : o->parameters()) {
                        if(p->name() == paramName) {
                            p->setDirection(dir);
                            parameterTable->item(r, c)->setToolTip(currVal);
                        }
                    }
                    break;
                default:;
                }
                s->update();
                });

        connect(addButton, &QPushButton::clicked, [this,o,s]{
                auto param = new QuUK::Parameter("parameter" +
                    QString::number(counter++), o);
                auto name = new QTableWidgetItem(param->name(), 0);
                name->setToolTip(param->name());
                auto type = new QTableWidgetItem("", 1);
                type->setToolTip("");
                auto direction = new QTableWidgetItem("In", 2);
                direction->setToolTip("In");
                parameterTable->setRowCount(parameterTable->rowCount() + 1);
                parameterTable->setItem(parameterTable->rowCount()-1,0,name);
                parameterTable->setItem(parameterTable->rowCount()-1,1,type);
                parameterTable->setItem(parameterTable->rowCount()-1,2,direction);
                s->update();});

        connect(removeButton, &QPushButton::clicked, [this,o,s]{
                auto selected = parameterTable->selectedItems();
                if(selected.size() == 0)
                    return;
                auto item = selected[0];
                int row = parameterTable->row(item);
                qDebug() << row;
                QString deleteName = parameterTable->item(row, 0)->text();
                qDebug() << deleteName;
                for(auto p : o->parameters()) {
                    if(p->name() == deleteName) {
                        o->removeParameter(p);
                        delete p;
                        parameterTable->removeRow(row);
                        break;
                    }
                }
                s->update();
                });
    }
};

QUML_END_NAMESPACE_GW

#endif /* GUI_WIDGETS_POPOVEROPERATION_H_ */

