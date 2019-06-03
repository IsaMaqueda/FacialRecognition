#include <Extract.h>
#include <DataBase.h>
#include <FaceIdentification.h>
#include <opencv2/highgui/highgui.hpp>

using namespace cv::flann;
using namespace std;

using std::string;
using cv::Mat;
using std::vector;

int main()
{
    FaceIdentification face_identification;
	Extractor e;

    DataBase db("PersonInfo.txt","features.txt","N.txt");
    cv::Mat feat = e.extractVector(image);
    std::pair<int, std::vector<std::pair<PersonInfo, float>>> result_case;
    result_case = face_identification.identificate(feat,db,1);
    
    
    if (result_case.first == 1) {
        cv::Mat recognized_image;
        recognized_image = cv::imread(result_case.second.at(0).first.img, cv::IMREAD_COLOR);
        
        std::cout << "La persona fue reconocida en la base de datos como: " << result_case.second.front().first.name << " " << result_case.second.front().first.lastName << " con la matrícula: " << result_case.second.front().first.matricula << "\n";
    } else {
        std::cout << "La persona no fue reconocida\n";
    }
    
    return 0;
}
