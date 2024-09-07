#include "FluVFlyout.h"

FluVFlyout::FluVFlyout(QWidget* target, FluFlyoutPosition position /*= FluFlyoutPosition::Top*/) : FluWidget(nullptr), m_targetWidget(target), m_position(position)
{
    m_hMainLayout = new QHBoxLayout;
    m_hMainLayout->setSpacing(0);
    m_hMainLayout->setContentsMargins(10, 10, 10, 10);
    setLayout(m_hMainLayout);

    m_shadowWidget = new QWidget(this);
    m_shadowWidget->setObjectName("shadowWidget");

    m_hMainLayout->addWidget(m_shadowWidget);

    m_vShadowLayout = new QVBoxLayout;
    m_shadowWidget->setLayout(m_vShadowLayout);
    m_vShadowLayout->setContentsMargins(8, 8, 8, 8);

    setFixedWidth(360);
    setMinimumHeight(96);

    // set shadow;
    m_shadowEffect = new QGraphicsDropShadowEffect;
    m_shadowEffect->setBlurRadius(8);
    m_shadowEffect->setOffset(0, 0);
    m_shadowEffect->setColor(QColor(0, 0, 0, 30));
    m_shadowWidget->setGraphicsEffect(m_shadowEffect);

    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    // FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluVFlyout.qss", this);
    // if (FluThemeUtils::isDarkTheme())
    // {
    //     FluStyleSheetUitls::setQssByFileName("../StyleSheet/dark/FluVFlyout.qss", this);
    // }

    onThemeChanged();
}

void FluVFlyout::showEvent(QShowEvent* event)
{
    int nX = 0;
    int nY = 0;

    QPoint targetPos = m_targetWidget->mapToGlobal(QPoint(0, 0));
    switch (m_position)
    {
        case FluFlyoutPosition::Top:
        {
            nX = targetPos.x() + (m_targetWidget->width() - width()) / 2;
            nY = targetPos.y() - height() + 5;
        }
        break;
        case FluFlyoutPosition::Bottom:
        {
            nX = targetPos.x() + (m_targetWidget->width() - width()) / 2;
            nY = targetPos.y() + m_targetWidget->height() - 5;
        }
        break;
        case FluFlyoutPosition::Left:
        {
            nX = targetPos.x() - width() + 5;
            nY = targetPos.y() - (height() - m_targetWidget->height()) / 2;
        }
        break;
        case FluFlyoutPosition::Right:
        {
            nX = targetPos.x() + m_targetWidget->width() - 5;
            nY = targetPos.y() - (height() - m_targetWidget->height()) / 2;
        }
        break;
        default:
            break;
    }

    move(nX, nY);
}

void FluVFlyout::closeEvent(QCloseEvent* event)
{
    //  LOG_DEBUG << "close it!";
    deleteLater();
}

void FluVFlyout::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

void FluVFlyout::onThemeChanged()
{
    if (FluThemeUtils::isLightTheme())
    {
        FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluVFlyout.qss", this);
    }
    else
    {
        FluStyleSheetUitls::setQssByFileName("../StyleSheet/dark/FluVFlyout.qss", this);
    }
}
