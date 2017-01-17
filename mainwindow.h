#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QGridLayout>
#include <QString>
#include "QRCodeGenerator.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGridLayout *upperLayout = new QGridLayout;
    int num = 1;
    bool numAdjustFlag = 0;
    QString currentname;
    QString  diretory = "D:/";
    bool successfulEncoding;
    CQR_Encode qrEncode;
    int encodeImageSize;
    QImage *img = new QImage;
    QImage *imgQR = new QImage;
    QImage *imagemodify(QImage*,int ,int,int,QString);
    QImage *salt(QImage*,int);
private slots:
    void modifypic1();
    void modifypic2();
    void modifypic3();
    void modifypic4();
    void modifypic5();
    void modifypic6();
    void modifypic7();
    void modifypic8();
    void modifypic9();
    void modifypic10();
    void modifypic11();
    void modifypic12();
  //  void modifypicQR();
    void savetopic();
    void generate();
    void numadjust();
    void selectdiretory();
    void updateQRImage();
};

#endif // MAINWINDOW_H
