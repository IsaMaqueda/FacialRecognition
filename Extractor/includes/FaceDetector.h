//
//  FaceDetector.hpp
//  ejemplo
//
//  Created by Christian Alberto Dalma Schults on 4/25/19.
//  Copyright © 2019 Christian Alberto Dalma Schultz. All rights reserved.
//

#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

class FaceDetector
{
private:
    cv::CascadeClassifier face_cascade;
    int next_height;
public:
    FaceDetector(std::string face_cascade_name, int next_height_ = 40);
    FaceDetector();
    ~FaceDetector();
    std::vector<cv::Rect> nextFrame (cv::Mat &frame);
};

#endif /* FaceDetector_hpp */
