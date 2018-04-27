///
/// Created by Igor Maschikevich on 01/23/2018.
///
/// UCDll
//=====================================================================================================
#include "./UCDll.h"
//=====================================================================================================
//#include <fstream>
#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif
//=====================================================================================================
namespace ucd {
//=====================================================================================================
//void mainUcdOld(const std::string &inFile, const std::string &inFile1){
//    using namespace std;
//    int count = 0;
//    string inPath, outPath;
//    ifstream in(inFile);
//    ifstream in1(inFile1);

//    if (!in)
//        fatal(inFile);
//    if (!in1)
//        fatal(inFile1);

//    while(in >> inPath && in1 >> outPath){
//#if defined(_WIN32) || defined(WIN32)
//        inCopyOutWin(inPath, outPath);
//#else
//        inCopyOut(inPath, outPath);
//#endif
//        ++count;
//    }
//    cout << "count : " << count << endl;
//}

void mainUcdNew(const std::string &inFile, const std::string &path){
    using namespace std;
    int count = 0;

    for(int i = 0; i < checkingAndCleaning(inFile, path).size(); ++i){
        string inPath = checkingAndCleaning(inFile, path)[i];
        string outPath = readAndWrite(checkingAndCleaning(inFile, path), path)[i];
        inCopyOutBoost(inPath, outPath);
        ++count;
    }
    cout << "count : " << count << endl;
}
//=====================================================================================================
void fatal(const std::string &error){
    std::cerr <<"ERROR::"<< error << "!!!" << std::endl;
    exit(1);
}
void fatal(const std::string &error, const std::string &path){
    std::cerr <<"ERROR::"<< error << "!!! --> " << path << std::endl;
    exit(1);
}
//=====================================================================================================
void inCopyOut(const std::string &in, const std::string &out){
    using namespace std;
    char * buffer;
    buffer = new char;
    ifstream inFile(in, ios::binary);
    if (!inFile)
        fatal("IN_COPY_OUT::BAD_IN_FILE");
    ofstream outFile(out, ios::binary);
    if (!outFile)
        fatal("IN_COPY_OUT::BAD_OUT_FILE");

    cout << "IN : " << in << endl;
    inFile.read(buffer, sizeof(char));
    while (!inFile.eof()){
        outFile.write(buffer, sizeof(char));
        inFile.read(buffer, sizeof(char));
    }
    cout << "OUT : " << out << endl;
}

void inCopyOutWin(const std::string &in, const std::string &out){
    using namespace std;
    cout << "WIN::IN : " << in << endl;
    CopyFile(in.c_str(), out.c_str(), 0);
    cout << "WIN::OUT : " << out << endl;
}

bool checkLines(std::string &val1, std::string &val2){
    if (strcmp(val1.c_str(),val2.c_str()) == 0)
        return true;
    else
        return false;
}
//=====================================================================================================
//void readFile(const std::string &inFile){
//    std::string res;
//    std::ifstream in(inFile);
//    if(!in)
//        fatal(inFile);
//    while(in >> res) {
//        std::cout << res << std::endl;
//    }
//}
//=====================================================================================================
std::vector<std::string> readAndWrite(const std::string &inFile, const std::string &path){
    using namespace std;
    if(inFile[inFile.size() - 4]!= '.')
        fatal("BAD_IN_FILE", inFile);

    if(path.back()!= '\\')
        fatal("BAD_PATH", path);

    vector<string> vecRes;
    string resIn, resOut;
    ifstream in(inFile);
    if(!in)
        fatal("BAD_IN_FILE", inFile);
    ofstream out(path + "temp_OUT_UCDll.txt");
    if(!out)
        fatal("DO_NOT_CREATE_FOLDER(S)", path);
    while(in >> resIn) {
        int temp;
        for (int i = resIn.size() - 1; i >= 0 ; --i){
            if((char)resIn[i] == '\\'){
                temp = i;
                break;
            }
        }
        resOut = path + resIn.substr(temp + 1, resIn.size());
        out << resOut << endl;
        vecRes.push_back(resOut);
    }
    return vecRes;
}

std::vector<std::string> readAndWrite(const std::vector<std::string> &inVector, const std::string &path){
    using namespace std;
    if(path.back()!= '\\')
        fatal("BAD_PATH", path);

    vector<string> vecRes;
    string resOut;

    ofstream out(path + "temp_READ_AND_WRITE_OUT_RES.txt");
    if(!out)
        fatal("DO_NOT_CREATE_FOLDER(S)", path);


    for (string resIn : inVector) {
        int temp;
        for (int i = resIn.size() - 1; i >= 0 ; --i){
            if((char)resIn[i] == '\\'){
                temp = i;
                break;
            }
        }
        resOut = path + resIn.substr(temp + 1, resIn.size());
        out << resOut << endl;
        vecRes.push_back(resOut);
    }
    return vecRes;
}

std::vector<std::string> checkingAndCleaning(const std::string &inFile, const std::string &path){
    using namespace std;
    vector<string> vecRes;
    string resIn;

    if(inFile[inFile.size() - 4]!= '.')
        fatal("BAD_IN_FILE", inFile);

    if(path.back()!= '\\')
        fatal("BAD_PATH", path);

    ifstream in(inFile);
    if(!in)
        fatal("BAD_IN_FILE", inFile);

    ofstream out(path + "temp_CHECK_OUT_RES.txt");
    if(!out)
        fatal("DO_NOT_CREATE_FOLDER(S)", path);

    while(in >> resIn) {
        string check = "c:\\msys";
        string temp = resIn.substr(0, 7);
        if (checkLines(temp, check)){
            out << resIn << endl;
            vecRes.push_back(resIn);
        }
    }
    return vecRes;
}

void inCopyOutBoost(const boost::filesystem::path &inPath, const boost::filesystem::path &outPath){
    using namespace std;
    cout << "BOOST::IN : " << inPath << endl;
    boost::filesystem::copy_file(inPath, outPath);
    cout << "BOOST::OUT : " << outPath << endl;
}

//=====================================================================================================
}
//=====================================================================================================
