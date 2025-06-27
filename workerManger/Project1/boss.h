#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

//总裁类，继承worker基类
class boss :public worker
{

public:
	//构造函数
	boss(int id, string name, int deptId);

	//重写
	void showInfo();
	string getDeptName();

};
