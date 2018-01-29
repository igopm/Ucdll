///
/// Created by Igor Maschikevich on 01/23/2018.
///
/// UCDll
//=====================================================================================================
#pragma once
#include <iostream>
#include <vector>
//=====================================================================================================
namespace ucd {
//class Ucdll{
//public:
//    Ucdll();
//public:  //======= Methods =======
/// copy files from in_folder in out_folder
void mainUcdOld(const std::string &inFile, const std::string &inFile1);
void mainUcdNew(const std::string &inFile, const std::string &path);

//private: //======= Methods =======
/// read file and write in console
void readFile(const std::string &inFile);
/// read inFile and write outFile with new path
std::vector<std::string> readAndWrite(const std::string &inFile, const std::string &path);
std::vector<std::string> readAndWrite(const std::vector<std::string> &inVector, const std::string &path);
/// check and clealeaning inFile.txt
std::vector<std::string> checkingAndCleaning(const std::string &inFile, const std::string &path);

//private: //======= Methods =======
/// message about error
void fatal(const std::string &error);
void fatal2(const std::string &error, const std::string &path);

/// copy files
void inCopyOut(const std::string &in, const std::string &out);
void inCopyOutWin(const std::string &in, const std::string &out);

/// check two string
bool checkLines(std::string &val1, std::string &val2);
//};
}
//=====================================================================================================
