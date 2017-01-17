#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include<QString>
#include <string>
#include <iostream>

#include <fstream>
#include <streambuf>
#include <stdlib.h>
#include "QRCodeGenerator.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // QImage *img = new QImage;
    if(!img->load(":/new/pic/lena1.jpg"))
    {
        //qDebug()<<"can't open image\n";
    }
    ui->_1leukocyte->setPixmap(QPixmap::fromImage(*img));
    if(!img->load(":/new/pic/lena2.jpg"))
    {
        //qDebug()<<"can't open image\n";
    }
    ui->_2nitrite->setPixmap(QPixmap::fromImage(*img));
    if(!img->load(":/new/pic/lena3.jpg"))
    {
        //qDebug()<<"can't open image\n";
    }
    ui->_3urobilinogen->setPixmap(QPixmap::fromImage(*img));
    if(!img->load(":/new/pic/lena4.jpg"))
    {
        //qDebug()<<"can't open image\n";
    }
    ui->_4protein->setPixmap(QPixmap::fromImage(*img));
    if(!img->load(":/new/pic/lena5.jpg"))
    {
        //qDebug()<<"can't open image\n";
    }
    ui->_5calcium->setPixmap(QPixmap::fromImage(*img));
    if(!img->load(":/new/pic/lena6.jpg"))
    {
        //qDebug()<<"can't open image\n";
    }
    ui->_6PH->setPixmap(QPixmap::fromImage(*img));
    if(!img->load(":/new/pic/lena7.jpg"))
    {
        //qDebug()<<"can't open image\n";
    }
    ui->_7vitaminC->setPixmap(QPixmap::fromImage(*img));
    if(!img->load(":/new/pic/lena8.jpg"))
    {
        //qDebug()<<"can't open image\n";
    }
    ui->_8occult_blood->setPixmap(QPixmap::fromImage(*img));
    if(!img->load(":/new/pic/lena9.jpg"))
    {
        //qDebug()<<"can't open image\n";
    }
    ui->_9amylaceum->setPixmap(QPixmap::fromImage(*img));
    if(!img->load(":/new/pic/lena10.jpg"))
    {
        //qDebug()<<"can't open image\n";
    }
    ui->_10bilirubin->setPixmap(QPixmap::fromImage(*img));
    if(!img->load(":/new/pic/lena11.jpg"))
    {
        //qDebug()<<"can't open image\n";
    }
    ui->_11acetone_bodies->setPixmap(QPixmap::fromImage(*img));
    if(!img->load(":/new/pic/lena12.jpg"))
    {
        //qDebug()<<"can't open image\n";
    }
    ui->_12specific_gravity_of_urine->setPixmap(QPixmap::fromImage(*img));
    if(!imgQR->load(":/new/pic/qr.bmp"))
    {
        //qDebug()<<"can't open image\n";
    }
    ui->QRcode->setPixmap(QPixmap::fromImage(*imgQR));
    ui->directory->setText(diretory);
    ui->lineEdit->setText("编号1");
    this->setWindowIcon(QIcon("ABENEA.ico"));
 //   QGridLayout *upperLayout = new QGridLayout;
    upperLayout->addWidget(ui->_1leukocyte,0,0);
    upperLayout->addWidget(ui->_2nitrite,0,1);
    upperLayout->addWidget(ui->_3urobilinogen,0,2);
    upperLayout->addWidget(ui->_4protein,0,3);
    upperLayout->addWidget(ui->_5calcium,1,0);
    upperLayout->addWidget(ui->_6PH,1,3);
    upperLayout->addWidget(ui->_7vitaminC,2,0);
    upperLayout->addWidget(ui->_8occult_blood,2,3);
    upperLayout->addWidget(ui->_9amylaceum,3,0);
    upperLayout->addWidget(ui->_10bilirubin,3,1);
    upperLayout->addWidget(ui->_11acetone_bodies,3,2);
    upperLayout->addWidget(ui->_12specific_gravity_of_urine,3,3);
    upperLayout->addWidget(ui->QRcode,1,1,2,2);



    QGridLayout *lowerLayout = new QGridLayout;
    lowerLayout->addWidget(ui->comboBox_1,0,0);
    lowerLayout->addWidget(ui->comboBox_2,0,1);
    lowerLayout->addWidget(ui->comboBox_3,0,2);
    lowerLayout->addWidget(ui->comboBox_4,0,3);
    lowerLayout->addWidget(ui->comboBox_5,1,0);
    lowerLayout->addWidget(ui->comboBox_6,1,3);
    lowerLayout->addWidget(ui->comboBox_7,2,0);
    lowerLayout->addWidget(ui->comboBox_8,2,3);
    lowerLayout->addWidget(ui->comboBox_9,3,0);
    lowerLayout->addWidget(ui->comboBox_10,3,1);
    lowerLayout->addWidget(ui->comboBox_11,3,2);
    lowerLayout->addWidget(ui->comboBox_12,3,3);
    lowerLayout->addWidget(ui->QRString,1,1,2,1);
    lowerLayout->addWidget(ui->lineEdit,1,2,2,1);
   // lowerLayout->addWidget(ui->pushButton,2,1,1,2);
    QGridLayout *buttomLayout = new QGridLayout;
    buttomLayout->addWidget(ui->generateButton,0,0);
    buttomLayout->addWidget(ui->saveButton,0,1);
    buttomLayout->addWidget(ui->directory,1,0);
    buttomLayout->addWidget(ui->selectButton,1,1);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(upperLayout);
    mainLayout->addSpacing(50);
    mainLayout->addLayout(lowerLayout);
    mainLayout->addLayout(buttomLayout);
    ui->centralWidget->setLayout(mainLayout);
    this->setWindowTitle("艾蓓乐图片");
    upperLayout->setHorizontalSpacing(54);
    upperLayout->setVerticalSpacing(54);

    this->setFixedHeight(746);
    this->setFixedWidth(500);

   // connect(ui->generateButton,SIGNAL(clicked()),ui->comboBox_1,SIGNAL(currentIndexChanged(int)));
    connect(ui->comboBox_1,SIGNAL(currentIndexChanged(int)),this,SLOT(modifypic1()));
   // connect(ui->generateButton,SIGNAL(clicked()),this,SLOT(modifypic2()));
    connect(ui->comboBox_2,SIGNAL(currentIndexChanged(int)),this,SLOT(modifypic2()));
   // connect(ui->generateButton,SIGNAL(clicked()),this,SLOT(modifypic3()));
    connect(ui->comboBox_3,SIGNAL(currentIndexChanged(int)),this,SLOT(modifypic3()));
   // connect(ui->generateButton,SIGNAL(clicked()),this,SLOT(modifypic4()));
    connect(ui->comboBox_4,SIGNAL(currentIndexChanged(int)),this,SLOT(modifypic4()));
   // connect(ui->generateButton,SIGNAL(clicked()),this,SLOT(modifypic5()));
    connect(ui->comboBox_5,SIGNAL(currentIndexChanged(int)),this,SLOT(modifypic5()));
   // connect(ui->generateButton,SIGNAL(clicked()),this,SLOT(modifypic6()));
    connect(ui->comboBox_6,SIGNAL(currentIndexChanged(int)),this,SLOT(modifypic6()));
   // connect(ui->generateButton,SIGNAL(clicked()),this,SLOT(modifypic7()));
    connect(ui->comboBox_7,SIGNAL(currentIndexChanged(int)),this,SLOT(modifypic7()));
   // connect(ui->generateButton,SIGNAL(clicked()),this,SLOT(modifypic8()));
    connect(ui->comboBox_8,SIGNAL(currentIndexChanged(int)),this,SLOT(modifypic8()));
   // connect(ui->generateButton,SIGNAL(clicked()),this,SLOT(modifypic9()));
    connect(ui->comboBox_9,SIGNAL(currentIndexChanged(int)),this,SLOT(modifypic9()));
   // connect(ui->generateButton,SIGNAL(clicked()),this,SLOT(modifypic10()));
    connect(ui->comboBox_10,SIGNAL(currentIndexChanged(int)),this,SLOT(modifypic10()));
   // connect(ui->generateButton,SIGNAL(clicked()),this,SLOT(modifypic11()));
    connect(ui->comboBox_11,SIGNAL(currentIndexChanged(int)),this,SLOT(modifypic11()));
   // connect(ui->generateButton,SIGNAL(clicked()),this,SLOT(modifypic12()));
    connect(ui->comboBox_12,SIGNAL(currentIndexChanged(int)),this,SLOT(modifypic12()));
    connect(ui->generateButton,SIGNAL(clicked()),this,SLOT(updateQRImage()));
    connect(ui->generateButton,SIGNAL(clicked()),this,SLOT(generate()));
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(savetopic()));
    connect(ui->lineEdit,SIGNAL(textEdited(QString)),this,SLOT(numadjust()));
    connect(ui->selectButton,SIGNAL(clicked()),this,SLOT(selectdiretory()));
}
void MainWindow::modifypic1()
{   int r, g ,b;
    QString imagename;
     switch(ui->comboBox_1->currentIndex())

        { case 0:
            r = 255, g = 224, b = 127;
            break;
          case 1:
            r = 232, g = 214, b = 107;
            break;
          case 2:
            r = 232, g = 198, b = 145;
            break;
          case 3:
            r = 207, g = 173, b = 102;
            break;
          case 4:
            r = 184, g = 151, b = 115;
            break;
          case 5:
            r = 141, g = 96, b = 106;
            break;
          case 6:
            r = 124, g = 67, b = 86;
            break;
          case 7:
            r = 117, g = 90, b = 120;
            break;
        }

        imagename += "lena1.jpg";

      img = this->imagemodify(img, r , g, b, imagename);
   // char p[100];
   // strcpy(p,imagename->toStdString().data());
  //  IplImage* imgcv = cvLoadImage( "lena1.jpg" );
   // saturate_sv(imgcv,b,g,r);
   // cvSaveImage(p,imgcv);
  //  QImage *img = new QImage;
  //  if(!img->load("lena1.jpg"))
  // {
       //qDebug()<<"can't open image\n";
  // }

    ui->_1leukocyte->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::modifypic2()
{   int r, g ,b;
    QString imagename;
     switch(ui->comboBox_2->currentIndex())

        { case 0:
            r = 255, g = 244, b = 109;
            break;
          case 1:
            r = 255, g = 207, b = 161;
            break;
          case 2:
            r = 255, g = 190, b = 181;
            break;
          case 3:
            r = 255, g = 139, b = 130;
            break;
          case 4:
            r = 220, g = 88, b = 79;
            break;

        }

        imagename += "lena2.jpg";


    img = this->imagemodify(img, r , g, b, imagename);

    ui->_2nitrite->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::modifypic3()
{   int r, g ,b;
    QString imagename;
     switch(ui->comboBox_3->currentIndex())

        { case 0:
            r = 255, g = 156, b = 110;
            break;
          case 1:
            r = 237, g = 122, b = 54;
            break;
          case 2:
            r = 231, g = 112, b = 85;
            break;
          case 3:
            r = 223, g = 103, b = 96;
            break;
          case 4:
            r = 202, g = 87, b = 81;
            break;
          case 5:
            r = 218, g = 63, b = 75;
            break;
          case 6:
            r = 198, g = 55, b = 70;
            break;
          case 7:
            r = 200, g = 34, b = 73;
            break;

        }

        imagename += "lena3.jpg";


    img = this->imagemodify(img, r , g, b,imagename);

    ui->_3urobilinogen->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::modifypic4()
{   int r, g ,b;
    QString imagename;
     switch(ui->comboBox_4->currentIndex())

        { case 0:
            r = 212, g = 224, b = 90;
            break;
          case 1:
            r = 162, g = 207, b = 98;
            break;
          case 2:
            r = 135, g = 199, b = 101;
            break;
          case 3:
            r = 118, g = 189, b = 27;
            break;
          case 4:
            r = 107, g = 192, b = 103;
            break;
          case 5:
            r = 117, g = 164, b = 96;
            break;
          case 6:
            r = 94, g = 145, b = 93;
            break;

        }
     imagename+="lena4.jpg";
      img = this->imagemodify(img, r , g, b, imagename);

    ui->_4protein->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::modifypic5()
{   int r, g ,b;
    QString imagename;
     switch(ui->comboBox_5->currentIndex())

        { case 0:
            r = 219, g = 63, b = 40;
            break;
          case 1:
            r = 229, g = 73, b = 50;
            break;
          case 2:
            r = 224, g = 126, b = 38;
            break;
          case 3:
            r = 227, g = 160, b = 35;
            break;
          case 4:
            r = 188, g = 181, b = 49;
            break;
          case 5:
            r = 101, g = 132, b = 65;
            break;
          case 6:
            r = 72, g = 129, b = 67;
            break;
          case 7:
            r = 20, g = 89, b = 64;
            break;
        }



     imagename+="lena5.jpg";
    img = this->imagemodify(img, r , g, b, imagename);

    ui->_5calcium->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::modifypic6()
{   int r, g ,b;
    QString imagename;
     switch(ui->comboBox_6->currentIndex())

        { case 0:
            r = 252, g = 186, b = 97;
            break;
          case 1:
            r = 252, g = 186, b = 97;
            break;
          case 2:
            r = 185, g = 151, b = 100;
            break;
          case 3:
            r = 141, g = 155, b = 107;
            break;
          case 4:
            r = 101, g = 120, b = 100;
            break;
          case 5:
            r = 85, g = 78, b = 78;
            break;
          case 6:
            r = 75, g = 51, b = 82;
            break;

        }



    if(ui->comboBox_6->currentIndex() == 1)
    {
        if(!img->load("lena6x.jpg"))
       {
           //qDebug()<<"can't open image\n";
       }
       // salt(img,1500);

    }
    else
    {   imagename+="lena6.jpg";
        img = this->imagemodify(img, r , g, b,imagename);


    }
    ui->_6PH->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::modifypic7()
{   int r, g ,b;
    QString imagename;
     switch(ui->comboBox_7->currentIndex())

        { case 0:
            r = 36, g = 52, b = 62;
            break;
          case 1:
            r = 58, g = 52, b = 61;
            break;
          case 2:
            r = 67, g = 87, b = 69;
            break;
          case 3:
            r = 120, g = 106, b = 69;
            break;
          case 4:
            r = 154, g = 139, b = 70;
            break;
          case 5:
            r = 190, g = 162, b = 69;
            break;
          case 6:
            r = 210, g = 170, b = 66;
            break;

        }
     imagename+="lena7.jpg";
        img = this->imagemodify(img, r , g, b,imagename);

    ui->_7vitaminC->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::modifypic8()
{   int r, g ,b;
    QString imagename;
     switch(ui->comboBox_8->currentIndex())

        { case 0:
            r = 203, g = 124, b = 88;
            break;
          case 1:
            r = 208, g = 114, b = 105;
            break;
          case 2:
            r = 180, g = 49, b = 70;
            break;
          case 3:
            r = 169, g = 38, b = 59;
            break;
          case 4:
            r = 165, g = 23, b = 67;
            break;
          case 5:
            r = 123, g = 32, b = 71;
            break;
          case 6:
            r = 122, g = 13, b = 60;
            break;
          case 7:
            r = 97, g = 6, b = 45;
            break;
        }
     imagename+="lena8.jpg";
      img = this->imagemodify(img, r , g, b,imagename);

    ui->_8occult_blood->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::modifypic9()
{   int r, g ,b;
    QString imagename;
     switch(ui->comboBox_9->currentIndex())

        { case 0:
            r = 254, g = 205, b = 100;
            break;
          case 1:
            r = 253, g = 204, b = 125;
            break;
          case 2:
            r = 196, g = 124, b = 92;
            break;
          case 3:
            r = 165, g = 101, b = 88;
            break;

        }
     imagename+="lena9.jpg";
        img = this->imagemodify(img, r , g, b,imagename);

    ui->_9amylaceum->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::modifypic10()
{   int r, g ,b;
    QString imagename;
     switch(ui->comboBox_10->currentIndex())

        { case 0:
            r = 100, g = 143, b = 130;
            break;
          case 1:
            r = 63, g = 130, b = 94;
            break;
          case 2:
            r = 88, g = 125, b = 89;
            break;
          case 3:
            r = 73, g = 110, b = 74;
            break;
          case 4:
            r = 151, g = 119, b = 64;
            break;
          case 5:
            r = 110, g = 37, b = 49;
            break;
          case 6:
            r = 86, g = 20, b = 48;
            break;

        }
     imagename+="lena10.jpg";
    img = this->imagemodify(img, r , g, b,imagename);

    ui->_10bilirubin->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::modifypic11()
{   int r, g ,b;
    QString imagename;
     switch(ui->comboBox_11->currentIndex())

        { case 0:
            r = 4, g = 1, b = 15;
            break;
          case 1:
            r = 0, g = 61, b = 37;
            break;
          case 2:
            r = 35, g = 96, b = 72;
            break;
          case 3:
            r = 56, g = 154, b = 72;
            break;
          case 4:
            r = 193, g = 203, b = 31;
            break;
          case 5:
            r = 212, g = 183, b = 40;
            break;
          case 6:
            r = 199, g = 159, b = 55;
            break;

     }
     imagename+="lena11.jpg";
       img = this->imagemodify(img, r , g, b,imagename);

    ui->_11acetone_bodies->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::modifypic12()
{   int r, g ,b;
    QString imagename;
     switch(ui->comboBox_12->currentIndex())

        { case 0:
            r = 245, g = 173, b = 206;
            break;
          case 1:
            r = 242, g = 135, b = 182;
            break;
          case 2:
            r = 206, g = 99, b = 146;
            break;
          case 3:
            r = 133, g = 92, b = 113;
            break;
          case 4:
            r = 107, g = 66, b = 87;
            break;
          case 5:
            r = 134, g = 20, b = 116;
            break;
          case 6:
            r = 110, g = 20, b = 85;
            break;
          case 7:
            r = 79, g = 0, b = 54;
            break;
        }
     imagename+="lena12.jpg";
       img = this->imagemodify(img, r , g, b, imagename);

    ui->_12specific_gravity_of_urine->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::updateQRImage()
{


    int level_index = 1;
    int version_index = 0;
    bool bExtent = true;
    int mask_index = -1;

    QString encode_string = ui->lineEdit->text();
    char *s = const_cast<char *>(encode_string.toStdString().data());
    successfulEncoding = qrEncode.EncodeData(level_index,
                                             version_index,
                                             bExtent,
                                             mask_index,
                                             s);

    if (!successfulEncoding)
    {

        return;
    }

    int qrImageSize = qrEncode.m_nSymbleSize;

    encodeImageSize = qrImageSize + ( 0 * 2 );
    QImage encode_image( encodeImageSize, encodeImageSize, QImage::Format_Mono );
    encode_image.fill( 1 );

    for ( int i = 0; i < qrImageSize; i++ )
        for ( int j = 0; j < qrImageSize; j++ )
            if ( qrEncode.m_byModuleData[i][j] )
                encode_image.setPixel( i + 0, j + 0, 0 );
    //salt(&encode_image,50);
    encode_image.save("qr.bmp");
    ui->QRcode->setPixmap( QPixmap::fromImage( encode_image ) );
    int scale = 10;
    int scale_size = encodeImageSize*scale;

    const QPixmap & scale_image = ui->QRcode->pixmap()->scaled( scale_size, scale_size );
    ui->QRcode->setPixmap( scale_image );
    //setScale(0);

   // ui->pButtonSave->setEnabled( successfulEncoding );
}


void MainWindow::generate()
{
    currentname = ui->lineEdit->text();
    if(ui->lineEdit->text().size() != 0)
    {
        if(!numAdjustFlag)
            {
                num++;

                 ui->statusBar->showMessage(currentname+" 已生成",2000);

                ui->lineEdit->setText("编号"+QString::number(num));
            }
            else {
                //numAdjustFlag = 0;
                ui->statusBar->showMessage(currentname+" 已生成",2000);
            }
        this->setWindowTitle("艾蓓乐图片 ----- " + currentname);
    }
    else
    {
        QMessageBox::about(NULL, "提示", "编号为空，请输入编号。");
    }

    QPoint topLeft = upperLayout->cellRect(0,0).topLeft();
    QPoint buttomRight = upperLayout->cellRect(3,3).bottomRight();
  //  qDebug() << topLeft;
   // qDebug() << buttomRight;

   // upperLayout->setHorizontalSpacing(53);
   // upperLayout->setVerticalSpacing(45);

}

void MainWindow::savetopic()
{
   // QRect rect(QPoint(0,15),QPoint(500,438));
    //QRect rect = (upperLayout->cellRect(0,0).topLeft(),upperLayout->cellRect(3,3).bottomRight());
    QPoint topLeft = upperLayout->cellRect(0,0).topLeft();
    QPoint buttomRight = upperLayout->cellRect(3,3).bottomRight();
    buttomRight.ry()+=20;
    buttomRight.rx()+=10;
    topLeft.rx()-=9;
    QRect rect(topLeft,buttomRight);

    QPixmap pixmap = QWidget::grab(rect);
    if(!numAdjustFlag)
    {
        if(num != 1)
        {
            ui->statusBar->showMessage(currentname+" 已保存",2000);
            pixmap.save(diretory+"/"+currentname+".jpg", "jpg");
        }
        else {
            QMessageBox::about(NULL, "提示", "尚未生成，请先生成再保存");
            ui->statusBar->showMessage("尚未生成，请先生成再保存");
        }
    }
    else
    {
        if(num != 1)
        {ui->statusBar->showMessage(currentname+" 已保存",2000);
            pixmap.save(diretory+"/"+currentname+".jpg", "jpg");}
        else
        {
            QMessageBox::about(NULL, "提示", "尚未生成，请先生成再保存");
            ui->statusBar->showMessage("尚未生成，请先生成再保存");
        }
    }
}

void MainWindow::numadjust()
{
    numAdjustFlag = 1;
    num = 0;
}

void MainWindow::selectdiretory()
{
    QString temp = diretory;
    diretory = QFileDialog::getExistingDirectory(this, tr("打开文件路径"),
                                                 diretory,
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    if(diretory.size() == 0)
        diretory = temp;
    ui->directory->setText(diretory);
}

QImage* MainWindow::imagemodify(QImage *img,int r,int g, int b, QString picname)
{   int height = img->height();
    int width = img->width();
        for(int i = 0; i < height; i++)
            for(int j = 0; j < width; j++)
            {
                *(img->bits()+(i*width+j)*4) = b;
                *(img->bits()+(i*width+j)*4+1) = g;
                *(img->bits()+(i*width+j)*4+2) = r;
               // *(img->bits()+(i*width+j)*4+3) = 128;

            }

        //salt(img,1500);
        img->save(picname);
    return img;
}

/*QImage* MainWindow::salt(QImage *img, int n)
{
     int i,j;
     int height = img->height();
     int width = img->width();
     for (int k = 0; k < n; k++ )
     {
         i = rand()% img->width();
         j = rand()% img->height();


         *(img->bits()+(i*width+j)*4) = 255;
         *(img->bits()+(i*width+j)*4+1) = 255;
         *(img->bits()+(i*width+j)*4+2) = 255;

     }

    return img;


}*/

MainWindow::~MainWindow()
{
    delete ui;
}
