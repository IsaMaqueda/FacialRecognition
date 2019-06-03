//FACE ENROLLMENT header
/*
*Analisis y Modelacion de software
*TEAM 3:Alexanda, Daniel, Moises, Alberto, Pablo
*/

#ifndef FACEENROLLMENT_H
#define FACEENROLLMENT_H

#include "../FaceIde/FaceIdentification.h"
#include "../FaceIde/DataBase.h"

class FaceEnrollment {
private:
  DataBase db;
  FaceIdentification fi;
  long long flag;
public:
  FaceEnrollment(DataBase &db1, FaceIdentification &fi1);
  ~FaceEnrollment();
  void enroll(PersonInfo &bio, cv::Mat &vec, cv:: Mat &img);
  void ErrorHandling(long long &flag);
};

#endif
