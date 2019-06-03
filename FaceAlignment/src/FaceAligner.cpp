/************************************************************************************************************************
 Based on Manu BN implementation
 ***********************************************************************************************************************/

#include <FaceAligner.h>


FaceAligner::FaceAligner(std::string sp_file)
{
	flag = 0;
	try {
		dlib::deserialize(sp_file) >> sp;
	} catch(dlib::serialization_error s) {
		flag += ERROR_1_MODULE_2;
	}
}

FaceAligner::FaceAligner() {
	flag = 0;
	#ifdef _WIN64
		try {
		dlib::deserialize("..\\shape_predictor_68_face_landmarks.dat") >> sp;
	} catch(dlib::serialization_error s) {
		flag += ERROR_2_MODULE_2;
	}
	#elif __linux__ && !__ANDROID__
		try {
			dlib::deserialize("../shape_predictor_68_face_landmarks.dat") >> sp;
		} catch(dlib::serialization_error s) {
			flag += ERROR_2_MODULE_2;
		}
#else
		flag += ERROR_3_MODULE_2;
FaceAligner::~FaceAligner() {};

void FaceAligner::Rect2rectangle(cv::Rect &r, dlib::rectangle &rec)
{
	rec = dlib::rectangle((long)r.tl().x, (long)r.tl().y, (long)r.br().x - 1, (long)r.br().y - 1);
}

void FaceAligner::dlib_point2cv_Point(dlib::full_object_detection &S, std::vector<cv::Point> &L, double &scale)
{
	for (unsigned int i = 0; i < S.num_parts(); ++i)
	{
		L.push_back(cv::Point(S.part(i).x() * (1 / scale), S.part(i).y() * (1 / scale)));
	}
}

//Obtains the rectangle that contains a face in the image and aligns it according to left_eye_coordinates, right_eye_coordinates and stores it on dst of size width*height
cv::Mat FaceAligner::align(cv::Mat &image, cv::Rect face, cv::Point left_eye_coordinates, cv::Point right_eye_coordinates, int width, int height)
{
	if(left_eye_coordinates.x > width || left_eye_coordinates.x < 0 || right_eye_coordinates.x > width || right_eye_coordinates.x < 0) {
		flag += ERROR_4_MODULE_2;
	}
	if(left_eye_coordinates.y > height || left_eye_coordinates.y < 0 || right_eye_coordinates.y > height || right_eye_coordinates.y < 0) {
		flag += ERROR_5_MODULE_2;
	}
	
	//Convert the cv::Rect to dlib::rectangle to detect using dlib
	dlib::rectangle dlib_face;
	Rect2rectangle(face, dlib_face);
	//Convert cv::Mat to dlib::image
	if(image.channels() == 3) {
		dlib::array2d<dlib::bgr_pixel> dlib_img;
		dlib::assign_image(dlib_img, dlib::cv_image<dlib::bgr_pixel>(image));
	} else {
		flag += ERROR_6_MODULE_2;
	}
	//Detect the current face's landmarks
	double scale = 1;
	std::vector<cv::Point> landmarks;
	dlib::full_object_detection shape = sp(dlib_img, dlib_face);
	//Store the landmarks as cv::Point s
	dlib_point2cv_Point(shape, landmarks, scale);
	//To store the scaled data
	cv::Mat scaled;
	cv::Point scaled_left_eye, scaled_right_eye;
	double scale_factor;
	//landmarks[47] is the right eye and landmarks[41] is the left eye
	double distance_x = landmarks[47].x - landmarks[41].x;
	double distance_y = landmarks[47].y - landmarks[41].y;
	double new_distance_x = left_eye_coordinates.x - right_eye_coordinates.x;
	double new_distance_y = left_eye_coordinates.y - right_eye_coordinates.y;
	//Get the hypotenuse of the of the triangle formed by the face's eyes
	double distance = sqrt(pow(distance_x, 2) + pow(distance_y, 2));
	//Get the hypotenuse of the of the triangle formed by the eyes' coordinates given
	double new_distance = sqrt(pow(new_distance_x, 2) + pow(new_distance_y, 2));
	//To scale the image as necessary
	scale_factor = new_distance / distance;
	//Scale the eyes
	scaled_left_eye.x = round(landmarks[47].x * scale_factor);
	scaled_left_eye.y = round(landmarks[47].y * scale_factor);
	scaled_right_eye.x = round(landmarks[41].x * scale_factor);
	scaled_right_eye.y = round(landmarks[41].y * scale_factor);
	//Scale the image
	cv::resize(image, scaled, cv::Size(), scale_factor, scale_factor, cv::INTER_AREA);
	//Get the cv::Rect that contains the new (scaled face)
	cv::Rect rect = cv::Rect(scaled_right_eye.x - left_eye_coordinates.x, scaled_right_eye.y - left_eye_coordinates.y, width, height);
	cv::Mat roi = scaled(rect);
	/*
	Get the desired angle (given by the eyes' coordinates in arguments) and the necessary angle (to be on horizontal) to obtain
	the total angle needed.
	*/
	double necessary_rotation = atan(distance_y / distance_x) * 180 / M_PI;
	double rotation_angle = necessary_rotation + (atan(new_distance_y / new_distance_x) * 180 / M_PI);
	std::cout << "Angle: " << rotation_angle << '\n';
	//Rotate the image according to the angle needed
	cv::Point2f rotation_center(roi.cols / 2., roi.rows / 2.);
	cv::Mat rotation = cv::getRotationMatrix2D(rotation_center, rotation_angle, 1.0);
	cv::Rect bbox = cv::RotatedRect(rotation_center, roi.size(), rotation_angle).boundingRect();
	rotation.at<double>(0, 2) += bbox.width / 2.0 - rotation_center.x;
	rotation.at<double>(1, 2) += bbox.height / 2.0 - rotation_center.y;
	cv::warpAffine(roi, roi, rotation, bbox.size());
	//Return the face aligned
	printf("%dX%d\n", roi.rows, roi.cols);
	cv::Rect f(0, 0, width, height);
	return roi(f);
};

void ErrorHandling() {
	if (flag & ERROR_1_MODULE_2) {
		std::cout << "Error while trying to deserialize .dat file: Wrong file name or file path" << '\n';
	}
	else if (flag & ERROR_2_MODULE_2) {
		std::cout << "Error while trying to deserialize .dat file: File not available on correct path" << '\n';
	}
	else if (flag & ERROR_3_MODULE_2) {
		std::cout << "Unable to resolve operating system in order to obtain .dat file from default path (..\\[.dat file])"
	}
	else if(flag & ERROR_4_MODULE_2) {
		std::cout << "Left or right 'x' coordinates out of range" << '\n';
	}
	else if (flag & ERROR_5_MODULE_2) {
		std::cout << "Left or right 'y' coordinates out of range" << '\n';
	}
	else if (flag & ERROR_6_MODULE_2) {
		std::cout << "Image passed to FaceAligner::align() has other than 3 channels (rgb)" << '\n';
	}
}

// int FaceAligner::align(cv::Mat &img, cv::Rect face, cv::Mat &dst)
// {
// 	// RGB image to dlib
// 	dlib::array2d<dlib::bgr_pixel> dlib_img;
// 	dlib::assign_image(dlib_img, dlib::cv_image<dlib::bgr_pixel>(img));

// 	//Convert cv::Rect to dlib::rectangle (face)
// 	dlib::rectangle dlib_face;
// 	Rect2rectangle(face, dlib_face);
// 	//Get all the landmarks from the face
// 	dlib::full_object_detection shape = sp(dlib_img, dlib_face);
// 	//Align the image using dlib's method. Which returns a 150X150 image with eyes horizontally aligned
// 	dlib::array2d<dlib::bgr_pixel> face_chip;
// 	extract_image_chip(dlib_img, get_face_chip_details(shape), face_chip);
// 	//Return the aligned face
// 	dst = dlib::toMat<dlib::array2d<dlib::bgr_pixel>>(face_chip);
// 	return 0;
// }