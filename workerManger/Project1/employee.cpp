#include"employee.h"
#include<string>

employee::employee(int id,string name,int deptId)
{
	this->w_id = id;
	this->w_name = name;
	this->w_deptId = deptId;
}

void employee::showInfo()
{
	cout << "职工编号：" << this->w_id
		<< "\t职工姓名：" << this->w_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理交代的任务" << endl;;
}

string employee::getDeptName()
{
	return string("普通员工");
}
