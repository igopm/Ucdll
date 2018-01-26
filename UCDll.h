///
/// Created by Igor Maschikevich on 01/23/2018.
///
/// UCDll
//=====================================================================================================
#pragma once
#include <iostream>
//=====================================================================================================
namespace ucd {
class Ucdll{
    //public:
    //    Ucdll();
public:  //======= Methods =======
    /// copy files from in_folder in out_folder
    static void mainUcd(const std::string &inFile, const std::string &inFile1);

    /// read file and write in console
    static void readFile(const std::string &inFile);

private: //======= Methods =======
    /// message about error
    static void fatal(const std::string &nameError);

    /// copy files
    static void inCopyOut(const std::string &in, const std::string &out);
    static void inCopyOutWin(const std::string &in, const std::string &out);
};
}
//=====================================================================================================
