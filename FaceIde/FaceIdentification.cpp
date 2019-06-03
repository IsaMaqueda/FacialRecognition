#include "FaceIdentification.h"
#include <opencv2/opencv.hpp>



FaceIdentification::FaceIdentification(){}; // default constructor
    std::pair <int, std::vector<std::pair<PersonInfo,float>>> FaceIdentification::identificate(cv::Mat ide, DataBase &db, int compare)
    {
        bool found = false;
        std::vector<std::pair<PersonInfo, float>> person_info;
        std::pair<cv::Mat, cv::Mat> output;
        int index;
        float distance;
        std::pair<PersonInfo,float> temp;
        output = db.search(ide, compare);
        
        for(int i = 0; i < compare;i++)
        {
            index = output.first.at<int>(i,0);
            distance = output.second.at<float>(i,0);
            
            temp.first = db.getUserInfoByID(index);
            temp.second = distance;
            person_info.push_back(temp);
            found = true;
        }
        return {found, person_info};
    }
    


