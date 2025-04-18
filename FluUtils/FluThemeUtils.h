﻿#pragma once

#include <QObject>

enum class FluTheme
{
    Light, 
    Dark, 
    Custom,
    _END,
};

class FluThemeUtils : public QObject
{
    Q_OBJECT
  private:
    FluThemeUtils(QObject* object = nullptr);

  public:
    FluTheme getTheme()
    {
        return m_theme;
    }

    void setTheme(FluTheme theme)
    {
        m_theme = theme;
        emit themeChanged(m_theme);
    }

    static QString getThemeName()
    {
        switch (getUtils()->getTheme())
        {
            case FluTheme::Light:
                return "light";
            case FluTheme::Dark:
                return "dark";
            case FluTheme::Custom:
                return "custom";
            default:
                return "Light";
        }
    }

    static FluThemeUtils* getUtils()
    {
        if (m_themeUtils == nullptr)
            m_themeUtils = new FluThemeUtils();
        return m_themeUtils;
    }

    static bool isLightTheme()
    {
        return getUtils()->getTheme() == FluTheme::Light;
    }

    static bool isDarkTheme()
    {
        return getUtils()->getTheme() == FluTheme::Dark;
    }

    static bool isCustomTheme()
    {
        return getUtils()->getTheme() == FluTheme::Custom;
    }

    static void __init()
    {
        getUtils();
    }

    static void __deInit()
    {
        if (m_themeUtils == nullptr)
            return;
        delete m_themeUtils;
        m_themeUtils = nullptr;
    }

  signals:
    void themeChanged(FluTheme theme);

  protected:
    FluTheme m_theme;

  private:
    static FluThemeUtils* m_themeUtils;
};
