#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opencv2/opencv.hpp"
using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    Mat image;
    // 此图片是我放在桌面的一张图片，改为你想显示的图片的路径
    image = imread("/Users/wyl/Desktop/wu.jpg", IMREAD_UNCHANGED);
    namedWindow("Image", WINDOW_AUTOSIZE);
    //    InputArray mat
    imshow("Image", image);


}

MainWindow::~MainWindow()
{
    delete ui;
}

