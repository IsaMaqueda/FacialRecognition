#include <FaceAligner.hpp>

int main() {
	FaceAligner fa = FaceAligner("../shape_predictor_68_face_landmarks.dat");

		cv::Mat image = cv::imread("../samples/a2.bmp");

		cv::CascadeClassifier cascade;

		cascade.load("../cascades/haarcascade_frontalface_alt2.xml");
		std::vector<cv::Rect> faces;
		cascade.detectMultiScale(image, faces);

		cv::Mat result;
		for(auto&& face : faces)
		{
			//Using team's method
			fa.align(image, face, cv::Point(20, 22), cv::Point(52, 22), 72, 80, result);
			//Using dlib's method
			// fa.align(image, face, result);
			imshow("Face", result);
			cv::waitKey(0);
		}
}
