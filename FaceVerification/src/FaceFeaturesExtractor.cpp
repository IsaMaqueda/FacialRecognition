//DLIB FACE FEATURES EXTRACTOR
/*
*Analisis y Modelacion de software
*TEAM 3:Alexanda, Daniel, Moises, Alberto, Pablo
*/

#include "FaceFeaturesExtractor.h"
#include "ErrorHandling.h"

using namespace std;
using namespace cv;


FaceFeaturesExtractor::FaceFeaturesExtractor(){//Constructor with default path to the trained model
  deserialize("../dlib_face_recognition_resnet_model_v1.dat") >> net;//path is the downloaded trained model
  pixelSize = 150;
  flag = 0;
}

FaceFeaturesExtractor::FaceFeaturesExtractor(string path, int pixel){//Constructor for a specified path to a model
  deserialize(path) >> net;//use this in the case you have another trained model
  pixelSize = pixel;
  flag = 0;
}

FaceFeaturesExtractor::~FaceFeaturesExtractor(){}//Destructor

Mat FaceFeaturesExtractor::faceToVector(Mat &f){//Extracts features from an image
  //Check if it's not 150x150
  if (f.rows != pixelSize || f.cols != pixelSize){
    flag += ERROR_1_MODULE_3;
    resize(f, f, Size(pixelSize,pixelSize));  //Resize f to 150x150 to test
  }
  cv_image<bgr_pixel> image(f);//Transform Mat into a rgb_pixel matrix
  matrix<rgb_pixel> m;
  assign_image(m, image);
  std::vector<matrix<rgb_pixel>> face;// Create a matrix vector for the identified face
  face.push_back(m);//Push face

  std::vector<matrix<float,0,1>> face_descriptors = net(face);//Obtain the vectorial description from the face
  Mat descriptor;
  descriptor = toMat(face_descriptors[0]); //Save face_descriptors in memory
  ErrorHandling (flag);
  return descriptor.clone();//Return cloned to give values and not memory directions
}

double FaceFeaturesExtractor::compareVectors(Mat &a, Mat &b, double threshold){
  //Calculate Euclidian Distance
  double dist = norm(a,b, NORM_L2);

  //returns if both are the same person or not
  if (dist > threshold){
    cout << "ACCESS DENIED" << endl;
  }
  else {
    cout << "ACCESS GRANTED" << endl;
  }
  return dist;
}

void FaceFeaturesExtractor::ErrorHandling(long long &flag){
  if (flag & ERROR_1_MODULE_3){
    cout << "Module 3 Error... Image size not 150x150" << endl;
  }
}
