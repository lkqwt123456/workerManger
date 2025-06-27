#pragma once
#include<stdio.h>
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manger.h"
#include"boss.h"
#include<fstream>
#define FILENAME "workerFile.txt"

//职工管理类
class workerManger
{

public:
	workerManger();

	//显示菜单
	void showMenu();

	//退出管理程序
	void exitSystem();

	//记录职工人数
	int w_num;

	//职工数组指针
	worker** w_numArr;

	//判断文件是否为空标志
	bool fileIsEmpty;

	//添加职工
	void addWorker();

	//保存职工
	void saveWorker();

	//获取职工人数
	int getWorkerNum();

	//初始化职工数组
	void init_worker();

	//显示职工信息
	void showWorker();

	//根据编号判断职工是否存在，若存在返回职工在数组中的位置，不存在返回-1
	int workerIsExist(int id);

	//删除职工信息
	void deleteWorker();

	//修改职工信息
	void modifyWorker();

	//查找职工
	void findWorker();

	//按编号对职工进行排序
	void sortWorker();

	//删除所有职工信息
	void deleteAllWorker();

	~workerManger();

};
