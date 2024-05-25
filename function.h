#ifndef FUNCTION_H
#define FUNCTION_H
#include "function.cpp"
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
void Make_Park(int col, int row, std::vector<std::vector<int>> &amount);
void Reset_Park(std::vector<std::vector<int>> &amount, int hang, int cot);
bool Check_Empty(std::vector<std::vector<int>> &amount, int row, int col);
void Input_Things(std::vector<std::vector<int>> &amount, int row, int col, bool &flag);
void Output_Park(std::vector<std::vector<int>> &amount);
void Make_BienSo(std::vector<Car> &a, int index);
void Print_Output(Car &a);
void function_01(std::vector<std::vector<int>> &Park, std::vector<Car> &a, int index, int &k);
void Release(std::vector<std::vector<int>> &Park, std::vector<Car> a, int index);
void Tonghop();
void find_vitri(vector<Car> &a, vector<vector<int>> Park);
#endif
