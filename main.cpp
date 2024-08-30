#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QString>
#include <QLineEdit>
#include "SerialPort/SerialPort.h"

using namespace std;

struct Serial_Port{
    Serial_Port(){
      COM = new char [10];
      str = new char[50];
    }
    char *COM;    // 串口名 COM1 | COM2 ...
    int baudrate;       // 波特率 2400、4800、9600、19200、38400、43000、56000、57600、115200
    char parity;        // 校验位 0为无校验，1为奇校验，2为偶校验，3为标记校验
    char databit;       // 数据位 通常为8位
    char stopbit;       // 停止位 1为1位停止位，2为2位停止位,3为1.5位停止位
    char *str;    // 填充数据
};

int main(int argc,char *argv[]) {

////    serial_port.str = "C2024A13A24A23A0A14A";
//    SerialPort.sendData(serial_port.COM,
//                             serial_port.baudrate,
//                             serial_port.parity,
//                             serial_port.databit,
//                             serial_port.stopbit,
//                             serial_port.str);

  // 应用程序对象
  QApplication app(argc, argv);
  // 创建窗口
  QWidget *window = new QWidget(); // 创建一个窗口对象
  // 设置窗口标题
  window->setWindowTitle("Serial port sending");
  // 设置窗口大小
  window->resize(600, 500);

  // 设置标签
  QLabel *label_COM = new QLabel("串口号：");
  label_COM->setParent(window);
  label_COM->move(170, 100);
  // 创建输入框
  QLineEdit *COM_input = new QLineEdit;
  COM_input->setParent(window);
  COM_input->setText("COM5");
  COM_input->setFixedSize(60, 30);
  COM_input->move(220, 90);
  // 设置标签
  QLabel *label_baudrate = new QLabel("波特率：");
  label_baudrate->setParent(window);
  label_baudrate->move(310, 100);
  // 创建输入框
  QLineEdit *baudrate_input = new QLineEdit;
  baudrate_input->setParent(window);
  baudrate_input->setText("4800");
  baudrate_input->setFixedSize(60, 30);
  baudrate_input->move(360, 90);
/****************************************************************************/
  // 设置标签
  QLabel *label_parity = new QLabel("校验位：");
  label_parity->setParent(window);
  label_parity->move(150, 150);
  // 创建输入框
  QLineEdit *parity_input = new QLineEdit;
  parity_input->setParent(window);
  parity_input->setText("0");
  parity_input->setFixedSize(40, 30);
  parity_input->move(200, 140);
  // 设置标签
  QLabel *label_databit = new QLabel("数据位：");
  label_databit->setParent(window);
  label_databit->move(250, 150);
  // 创建输入框
  QLineEdit *databit_input = new QLineEdit;
  databit_input->setParent(window);
  databit_input->setText("8");
  databit_input->setFixedSize(40, 30);
  databit_input->move(300, 140);
  // 设置标签
  QLabel *label_stopbit = new QLabel("停止位：");
  label_stopbit->setParent(window);
  label_stopbit->move(350, 150);
  // 创建输入框
  QLineEdit *stopbit_input = new QLineEdit;
  stopbit_input->setParent(window);
  stopbit_input->setText("1");
  stopbit_input->setFixedSize(40, 30);
  stopbit_input->move(400, 140);
/****************************************************************************/
  // 设置标签
  QLabel *label_str = new QLabel("设置时钟");
  label_str->setParent(window);
  QFont font = label_str->font();
  font.setPointSize(16); // 设置字体大小为16
  label_str->setFont(font);
  label_str->move(250, 200);

  // 年
  QLineEdit *str_year_input = new QLineEdit;
  str_year_input->setParent(window);
  str_year_input->setFixedSize(50, 30);
  str_year_input->move(200, 240);
  QLabel *label_year_str = new QLabel("年");
  label_year_str->setParent(window);
  label_year_str->move(250, 250);
  // 月
  QLineEdit *str_month_input = new QLineEdit;
  str_month_input->setParent(window);
  str_month_input->setFixedSize(50, 30);
  str_month_input->move(270, 240);
  QLabel *label_month_str = new QLabel("月");
  label_month_str->setParent(window);
  label_month_str->move(320, 250);
  // 日
  QLineEdit *str_day_input = new QLineEdit;
  str_day_input->setParent(window);
  str_day_input->setFixedSize(50, 30);
  str_day_input->move(340, 240);
  QLabel *label_day_str = new QLabel("日");
  label_day_str->setParent(window);
  label_day_str->move(390, 250);
/****************************************************************************/
  // 时
  QLineEdit *str_hour_input = new QLineEdit;
  str_hour_input->setParent(window);
  str_hour_input->setFixedSize(50, 30);
  str_hour_input->move(200, 290);
  QLabel *label_hour_str = new QLabel("时");
  label_hour_str->setParent(window);
  label_hour_str->move(250, 300);
  // 分
  QLineEdit *str_min_input = new QLineEdit;
  str_min_input->setParent(window);
  str_min_input->setFixedSize(50, 30);
  str_min_input->move(270, 290);
  QLabel *label_min_str = new QLabel("分");
  label_min_str->setParent(window);
  label_min_str->move(320, 300);
  // 秒
  QLineEdit *str_sec_input = new QLineEdit;
  str_sec_input->setParent(window);
  str_sec_input->setFixedSize(50, 30);
  str_sec_input->move(340, 290);
  QLabel *label_sec_str = new QLabel("秒");
  label_sec_str->setParent(window);
  label_sec_str->move(390, 300);
/****************************************************************************/
  // 创建一个按钮
  QPushButton *button_send = new QPushButton();
  button_send->setParent(window);
  button_send->setText("发送");
  button_send->setFixedSize(50, 30);
  button_send->move(260,390);

  QObject::connect(button_send, &QPushButton::clicked, window, [=]{
      Serial_Port serial_port;
      SerialPort SerialPort;
      std::string stdText = COM_input->text().toStdString();
      strcpy(serial_port.COM, stdText.c_str());
      serial_port.baudrate = baudrate_input->text().toInt();
      serial_port.parity = (char )parity_input->text().toInt();
      serial_port.databit = (char )databit_input->text().toInt();
      serial_port.stopbit = (char )stopbit_input->text().toInt();

      int label_year_str_length[6];
      label_year_str_length[0] = str_year_input->text().length();
      label_year_str_length[1] = str_month_input->text().length();
      label_year_str_length[2] = str_day_input->text().length();
      label_year_str_length[3] = str_hour_input->text().length();
      label_year_str_length[4] = str_min_input->text().length();
      label_year_str_length[5] = str_sec_input->text().length();

      QLineEdit *temp[6] = {str_year_input,str_month_input,str_day_input,str_hour_input,str_min_input,str_sec_input};
      char serial_data[100] = {'\0'};
      serial_data[0] = 'C';
      int k = 1;
      for (int i = 0; i < 6; ++i) {
        for (int j = k; j < k + label_year_str_length[i]; ++j) {
          serial_data[j] = temp[i]->text().at(j - k).toLatin1();
        }
        k = k + label_year_str_length[i];
        serial_data[k] = 'A';
        k++;
      }
      strcpy(serial_port.str, serial_data);
      SerialPort.sendData(serial_port.COM,
                          serial_port.baudrate,
                          serial_port.parity,
                          serial_port.databit,
                          serial_port.stopbit,
                          serial_port.str);
      qDebug() << "串口名:" << serial_port.COM;
      qDebug() << "波特率:" <<serial_port.baudrate;
      qDebug() << "校验位:" <<serial_port.parity;
      qDebug() << "数据位:" <<serial_port.databit;
      qDebug() << "停止位:" <<serial_port.stopbit;
      qDebug() << "发送数据:" <<serial_port.str;
  });

/****************************************************************************/
  window->show();     // 显示窗口
  return app.exec();  // 进入消息循环
}
