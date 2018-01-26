//
// Created by Igor Maschikevich on 12/19/2017.
//
//=====================================================================================================
#include <iostream>
#include <fstream>

#include <vector>
#include "./UCDll.h"
//=====================================================================================================
static void fatal(const std::string &error){
    std::cerr <<"ERROR::"<< error << "!!!" << std::endl;
    exit(1);
}
static void fatal2(const std::string &error, const std::string &path){
    std::cerr <<"ERROR::"<< error << "!!! --> " << path << std::endl;
    exit(1);
}
static std::vector<std::string> readFile2(const std::string &inFile, const std::string &path){
    using namespace std;
    vector<string> vecRes;
    string resIn, resOut;
    ifstream in(inFile);
    if(!in)
        fatal2("BAD_IN_FILE", inFile);
    ofstream out(path + "OUT_UCDll.txt");
    if(!out)
        fatal2("DO_NOT_CREATE_FOLDER", path);
    while(in >> resIn) {
        int temp;
        for (int i = resIn.size()-1; i >= 0 ; --i ){
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
int main(){
    using namespace std;
    /// TEST 1
    for (string n : ucd::Ucdll::readAndWrite("d:\\Kaa_test\\1\\In.txt", "D:\\")) {
        cout << n << '\n';
    }
    /// TEST 2
    const string s1 = "D:\\Kaa_test\\1\\testIn.txt";
    const string s2 = "D:\\Kaa_test\\2\\testOut.txt";
    ucd::Ucdll::mainUcd(s1, s2);
    return 0;
}
//=====================================================================================================
