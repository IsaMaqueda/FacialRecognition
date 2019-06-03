#include <Extract.h>

int main() {
	Extractor e;
	cv::Mat image = cv::imread("../samples/a2.bmp");
	cv::Mat m = e.extractVector(image);
	
	std::cout << m << '\n';
	
	return 0;
}