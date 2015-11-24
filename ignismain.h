#ifndef IGNISMAIN_H
#define IGNISMAIN_H

#include <QMainWindow>
#include <QStyle>
#include <QDesktopWidget>
#include "component/editorcanvas.h"

namespace Ui {
class IgnisMain;
}

class IgnisMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit IgnisMain(QWidget *parent = 0);
    ~IgnisMain();


private:
    Ui::IgnisMain *ui;
    EditorCanvas* m_editorCanvas;
};

#endif // IGNISMAIN_H
