//
// Created by Igor Maschikevich on 12/19/2017.
//
//=====================================================================================================
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "./UCDll.h"
//=====================================================================================================
int main(int argc, char *argv[]){
    using namespace std;
    using namespace ucd;
    /// TEST 1
    //    for (string n : ucd::Ucdll::readAndWrite("d:\\Kaa_test\\1\\In.txt", "D:\\UCD\\")) {
    //        cout << n << '\n';
    //    }

    /// TEST 2
    //    for (string n : ucd::Ucdll::checkingAndCleaning("C:\\Users\\West\\Desktop\\test21.txt")) {
    //        cout << n << '\n';
    //    }

    /// TEST 3
    //    for (string n : ucd::Ucdll::readAndWrite(ucd::Ucdll::checkingAndCleaning("C:\\Users\\West\\Desktop\\test21.txt", "D:\\TEMP\\"),"D:\\TEMP\\")) {
    //        cout << n << '\n';
    //    }

    /// TEST 4
    ///
    string inTxt = "BAD_TXT";
    string path = "D:\\TEMP\\";
    if (argc >= 2)
        inTxt = argv[1];
    if (argc >= 3)
        path = argv[2];
    cout << "UCopyDll v.1.0\n";
    cout << "UCD: <*\\path\\in.txt> <path>\n";
    cout << "in.txt = " << inTxt << endl;
    cout << "path = " << path << endl;
    mainUcdNew(inTxt, path);

    //    mainUcdNew("C:\\Users\\West\\Desktop\\test21.txt", "D:\\TEMP\\");
    /// TEST 5
    //    const string s1 = "D:\\Kaa_test\\1\\testIn.txt";
    //    const string s2 = "D:\\Kaa_test\\2\\testOut.txt";
    //    ucd::Ucdll::mainUcd(s1, s2);
    return 0;
}
//=====================================================================================================
