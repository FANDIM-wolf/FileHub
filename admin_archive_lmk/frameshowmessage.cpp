#include "frameshowmessage.h"
#include "ui_frameshowmessage.h"

FrameShowMessage::FrameShowMessage(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameShowMessage)
{
    ui->setupUi(this);
}

FrameShowMessage::~FrameShowMessage()
{
    delete ui;
}
