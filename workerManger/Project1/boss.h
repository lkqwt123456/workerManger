#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

//�ܲ��࣬�̳�worker����
class boss :public worker
{

public:
	//���캯��
	boss(int id, string name, int deptId);

	//��д
	void showInfo();
	string getDeptName();

};
