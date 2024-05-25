#ifndef XE_H
#define XE_H
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
class Xe
{
private:
    std::string biensoxe;
    int tien = 0;

public:
    std::string time_in, time_out;
    Xe(std::string biensoxe, std::string time_in)
    {
        this->biensoxe = biensoxe;
        this->time_in = time_in;
    }
    Xe()
    {
    }
    std::string getBienSo()
    {
        return biensoxe;
    }
    std::string getTimeIn()
    {
        return time_in;
    }
    void setTimeOut(std::string time_out)
    {
        this->time_out = time_out;
    }
    std::string getTimeOut()
    {
        return time_out;
    }
    void setTien(int tien)
    {
        this->tien = tien;
    }
    int getTien()
    {
        return tien;
    }
    void tinhTien(Xe &c);
};

void Xe::tinhTien(Xe &c)
{
    float differ = stoi(c.getTimeIn()) - stoi(c.getTimeOut());
    if (differ <= 30)
    {
        c.setTien(50000);
    }
    else
    {
        c.setTien(50000);
        c.setTien(c.getTien() + 20000 * (differ / 30));
    }
}
#endif