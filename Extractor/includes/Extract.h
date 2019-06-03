//GLOBAL EXTRACTOR header
/*
*Analisis y Modelacion de software
*Clase para extraer los vectores de una imagen
*/

#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <FaceDetector.h>
#include <FaceAligner.h>
#include <FaceFeaturesExtractor.h>

class Extractor {
	private:
		FaceAligner a;
		FaceDetector d;
		FaceFeaturesExtractor e;
	public:
		Extractor();
		~Extractor();
		cv::Mat extractVector(cv::Mat &img);
};

#endif
