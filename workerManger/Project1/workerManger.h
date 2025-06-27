#pragma once
#include<stdio.h>
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manger.h"
#include"boss.h"
#include<fstream>
#define FILENAME "workerFile.txt"

//ְ��������
class workerManger
{

public:
	workerManger();

	//��ʾ�˵�
	void showMenu();

	//�˳��������
	void exitSystem();

	//��¼ְ������
	int w_num;

	//ְ������ָ��
	worker** w_numArr;

	//�ж��ļ��Ƿ�Ϊ�ձ�־
	bool fileIsEmpty;

	//���ְ��
	void addWorker();

	//����ְ��
	void saveWorker();

	//��ȡְ������
	int getWorkerNum();

	//��ʼ��ְ������
	void init_worker();

	//��ʾְ����Ϣ
	void showWorker();

	//���ݱ���ж�ְ���Ƿ���ڣ������ڷ���ְ���������е�λ�ã������ڷ���-1
	int workerIsExist(int id);

	//ɾ��ְ����Ϣ
	void deleteWorker();

	//�޸�ְ����Ϣ
	void modifyWorker();

	//����ְ��
	void findWorker();

	//����Ŷ�ְ����������
	void sortWorker();

	//ɾ������ְ����Ϣ
	void deleteAllWorker();

	~workerManger();

};
