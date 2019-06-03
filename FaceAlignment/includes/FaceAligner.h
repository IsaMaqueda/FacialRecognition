/************************************************************************************************************************
 Based on Manu BN implementation
 ***********************************************************************************************************************/

#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include "dlib/image_processing/shape_predictor.h"
#include <dlib/image_processing.h>
#include <dlib/opencv/cv_image.h>
#include <dlib/opencv.h>
#include <iostream>

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2/photo.hpp"

#include <ErrorHandling.h>


class FaceAligner {
private:
	dlib::shape_predictor sp;
	dlib::frontal_face_detector detector;

	long long flag;
	void dlib_point2cv_Point(dlib::full_object_detection &S, std::vector<cv::Point> &L, double &scale);
	void Rect2rectangle(cv::Rect &r, dlib::rectangle &rec);
public:
	FaceAligner();
	FaceAligner(std::string sp_file);
	~FaceAligner();
	cv::Mat align(cv::Mat &image, cv::Rect face, cv::Point left_eye_coordinates, cv::Point right_eye_coordinates, int width, int height);
//   int align(cv::Mat &img, cv::Rect face, cv::Mat &dst);
};
