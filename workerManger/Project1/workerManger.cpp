#include"workerManger.h"

workerManger::workerManger()
{
	//这种初始化不知道文件是否存在
	/*this->w_num = 0;
	this->w_numArr = NULL;*/

	//初始化文件
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->w_num = 0;
		this->w_numArr = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在，数据为空
	char ch;
	//读数据
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件存在,但数据为空" << endl;
		this->w_num = 0;
		this->w_numArr = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且不为空
	int num = this->getWorkerNum();
	//cout << "职工人数为" << num << endl;
	this->w_num = num;

	this->w_numArr = new worker * [this->w_num];
	this->init_worker();

}

//显示菜单
void workerManger::showMenu()
{
	cout << "*********************************************" << endl;
	cout << "*********** 欢迎使用职工管理系统! ***********" << endl;
	cout << "*************** 0.退出管理程序 **************" << endl;
	cout << "*************** 1.增加职工信息 **************" << endl;
	cout << "*************** 2.显示职工信息 **************" << endl;
	cout << "*************** 3.删除离职职工 **************" << endl;
	cout << "*************** 4.修改职工信息 **************" << endl;
	cout << "*************** 5.查找职工信息 **************" << endl;
	cout << "*************** 6.按照编号排序 **************" << endl;
	cout << "*************** 7.清空所有文档 **************" << endl;
	cout << "*********************************************" << endl;
	cout << endl;
}

//退出管理程序
void workerManger::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加职工
void workerManger::addWorker()
{
	cout << "请输入添加人数:";
	int add_num = 0;
	cin >> add_num;

	if (add_num > 0)
	{

		//添加
		//计算新空间的大小
		int newSize = this->w_num + add_num;

		//开辟新空间
		worker ** newSpace = new worker * [newSize];

		//将原来空间下的数据拷贝到新空间下
		if (this->w_numArr != NULL)
		{
			for (int i = 0; i < this->w_num; i++)
			{
				newSpace[i] = this->w_numArr[i];
			}
		}

		//批量添加数据
		for (int i = 0; i < add_num; i++)
		{
			int id;
			string name;
			int w_select;

			while (true)
			{
				cout << "请输入第" << i + 1 << "个添加职工的编号" << endl;
				cin >> id;
				int ret = this->workerIsExist(id);
				if (ret != -1)
				{
					cout << "编号已存在" << endl;
				}
				else
				{
					break;
				}
			}
			cout << "请输入第" << i + 1 << "个添加职工的姓名" << endl;
			cin >> name;
			cout << "请选择该岗位职责" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> w_select;

			worker* worker = NULL;
			switch (w_select)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manger(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				cout << "选择有误" << endl;
				break;
			}

			//将创建岗位职责保存到数组中
			newSpace[this->w_num + i] = worker;

		}

		//释放原有空间,二级指针
		delete[] this->w_numArr;

		//更新新空间的指向
		this->w_numArr = newSpace;

		//更新新的职工人数
		this->w_num = newSize;
		this->fileIsEmpty = false;

		//保存职工信息
		this->saveWorker();
		cout << "成功添加" << add_num << "名新职工" << endl;

	}
	else
	{
		cout << "输入有误" << endl;
	}

	system("pause");
	system("cls");

}

//保存职工信息
void workerManger::saveWorker()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->w_num; i++)
	{
		ofs << this->w_numArr[i]->w_id << " "
			<< this->w_numArr[i]->w_name << " "
			<< this->w_numArr[i]->w_deptId << endl;
	}
	ofs.close();

}

//获取职工人数
int workerManger::getWorkerNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int deptId;
	int num = 0;
	
	while (ifs >> id && ifs >> name && ifs >> deptId)
	{
		num++;
	}

	ifs.close();
	return num;
	
}

//初始化职工数组
void workerManger::init_worker()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int deptId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deptId)
	{
		worker* worker = NULL;
		if (deptId == 1)
		{
			worker = new employee(id, name, deptId);
		}
		else if(deptId == 2)
		{
			worker = new manger(id, name, deptId);
		}
		else
		{
			worker = new boss(id, name, deptId);
		}
		this->w_numArr[index] = worker;
		index++;
	}
	ifs.close();
}

