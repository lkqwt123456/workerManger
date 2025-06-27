#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

//员工类，继承worker基类
class employee :public worker
{

public:
	//构造函数
	employee(int id, string name, int deptId);
	
	//重写
	void showInfo();
	string getDeptName();

};
