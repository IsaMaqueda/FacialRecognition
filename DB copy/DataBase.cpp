#include "DataBase.h"
#include <opencv2/opencv.hpp>


#define INVALmatriculasMatRICULA -1
#define INVALID_NAME -2
#define INVALID_LAST_NAME -4
#define INVALID_AGE -16


DataBase::DataBase() {
    this->PersonInfoFile= "PersonInfo.txt";
    this->featuresFile = "features.txt";
    this->nFile = "N.txt";
    CV_Assert(load_N_File());
    if (existsFile(featuresFile)) {
        CV_Assert(load_featuresFile());
        CV_Assert(load_PersonInfoFile());
        flann_index = new cv::flann::Index(descriptores, cv::flann::KDTreeIndexParams());
    }
}
DataBase::DataBase(std::string PersonInfoFile,std::string featuresFile,std::string nFile){
    this->PersonInfoFile=PersonInfoFile;
    this->featuresFile=featuresFile;
    this->nFile=nFile;
    CV_Assert(load_N_File());
    if (existsFile(featuresFile)) {
        CV_Assert(load_featuresFile());
        CV_Assert(load_PersonInfoFile());
        flann_index = new cv::flann::Index(descriptores, cv::flann::KDTreeIndexParams());
    }
}

inline bool DataBase::existsFile (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
    
}
bool DataBase::load_N_File(){
    if (!existsFile(nFile)){
        N.open(nFile,std::ios::out);
        if (N.is_open()) {
            N<<"0\n";
            std::cout<<"***Fichero N.txt creado con éxito***\n";
            N.close();
            return true;
        } else {
            std::cout<< "Unable creating N.txt\n";
            return false;
        } 
    }
    return true;
}
bool DataBase::load_PersonInfoFile() {
    std::string line;
//std::cout<<"Hola"<<std::endl;
    biographicalDB.open(PersonInfoFile, std::ios::in);
    if (biographicalDB.is_open()) {
        while (true) {
            std::getline(biographicalDB,line);
            if(biographicalDB.eof()){
                break;
            }
            biograData.push_back(String_To_Structure(line));
            //std::cout<<"Test 1"<<std::endl;
        }
        biographicalDB.close();
        return true;
    }else{
        std::cout<<"Unable to open: "<<PersonInfoFile<<'\n';
        return false;
    }
    
}


bool DataBase::load_featuresFile(){
    
    std::ifstream file(featuresFile);
    
    std::string line;
    
    cv::Mat features;
    if(file.is_open()){
        // Read one line at a time into the variable line:
        while(std::getline(file, line))
        {
            std::vector<float>   lineData;
            std::stringstream  lineStream(line);
            
            float value;
            // Read a float at a time from the line
            int id = value;
            while(lineStream >> value)
            {
                // Add the float from a line to a 1D array (vector)
                lineData.push_back(value);
            }
            
            cv::Mat aux(1, (int)lineData.size(), CV_32FC1, lineData.data());
            features.push_back(aux);
            
        }
        //cv::Mat res_ = features.clone();
        
        
        descriptores = features.clone();
        //std::cout << descriptores << std::endl;
        return true;
        
    }else{
        std::cout<<"Unable to open: "<<featuresFile<<'\n';
        return false;
        
    }
}


cv::Mat DataBase::getMatrix(){
    return descriptores;
 }

cv::Mat DataBase::getColumn(int num){
    return descriptores.col(num);
 }

cv::Mat DataBase::getRow(int num){
    return descriptores.row(num);
 }
cv::Mat DataBase::getfeatureByID(int ID){
   return descriptores.row(ID);
}

std::pair <cv::Mat,cv::Mat> DataBase::search(cv::Mat elementoaBuscar, int K){
    std::pair <cv::Mat, cv::Mat> PAIR1 ;
    clock_t tStart = clock();
    cv::Mat indices,dists;
    //cvflann::Matrix<int> indices(new int [queries.rows * K] ,queries.rows, K);
    //cvflann::Matrix<float> dists(new float[queries.rows * K], queries.rows, K);
    
    flann_index->knnSearch(elementoaBuscar,indices,dists ,K, cv::flann::SearchParams(128));
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    PAIR1.first = indices.clone();
    
    float distanciaEuclidiana = 0;
    for(int i = 0; i < K;i++){
        dists.at<float>(i,0) = (cv::norm(elementoaBuscar, getfeatureByID(PAIR1.first.at<int>(i,0)), cv::NORM_L2));
    }
     PAIR1.second = dists.clone();
    return PAIR1; 
 }


cv::Mat DataBase::getfeatureByMatricula(std::string matricula){
    cv::Mat m;
    for(int i=0;i<biograData.size();i++){
        if(biograData[i].matricula == matricula){
            return descriptores.row(i);
        }
    }
    return m.clone();
}

    PersonInfo DataBase::getUserInfoByID(int ID){
    return biograData[ID];
}


    PersonInfo DataBase::getUserInfoByMatricula(std::string matricula){
    for(int i=0;i<biograData.size();i++){
        if(biograData[i].matricula == matricula){
            return biograData[i];
        }
    }
}

bool DataBase::saveUserDataInAFile(PersonInfo bio){
    
    int x = ValidateData(bio), id = n;

	if (x < 0) {
        std::cout << " ERROR : Credenciales ingresadas son incorrectas" << std::endl;
			return false;
	}

    biographicalDB.open(PersonInfoFile,std::ios::out | std::ios::app);
    
    if(biographicalDB.is_open()){
        
        biographicalDB<<id<<","<<bio.matricula<<","<<bio.name<<","<<bio.lastName<<","<<bio.age<<","<<"../DB/Img/"+std::to_string(id)+".jpg";
        biographicalDB<<"\n";
        biographicalDB.close();
		updateDataBase();
        return true;
    }else{
        std::cout<<"Unable to open file: "<<PersonInfoFile<<'\n';
        return false;
    } 
    
}



