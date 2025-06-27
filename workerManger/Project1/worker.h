#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工抽象基类
class worker{

public:
	//纯虚函数
	//显示个人信息
	virtual void showInfo() = 0;

	//获取岗位名称
	virtual string getDeptName() = 0;

public:
	int w_id;
	string w_name;
	int w_deptId;

};
