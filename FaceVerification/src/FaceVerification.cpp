#include "FaceVerification.h"

FaceVerification::FaceVerification() {};

std::pair<bool, PersonInfo> FaceVerification::verify(cv::Mat &to_verify, std::string matricula,  DataBase &db, double threshold) {
	PersonInfo p_info;
	cv::Mat p_feature;
	float distance;
	bool is_p;

	p_info = db.getUserInfoByMatricula(matricula);
	p_feature = db.getfeatureByMatricula(matricula);
	is_p = ffe.compareVectors(to_verify, p_feature, threshold);

	return {is_p, p_info};
}