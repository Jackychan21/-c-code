#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#define FILENAME "emp_direct.txt"


class WorkerManager
{
public:
    WorkerManager();

    void Show_Menu();
    void exitSystem();
    //員工編號
    int m_EmpNum;
    //員工指針陣列
    Worker** m_EmpArray;
    //加入
    void Add_Employe();
    //储存
    void Save();
    //判斷文件是否為空
    bool m_FileIsEmpty;
    int get_EmpNum(); //獲取紀錄的員工個數
	void init_Emp(); //初始化員工
	void  Show_Emp(); //顯示員工
	int IsExist(int id); //判斷員工是否存在
	Worker * switch_Emp(int Id, string name); //切換員工
	void  Del_Emp(); //刪除員工
	void  Mod_Emp(); //修改員工
	void  Find_Emp(); //查找員工
	void  Sort_Emp(); //排序員工
	void  Clean_File(); //清空文件
    ~WorkerManager();
};