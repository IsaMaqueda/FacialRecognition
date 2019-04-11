#include "DataBase.h"
#include <opencv2/highgui/highgui.hpp>

using namespace cv::flann;
using namespace std;

using std::string;
using cv::Mat;
using std::vector;


int main()
{
    
    DataBase db("PersonInfo.txt","features.txt","N.txt");
    //DataBase db;
    //cout<<"hola"<<endl;
    Mat feat = db.getfeatureByID(1);
    //db.saveUserfeatureDataInAFile(feat);
    //cout<<"hola1"<<endl;
    std::cout<<std::get<0>(db.search(feat,1))<<std::endl;
    /*cout<<"hola2"<<endl;
    //std::cout<<db.getRow(0)<<std::endl;
    cout<<"hola3"<<endl;
    std::cout << db.getMatrix().at<float>(0,1);
    cout<<"hola4"<<endl;
    std::cout << db.getMatrix()<<std::endl;
    cout<<"hola5"<<endl;*/
    db.BackUp();
    
    return 0;
}
