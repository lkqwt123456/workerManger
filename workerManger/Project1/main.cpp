#include<iostream>
using namespace std;
#include "workerManger.h"
#include"worker.h"
#include"employee.h"
#include"manger.h"
#include"boss.h"


//���Դ���
void test() 
{
	//��̬��ʵ��
	worker* worker = NULL;
	worker = new employee(1, "����", 1);
	worker->showInfo();
	delete worker;

	worker = new manger(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new boss(3, "����", 3);
	worker->showInfo();
	delete worker;
}


int main()
{

	//test();
	workerManger WM;
	int choice = 0;
	while (true)
	{
		//��ʾ�˵�
		WM.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			WM.exitSystem();	//�˳��������
			break;
		case 1:
			WM.addWorker();		//���ְ��
			break;
		case 2:
			WM.showWorker();	//��ʾְ����Ϣ
			break;
		case 3:
			WM.deleteWorker();	  //ɾ��ְ����Ϣ
			break;
		case 4:
			WM.modifyWorker();	   //�޸�ְ����Ϣ
			break;
		case 5:
			WM.findWorker();	  //����ְ��
			break;
		case 6:
			WM.sortWorker();	  //����Ŷ�ְ����������
			break;
		case 7:
			WM.deleteAllWorker();		//ɾ������ְ����Ϣ
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
