#include "mcu_cam_controller.hpp"

int mcu_cam_controller::count_detected_obj = 0;

mcu_cam_controller::mcu_cam_controller(
    float cpu_speed,int memory,string os,string nama,int volt,string obj_detected)
    : MCU(cpu_speed,memory,os,nama,volt)
{
    this->obj_detected = obj_detected;
}

void mcu_cam_controller::detect_other_object(string other, bool moving){

    cout << "Camera detected object: " << other;

    if(moving){
        cout << " (Moving)" << endl;
    }
    else{
        cout << " (Static)" << endl;
    }

    count_detected_obj++;
}

void mcu_cam_controller::showSpek(){
    cout << "[CAM MCU] : " << name
         << " | Target: " << obj_detected
         << " | CPU: " << cpu_speed
         << "GHz | RAM: " << memory
         << "MB | OS: " << os
         << " | Volt: " << volt << "V" << endl;
}

void mcu_cam_controller::nambah_volt(int penambahan_voltase){
    volt += penambahan_voltase;
}

void mcu_cam_controller::ganti_os(string new_os){
    os = new_os;
}

mcu_cam_controller::~mcu_cam_controller(){
    cout << "[CAM MCU SHUTDOWN] " << name << endl;
}