# FACE FEATURES EXTRACTION

## Installing

Download or clone the complete folder/repository. 

Create a folder inside FaceFeaturesExtraction folder named build

### Linux (Ubuntu 18.10)

Go into the build folder you just created with command:
cd YOUR_PATH/build

Once inside the build folder use the command:
cmake ..

The .. will look for the CMakeList.txt just outside the build folder

Once every compiled file is downloaded use the command:
make

Make will create an executable called fr

Do the following command and the program will run:
./fr

## API 

For "FaceFeaturesExtractor.cpp"

* **FaceFeaturesExtractor()**
  Default constructor that sets the resnet file as "dlib_face_recognition_resnet_model_v1.dat" and the pixel size of the image as 150.

* **FaceFeaturesExtractor(string path, int pixel)**
  Constructor that receives the path of the resnet file you want to use and the pixelsize of your image. (Default pixel is 150)

* **~FaceFeaturesExtractor()**
  Destructor of the class.

* **Mat faceToVector(Mat &f)**
  Function that receives a Mat object of an image, extracts its features into a vector and returns the vector in a Mat.

* **double compareVectors(Mat &a, Mat &b, double threshold)**
  Function that receives two Mat objects (which represent vectors of features) and a threshold (the value of comparison for the vectors. We recommend to use 0.5), prints if the threshold is met (ACCESS GRANTED) or not (ACCESS DENIED), and returns the uclidian distance between both vectors.
  
* **void ErrorHandling(long long &flag)**
  Function that handles the errors in the class. The variable flag will make a logical AND to print errors. 
  Note: Even if the size error occurs, the program will resize to be able to complete the run.
