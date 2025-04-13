#include "FluProgressBar.h"

FluProgressBar::FluProgressBar(QWidget* parent /*= nullptr*/) : QProgressBar(parent)
{
    setTextVisible(false);
    onThemeChanged();
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

void FluProgressBar::onThemeChanged()
{
    // if (FluThemeUtils::isLightTheme())
    // {
    //     FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluProgressBar.qss", this);
    // }
    // else
    // {
    //     FluStyleSheetUitls::setQssByFileName("../StyleSheet/dark/FluProgressBar.qss", this);
    // }

    FluStyleSheetUitls::setQssByFileName("FluProgressBar.qss", this, FluThemeUtils::getUtils()->getTheme());
}
