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
	cout << "ְ����ţ�" << this->w_id
		<< "\tְ��������" << this->w_name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɾ�����������" << endl;;
}

string employee::getDeptName()
{
	return string("��ͨԱ��");
}
