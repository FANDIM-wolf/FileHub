#ifndef FRAMESHOWMESSAGE_H
#define FRAMESHOWMESSAGE_H

#include <QFrame>

namespace Ui {
class FrameShowMessage;
}

class FrameShowMessage : public QFrame
{
    Q_OBJECT

public:
    explicit FrameShowMessage(QWidget *parent = nullptr);
    ~FrameShowMessage();

private:
    Ui::FrameShowMessage *ui;
};

#endif // FRAMESHOWMESSAGE_H
