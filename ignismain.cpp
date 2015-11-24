#include "ignismain.h"
#include "ui_ignismain.h"

IgnisMain::IgnisMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IgnisMain)
{
    ui->setupUi(this);
    setWindowTitle("Ignis Studio");

    // Create the EditorCanvas
    this->m_editorCanvas = new EditorCanvas(this->ui->scrollArea);
    this->ui->scrollArea->setWidget(this->m_editorCanvas);

    // Center on Screen
    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            size(),
            qApp->desktop()->availableGeometry()
        )
    );
}

IgnisMain::~IgnisMain()
{
    delete ui;
}
