//
//  FaceDetector.hpp
//  ejemplo
//
//  Created by Christian Alberto Dalma Schults on 4/25/19.
//  Copyright © 2019 Christian Alberto Dalma Schultz. All rights reserved.
//

#ifndef FaceDetector_hpp
#define FaceDetector_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>

class FaceDetector
{
private:
    cv::CascadeClassifier face_cascade;
    int next_height;
    long long flag;
public:
    FaceDetector(std::string face_cascade_name, int next_height_ = 40);
    FaceDetector();
    ~FaceDetector() {};
    std::vector<cv::Rect> nextFrame (cv::Mat frame);
    void ErrorHandling(long long &flag);
};

#endif /* FaceDetector_hpp */
