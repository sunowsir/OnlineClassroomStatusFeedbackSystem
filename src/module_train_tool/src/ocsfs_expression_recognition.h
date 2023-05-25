/*
	* File     : ocsfs_expression_recognition.h
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : 2023年03月13日 星期一 21时10分42秒
*/

#ifndef _OCSFS_EXPREOCSFSON_RECOGNITION_H
#define _OCSFS_EXPREOCSFSON_RECOGNITION_H

#include <dlib/opencv.h>
#include <dlib/image_io.h>
#include <opencv2/opencv.hpp>
#include <dlib/gui_widgets.h>
#include <opencv2/imgproc/types_c.h>
#include <dlib/image_processing.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>

#include <QDir>
#include <QImage>
#include <QString>
#include <QCoreApplication>

#include "ocsfs_image_converter.h"
#include "ocsfs_face_recognition.h"
#include "ocsfs_define.h"


namespace ns_fs = std::filesystem;
namespace ns_CVML = cv::ml;

/* 表情识别器 */
class OCSFS_Expression_Recognition {
private: 
    cv::Ptr<ns_CVML::SVM>   svm;

    /* 人脸识别器 */
    OCSFS_Face_Recognition    *sfr;

public:
    OCSFS_Expression_Recognition(const QString& /* module file path */);
    ~OCSFS_Expression_Recognition();

    /* 表情识别，传入图片，获得表情 */
    bool recognize(const QImage&, int& /* face type */);
};

#endif
