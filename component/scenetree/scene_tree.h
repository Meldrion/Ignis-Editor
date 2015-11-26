#ifndef SCENETREEWIDGET_H
#define SCENETREEWIDGET_H

#include <QTreeWidget>

class Scene_Tree : public QTreeWidget
{
public:
    Scene_Tree(QWidget* parent = 0);
    QSize sizeHint() const;
signals:

public slots:
};

#endif // SCENETREEWIDGET_H
