#ifndef VIDEOPROBESENDER_H
#define VIDEOPROBESENDER_H

#include <QObject>
#include <QString>
#include <QVideoFrame>
#include <QCamera>
#include <QVideoProbe>
#include <QUdpSocket>
#include <QtWidgets/QWidget>

class VideoProbeSender : QWidget
{
    Q_OBJECT
    Q_PROPERTY(QCamera* q_camera READ getCamera)

public:
    VideoProbeSender(QWidget *parent);
    QCamera getCamera();

private:
    void sendDataToUpd(QVideoFrame &videoFrame);
    QCamera* q_camera;
    QVideoProbe videoProbe;
    QUdpSocket udpSocket;
};



#endif // VIDEOPROBESENDER_H
