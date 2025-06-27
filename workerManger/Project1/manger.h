#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

//经理类，继承worker基类
class manger :public worker
{

public:
	//构造函数
	manger(int id, string name, int deptId);

	//重写
	void showInfo();
	string getDeptName();

};
