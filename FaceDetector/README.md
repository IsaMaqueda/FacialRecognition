# Face Recognition
## Project
This project contains a class called **FaceDetector.cpp** which calls the header **FaceDetector.h**
## Header (FaceDetector.h)
### Public
* ___FaceDetector(std::string face_cascade_name, int next_height_ = 40):__ Constructor hat recieves the path to the database that is going to be referred to when knowing what is a face in an image, it also sets the parameter of 'next_height' as 40, the prefered starting parameter for the function.
* __FaceDetector():__ Default constructor sets */usr/local/Cellar/opencv/4.0.1/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml* as the route for the faces database, also sets 40 as the starting parameter for 'next_height'.
* __~FaceDetector() {}:__ Destructor of the class.
* __std::vector<cv::Rect> nextFrame (cv::Mat frame):__ Function that recieves a frame, finds the faces inside the frame and returns a vector of rectangles containing the coordinates and sizes of every face in the frame.
* __void ErrorHandling(long long &flag):__  Error Handling

### Private
* __cv::CascadeClassifier face_cascade:__ Loads a CascadeClassifier object, which uses the functions needed to find the faces inside a frame.
* __int next_height:__ The height in pixels that is going to be used for looking for faces inside the frame during every itteration.

## Class (FaceDetector.cpp)
Contains the constructor that deffines a 'FaceDetector' object, which has 2 parameters: 
* __string face_cascade_name:__ Name of the path of the database containinfg the information needed to know what is a face.
* **int next_height_:** Int that is going to deffine number of pixels that are going to be used to search in faces in a frame, this variable id foing to be updated deppending on the size of the smallest face found in the last frame.

### vector<Rect> FaceDetector::nextFrame( Mat frame )
Function that recieves a frame and finds all the faces existing in that same frame, it returns a vector of Rect, which contains rectangles which have coordinates and sizes
