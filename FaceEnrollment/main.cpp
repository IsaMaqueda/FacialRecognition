#include "FaceEnrollment.cpp"
#include "../FaceFeaturesExtraction/FaceFeaturesExtractor.h"


using namespace std;
using namespace cv;


int main(){
  FaceFeaturesExtractor f;
  Mat img = imread("../test1.jpg",1);
  Mat v = f.faceToVector(img);
  DataBase a1;
  FaceIdentification f1;
  PersonInfo bio;
  bio.id = "1";
  bio.matricula = "a01421434";
  bio.name = "Pablo";
  bio.lastName = "Teran";
  bio.img = "../test1.jpg";
  bio.age = 21;

  FaceEnrollment fe(a1,f1);
  fe.enroll(bio,v,img);




}
