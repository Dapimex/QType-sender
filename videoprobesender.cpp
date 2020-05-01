#include "videoprobesender.h"
#include <QUdpSocket>

VideoProbeSender::VideoProbeSender(QWidget *parent) : QWidget
{
    q_camera* = new QCamera(this);
    viewfinder = new QCameraViewfinder(this);
    q_camera->setViewfinder(viewfinder);
    setCentralWidget(viewfinder);
    viewfinder->show();
    camera->start();

    videoProbe = new QVideoProbe(this);
    if (videoProbe->setSource(camera))
    {
      qDebug() << "setSource success";
      // Probing succeeded, videoProbe->isValid() should be true.
      connect(videoProbe, SIGNAL(videoFrameProbed(QVideoFrame)),
              this, SLOT(sendDataToUdp(QVideoFrame)));
    }
}

void VideoProbeSender::sendDataToUdp(const QVideoFrame &videoFrame) {
    Q_UNUSED(videoFrame);

    QByteArray datagram = "Broadcasting frame " + QByteArray::number(messageNo);
    udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 45454);
    ++messageNo;
}

QCamera VideoProbeSender::getCamera() {return q_camera;}
//void VideoProbeSender::loadPDF(QString filename) {
//    if (pdfPage)
//        delete pdfPage;
//    if (document)
//        delete document;
//    document = Poppler::Document::load(filename);
//    if (!document || document->isLocked()) {
//        emit sendErrorTextToQml("The document can not be loaded");
//        return;
//    }
//    document->setRenderHint(Poppler::Document::TextAntialiasing);
//    document->setRenderHint(Poppler::Document::Antialiasing);
//    document->setRenderHint(Poppler::Document::TextHinting);
//    drawPageByNumber(0);
//    currentPageNumber = 1;
//    //TASK 1.7 - add emission signal for currentPageChanged() method. Set currentPage number as argument
//    emit currentPageChanged(currentPageNumber);
//}
