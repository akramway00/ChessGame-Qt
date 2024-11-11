/********************************************************************************
** Form generated from reading UI file 'CHESS.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESS_H
#define UI_CHESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CHESSClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;

    void setupUi(QMainWindow *CHESSClass)
    {
        if (CHESSClass->objectName().isEmpty())
            CHESSClass->setObjectName(QString::fromUtf8("CHESSClass"));
        CHESSClass->resize(1086, 639);
        centralWidget = new QWidget(CHESSClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        CHESSClass->setCentralWidget(centralWidget);

        retranslateUi(CHESSClass);

        QMetaObject::connectSlotsByName(CHESSClass);
    } // setupUi

    void retranslateUi(QMainWindow *CHESSClass)
    {
        CHESSClass->setWindowTitle(QCoreApplication::translate("CHESSClass", "CHESS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CHESSClass: public Ui_CHESSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESS_H
