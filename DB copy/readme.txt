
El archivo DataBase.h contiene la declaración de los métodos.
El archivo DatabBase.cpp contiene la definición de los  métodos

DataBase();
Manda a llamar el metodo que manda a llamar y cargar los archivos .txt conteniendo los datos personales y caracteristicas de los usuarios de la base de datos, asi como tambi�n el archivo conteniendo el contador del tama�o de la base de datos.
 
cv::Mat getMatrix();
Obtiene los descriptores de la matriz	

cv::Mat getBiometricByID(int ID);
No esta definida

cv::Mat getfeatureByID(int ID);
Regresa rasgos del usuario segun su ID, regresa un mat

cv::Mat getfeatureByMatricula(std::string matricula);
Regresa rasgos del usuario según la matricula que recibe, regresa un mat

search(cv::Mat elementoaBuscar, int K)
Regresa el par de mats más parecido 

getUserInfoByID(int ID); // no esta correctamente implementado

getUserInfoByMatricula(std::string matricula)
Regresa una estructura tipo PersonInfo segun la matricula ingresada


bool saveUserDataInAFile(PersonInfo bio,std::vector<cv::Point2f> points);
Guarda la informaci�n personal del usuario dentro del archivo "PersonInfo.txt"

bool saveUserfeatureDataInAFile(cv::Mat feature);
Guarda las caracteristicas de un usuario dentro del archivo "features.txt" donde crea un espacio vacio antes de registrar los archivos .mat con las caracteristicas del usuario. La persona puede ser tanto un nuevo usuario como uno ya existente.
	 
bool saveUserBiometricDataInAFile(cv::Mat feature);
Guarda la informaci�n biometrica de una persona dentro del archivo "


void saveUserImage(cv::Mat &image);
Se guarda la imagen de la persona dentro de la direcci�n "../DB/Img/" en formato jpg, editando la string fileNameLocation para agregar la ubicaci�n

bool getN();
Se obtiene el valor numerico de personas que se encuentran en la base de datos del archivo "N.txt".

bool updateDataBase();
Actualiza el archivo "N.txt" en su contador para permitir mas personas en la base de datos.
       
void BackUp();
Metodo que respalda la informaci�n de las personas y de las caracteristicas en archivos de texto .txt "BackupPerson.txt" y "BackupFeat.txt" respectivamente. Crea los archivos si no existen.
