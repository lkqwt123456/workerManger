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
	cout << "ְ����ţ�" << this->w_id
		<< "\tְ��������" << this->w_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ�𣺹���˾һ������" << endl;;
}

string boss::getDeptName()
{
	return string("�ܲ�");
}