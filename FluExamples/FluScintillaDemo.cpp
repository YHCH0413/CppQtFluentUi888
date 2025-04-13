#include "FluScintillaDemo.h"

FluScintillaDemo::FluScintillaDemo(QWidget* parent /*= nullptr*/) : FluTemplateDemo(parent)
{

    setWindowTitle("CppQt WinUI3 Scintiila Demo Dev");
#ifndef _DEBUG
    setWindowTitle("CppQt WinUI3 Scintiila Demo");
#endif

    m_contentLayout->setContentsMargins(0, 0, 0, 0);
    auto edit = new QsciScintilla;
    edit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_contentLayout->addWidget(edit);

    // show line number;
    edit->setMarginType(0, QsciScintilla::NumberMargin);
    edit->setMarginLineNumbers(0, true);
    edit->setMarginWidth(0, 30);

    // set background color;
    edit->setStyleSheet("border:1px solid rgb(232, 232, 232);");

    // set line number background color;
    edit->setMarginsBackgroundColor(QColor(255, 255, 255));
    // set line number text color;
    edit->setMarginsForegroundColor(Qt::red);

    edit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    edit->setScrollWidth(5);
    edit->setScrollWidthTracking(true);

    // // set cpp lexer
    // edit->setLexer(new QsciLexerCPP(edit));
    // edit->setFolding(QsciScintilla::BoxedTreeFoldStyle);
    // edit->setFoldMarginColors(QColor(255, 255, 255), QColor(255, 255, 255));

    auto delegate = new FluScrollDelegate(edit);
}
