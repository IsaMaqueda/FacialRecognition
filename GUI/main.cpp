//
//  main.cpp
//  Graphics
//
//  Created by Sukma.
//  Copyright © 2019 Sukma. All rights reserved.
//

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <stdarg.h>
#include <sstream>


using namespace cv;
using namespace std;

Mat TakePhoto();

int main()
{
    Mat img1=imread("/Users/simonmetta/Documents/ITESM/Quinto Semestre/Sistemas de Software/GUI/p1.jpg");
    Mat img2=imread("/Users/simonmetta/Documents/ITESM/Quinto Semestre/Sistemas de Software/GUI/p2.jpg");
    Mat img4 =imread("/Users/simonmetta/Documents/ITESM/Quinto Semestre/Sistemas de Software/GUI/p4.jpg");
    Mat img5 =imread("/Users/simonmetta/Documents/ITESM/Quinto Semestre/Sistemas de Software/GUI/p5.jpg");
    Mat img6 =imread("/Users/simonmetta/Documents/ITESM/Quinto Semestre/Sistemas de Software/GUI/p6.jpg");
    Mat img7 =imread("/Users/simonmetta/Documents/ITESM/Quinto Semestre/Sistemas de Software/GUI/p7.jpg");
    Mat img8 =imread("/Users/simonmetta/Documents/ITESM/Quinto Semestre/Sistemas de Software/GUI/p8.jpg");
    Mat spy= imread("/Users/simonmetta/Documents/ITESM/Quinto Semestre/Sistemas de Software/GUI/007.jpg");
    int select;
    cout <<"Seleccione que desea hacer:\n";
    cout <<"1 Verificar\n";
    cout <<"2 Identificar\n";
    cout <<"3 Registrar\n";
    cin >>select;
    switch (select)
    {
        case 1:
        {//Verificación
            std::string ID;
            cout<<"Introduzca su Matrícula\n";
            cin>>ID;
            
            Mat img_registro = TakePhoto();
            
            Mat imgv = Mat::zeros(720, 1080, CV_8UC3);
            if (ID=="007")
            {
                resize(spy, spy, Size(360, 360));
                Mat spy_roi(imgv, Rect(300,40,360,360));
                spy.copyTo(spy_roi);
                putText(imgv, "ID: "+ID, Point(40,440), FONT_HERSHEY_DUPLEX, 1, Scalar(255,255,255), 2, LINE_AA);
                putText(imgv, "Nombre: James Bond", Point(40,520), FONT_HERSHEY_DUPLEX, 1, Scalar(255,255,255), 2, LINE_AA);
                putText(imgv, "Nice try...", Point(350,600), FONT_HERSHEY_DUPLEX, 2, Scalar(255,255,255), 2, LINE_AA);
            }
            else
            {
                resize(img1, img1, Size(360, 360));
                resize(img_registro, img_registro, Size(360, 360));
                
                Mat img1_roi(imgv, Rect(160,40,360,360));
                Mat img_registro_roi(imgv, Rect(580,40,360,360));
                
                img1.copyTo(img1_roi);
                img_registro.copyTo(img_registro_roi);
                
                putText(imgv, "Matricula: " + ID, Point(40,420), FONT_HERSHEY_DUPLEX, 1, Scalar(255,255,255), 2, LINE_AA);
                putText(imgv, "Nombre:", Point(40,520), FONT_HERSHEY_DUPLEX, 1, Scalar(255,255,255), 2, LINE_AA);
            }
            
            namedWindow("Verificar", WINDOW_NORMAL);
            imshow("Verificar",imgv);
            waitKey();
        }
            break;
        case 2:
        {//Identificar
            Mat img_registro = TakePhoto();
            
            Mat imge = Mat::zeros(720, 1080, CV_8UC3);
            resize(img_registro, img_registro, Size(360,360));
            resize(img4, img4, Size(100,100));
            resize(img5, img5, Size(100,100));
            resize(img6, img6, Size(100,100));
            resize(img7, img7, Size(100,100));
            resize(img8, img8, Size(100,100));
            
            Mat img_registro_roi(imge, Rect(40, 40, 360,360));
            Mat img4_roi(imge, Rect(430, 40, 100, 100));
            Mat img5_roi(imge, Rect(430, 160, 100, 100));
            Mat img6_roi(imge, Rect(430, 280, 100, 100));
            Mat img7_roi(imge, Rect(430, 400, 100, 100));
            Mat img8_roi(imge, Rect(430, 520, 100, 100));
            
            img_registro.copyTo(img_registro_roi);
            img4.copyTo(img4_roi);
            img5.copyTo(img5_roi);
            img6.copyTo(img6_roi);
            img7.copyTo(img7_roi);
            img8.copyTo(img8_roi);
            putText(imge, "El rango de distancia ideal es de: ", Point(40, 30), FONT_HERSHEY_DUPLEX, 1, Scalar(255,255,255), .3, LINE_AA);
            //img4
            putText(imge, "ID:", Point(560, 50), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            putText(imge, "Nombre:", Point(560,70), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            putText(imge, "Distancia:", Point(560,90), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            //img5
            putText(imge, "ID:", Point(560, 170), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            putText(imge, "Nombre:", Point(560,190), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            putText(imge, "Distancia:", Point(560,210), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            //img6
            putText(imge, "ID:", Point(560, 290), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            putText(imge, "Nombre:", Point(560, 310), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            putText(imge, "Distancia:", Point(560, 330), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            //img7
            putText(imge, "ID:", Point(560, 410), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            putText(imge, "Nombre:", Point(560,430), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            putText(imge, "Distancia:", Point(560,450), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            //img 8
            putText(imge, "ID:", Point(560, 530), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            putText(imge, "Nombre:", Point(560,550), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            putText(imge, "Distancia:", Point(560,570), FONT_HERSHEY_DUPLEX, .5, Scalar(255,255,255), .3, LINE_AA);
            namedWindow("Identificar", WINDOW_NORMAL);
            imshow("Identificar",imge);
            waitKey();
        }
            break;
        case 3:
        {//Registrar
            std::string id, matricula, name, lastName;
            int age;
            std::string out_string;
            std::stringstream age_string;
            cout<<"Llene el formulario:\n";
            cout<<"Nombre:\n";
            cin>>name;
            cout<<"Apellido:\n";
            cin>>lastName;
            cout<<"Matrícula:\n";
            cin>>matricula;
            cout<<"Edad:\n";
            cin>>age;
            age_string << age;
            out_string = age_string.str();
            cout<<"Sus datos son:\n";
            cout<<name<<endl;
            cout<<lastName<<endl;
            cout<<matricula<<endl;
            cout<<age<<endl;
            Mat imgr = Mat::zeros(720, 1080, CV_8UC3);
            
            Mat img_registro = TakePhoto();
            
            resize(img_registro, img_registro, Size(360, 360));
            
            Mat img_registro_roi(imgr, Rect(340,100,360,360));
            
            img_registro.copyTo(img_registro_roi);
            
            putText(imgr, "Su foto ha sido registrada", Point(80,40), FONT_HERSHEY_DUPLEX, 1.5, Scalar(255,255,255), .5, LINE_AA);
            putText(imgr, "Nombre: " + name, Point(80, 500), FONT_HERSHEY_DUPLEX, 1, Scalar(255,255,255), .5, LINE_AA);
            putText(imgr, "Apellido: " + lastName, Point(80, 530), FONT_HERSHEY_DUPLEX, 1, Scalar(255,255,255), .5, LINE_AA);
            putText(imgr, "Matricula: " + matricula, Point(80, 560), FONT_HERSHEY_DUPLEX, 1, Scalar(255,255,255), .5, LINE_AA);
            putText(imgr, "Edad: " + out_string, Point(80, 590), FONT_HERSHEY_DUPLEX, 1, Scalar(255,255,255), .5, LINE_AA);
            namedWindow("Registrar", WINDOW_NORMAL);
            imshow("Registrar",imgr);
            waitKey();
            
        }
            break;
        default:
            break;
    }
    
    //Enrolar
    
    return 0;
}

Mat TakePhoto()
{
    Mat photo, final_photo;
    
    VideoCapture capture;
    
    capture = VideoCapture(0);
    
    if(capture.isOpened())
    {
        while(true)
        {
            capture >> photo;
            
            Point top (339 , 99 );
            Point bottom (940, 700);
            rectangle( photo, top, bottom, Scalar( 255, 0, 255 ));
            
            imshow("Take Photo", photo );
            
            char c = waitKey(1);
            if(  c == 't' )
            {
                final_photo = photo;
                destroyWindow("Take Photo");
                break;
            }
        }
    }
    
    Mat roi(final_photo, Rect(340,100,600,600));
    
    return roi;
}
