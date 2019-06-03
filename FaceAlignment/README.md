# Face Recognition System: Team 2 (Face Alignment)

As part of the project of the *Análisis y modelación de sistemas de software* (TC2004) course by Leonardo Chang Fernández we were given the task of creating one of five modules in order to develop a facial recognition system.

## Main Objective

This module receives as input an image and the region of the face in it. The module must be able to detect on the face region several landmark points that will serve as reference for the transformations needed to obtain an aligned face, which is also the objective of this module.

## Important Dates

|     Activity     |     Date     |
|:----------------:|:------------:|
|  First iteration |  February 28 |
| Second iteration |    April 1   |
| Final evaluation |    May 17    |

## Requirements

### Functional

The program will be able to align a face image given the following template (specified by Team 3):
- Scale must be 72x80px.
- Left and right eye coordinates must be (20, 22) and (52, 22) respectively.

### Non-functional

The program should be developed in the following way:
- Team of 5 people.
- The development must follow the iterative model with **two iterations** and a final delivery.
- Must be able to run on 4GB RAM PC.
- Must be multiplatform.
- To be delivered on **May 17th**.
- The programming language used is C++.
- The support library is OpenCV-4 (using CMake).

## Instructions

---

Use the `test.cpp` to test the FaceAligner class. The module uses CMake. To use it simply (from current directory) run cmake. (CMake and make should be installed)

**Linux/Mac**

```bash
mkdir build
cd build
cmake ..
make main && ./main
```

For windows you is almost the same

**Windows**

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Project

This module just has the module `FaceAligner` class which contains two methods:

```cpp
void align(cv::Mat image, cv::Rect face, cv::Point left_eye_coordinates, cv::Point right_eye_coordinates, int width, int height, cv::Mat &dst);
```

The first method works by detecting the face landmarks using dlib and aligning the face using opencv. The landmarks are obtained by using `shape_predictor sp` which returns a `full_object_detection` which is just a series of points. We transform these points to `cv::Point` class in order to align the face using each eye's landmark point.

Before the alignment we scale the image by the factor obtained by the distance between the eyes' coordinates specified and the actual distance in the image. After this we obtain the ROI containing the face and save it on a `cv::Mat` which we then rotate accordingly to the eyes' coordinates specified.

```cpp
void align(cv::Mat &img, cv::Rect face, cv::Mat &dst);
```

This method is much simpler as it uses the align method implemented by dlib which gives the aligned face in a 150X150 image with the eyes aligned horizontally.

*Note: For more details checkout the code. Any doubts can be sent to eecanton@gmail.com*