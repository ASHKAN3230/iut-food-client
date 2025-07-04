#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QJsonObject>
#include <string>
#include <QTcpSocket>
#include <QTcpServer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void run();

    void click_login_button();

    std::string message;

    void receive_message();

    QTcpSocket socket;

    ~MainWindow();

signals:

    void click();

    void click_server();

public slots:

    void open_signin_window();

    void open_forgot_window();

    void on_login_button_clicked();
    
    // Network manager slots
    void onLoginSuccess(const QJsonObject &userInfo);
    void onLoginFailed(const QString &error);
    void onNetworkError(const QString &error);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
