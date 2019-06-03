//FACE ENROLLMENT
/*
*Analisis y Modelacion de software
*TEAM 3:Alexanda, Daniel, Moises, Alberto, Pablo
*/

#include <iostream>
#include "FaceEnrollment.h"
#include "../ErrorHandling/ErrorHandling.h"

using namespace std;
using namespace cv;


FaceEnrollment::FaceEnrollment(DataBase &db1, FaceIdentification &fi1){
  db = db1;
  fi = fi1;
  flag = 0;
}

FaceEnrollment::~FaceEnrollment(){}

void FaceEnrollment::enroll(PersonInfo &bio, Mat &vec, Mat &img){

  //pair<int, vector<pair<PersonInfo, float>>> p = fi.identificate(vec, db, 10);//compara con 10 personas y se puede cambiar
  int bl = 0;//p.first;
  if (bl == 0){
    db.saveUserDataInAFile(bio);
    db.saveUserfeatureDataInAFile(vec);
    db.saveUserImage(img);
    flag += ANSWER_1_PERSON_ENROLLED_SUCCESSFULLY;
  }
  else {
    flag += ERROR_1_PERSON_ALREADY_ENROLLED;
  }
  ErrorHandling(flag);
}

void FaceEnrollment::ErrorHandling(long long &flag){
  if (flag & ERROR_1_PERSON_ALREADY_ENROLLED){
    cout << "Module 7 Error... Person is already enrolled." << endl;
  }
  if (flag & ANSWER_1_PERSON_ENROLLED_SUCCESSFULLY){
    cout << "Module 7 Answer... Person successfully enrolled." << endl;
  }
}
