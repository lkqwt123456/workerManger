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
	cout << "ְ����ţ�" << this->w_id
		<< "\tְ��������" << this->w_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;;
}

string manger::getDeptName()
{
	return string("����");
}