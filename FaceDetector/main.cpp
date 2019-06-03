
//
//  main.cpp
//  FaceRecognition
//
//  Created by Sukma on 4/1/19.
//  Copyright © 2019 Sukma. All rights reserved.
//

//Libreria de UI
#include <opencv2/highgui/highgui.hpp>
//Libreria para procesar la imagen, cambiar el color, recortar, etc.
#include <opencv2/imgproc/imgproc.hpp>
//Libreria que detecta objetos en imagenes
#include <opencv2/objdetect/objdetect.hpp>

#include <iostream>
#include <stdio.h>
#include "FaceDetector.h"

using namespace std;
using namespace cv;

void nextFrame( Mat frame );

//ubicacion de archivos para que el algoritmo sepa que es una cara
String face_cascade_name = "/usr/local/Cellar/opencv/4.0.1/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml";

//Nombre de la ventana
string window_name = "Deteccion Facial";
//Tamaño inicial de revision por frame
int next_height = 40;


//# main del codigo
int main( int argc, const char** argv )
{
    //Variables de captura de imagen y matriz de valores donde se guardara esta captura
    VideoCapture capture;
    Mat frame;
    vector<Rect> faces;
    
    //llamar a la clase
    FaceDetector Detect(face_cascade_name);
    
    //Se asigna video en vivo a captura
    capture = VideoCapture(0);
    
    //Conocer el framerate de la camara de usuario
    double fps = capture.get(CAP_PROP_FPS);
    cout << "Frames per second using video.get(CV_CAP_PROP_FPS) : " << fps << endl;
    
    //@ Si existe captura...
    if(capture.isOpened())
    {
        //@ Repetir proceso hasta ser cancelado
        while( true )
        {
            //obtener valor de reloj inicial para FPS
            clock_t a = clock();
            
            //asignar captura a la matriz
            capture >> frame;
            
            //@ Si la matriz no se encuentra vacia...
            if( !frame.empty() )
            {
                //funcion de detactar
                faces = Detect.nextFrame( frame );
            }
            else
            {
                //La matriz esta vacia, marcar error
                printf("Error: No existe un frame capturado --- break");
                break;
            }
            
            cout << "########################################" << endl;
            
            for(int i = 0; i < faces.size(); i++)
            {
                cout << i << ": " << "(" << faces[i].x << "," << faces[i].y << ")" << endl;
            }
            
            cout << "#########################################" << endl;
            
            //obtener valor final de reloj, conocer FPS actual
            fps = double(CLOCKS_PER_SEC) / double(clock() - a);
            
            //imprimir FPS
            cout << "FPS: " << fps << endl;
        }
    }
    return 0;
}
