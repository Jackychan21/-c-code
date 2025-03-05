#include <iostream>
#include "Header.h"
using namespace std;

int main() 
{
	AddressBooks abs; //創建通訊錄結構體變量
	abs.m_Size = 0; //初始化通訊錄中當前人數
	read(&abs); //讀取文件中數據
	int selct = 0;

	while (true)
	{
		//菜單介面
		Show_Menu();
		//輸入選擇
		cout << "請輸入選擇: ";
		cin >> selct;
		cout << endl;
		switch (selct)
		{
		case 1: //添加聯絡人
			add_Person(&abs);
			break;
		case 2: //顯示聯絡人
			show_Info(&abs);
			break;
		case 3: //刪除聯絡人
			del_Person(&abs);
			break;
		case 4: //查找聯絡人
			find_Person(&abs);
			break;
		case 5: //修改聯絡人
			mod_Person(&abs);
			break;
		case 6: //清空聯絡人
			clear_Addr(&abs);
			break;
		case 0: //退出通訊錄
			cout << "歡迎下次使用！" << endl; 
			system("pause");
	        Save(&abs); //退出通訊錄時，保存數據到文件
			return 0;
			break;
		default:
			cout << "沒有該指令，請重新輸入。" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}