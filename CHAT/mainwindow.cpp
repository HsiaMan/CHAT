#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _login_dlg = new LoginDialog(this);
    //会让_login_dlg成为MainWindow 的child widget,Qt会接管其生命周期
    setCentralWidget(_login_dlg);
    // _login_dlg->show();
    //创建和注册消息链接
    connect(_login_dlg,&LoginDialog::switchRegister,this,&MainWindow::SlotSwitchReg);

    _reg_dlg = new RegisterDialog(this);
    //嵌入式界面切换，隐藏窗口边框，让对话框在主界面内部显示，不谈出独立窗口
    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    _reg_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    _reg_dlg->hide();
}

MainWindow::~MainWindow()
{
    // delete ui;
    // if(_login_dlg){
    //     delete _login_dlg;
    //     _login_dlg = nullptr;
    // }
    // if(_reg_dlg){
    //     delete _reg_dlg;
    //     _reg_dlg = nullptr;
    // }
}
void MainWindow::SlotSwitchReg(){
    setCentralWidget(_reg_dlg);
    _login_dlg->hide();
    _reg_dlg->show();
}