//显示职工信息
void workerManger::showWorker()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->w_num; i++)
		{
			this->w_numArr[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

//根据编号判断职工是否存在，若存在返回职工在数组中的位置，不存在返回-1
int workerManger::workerIsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->w_num; i++)
	{
		if (this->w_numArr[i]->w_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//删除职工信息
void workerManger::deleteWorker()
{
	if (this->fileIsEmpty) {
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号：";
		int id;
		cin >> id;

		if (this->workerIsExist(id) == -1)
		{
			cout << "职工不存在" << endl;
		}
		else
		{
			for (int i = this->workerIsExist(id); i < this->w_num - 1; i++)
			{
				this->w_numArr[i] = this->w_numArr[i + 1];
			}
			this->w_num--;
			this->saveWorker();
			cout << "删除成功" << endl;
		}
	}

	system("pause");
	system("cls");
}

//修改职工信息
void workerManger::modifyWorker()
{
	if (!this->fileIsEmpty)
	{
		cout << "请输入修改职工的编号：" << endl;
		int id = 0;
		cin >> id;
		int ret = this->workerIsExist(id);
		if (ret != -1)
		{
			delete this->w_numArr[ret];

			int newId = 0;
			string newName = "";
			int newDeptId = 0;

			cout << "请输入新的职工编号：";
			cin >> newId;
			cout << "请输入新的职工姓名：";
			cin >> newName;
			cout << "请输入新的职工岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> newDeptId;

			worker* worker = NULL;
			switch (newDeptId)
			{
			case 1:
				worker = new employee(newId, newName, 1);
				break;
			case 2:
				worker = new manger(newId, newName, 2);
				break;
			case 3:
				worker = new boss(newId, newName, 3);
				break;
			default:
				break;
			}
			this->w_numArr[ret] = worker;
			cout << "修改成功" << endl;

			this->saveWorker();
		}
		else
		{
			cout << "未找到该职工，修改失败" << endl;
		}
	}
	else
	{
		cout << "文件不存在或者数据为空" << endl;
	}

	system("pause");
	system("cls");
}

//查找职工
void workerManger::findWorker()
{
	if (!this->fileIsEmpty)
	{
		cout << "请输入查找方式" << endl;
		cout << "1.按编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		int findSelect;
		cin >> findSelect;

		if (findSelect == 1)
		{
			cout << "请输入查找的编号" << endl;
			int findId;
			cin >> findId;
			if (this->workerIsExist(findId) != -1)
			{
				cout << "找到编号为" << findId << "的职工" << endl;
				this->w_numArr[this->workerIsExist(findId)]->showInfo();
			}
			else
			{
				cout << "按编号查找失败" << endl;
			}
		}
		else if (findSelect == 2)
		{
			cout << "请输入查找的姓名" << endl;
			string findName;
			cin >> findName;
			bool isFind = false;
			for (int i = 0; i < this->w_num; i++)
			{
				if (this->w_numArr[i]->w_name == findName)
				{
					isFind = true;
					cout << "找到姓名为" << findName << "的职工" << endl;
					this->w_numArr[i]->showInfo();
				}
			}
			if (!isFind)
			{
				cout << "按姓名查找失败" << endl;
			}
		}
		else
		{
			cout << "输入的查找方式有误" << endl;
		}
		
	}
	else
	{
		cout << "文件不存在或者数据为空" << endl;
	}

	system("pause");
	system("cls");
}

//按编号对职工进行排序
void workerManger::sortWorker()
{
	if (!this->fileIsEmpty)
	{
		cout << "请输入排序方式" << endl;
		cout << "1.按编号进行升序" << endl;
		cout << "2.按编号进行降序" << endl;
		int sortSelect;
		cin >> sortSelect;
		for (int i = 0; i < this->w_num; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->w_num; j++)
			{
				if (sortSelect == 1)
				{
					if (this->w_numArr[minOrMax]->w_id > this->w_numArr[j]->w_id)
					{
						minOrMax = j;
					}
				}
				else if (sortSelect == 2)
				{
					if (this->w_numArr[minOrMax]->w_id < this->w_numArr[j]->w_id)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "输入的查找方式有误" << endl;
				}
			}
			if (i != minOrMax)
			{
				worker* temp = this->w_numArr[i];
				this->w_numArr[i] = this->w_numArr[minOrMax];
				this->w_numArr[minOrMax] = temp;
			}
		}
		cout << "排序成功" << endl;
		this->saveWorker();
		this->showWorker();
	}
	else
	{
		cout << "文件不存在或者数据为空" << endl;
		system("pause");
		system("cls");
	}
}

//删除所有职工信息
void workerManger::deleteAllWorker()
{
	if (!this->fileIsEmpty)
	{
		cout << "是否确认删除?" << endl;
		cout << "1.确认" << endl;
		cout << "2.返回" << endl;
		int isDelete;
		cin >> isDelete;
		if (isDelete == 1)
		{
			//如果文件存在，删除文件并重新创建
			ofstream ofs(FILENAME, ios::trunc);
			ofs.close();
			if (this->w_numArr != NULL)
			{
				for (int i = 0; i < this->w_num; i++)
				{
					if (this->w_numArr[i] != NULL)
					{
						delete this->w_numArr[i];
						this->w_numArr[i] = NULL;
					}
				}
				delete[] this->w_numArr;
				this->w_numArr = NULL;
				this->w_num = 0;
				this->fileIsEmpty = true;
			}
			cout << "清空成功!" << endl;
		}
	}
	else
	{
		cout << "文件不存在或者数据为空" << endl;
	}
	system("pause");
	system("cls");
}

workerManger::~workerManger()
{
	//对堆区开辟的数据进行清空
	if (this->w_numArr != NULL)
	{
		for (int i = 0; i < this->w_num; i++)
		{
			if (this->w_numArr[i] != NULL)
			{
				delete this->w_numArr[i];
				this->w_numArr[i] = NULL;
			}
		}
		delete[] this->w_numArr;
		this->w_numArr = NULL;
	}
}