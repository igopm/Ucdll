//
// Created by Igor Maschikevich on 26/04/2018.
//
//=====================================================================================================
#include "./UCDllGTKMM.h"
#include <gtkmm/application.h>
//=====================================================================================================
int main (int argc, char *argv[]){
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    UcdllGtkmm ucdllgtkmm;
    return app->run(ucdllgtkmm);
}
//=====================================================================================================
