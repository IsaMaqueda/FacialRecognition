# Face Recognition System: Error Handling

## Main Objective

This module will handle the errors that each module of this software can generate. This module will be able to return which errors were generated and print then to the user.

## Instructions

Every module need to define in the class *"ErrorHandling.h"* every error that their funtions can give, by declaring a variable named after the error, and initializing it with the corresponding number with power 2. See example.

At this moment, every model has a range of 20 errors, but this number can increased as needed.

After doing that, every module need to check at every part of it class, where the error defined in the aforementioned error class, if an error occur or not. If some error occur, you have to add to the a variable of type long long, called *"flag"*, the value that corresponds to that error.

Also, every module need to have inside their class a method called *"ErrorHandling"*, that will receive the variable flag.

Inside this method, the variable flag will be compared with each error variable, by means of a logical AND. See example below.

## Example

### Errors definition in ErrorHandling.h

Taking Module 2, FaceAlignment, as an example:

```
//MODULE 2, FACE ALIGNMENT
#define ERROR_1_MODULE_2 1
#define ERROR_2_MODULE_2 2
#define ERROR_3_MODULE_2 4
#define ERROR_4_MODULE_2 8
#define ERROR_5_MODULE_2 16
#define ERROR_6_MODULE_2 32
#define ERROR_7_MODULE_2 64
#define ERROR_8_MODULE_2 128
#define ERROR_9_MODULE_2 256
#define ERROR_10_MODULE_2 512
#define ERROR_11_MODULE_2 1024
#define ERROR_12_MODULE_2 2048
#define ERROR_13_MODULE_2 4096
#define ERROR_14_MODULE_2 8192
#define ERROR_15_MODULE_2 18384
#define ERROR_16_MODULE_2 32768
#define ERROR_17_MODULE_2 65536
#define ERROR_18_MODULE_2 131072
#define ERROR_19_MODULE_2 262144
#define ERROR_20_MODULE_2 524288
```

### Errors comparison in function ErrorHandling

Again, taking Module 2, FaceAlignment, as an example:

```
//MODULE 2, FACE ALIGNMENT
void ErrorHandling(long long flag)
	if (flag & ERROR_1_MODULE_2) {
		std::cout << "Error while trying to deserialize .dat file: Wrong file name or file path" << '\n';
	}
	else if (flag & ERROR_2_MODULE_2) {
		std::cout << "Error while trying to deserialize .dat file: File not available on correct path" << '\n';
	}
	else if (flag & ERROR_3_MODULE_2) {
		std::cout << "Unable to resolve operating system in order to obtain .dat file from default path (..\\[.dat file])"
	}
	else if(flag & ERROR_4_MODULE_2) {
		std::cout << "Left or right 'x' coordinates out of range" << '\n';
	}
	else if (flag & ERROR_5_MODULE_2) {
		std::cout << "Left or right 'y' coordinates out of range" << '\n';
	}
	else if (flag & ERROR_6_MODULE_2) {
		std::cout << "Image passed to FaceAligner::align() has other than 3 channels (rgb)" << '\n';
	}
	And so on...
```
