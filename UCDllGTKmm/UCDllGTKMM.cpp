//
// Created by Igor Maschikevich on 26/04/2018.
//
//=====================================================================================================
#include "./UCDllGTKMM.h"
#include <iostream>
#include <memory>
//=====================================================================================================

UcdllGtkmm::UcdllGtkmm(){
    using namespace std;
    set_title("Where are dlls");
    set_border_width(10);
    set_default_size(96, 132);
    set_icon_from_file("icon/32x32/dll.png");
    //    set_default_size(640, 480);
    set_resizable(false);
    static int margin = 5;
    //===========================================
    mContainer.property_margin() = margin;

    mEntry.set_text("C:\\msys");
    mEntry.set_max_length(7);

    //    buttonRun.set_image_from_icon_name("dll.png");
    buttonRun.property_margin() = margin;
    buttonBack.property_margin() = margin;

//    Gtk::Image *m_image = new Gtk::Image("icon/16x16/play.png");
//    m_Button->set_image_position(Gtk::POS_LEFT);
//    m_Button->set_image(*m_image);
//    m_image->show();
//    show_all_children();
    shared_ptr<Gtk::Image> *dd (new Gtk::Image ("icon/16x16/play.png"));

    buttonRun.set_image_position(Gtk::POS_LEFT);
    buttonRun.set_image(**dd);
    buttonBack.set_halign(Gtk::ALIGN_START);
    buttonBack.set_valign(Gtk::ALIGN_END);
    buttonRun.set_halign(Gtk::ALIGN_END);
    buttonRun.set_valign(Gtk::ALIGN_END);
    //===========================================
    mLabelRes.set_halign(Gtk::ALIGN_CENTER);
    mLabelRes.set_valign(Gtk::ALIGN_CENTER);
    //===========================================
    hBoxEnter.property_margin() = margin;
    //    hBoxEnter.set_halign(Gtk::ALIGN_CENTER);
    //    hBoxEnter.set_valign(Gtk::ALIGN_CENTER);
    //===========================================
    //=====================================================================================================
    buttonRun.signal_clicked().connect([this]() -> void {
                                           UcdllGtkmm::onButtonRun();});
    buttonBack.signal_clicked().connect([this]() -> void {
                                            UcdllGtkmm::onButtonBack();});
    //=====================================================================================================
    add(vBoxMain);
    vBoxMain.add(hBoxEnter);
    vBoxMain.pack_start(mLabelRes);
    vBoxMain.pack_end(hBoxButton);
    hBoxButton.add(buttonBack);
    hBoxButton.pack_end(buttonRun);
    hBoxEnter.add(mContainer);
    mContainer.add(mEntry);

    vBoxMain.show();
    hBoxEnter.show_all();
    hBoxButton.show();
    buttonBack.hide();
    buttonRun.show();

    //    show_all_children();
}
void UcdllGtkmm::onButtonRun(){
    buttonBack.show();


    //    if(getRes() == RadioMode::ENTER){
    //        std::cout << "Enter" << std::endl;
    //    }

    //    if(getRes()== RadioMode::MSYS){
    //        std::cout << "MSYS" << std::endl;
    //    }
    //    mEntry.get_text()!= "";
    //    setRes(RadioMode::ENTER);
    if(mEntry.get_text()!= ""){
        mLabelRes.set_text(mEntry.get_text());
    }
    hBoxEnter.hide();
    mLabelRes.show();
}

void UcdllGtkmm::onButtonBack(){
    buttonBack.hide();
    hBoxEnter.show();
}
