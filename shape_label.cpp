#include "shape_label.h"

#include <QEvent>
#include <QBitmap>
#include <QMouseEvent>

CShapeLabel::CShapeLabel(QWidget *parent) : QLabel(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
}

void CShapeLabel::SetPixmaps(const QString& strResNormal, const QString& strResHover)
{
    m_strPixmapNormal = strResNormal;
    m_strPixmapHover = strResHover;

    if (m_strPixmapHover.length() > 0) {
        QPixmap pixmap(m_strPixmapHover);
        setMask(pixmap.mask());
    }

    if (m_strPixmapNormal.length() > 0) {
        QPixmap pixmap(m_strPixmapNormal);
        setPixmap(pixmap);
    }
}

bool CShapeLabel::event(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::Enter:
        {
            QPixmap pixmap(m_strPixmapHover);
            setPixmap(pixmap);
        }
        break;

    case QEvent::Leave:
        {
            QPixmap pixmap(m_strPixmapNormal);
            setPixmap(pixmap);
        }
        break;

    default:
        break;
    }

    return QLabel::event(event);
}

void CShapeLabel::mousePressEvent(QMouseEvent *event)
{
    QLabel::mousePressEvent(event);

    if (event->button() == Qt::LeftButton) {
        emit mouseBtnClicked(event);
    }
}

void CShapeLabel::resizeEvent(QResizeEvent *event)
{
    if (m_strPixmapHover.length() > 0)
    {
        QPixmap pixmap(m_strPixmapHover);
        setMask(pixmap.mask());
    }
}
