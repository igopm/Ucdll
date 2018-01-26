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
void Ucdll::fatal(const std::string &nameError){
    std::cerr <<"Cannot read "<< nameError << " !" << std::endl;
    exit(1);
}
//=====================================================================================================
void Ucdll::inCopyOut(const std::string &in, const std::string &out){
    using namespace std;
    char * buffer;
    buffer = new char;
    ifstream inFile(in, ios::binary);
    ofstream outFile(out, ios::binary);

    if (!inFile)
        fatal(in);
    if (!outFile)
        fatal(out);
    cout << "In : " << in << endl;
    inFile.read(buffer, sizeof(char));
    while (!inFile.eof()){
        outFile.write(buffer, sizeof(char));
        inFile.read(buffer, sizeof(char));
    }
    cout << "Out : " << out << endl;
    inFile.close();
    outFile.close();
    delete buffer;
}

void Ucdll::inCopyOutWin(const std::string &in, const std::string &out){
    using namespace std;
    cout << "Win In : " << in << endl;
    CopyFile(in.c_str(), out.c_str(), 0);
    cout << "Win Out : " << out << endl;
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
}
//=====================================================================================================
