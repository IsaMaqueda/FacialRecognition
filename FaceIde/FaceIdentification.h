
#include <sys/stat.h>
#include <iostream>
#include <vector>
#include "DataBase.h"

class FaceIdentification
{
public:
    FaceIdentification();
    std::pair <int, std::vector<std::pair<PersonInfo,float>>> identificate(cv::Mat ide, DataBase &db, int compare);
    
};
