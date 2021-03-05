/********************************************************************************
** Form generated from reading UI file 'textfinder.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTFINDER_H
#define UI_TEXTFINDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextFinder
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *keyWord;
    QLineEdit *lineEdit;
    QPushButton *findButton;
    QTextEdit *textEdit;

    void setupUi(QWidget *TextFinder)
    {
        if (TextFinder->objectName().isEmpty())
            TextFinder->setObjectName(QString::fromUtf8("TextFinder"));
        TextFinder->resize(800, 600);
        verticalLayout = new QVBoxLayout(TextFinder);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        keyWord = new QLabel(TextFinder);
        keyWord->setObjectName(QString::fromUtf8("keyWord"));

        horizontalLayout->addWidget(keyWord);

        lineEdit = new QLineEdit(TextFinder);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        findButton = new QPushButton(TextFinder);
        findButton->setObjectName(QString::fromUtf8("findButton"));

        horizontalLayout->addWidget(findButton);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(TextFinder);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        retranslateUi(TextFinder);

        QMetaObject::connectSlotsByName(TextFinder);
    } // setupUi

    void retranslateUi(QWidget *TextFinder)
    {
        TextFinder->setWindowTitle(QCoreApplication::translate("TextFinder", "TextFinder", nullptr));
        keyWord->setText(QCoreApplication::translate("TextFinder", "KeyWord", nullptr));
        findButton->setText(QCoreApplication::translate("TextFinder", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextFinder: public Ui_TextFinder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTFINDER_H
