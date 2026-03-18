#include "core_mcu.hpp"

float cpu_speed;
int memory;
string os;
string nama;
int volt;

Core_MCU::Core_MCU(float cpu_speed,int memory,string os,string nama,int volt)
{
    this->cpu_speed = cpu_speed;
    this->memory = memory;
    this->os = os;
    this->nama = nama;
    this->volt = volt;
}

void Core_MCU::showSpek()
{
    cout << "Nama Device : " << nama << endl;
    cout << "CPU Speed : " << cpu_speed << endl;
    cout << "Memory : " << memory << endl;
    cout << "OS : " << os << endl;
    cout << "Volt : " << volt << endl;
}

Core_MCU::~Core_MCU()
{
    cout << "MCU dimatikan" << endl;
}

void Core_MCU::nambah_volt(int penambahan_voltase)
{
    volt += penambahan_voltase;
}

void Core_MCU::ganti_os(string new_os)
{
    os = new_os;
}

string Core_MCU::get_os()
{
    return os;
}
