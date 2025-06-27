#include<iostream>
using namespace std;
#include "workerManger.h"
#include"worker.h"
#include"employee.h"
#include"manger.h"
#include"boss.h"


//测试代码
void test() 
{
	//多态的实现
	worker* worker = NULL;
	worker = new employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new manger(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
}


int main()
{

	//test();
	workerManger WM;
	int choice = 0;
	while (true)
	{
		//显示菜单
		WM.showMenu();
		cout << "请输入您的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			WM.exitSystem();	//退出管理程序
			break;
		case 1:
			WM.addWorker();		//添加职工
			break;
		case 2:
			WM.showWorker();	//显示职工信息
			break;
		case 3:
			WM.deleteWorker();	  //删除职工信息
			break;
		case 4:
			WM.modifyWorker();	   //修改职工信息
			break;
		case 5:
			WM.findWorker();	  //查找职工
			break;
		case 6:
			WM.sortWorker();	  //按编号对职工进行排序
			break;
		case 7:
			WM.deleteAllWorker();		//删除所有职工信息
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
