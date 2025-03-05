#include "workerManager.h"
WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    //文件不存在
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        //初始化
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    //文件存在且為空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件為空" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    //文件存在並記錄數據
    int num = this->get_EmpNum();
    this->m_EmpNum = num;

	//初始化員工陣列
	this->m_EmpArray = new Worker * [this->m_EmpNum];
    this->init_Emp();


}
//切換員工
Worker *WorkerManager::switch_Emp(int Id, string name)
{
	int dSelect = 0;
    cin >> dSelect;
	Worker* worker = NULL;
	switch (dSelect)
	{
	case 1:
		worker = new Employee(Id, name, dSelect);
		break;
	case 2:
		worker = new Manager(Id, name, dSelect);
		break;
	case 3:
		worker = new Boss(Id, name, dSelect);
		break;
	default:
		break;
	}
    return worker;
}
//顯示菜單
void WorkerManager::Show_Menu()
{
    cout << "===========================" << endl;
    cout << "歡迎來到員工管理系統!" << endl;
    cout << "0.退出管理系統" << endl;
    cout << "1.增加新進員工" << endl;
    cout << "2.顯示在職員工" << endl;
    cout << "3.刪除離職員工" << endl;
    cout << "4.修改員工訊息" << endl;
    cout << "5.查找員工訊息" << endl;
    cout << "6.按照編號排序" << endl;
    cout << "7.清空所有文件" << endl;
    cout << "===========================" << endl;
	cout << "目前員工人數為：" << this->m_EmpNum << endl;
}
//退出系統
void WorkerManager::exitSystem()
{
	cout << "歡迎下次使用~" << endl;
    exit(0);
}
//添加員工
void WorkerManager::Add_Employe()
{
    cout << "請輸入要添加幾人：" << endl;
    int add_num = 0;
    cin >> add_num;
    if (add_num > 0)
    {
        //添加
        //計算添加新空間大小
        int newSize = this->m_EmpNum + add_num; //原本個數 ＋ 新增人數
        //開闢新空間
        Worker ** newSpace = new Worker* [newSize];
        //copy 到新空間
        if (this->m_EmpArray !=NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //添加新數據
        for (int i = 0; i < add_num; i++)
        {
            int id;
            string name;
            int dSelect;
            cout << "請輸入第" << (i + 1) << "個新員工編號：" << endl;
            cin >> id;
			if (this->IsExist(id)==0 || newSpace[this->m_EmpNum+i-1]->m_ID == id)
			{
				cout << "編號重複，請重新輸入" << endl;
				i--;
				continue;
			}
            cout << "請輸入第" << (i + 1) << "個 新員工名稱：" << endl;
            cin >> name;
            cout << "請選擇該員工的崗位"
                << "\n1.普通員工"
                << "\n2.經理"
                << "\n3.老闆" << endl;
            
            //保存到陣列中
            newSpace[this->m_EmpNum + i] = this->switch_Emp(id,name);
        }
        //釋放原有空間
        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        this->m_FileIsEmpty = false; //更新不為空標誌
        cout << "成功添加" << add_num << "員工" << endl;

        this->Save();
    }
    else
    {
        cout << "輸入有誤~" << endl;
    }
    system("pause");
    system("cls");
}
//保存文件
void WorkerManager::Save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); //用輸出的方式寫文件
    //將資料寫入文件
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i] != nullptr)
        {
            ofs << this->m_EmpArray[i]->m_ID << " "
                << this->m_EmpArray[i]->m_Name << " "
                << this->m_EmpArray[i]->m_dID << endl;
        }
    }
	ofs.close();
}
//獲取員工人數
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dID;
    int num = 0;
    
    while (ifs >> id && ifs >> name && ifs >> dID)
    {
        num++;
    }
    ifs.close();
    return num;
}
//讀取員工訊息
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
    int id;
	string name;
	int dID;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		Worker* worker = NULL;
		if (dID == 1) //員工
		{
			worker = new Employee(id, name, dID);
		}
		else if (dID == 2)
		{
			worker = new Manager(id, name, dID);
		}
		else
		{
			worker = new Boss(id, name, dID);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
//顯示員工
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者記錄為空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
}
//判斷存在
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
//刪除員工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者記錄為空" << endl;
	}
	else
	{
		this->Show_Emp();
		cout << "請輸入要刪除的員工編號：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->Save();
			cout << "刪除成功" << endl;
		}
		else
		{
			cout << "刪除失敗，查無此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
//修改員工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者記錄為空" << endl;
	}
	else
	{
		this->Show_Emp();
		cout << "請輸入要修改的員工編號：" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newID = 0;
			string newName = "";
			cout << "查到：" << id << "號員工，請輸入新的員工編號：" << endl;
			cin >> newID;
			cout << "請輸入新的員工姓名：" << endl;
			cin >> newName;
            cout << "請輸入新的崗位"
                << "\n1.普通員工"
                << "\n2.經理"
                << "\n3.老闆" << endl;
			this->m_EmpArray[ret] = this->switch_Emp(newID, newName);
			cout << "修改成功，員工訊息如下：" << endl;
			this->m_EmpArray[ret]->showInfo();
			this->Save();
		}
		else
		{
			cout << "修改失敗，查無此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
//查找員工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者記錄為空" << endl;
	}
	else
	{
		cout << "請輸入查找方式"
			<< "\n1.按照編號查找"
			<< "\n2.按照姓名查找" << endl;
		int select = 0;
		cin >> select;
		if(select == 1)
		{
			int id;
			cout << "請輸入查找的編號：" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查無此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "請輸入查找的姓名：" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查到此人，職工編號為：" << this->m_EmpArray[i]->m_ID << " 員工訊息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查無此人" << endl;
			}
		}
		else
		{
			cout << "輸入有誤" << endl;
		}
	}
	system("pause");
	system("cls");
}
//排序員工
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者記錄為空" << endl;
	}
	else
	{
		cout << "請選擇排序方式"
			<< "\n1.按照編號升序"
			<< "\n2.按照編號降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i; //記錄最小值或最大值
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1) //升序
				{
					if (this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功，排序後結果如下：" << endl;
		this->Save();
		this->Show_Emp();
		system("pause");
		system("cls");
	}
}
//清空文件
void WorkerManager::Clean_File()
{
	cout << "確定清空？"
		<< "\n1.確定"
		<< "\n2.取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		this->m_FileIsEmpty = true;
		this->m_EmpNum = 0;
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}