//main.cpp
/*
*Analisis y Modelacion de software
*TEAM 3:Alexanda, Daniel, Moises, Alberto, Pablo
*/

#include "FaceFeaturesExtractor.cpp"
#include <iostream>

int main(){
  FaceFeaturesExtractor r; //Creates FaceFeaturesExtractor Object

  //Read first image
  Mat img = imread("../test1.jpg",1);
  //Check if the image is read
  if (img.empty())
    cout << "ERROR: empty image" << endl;

  //Read second image (Simulates image/vector extracted from de DBMS)
  Mat img2 = imread("../test1.jpg",1);
  //Check if the image is read
  if (img2.empty())
    cout << "ERROR: empty image2" << endl;

  //Use FaceFeaturesExtractor to get vectors.
  //In case your second vector comes from the DBMS delete v2 line.
  Mat v = r.faceToVector(img);
  Mat v2 = r.faceToVector(img2);
  //cout << v << endl; //Use this if you want to see vector from img
  //cout << v2 << endl; //Use this if you want to see vector from img2

  //Show images (Images are already resized inside the faceToVector method)
  imshow("Imagen 1", img);
  imshow("Imagen 2", img2);

  //Compare images using Euclidian Distance
  //Documentation threshold 0.5
  //Documentation accuracy 0.99383
  double ans = r.compareVectors(v,v2);
  cout << ans << endl;
  //ans is the euclidian distance between vectors compared
  //Inside compareVectors a phrase is printed to know if the vector is accepted or not


  waitKey(0);//Desplay images for X ms(0 means until close)
  return 0;//End program
}
