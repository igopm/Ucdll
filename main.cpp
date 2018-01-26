//
// Created by Igor Maschikevich on 12/19/2017.
//
//=====================================================================================================
#include <iostream>
#include <windows.h>
#include "./UCDll.h"
//=====================================================================================================
int main(){
    using namespace std;

    const string s1 = "D:\\Kaa_test\\1\\testIn.txt";
    const string s2 = "D:\\Kaa_test\\2\\testOut.txt";
    const string s3 = "D:\\Kaa_test\\1\\te.txt";
    const string s4 = "D:\\Kaa_test\\2\\te.txt";
    ucd::Ucdll::mainUcd(s1, s2);
        CopyFile (s3.c_str(), s4.c_str(), 0);
    return 0;
}
//=====================================================================================================
