#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

//�����࣬�̳�worker����
class manger :public worker
{

public:
	//���캯��
	manger(int id, string name, int deptId);

	//��д
	void showInfo();
	string getDeptName();

};
