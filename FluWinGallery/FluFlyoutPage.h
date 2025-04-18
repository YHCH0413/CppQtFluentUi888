#pragma once

#include "FluAEmptyPage.h"
#include "../FluControls/FluDisplayBox.h"
#include "../FluControls/FluVScrollView.h"
#include "../FluControls/FluPushButton.h"
#include "../FluControls/FluConfirmFlyout.h"

class FluFlyoutPage : public FluAEmptyPage
{
    Q_OBJECT
  public:
    FluFlyoutPage(QWidget* parent = nullptr);

  public slots:
    void onThemeChanged();
};
