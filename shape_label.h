#ifndef CSHAPELABEL_H
#define CSHAPELABEL_H

#include <QLabel>

class CShapeLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CShapeLabel(QWidget *parent = nullptr);

    void SetPixmaps(const QString& strResNormal, const QString& strResHover);

signals:
    void mouseBtnClicked(QMouseEvent* ev);

protected:
    bool event(QEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QString m_strPixmapNormal;
    QString m_strPixmapHover;
};

#endif // CSHAPELABEL_H
