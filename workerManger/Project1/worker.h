#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ���������
class worker{

public:
	//���麯��
	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	//��ȡ��λ����
	virtual string getDeptName() = 0;

public:
	int w_id;
	string w_name;
	int w_deptId;

};
