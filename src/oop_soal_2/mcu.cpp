#include "mcu.hpp"

MCU::MCU(float cpu_speed,int memory,string os,string name,int volt){
    this->cpu_speed = cpu_speed;
    this->memory = memory;
    this->os = os;
    this->name = name;
    this->volt = volt;
}

void MCU::nambah_volt(int penambahan_voltase){
    volt += penambahan_voltase;
}

void MCU::ganti_os(string new_os){
    os = new_os;
}

MCU::~MCU(){
    cout << "[MCU DESTROYED] " << name << endl;
}

void MCU::showSpek() {
    cout << "[BASE MCU] : " << name << " | CPU: " << cpu_speed 
         << "GHz | RAM: " << memory << "MB | OS: " << os 
         << " | Volt: " << volt << "V" << endl;
};