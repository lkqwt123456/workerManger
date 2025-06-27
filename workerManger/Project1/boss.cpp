#include"boss.h"
#include<string>

boss::boss(int id, string name, int deptId)
{
	this->w_id = id;
	this->w_name = name;
	this->w_deptId = deptId;
}

void boss::showInfo()
{
	cout << "职工编号：" << this->w_id
		<< "\t职工姓名：" << this->w_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：管理公司一切事务" << endl;;
}

string boss::getDeptName()
{
	return string("总裁");
}