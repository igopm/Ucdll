//
// Created by Igor Maschikevich on 26/04/2018.
//
//=====================================================================================================
#pragma once
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/grid.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>

class UcdllGtkmm : public Gtk::Window{
public:
    UcdllGtkmm();

    void onButtonRun();
    void onButtonBack();
private:
    Gtk::Box vBoxMain {Gtk::ORIENTATION_VERTICAL, false};

    Gtk::Box hBoxButton {Gtk::ORIENTATION_HORIZONTAL, false};
    Gtk::Box hBoxEnter {Gtk::ORIENTATION_HORIZONTAL, false};

    Gtk::Grid mContainer;

    Gtk::Label mLabelRes;
    Gtk::Entry mEntry;
    Gtk::Button buttonRun ;
    Gtk::Button buttonBack {"Back"};
};
//=====================================================================================================
