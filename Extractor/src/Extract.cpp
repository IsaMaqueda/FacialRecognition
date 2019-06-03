//GLOBAL EXTRACTOR
/*
*Analisis y Modelacion de software
*Clase para extraer los vectores de una imagen
*/

#include <Extract.h>

using namespace std;
using namespace cv;


Extractor::Extractor(){}

Extractor::~Extractor(){}

Mat Extractor::extractVector(Mat &img){
	Mat vec;

	std::vector<Rect> v = d.nextFrame(img);
	for (auto rect : v) {
		vec = a.align(img, rect, Point(50, 50), Point(100, 50), 150, 150);
		vec = e.faceToVector(vec);
	}
	return vec;
}

