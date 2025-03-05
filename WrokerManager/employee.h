#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Employee : public Worker
{
public:
	Employee(int ID, string name, int dID);
	//顯示訊息
	void showInfo();
	//得到部門編號
	string getDepName();
};