#include "mcu_walker.hpp"

mcu_walker::mcu_walker(
    float cpu_speed,int memory,string os,string nama,int volt,
    int motor_speed,int rotation)
    : MCU(cpu_speed,memory,os,nama,volt)
{
    this->motor_speed = motor_speed;
    this->rotation = rotation;
}

void mcu_walker::rotate(int rotation){
    this->rotation = rotation;
    cout << name << " rotated to " << rotation << " degrees" << endl;
}

void mcu_walker::increase_speed(int speed){
    motor_speed += speed;
    cout << name << " speed increased to " << motor_speed << endl;
}

void mcu_walker::showSpek(){
    cout << "[WALKER MCU] : " << name
         << " | Speed: " << motor_speed
         << " | Rotation: " << rotation
         << " | CPU: " << cpu_speed
         << "GHz | RAM: " << memory
         << "MB | OS: " << os
         << " | Volt: " << volt << "V" << endl;
}

void mcu_walker::nambah_volt(int penambahan_voltase){
    volt += penambahan_voltase;
}

void mcu_walker::ganti_os(string new_os){
    os = new_os;
}

mcu_walker::~mcu_walker(){
    cout << "[WALKER MCU SHUTDOWN] " << name << endl;
}