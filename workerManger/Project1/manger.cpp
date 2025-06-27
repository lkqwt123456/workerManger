#include"manger.h"
#include<string>

manger::manger(int id, string name, int deptId)
{
	this->w_id = id;
	this->w_name = name;
	this->w_deptId = deptId;
}

void manger::showInfo()
{
	cout << "职工编号：" << this->w_id
		<< "\t职工姓名：" << this->w_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成老板交代的任务，并下发任务给员工" << endl;;
}

string manger::getDeptName()
{
	return string("经理");
}