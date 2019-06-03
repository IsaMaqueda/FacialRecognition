
#include <iostream>
#include <string>
#include <DataBase.h>
#include <opencv2/opencv.hpp>
#include <FaceFeaturesExtractor.h>

class FaceVerification {
	private:
		FaceFeaturesExtractor ffe;
	public:
		FaceVerification();
		std::pair <bool, PersonInfo> verify(cv::Mat &to_verify, std::string matricula, DataBase &db, double threshold = 0.6);
};