bool DataBase::saveUserfeatureDataInAFile(cv::Mat feature){
    std::string nuevoUsuario = "";
    int id=n;
    featureDB.open(featuresFile,std::ios::out | std::ios::app);
    
    if(featureDB.is_open()){
        nuevoUsuario+=std::to_string(id);
        nuevoUsuario+=" ";
        for(int i = 0 ; i< feature.rows;i++){
           float nearest = feature.at<float>(i,0);
            //cout<<nearest<<" ";
            nuevoUsuario+= std::to_string(nearest);
            if(i < feature.rows-1){
                nuevoUsuario+=' ';
            }
        }
        //std::cout<<nuevoUsuario<<std::endl;
        featureDB<<nuevoUsuario<<"\n";
        featureDB.close();
        return true;
    }else{
        std::cout<<"Unable to open file: "<<featuresFile<<'\n';
        return false;

    } 
}
    
void DataBase::saveUserImage(cv::Mat &image){
        
    //cv::imwrite("Fotos/2.jpg",image);
    std::string fileNameLocation = "../DB/Img/";
        
    fileNameLocation.append(std::to_string(n));
    fileNameLocation.append(".jpg");
    cv::imwrite(fileNameLocation, image);
}

bool DataBase::getN()
{
    N.open(nFile,std::ios::in);

    if(N.is_open()){
        N>>n;
        N.close();
        return true;
    }else{
        std::cout<<"Unable to open: "<<nFile<<'\n';
        return false;
    } 
     
}

bool DataBase::updateDataBase(){
    N.open(nFile);
    n=n+1;
    if(N.is_open()){
        //std::cout<<"n: "<<n<<std::endl;
        N<<n<<"\n";
        N.close();
        return true;
    }else{
        std::cout<<"Error updating N.txt file\n";
        return false;
    } 
   
}

//Splits the dataLine (strings) to a vector of strings
std::vector<std::string> DataBase::indexData(std::string dataLine) {
	std::vector <int> keys;
	std::vector<std::string> dataMatrix;
	std::string line = dataLine;					//Holds one line of data
	std::string delimiter = ",";						//The character separating the data
	size_t pos = 0;								//Starting at index 0
	int j = 0;
	std::string data;
	while ((pos = line.find(delimiter)) != std::string::npos) {	//While the delimiter still exits
		data = line.substr(0, pos);							//Get one piece of data (up to the delimiter)
		dataMatrix.push_back(data);			//String to float of bit of isolated data, add to data matrix
		line.erase(0, pos + delimiter.length());			//Erase the line up to the delimiter
		j++;
	}
	dataMatrix.push_back(line);			//Last bit of data doesn't have a delimiter
	return dataMatrix;
}







PersonInfo DataBase::String_To_Structure(std::string Data_As_String) {
    PersonInfo Data_Struct;
    std::vector<std::string> Data_Vector_String=indexData(Data_As_String);
    Data_Struct.id=Data_Vector_String[0];
    Data_Struct.matricula=Data_Vector_String[1];
    Data_Struct.name=Data_Vector_String[2];
    Data_Struct.lastName=Data_Vector_String[3];
    Data_Struct.age=std::stoi(Data_Vector_String[4]);
    Data_Struct.img = Data_Vector_String[5];
		return Data_Struct;
}








bool DataBase::DuplicatedMatricula(std::string mat) {
    cv::Mat m = getfeatureByMatricula(mat);
       if(m.rows == 0 && m.cols ==0) {
           return false;
       }
       return true;
}
int DataBase::ValidateData(PersonInfo bio) {
    int result_case_3=0;
    if(!ValidateMatricula(bio.matricula))
        result_case_3+=INVALmatriculasMatRICULA;
    if(!ValidName(bio.name))
        result_case_3+=INVALID_NAME;
    if(!ValidName(bio.lastName))
        result_case_3+=INVALID_LAST_NAME;
    if(bio.age>100||bio.age<1)
        result_case_3+=INVALID_AGE;
	
    return result_case_3;
}
bool DataBase::ValidName(std::string word) {
    bool verdict=1;
    
    std::string InvalidNameCharacters=" !\"#$%&()*+,./:;<=>?[\\]^_{|}~";
    for(int H=0;H<word.size();H++) {
        if(isdigit(word[H])||InvalidNameCharacters.find(word[H])!=std::string::npos) {
            verdict=0;
            break;
        }
    }
    return verdict;
}	

bool DataBase::ValidateMatricula(std::string matricula) {
    const std::regex pattern_Matricula("(A|L)[0-9]{8}");
    return std::regex_match(matricula, pattern_Matricula);
}
void DataBase::BackUp() {
    std::ofstream backupFeat;
    backupFeat.open("backupFeat.txt");
    
    std::ifstream inputFeat;
    inputFeat.open(featuresFile);
    
    std::string ch;
    while (!inputFeat.eof()) {
        std::getline(inputFeat,ch);
        backupFeat<<ch;
    }
    inputFeat.close();
    //
    std::ofstream backupPerson;
    backupPerson.open("backupPerson.txt");
    
    std::ifstream inputPerson;
    inputFeat.open(PersonInfoFile);
    
    std::string ch1;
    while (!inputPerson.eof()) {
        std::getline(inputPerson,ch1);
        backupPerson<<ch1;
    }
    inputPerson.close();
}
