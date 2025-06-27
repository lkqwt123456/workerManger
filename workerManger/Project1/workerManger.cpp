#include"workerManger.h"

workerManger::workerManger()
{
	//���ֳ�ʼ����֪���ļ��Ƿ����
	/*this->w_num = 0;
	this->w_numArr = NULL;*/

	//��ʼ���ļ�
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//�ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->w_num = 0;
		this->w_numArr = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڣ�����Ϊ��
	char ch;
	//������
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�����,������Ϊ��" << endl;
		this->w_num = 0;
		this->w_numArr = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ������Ҳ�Ϊ��
	int num = this->getWorkerNum();
	//cout << "ְ������Ϊ" << num << endl;
	this->w_num = num;

	this->w_numArr = new worker * [this->w_num];
	this->init_worker();

}

//��ʾ�˵�
void workerManger::showMenu()
{
	cout << "*********************************************" << endl;
	cout << "*********** ��ӭʹ��ְ������ϵͳ! ***********" << endl;
	cout << "*************** 0.�˳�������� **************" << endl;
	cout << "*************** 1.����ְ����Ϣ **************" << endl;
	cout << "*************** 2.��ʾְ����Ϣ **************" << endl;
	cout << "*************** 3.ɾ����ְְ�� **************" << endl;
	cout << "*************** 4.�޸�ְ����Ϣ **************" << endl;
	cout << "*************** 5.����ְ����Ϣ **************" << endl;
	cout << "*************** 6.���ձ������ **************" << endl;
	cout << "*************** 7.��������ĵ� **************" << endl;
	cout << "*********************************************" << endl;
	cout << endl;
}

//�˳��������
void workerManger::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void workerManger::addWorker()
{
	cout << "�������������:";
	int add_num = 0;
	cin >> add_num;

	if (add_num > 0)
	{

		//���
		//�����¿ռ�Ĵ�С
		int newSize = this->w_num + add_num;

		//�����¿ռ�
		worker ** newSpace = new worker * [newSize];

		//��ԭ���ռ��µ����ݿ������¿ռ���
		if (this->w_numArr != NULL)
		{
			for (int i = 0; i < this->w_num; i++)
			{
				newSpace[i] = this->w_numArr[i];
			}
		}

		//�����������
		for (int i = 0; i < add_num; i++)
		{
			int id;
			string name;
			int w_select;

			while (true)
			{
				cout << "�������" << i + 1 << "�����ְ���ı��" << endl;
				cin >> id;
				int ret = this->workerIsExist(id);
				if (ret != -1)
				{
					cout << "����Ѵ���" << endl;
				}
				else
				{
					break;
				}
			}
			cout << "�������" << i + 1 << "�����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ��ø�λְ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
			cin >> w_select;

			worker* worker = NULL;
			switch (w_select)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manger(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				cout << "ѡ������" << endl;
				break;
			}

			//��������λְ�𱣴浽������
			newSpace[this->w_num + i] = worker;

		}

		//�ͷ�ԭ�пռ�,����ָ��
		delete[] this->w_numArr;

		//�����¿ռ��ָ��
		this->w_numArr = newSpace;

		//�����µ�ְ������
		this->w_num = newSize;
		this->fileIsEmpty = false;

		//����ְ����Ϣ
		this->saveWorker();
		cout << "�ɹ����" << add_num << "����ְ��" << endl;

	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");

}

//����ְ����Ϣ
void workerManger::saveWorker()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->w_num; i++)
	{
		ofs << this->w_numArr[i]->w_id << " "
			<< this->w_numArr[i]->w_name << " "
			<< this->w_numArr[i]->w_deptId << endl;
	}
	ofs.close();

}

//��ȡְ������
int workerManger::getWorkerNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int deptId;
	int num = 0;
	
	while (ifs >> id && ifs >> name && ifs >> deptId)
	{
		num++;
	}

	ifs.close();
	return num;
	
}

//��ʼ��ְ������
void workerManger::init_worker()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int deptId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deptId)
	{
		worker* worker = NULL;
		if (deptId == 1)
		{
			worker = new employee(id, name, deptId);
		}
		else if(deptId == 2)
		{
			worker = new manger(id, name, deptId);
		}
		else
		{
			worker = new boss(id, name, deptId);
		}
		this->w_numArr[index] = worker;
		index++;
	}
	ifs.close();
}

