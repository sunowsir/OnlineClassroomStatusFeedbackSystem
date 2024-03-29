/*
	* File     : ocsfs_client.h
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : 2023年05月20日 星期六 19时22分59秒
*/

#ifndef _OCSFS_CLIENT_H
#define _OCSFS_CLIENT_H

#include <string>
#include <iostream>

#include <QImage>
#include <QObject>
#include <QString>
#include <QBuffer>
#include <QtEndian>
#include <QTcpSocket>
#include <QByteArray>
#include <QMainWindow>

#include "ocsfs_define.h"

class OCSFS_Client : public QObject {
private:
    Q_OBJECT

    QMainWindow *mainwindow;
    
    QTcpSocket  *socket;

    QString     client_id;

    /* 
     * 0: 确认客户端类型，接收ID
     * 1: 准备确认
     * 2：工作中，传输正式工作数据
     * */
    uint8_t       step;

    QString     serv_ip;

private:
    bool send_data(const QString&, const QString&, const QString&);
    bool send_data_by_byte(const QString&, const QString&, const QByteArray&);
    bool parse_data(QString&, QString&, const QByteArray&, QByteArray&, int&);
    bool step0_handler(QByteArray &recv_data);
    bool step1_handler(QByteArray &recv_data);
    bool step2_handler(QString src_client_id, QByteArray &recv_data);

public: 
    OCSFS_Client(QMainWindow *mainwindow = nullptr);
    ~OCSFS_Client();

signals: 
    void login_to_server_success();
    void login_to_server_failed();
    void handshake_failed();
    void have_user_check_in(QString &);
    void have_user_roll_call(QString &);
    void have_user_warning_res(QString &);
    void have_user_status(QString&, int&);
    void have_user_status_image(QString&, QImage&);
    void have_user_ready(QString&);

    
public slots: 
    void recv_data();
    void connect_to_server(const QString&);
    void login_to_server(const QString&);

    void slot_checkin_click();
    void slot_rollcall_click(const QString&);
    void slot_click_send_warning(const QString&);
};

#endif
