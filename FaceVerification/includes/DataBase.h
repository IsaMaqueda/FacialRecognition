#ifndef DATABASE_H
#define DATABASE_H

#include <sys/stat.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <opencv2/core.hpp>
#include <opencv2/flann/miniflann.hpp>
#include <opencv2/flann/flann_base.hpp>


struct PersonInfo {
    std::string id, matricula,name,lastName,img;
    int age;
};

class DataBase {
    private:
        cv::Mat descriptores;
        cv::flann::Index *flann_index;
        int n;
        std::string PersonInfoFile,featuresFile,nFile;
        std::fstream biographicalDB,biometricDB,N,featureDB;
        std::vector<PersonInfo> biograData;
        inline bool existsFile (const std::string& name);
        bool load_N_File();
        bool load_featuresFile();
        bool load_PersonInfoFile();

        bool ValidName(std::string word);
        int ValidateData(PersonInfo Data);
        bool ValidateMatricula(std::string matricula);

        bool DuplicatedMatricula(std::string mat);

		//Essential
        std::vector<std::string> indexData(std::string dataLine);
        PersonInfo String_To_Structure(std::string Data_As_String);
    
    public:
        DataBase();
        DataBase(std::string PersonInfoFile,std::string featuresFile,std::string nFile);
        cv::Mat getMatrix();
        cv::Mat getColumn(int num);
        cv::Mat getRow(int num);
        cv::Mat getBiometricByID(int ID);
        cv::Mat getfeatureByID(int ID);
        cv::Mat getfeatureByMatricula(std::string matricula);
        std::pair <cv::Mat,cv::Mat> search(cv::Mat elementoaBuscar,int K);
        PersonInfo getUserInfoByID(int ID);
        PersonInfo getUserInfoByMatricula(std::string matricula);
        bool saveUserDataInAFile(PersonInfo bio);
        bool saveUserfeatureDataInAFile(cv::Mat feature);
        //bool saveUserBiometricDataInAFile(cv::Mat feature);
        void saveUserImage(cv::Mat &image);
        bool getN();
        bool updateDataBase();
        void BackUp();
};
#endif
