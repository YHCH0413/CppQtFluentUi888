﻿#include "FluListView.h"

FluListView::FluListView(QWidget* parent /*= nullptr*/) : QListWidget(parent)
{
    setItemDelegate(new FluListViewItemDelegate);
    m_delegate = new FluScrollDelegate(this);
    onThemeChanged();
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

void FluListView::onThemeChanged()
{
    FluStyleSheetUitls::setQssByFileName("FluListView.qss", this, FluThemeUtils::getUtils()->getTheme());
}
