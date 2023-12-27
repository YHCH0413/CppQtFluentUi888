#pragma once

#include <QPixmap>
#include <QFont>
#include <QIcon>

#include "../FluControls/FluDef.h"

#define FluGetIcon(nType) FluIconUtils::GetFluentIcon(nType)
#define FluGetIconPixmap(nType) FluIconUtils::GetFluentIconPixmap(nType)

class FluIconUtils
{
  private:
    FluIconUtils();
    ~FluIconUtils();

  public:
    static FluIconUtils* getInstance();
    static QPixmap getFluentIconPixmap(FluAwesomeType nType);
    static QIcon getFluentIcon(FluAwesomeType nType);

    static QPixmap getFluentIconPixmap(FluAwesomeType nType, QColor penColor);
    static QIcon getFluentIcon(FluAwesomeType nType, QColor penColor);

    static void saveFluentPng(FluAwesomeType nType, QString filename);
  private:
    QFont m_fluentFont;
};