//��ʾְ����Ϣ
void workerManger::showWorker()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->w_num; i++)
		{
			this->w_numArr[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

//���ݱ���ж�ְ���Ƿ���ڣ������ڷ���ְ���������е�λ�ã������ڷ���-1
int workerManger::workerIsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->w_num; i++)
	{
		if (this->w_numArr[i]->w_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//ɾ��ְ����Ϣ
void workerManger::deleteWorker()
{
	if (this->fileIsEmpty) {
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ����ţ�";
		int id;
		cin >> id;

		if (this->workerIsExist(id) == -1)
		{
			cout << "ְ��������" << endl;
		}
		else
		{
			for (int i = this->workerIsExist(id); i < this->w_num - 1; i++)
			{
				this->w_numArr[i] = this->w_numArr[i + 1];
			}
			this->w_num--;
			this->saveWorker();
			cout << "ɾ���ɹ�" << endl;
		}
	}

	system("pause");
	system("cls");
}

//�޸�ְ����Ϣ
void workerManger::modifyWorker()
{
	if (!this->fileIsEmpty)
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id = 0;
		cin >> id;
		int ret = this->workerIsExist(id);
		if (ret != -1)
		{
			delete this->w_numArr[ret];

			int newId = 0;
			string newName = "";
			int newDeptId = 0;

			cout << "�������µ�ְ����ţ�";
			cin >> newId;
			cout << "�������µ�ְ��������";
			cin >> newName;
			cout << "�������µ�ְ����λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
			cin >> newDeptId;

			worker* worker = NULL;
			switch (newDeptId)
			{
			case 1:
				worker = new employee(newId, newName, 1);
				break;
			case 2:
				worker = new manger(newId, newName, 2);
				break;
			case 3:
				worker = new boss(newId, newName, 3);
				break;
			default:
				break;
			}
			this->w_numArr[ret] = worker;
			cout << "�޸ĳɹ�" << endl;

			this->saveWorker();
		}
		else
		{
			cout << "δ�ҵ���ְ�����޸�ʧ��" << endl;
		}
	}
	else
	{
		cout << "�ļ������ڻ�������Ϊ��" << endl;
	}

	system("pause");
	system("cls");
}

//����ְ��
void workerManger::findWorker()
{
	if (!this->fileIsEmpty)
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1.����Ų���" << endl;
		cout << "2.����������" << endl;
		int findSelect;
		cin >> findSelect;

		if (findSelect == 1)
		{
			cout << "��������ҵı��" << endl;
			int findId;
			cin >> findId;
			if (this->workerIsExist(findId) != -1)
			{
				cout << "�ҵ����Ϊ" << findId << "��ְ��" << endl;
				this->w_numArr[this->workerIsExist(findId)]->showInfo();
			}
			else
			{
				cout << "����Ų���ʧ��" << endl;
			}
		}
		else if (findSelect == 2)
		{
			cout << "��������ҵ�����" << endl;
			string findName;
			cin >> findName;
			bool isFind = false;
			for (int i = 0; i < this->w_num; i++)
			{
				if (this->w_numArr[i]->w_name == findName)
				{
					isFind = true;
					cout << "�ҵ�����Ϊ" << findName << "��ְ��" << endl;
					this->w_numArr[i]->showInfo();
				}
			}
			if (!isFind)
			{
				cout << "����������ʧ��" << endl;
			}
		}
		else
		{
			cout << "����Ĳ��ҷ�ʽ����" << endl;
		}
		
	}
	else
	{
		cout << "�ļ������ڻ�������Ϊ��" << endl;
	}

	system("pause");
	system("cls");
}

//����Ŷ�ְ����������
void workerManger::sortWorker()
{
	if (!this->fileIsEmpty)
	{
		cout << "����������ʽ" << endl;
		cout << "1.����Ž�������" << endl;
		cout << "2.����Ž��н���" << endl;
		int sortSelect;
		cin >> sortSelect;
		for (int i = 0; i < this->w_num; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->w_num; j++)
			{
				if (sortSelect == 1)
				{
					if (this->w_numArr[minOrMax]->w_id > this->w_numArr[j]->w_id)
					{
						minOrMax = j;
					}
				}
				else if (sortSelect == 2)
				{
					if (this->w_numArr[minOrMax]->w_id < this->w_numArr[j]->w_id)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "����Ĳ��ҷ�ʽ����" << endl;
				}
			}
			if (i != minOrMax)
			{
				worker* temp = this->w_numArr[i];
				this->w_numArr[i] = this->w_numArr[minOrMax];
				this->w_numArr[minOrMax] = temp;
			}
		}
		cout << "����ɹ�" << endl;
		this->saveWorker();
		this->showWorker();
	}
	else
	{
		cout << "�ļ������ڻ�������Ϊ��" << endl;
		system("pause");
		system("cls");
	}
}

//ɾ������ְ����Ϣ
void workerManger::deleteAllWorker()
{
	if (!this->fileIsEmpty)
	{
		cout << "�Ƿ�ȷ��ɾ��?" << endl;
		cout << "1.ȷ��" << endl;
		cout << "2.����" << endl;
		int isDelete;
		cin >> isDelete;
		if (isDelete == 1)
		{
			//����ļ����ڣ�ɾ���ļ������´���
			ofstream ofs(FILENAME, ios::trunc);
			ofs.close();
			if (this->w_numArr != NULL)
			{
				for (int i = 0; i < this->w_num; i++)
				{
					if (this->w_numArr[i] != NULL)
					{
						delete this->w_numArr[i];
						this->w_numArr[i] = NULL;
					}
				}
				delete[] this->w_numArr;
				this->w_numArr = NULL;
				this->w_num = 0;
				this->fileIsEmpty = true;
			}
			cout << "��ճɹ�!" << endl;
		}
	}
	else
	{
		cout << "�ļ������ڻ�������Ϊ��" << endl;
	}
	system("pause");
	system("cls");
}

workerManger::~workerManger()
{
	//�Զ������ٵ����ݽ������
	if (this->w_numArr != NULL)
	{
		for (int i = 0; i < this->w_num; i++)
		{
			if (this->w_numArr[i] != NULL)
			{
				delete this->w_numArr[i];
				this->w_numArr[i] = NULL;
			}
		}
		delete[] this->w_numArr;
		this->w_numArr = NULL;
	}
}