#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

//Ա���࣬�̳�worker����
class employee :public worker
{

public:
	//���캯��
	employee(int id, string name, int deptId);
	
	//��д
	void showInfo();
	string getDeptName();

};
