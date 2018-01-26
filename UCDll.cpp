///
/// Created by Igor Maschikevich on 01/23/2018.
///
/// UCDll
//=====================================================================================================
#include "./UCDll.h"
//=====================================================================================================
#include <fstream>
#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif
//=====================================================================================================
namespace ucd {
//Ucdll::Ucdll(){
//}
//=====================================================================================================
void Ucdll::mainUcd(const std::string &inFile, const std::string &inFile1){
    using namespace std;
    int count = 0;
    string inPath, outPath;
    ifstream in(inFile);
    ifstream in1(inFile1);

    if (!in)
        fatal(inFile);
    if (!in1)
        fatal(inFile1);

    while(in >> inPath && in1 >> outPath){
#if defined(_WIN32) || defined(WIN32)
        inCopyOutWin(inPath, outPath);
#else
        inCopyOut(inPath, outPath);
#endif
        ++count;
    }
    cout << "count : " << count << endl;
}
//=====================================================================================================
void Ucdll::fatal(const std::string &error){
    std::cerr <<"ERROR::"<< error << "!!!" << std::endl;
    exit(1);
}
void Ucdll::fatal2(const std::string &error, const std::string &path){
    std::cerr <<"ERROR::"<< error << "!!! --> " << path << std::endl;
    exit(1);
}
//=====================================================================================================
void Ucdll::inCopyOut(const std::string &in, const std::string &out){
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
    inFile.close();
    outFile.close();
    delete buffer;
}

void Ucdll::inCopyOutWin(const std::string &in, const std::string &out){
    using namespace std;
    cout << "WIN::IN : " << in << endl;
    CopyFile(in.c_str(), out.c_str(), 0);
    cout << "WIN::OUT : " << out << endl;
}
//=====================================================================================================
void Ucdll::readFile(const std::string &inFile){
    std::string res;
    std::ifstream in(inFile);
    if(!in)
        fatal(inFile);
    while(in >> res) {
        std::cout << res << std::endl;
    }
}
//=====================================================================================================
std::vector<std::string> Ucdll::readAndWrite(const std::string &inFile, const std::string &path){
    using namespace std;
    if(inFile[inFile.size() - 4]!= '.')
        fatal2("BED_IN_FILE", inFile);

    if(path.back()!= '\\')
        fatal2("BED_PATH", path);

    vector<string> vecRes;
    string resIn, resOut;
    ifstream in(inFile);
    if(!in)
        fatal2("BAD_IN_FILE", inFile);
    ofstream out(path + "tepm_OUT_UCDll.txt");
    if(!out)
        fatal2("DO_NOT_CREATE_FOLDER(S)", path);
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
//=====================================================================================================
}
//=====================================================================================================
