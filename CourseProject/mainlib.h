#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <Windows.h>

using namespace std;

struct PC;
void Input(int point);
void Output(int point);
void Sort();
void Edit();
void Select();
void Delete(int& N);
PC* search(int& j, int point);
void search(PC* CATALOG2, int kol, int point);