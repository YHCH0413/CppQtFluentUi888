#include "FluExpander.h"
#include <QEvent>

FluExpander::FluExpander(QWidget* parent /*= nullptr*/) : FluWidget(parent)
{
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->setSpacing(0);

    m_wrap1 = new QWidget(this);
    m_wrap1->installEventFilter(this);
    m_wrap1->setObjectName("wrap1");
    m_wrap1->setFixedHeight(48);  // the wrap1 set fixed height 48.

    m_hWrap1Layout = new QHBoxLayout;
    m_wrap1->setLayout(m_hWrap1Layout);
    m_hWrap1Layout->setContentsMargins(5, 5, 5, 5);

    m_downOrUpButton = new FluIconButton(FluAwesomeType::ChevronDown, m_wrap1);
    m_downOrUpButton->setNoBorder(true);
    // m_downOrUpButton->setObjectName("downOrUpButton");

    //   m_hWrap1Layout->addStretch();
    //   m_hWrap1Layout->addWidget(m_downOrUpButton, Qt::AlignHCenter);

    m_wrap2 = new QWidget(this);
    m_wrap2->setObjectName("wrap2");
    m_wrap2->setFixedHeight(0);
    // m_wrap2->setMinimumHeight(50);

    m_vWrap2Layout = new QVBoxLayout;
    m_vWrap2Layout->setContentsMargins(5, 5, 5, 5);
    m_wrap2->setLayout(m_vWrap2Layout);

    m_mainLayout->addWidget(m_wrap1);
    // m_mainLayout->addSpacing(1);
    m_mainLayout->addWidget(m_wrap2);

    // m_bDown = true;
    setDown(true);
    setTopRadius0(false);
    m_expandAni = new QPropertyAnimation(m_wrap2, "geometry");
    m_expandAni->setDuration(300);

    // m_wrap2Height = 128;
    connect(m_downOrUpButton, &QPushButton::clicked, [=](bool b) { onClicked(); });

    connect(m_expandAni, &QPropertyAnimation::valueChanged, [=](const QVariant& value) {
        QRect tmp = value.toRect();
        m_wrap2->setFixedHeight(tmp.height());
        setFixedHeight(m_wrap1->height() + m_wrap2->height() + 1);
        // LOG_DEBUG << "height:" << height();
        update();
    });

    connect(m_expandAni, &QPropertyAnimation::finished, [=](void) { setDown(!m_bDown); });

    onThemeChanged();
}

bool FluExpander::getDown()
{
    return m_bDown;
}

void FluExpander::setDown(bool bDown)
{
    m_bDown = bDown;
    setProperty("down", bDown);
    m_wrap1->setProperty("down", bDown);
    m_wrap2->setProperty("down", bDown);

    style()->polish(this);
    m_wrap1->style()->polish(m_wrap1);
    m_wrap2->style()->polish(m_wrap2);
}

void FluExpander::setTopRadius0(bool bTopRadius0)
{
    m_wrap1->setProperty("topRadius0", bTopRadius0);
    setProperty("topRadius0", bTopRadius0);

    style()->polish(this);
    m_wrap1->style()->polish(m_wrap1);
}

void FluExpander::setWrap2Height(int h)
{
    m_wrap2Height = h;
}

QHBoxLayout* FluExpander::getWrap1Layout()
{
    return m_hWrap1Layout;
}

QVBoxLayout* FluExpander::getWrap2Layout()
{
    return m_vWrap2Layout;
}

void FluExpander::resizeEvent(QResizeEvent* event)
{
    int nX = m_wrap1->width() - m_downOrUpButton->height() - 5;
    int nY = (m_wrap1->height() - m_downOrUpButton->height()) / 2;
    m_downOrUpButton->move(nX, nY);
}

bool FluExpander::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == m_wrap1 && event->type() == QEvent::MouseButtonRelease)
    {
        m_downOrUpButton->clicked();
    }
    return QWidget::eventFilter(watched, event);
}

void FluExpander::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

void FluExpander::onThemeChanged()
{
    // if (FluThemeUtils::isLightTheme())
    // {
    //     FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluExpander.qss", this);
    // }
    // else
    // {
    //     FluStyleSheetUitls::setQssByFileName("../StyleSheet/dark/FluExpander.qss", this);
    // }
    FluStyleSheetUitls::setQssByFileName("FluExpander.qss", this, FluThemeUtils::getUtils()->getTheme());
}

void FluExpander::onClicked()
{
    if (m_bDown)
    {
        m_expandAni->setStartValue(QRect(m_wrap2->x(), m_wrap2->y(), m_wrap2->width(), 0));
        m_expandAni->setEndValue(QRect(m_wrap2->x(), m_wrap2->y(), m_wrap2->width(), m_wrap2->sizeHint().height()));
        m_expandAni->start();

        m_downOrUpButton->setType1(FluAwesomeType::ChevronUp);
    }
    else
    {
        m_expandAni->setStartValue(QRect(m_wrap2->x(), m_wrap2->y(), m_wrap2->width(), m_wrap2->sizeHint().height()));
        m_expandAni->setEndValue(QRect(m_wrap2->x(), m_wrap2->y(), m_wrap2->width(), 0));
        m_expandAni->start();
        m_downOrUpButton->setType1(FluAwesomeType::ChevronDown);
    }
}
