# FaceEnrollment

## Methods
Face Enrollment counts with a total of 3 methods.

```
FaceEnrollment();

~FaceEnrollment();

enroll(PersonInfo &bio, Mat &vec, Mat &img);

ErrorHandling(long long &flag);
```
`FaceEnrollment();` Is the constructor of the class.

`~FaceEnrollment();` Is the destructor of the class.

`enroll(PersonInfo &bio, Mat &vec, Mat &img);` It will recieve the information in a PersonInfo struct defined by the DataBase, a features vector and the image of the person. It will compare the values to the database using the *identificate* method from FaceIdentification. If the values are not stored yet, all values will be stored in the database. 

`FaceEnrollment(long long &flag);` It will handle the errors in the class using a logical AND to know which error is active.

### Variables
`bio` is the struct with the information from the person you wish to enroll.

`vec` is a features vector from the image of the person.

`img` is an image of the persont that is being enrolled. 

`flag` is an integer used to know what errors are active during the run of the class. 
