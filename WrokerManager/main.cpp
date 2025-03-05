#include <iostream>
#include "WorkerManager.h"
#include "employee.h"
using namespace std;


int main()
{
    WorkerManager wm;

    int choice = 0;

    while (true)
    {

        wm.Show_Menu(); // 顯示菜單
        cout << "請輸入選項：" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0: //退出系統
            wm.exitSystem();
            break;
        case 1: //新增員工
            wm.Add_Employe();
            break;
        case 2: //顯示員工
			wm.Show_Emp();
            system("pause");
            system("cls");
            break;
        case 3: //刪除員工
            wm.Del_Emp();
            break;
        case 4: //修改員工
			wm.Mod_Emp();
            break;
        case 5: //查找員工
			wm.Find_Emp();
            break;
        case 6: //編號排序
            wm.Sort_Emp();
            break;
        case 7: //清空文件
            wm.Clean_File();
            break;
        default:
			cout << "找不到該功能，請重新輸入" << endl;
            break;
        }
    }
    system("pause");
    return 0;
}