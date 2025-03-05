#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define Max 1000 //最大通訊錄人數

struct Person
{
	string m_Name; //姓名
	int m_Sex; //性別 1 男 2 女
	int m_Age; //年齡
	string m_Phone; //電話
	string m_Addr; //地址
};
struct AddressBooks
{
	Person personArray[Max]; //通訊錄中存放的聯絡人數組
	int m_Size; //通訊錄中當前人數
};
//菜單介面
void Show_Menu()
{
	cout << "**************************" << endl;
	cout << "1.添加聯絡人" << endl;
	cout << "2.顯示聯絡人" << endl;
	cout << "3.刪除聯絡人" << endl;
	cout << "4.查找聯絡人" << endl;
	cout << "5.修改聯絡人" << endl;
	cout << "6.清空聯絡人" << endl;
	cout << "0.退出通訊錄" << endl;
	cout << "**************************" << endl;
}

//添加聯絡人
void add_Person(AddressBooks *abs)
{
	if (abs->m_Size == Max)
	{
		cout << "通訊錄已滿，無法添加！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "請輸入姓名: ";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性別
		int sex = 0;
		cout << "請輸入性別: 1 男 2 女" << endl;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				"輸入有誤，請重新輸入。";
			}
		}
		//年齡
		int age = 0;
		cout << "請輸入年齡: ";
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//電話
		string phone;
		cout << "請輸入電話: ";
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//地址
		string addr;
		cout << "請輸入地址: ";
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		//更新通訊錄人數
		abs->m_Size++;
		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
	}
}
//顯示聯絡人
void show_Info(AddressBooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通訊錄為空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name
				 << "\t性別：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女")
				 << "\t年齡：" << abs->personArray[i].m_Age
				 << "\t電話：" << abs->personArray[i].m_Phone
				 << "\t地址：" << abs->personArray[i].m_Addr << endl;
		}

	}
	system("pause");
	system("cls");
}
//判斷是否存在
int is_Exist(AddressBooks *abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
//刪除聯絡人
void del_Person(AddressBooks *abs)
{
	string name;
	cout << "請輸入要刪除的姓名: ";
	cin >> name;
	int ret = is_Exist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "刪除成功！" << endl;
	}
	else
	{
		cout << "查無此人！" << endl;
	}
	system("pause");
	system("cls");
}
//查找聯絡人
void find_Person(AddressBooks* abs)
{
	string name;
	cout << "請輸入要查找的姓名: ";
	cin >> name;
	int ret = is_Exist(abs, name);
	if (ret !=-1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name
			<< "\t性別：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女")
			<< "\t年齡：" << abs->personArray[ret].m_Age
			<< "\t電話：" << abs->personArray[ret].m_Phone
			<< "\t地址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查無此人！" << endl;
	}
	system("pause");
	system("cls");
}
//修改聯絡人
void mod_Person(AddressBooks *abs)
{
	string name;
	cout << "請輸入要修改的姓名: ";
	cin >> name;
	int ret = is_Exist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "請輸入姓名: ";
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性別
		int sex = 0;
		cout << "請輸入性別: 1 男 2 女" << endl;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				"輸入有誤，請重新輸入。";
			}
		}
		//年齡
		int age = 0;
		cout << "請輸入年齡: ";
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//電話
		string phone;
		cout << "請輸入電話: ";
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//地址
		string addr;
		cout << "請輸入地址: ";
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
		//更新通訊錄人數
		cout << "修改成功！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "查無此人！" << endl;
	}
	system("pause");
	system("cls");
}
//清空聯絡人
void clear_Addr(AddressBooks *abs)
{
	abs->m_Size = 0;
	cout << "通訊錄已清空！" << endl;
	system("pause");
	system("cls");
}
//保存
void Save(AddressBooks* abs)
{
	ofstream ofs;
	ofs.open("AddressBooks.txt", ios::out);
	for (int i = 0; i < abs->m_Size; i++)
	{
		
		ofs << abs->personArray[i].m_Name << " "
			<< abs->personArray[i].m_Sex << " "
			<< abs->personArray[i].m_Age << " "
			<< abs->personArray[i].m_Phone << " "
			<< abs->personArray[i].m_Addr << endl;
	}
	cout << "保存成功！" << endl;
	ofs.close();
}
//讀取
void read(AddressBooks* abs)
{
	ifstream ifs;
	string name;
	int sex;
	int age;
	string phone;
	string addr;
	ifs.open("AddressBooks.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		return;
	}
	while (ifs >> name && ifs >> sex && ifs >> age && ifs >> phone && ifs >> addr)
	{
		abs->personArray[abs->m_Size].m_Name = name;
		abs->personArray[abs->m_Size].m_Addr = addr;
		abs->personArray[abs->m_Size].m_Age = age;
		abs->personArray[abs->m_Size].m_Phone = phone;
		abs->personArray[abs->m_Size].m_Addr = addr;
		abs->m_Size++;
	}
	ifs.close();
}