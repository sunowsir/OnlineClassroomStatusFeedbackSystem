/*
	* File     : ocsfs_image_converter.h
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : 2023年03月13日 星期一 20时48分55秒
*/

#ifndef _OCSFS_IMAGE_CONVERTER_H
#define _OCSFS_IMAGE_CONVERTER_H

#include <dlib/opencv.h>
#include <dlib/image_io.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>

#include <QImage>
#include <QCoreApplication>

/* 图片转换器 */
class OCSFS_Image_Converter {
private: 
    
public: 
    OCSFS_Image_Converter();
    ~OCSFS_Image_Converter();

    bool qimage_2_mat(const QImage&, cv::Mat&);
    bool mat_2_qimage(const cv::Mat&, QImage&);
};

#endif
