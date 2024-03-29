/* File     : ocsfs_widget.h
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : 2023年03月05日 星期日 01时13分49秒
*/

#ifndef _OCSFS_WIDGET_H
#define _OCSFS_WIDGET_H

#include <QTimer>
#include <QString>
#include <QSettings>
#include <QCheckBox>
#include <QComboBox>
#include <QPushButton>
#include <QMainWindow>
#include <QMessageBox>
#include <QVideoWidget>
#include <QCoreApplication>

#include <QtMultimedia>
#include <QMediaDevices>

class OCSFS_Widget: public QWidget {
    Q_OBJECT
private: 

    QSettings       *settings;

/* 组件 */
    
    /* 打开摄像头 */
    QPushButton     *open_camera;

    /* 关闭摄像头 */
    QPushButton     *close_camera;

    /* 列出摄像头下拉列表 */
    QComboBox       *camera_combobox;

    /* 摄像头组件 */
    QVideoWidget    *camera_view;

    /* 学生签到按钮 */
    QPushButton     *checkin_button;

    /* 学生确认点名按钮 */
    QPushButton     *rollcall_button;


/* 数据 */

    /* 选择的摄像头 */
    QCamera                                 *selected_camera;

    /* 摄像头列表 */
    QList<QCameraDevice>     *cameras_list;

    /* 连接器 */
    QMediaCaptureSession                    *capture_session;

    /* 媒体采集器 */
    QImageCapture                           *image_capture;

    /* 采集到的当前一帧画面, 该属性随刷新率变化而不断变化 */
    QImage                                  *camera_frame;

    /* 定时器，用于定时采集摄像头图像 */
    QTimer                                  *capture_timer;

private: 
    
    void camera_devices_refresh();

public: 
    OCSFS_Widget(QMainWindow *parent = nullptr);
    ~OCSFS_Widget();

signals: 
    void send_image_to_server(const QImage&);

    void response_mgr_check_in();
    void response_mgr_roll_call();
    void response_mgr_warning();

public slots:
    void slots_open_camera();
    void slots_close_camera();
    void slots_select_camera(const QString&);
    void slots_capture_camera_frame(int, const QImage&);
    void slots_timer_out();
    void slots_checkin_click();
    void slots_rollcall_click();

    void have_mgr_check_in(const QString &);
    void have_mgr_roll_call(const QString &);
    void have_mgr_warning(const QString &);
};

#endif
