#include "employee.h"

Employee::Employee(int ID, string name, int dID)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_dID = dID;
}

void Employee::showInfo()
{
	cout << "員工編號：" << this->m_ID
		<< "\t員工名稱：" << this->m_Name
		<< "\t崗位：" << this->getDepName()
		<< "\t崗位職責：" << endl;
}

string Employee::getDepName()
{
	return string("員工");
}