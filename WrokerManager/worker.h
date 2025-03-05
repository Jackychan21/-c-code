#pragma once
#include <iostream>
#include <string>
using namespace std;


class Worker
{
public:
	Worker() : m_ID(0), m_Name(""), m_dID(0) {}
	//顯示訊息
	virtual void showInfo() = 0;
	// 取得部門編號
	virtual string getDepName() = 0;
	int m_ID; //編號
	string m_Name; //姓名
	int m_dID; //部門編號
};