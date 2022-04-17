#include "stdafx.h"
#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int main();
void show_data(int searchkey);
void get_data(int i);
void search_student(int searchkey);
int add_student();
int n;
void C_show_data(int C_searchkey);
void C_get_data(int j);
void search_colleague(int C_searchkey);
int add_colleague();
int m;
void W_show_data(int W_searchkey);
void W_get_data(int k);
void search_worker(int W_searchkey);
int add_worker();
int l;
int FEE, colleagueFEE, workerFEE;
string nameArr[1000];
double avgArr[1000];
int idArr[1000];
int feeArr[1000];
int C_feeArr[1000];
int W_feeArr[1000];

struct student
{
	int st_id;
	string st_name;
	int physics, math, computer, chemistry;
	int units, st_fee;
	double avg;
};

struct colleague
{
	int c_id;
	string c_name;
	int c_units, c_salaryfee;
};

struct worker
{
	int w_id;
	string w_name;
	int w_hours, w_salaryfee;
};

student st[1000];
colleague c[1000];
worker w[1000];

int main()
{
	system("CLS");
	int ch;
	int searchkey;
	int C_searchkey;
	int W_searchkey;
	do
	{
		cout << "\t\t#####################################" << endl;
		cout << "\t\t1.Add student" << endl;
		cout << "\t\t2.Search student" << endl;
		cout << "\t\t3.Add colleague" << endl;
		cout << "\t\t4.Search colleague" << endl;
		cout << "\t\t5.Add worker" << endl;
		cout << "\t\t6.Search worker" << endl;
		cout << "\t\t7.calculate university expense" << endl;
		cout << "\t\t\8.Sort students by name" << endl;
		cout << "\t\t9.Sort students by GPA" << endl;
		cout << "\t\t10.Sort students by student number" << endl;
		cout << "\t\t11.Sort students by tuition fee" << endl;
		cout << "\t\t12.Sort colleagues by salary" << endl;
		cout << "\t\t13.Sort workers by salary" << endl;
		cout << "\t\t14.Quit Program" << endl;
		cout << "\t\t#####################################" << endl;
		cout << "Enter your choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			add_student();
			break;
		case 2:
			cout << "Enter id number of student you want to show: ";
			cin >> searchkey;
			search_student(searchkey);
			break;
		case 3:
			add_colleague();
			break;
		case 4:
			cout << "Enter id number of colleague you want to show: ";
			cin >> C_searchkey;
			search_colleague(C_searchkey);
			break;
		case 5:
			add_worker();
			break;
		case 6:
			cout << "Enter id number of worker you want to show: ";
			cin >> W_searchkey;
			search_worker(W_searchkey);
			break;
		case 7:
			cout << "total university expense: " << (FEE - (colleagueFEE + workerFEE)) << " $";
			break;
		case 8:
			cout << "students sorted by name: ";
			sort(nameArr, nameArr + n);
			for (int x = 0; x < n; x++)
			{
				cout << nameArr[x] << ",";
			}
			cout << endl;
			break;
		case 9:
			cout << "students sorted by GPA: ";
			stable_sort(avgArr, avgArr + n);
			for (int x = 0; x < n; x++)
			{
				cout << avgArr[x] << ",";
			}
			cout << endl;
			break;
		case 10:
			cout << "students sorted by id number: ";
			sort(idArr, idArr + n);
			for (int x = 0; x < n; x++)
			{
				cout << idArr[x] << ",";
			}
			cout << endl;
			break;
		case 11:
			cout << "students sorted by tuition fee: ";
			sort(feeArr, feeArr + n);
			for (int x = 0; x < n; x++)
			{
				cout << feeArr[x] << ",";
			}
			cout << endl;
			break;
		case 12:
			cout << "colleagues sorted by salary: ";
			sort(C_feeArr, C_feeArr + m);
			for (int x = 0; x < m; x++)
			{
				cout << C_feeArr[x] << ",";
			}
			cout << endl;
			break;
		case 13:
			cout << "workers sorted by salary: ";
			sort(W_feeArr, W_feeArr + l);
			for (int x = 0; x < l; x++)
			{
				cout << W_feeArr[x] << ",";
			}
			cout << endl;
			break;
		case 14:
			return 0;
			break;
		}
	} while (ch != 10);
	return 0;
}


void get_data(int i)      //student get data
{
	cout << "Enter student id number : ";
	cin >> st[i].st_id;
	cout << "Enter student name: ";
	cin >> st[i].st_name;
	cout << "Enter student's physics mark: ";
	cin >> st[i].physics;
	cout << "Enter student's math mark: ";
	cin >> st[i].math;
	cout << "Enter student's computer mark: ";
	cin >> st[i].computer;
	cout << "Enter student's chemistry mark: ";
	cin >> st[i].chemistry;
	cout << "Enter how many units does the student have: ";
	cin >> st[i].units;
	st[i].st_fee = (32000 + (st[i].units * 500));
	st[i].avg = (st[i].physics + st[i].math + st[i].computer + st[i].chemistry) / 4.00;
	nameArr[i] = st[i].st_name;
	idArr[i] = st[i].st_id;
	feeArr[i] = st[i].st_fee;
	avgArr[i] = st[i].avg;
}

void C_get_data(int j)      //colleague get data
{
	cout << "Enter colleague id number : ";
	cin >> c[j].c_id;
	cout << "Enter colleague name: ";
	cin >> c[j].c_name;
	cout << "Enter how many units does the colleague is teaching: ";
	cin >> c[j].c_units;
	c[j].c_salaryfee = (4000 + (c[j].c_units * 200));
	C_feeArr[j] = c[j].c_salaryfee;
}

void W_get_data(int k)      //worker get data
{
	cout << "Enter worker id number : ";
	cin >> w[k].w_id;
	cout << "Enter worker name: ";
	cin >> w[k].w_name;
	cout << "Enter how many hours does the worker is working: ";
	cin >> w[k].w_hours;
	w[k].w_salaryfee = (2000 + (w[k].w_hours * 50));
	W_feeArr[k] = w[k].w_salaryfee;
}

void show_data(int searchkey)      //show student data
{
	int i = searchkey;
	cout << "id number: " << st[i].st_id << endl;
	cout << "student name: " << st[i].st_name << endl;
	cout << "physics mark: " << st[i].physics << endl;
	cout << "math mark: " << st[i].math << endl;
	cout << "computer mark: " << st[i].computer << endl;
	cout << "chemistry mark: " << st[i].chemistry << endl;
	cout << "student average: " << st[i].avg << endl;
	cout << "student fee: " << st[i].st_fee << " $" << endl;
}

void C_show_data(int C_searchkey)      //show colleague data
{
	int j = C_searchkey;
	cout << "id number: " << c[j].c_id << endl;
	cout << "colleague name: " << c[j].c_name << endl;
	cout << "colleague salary: " << c[j].c_salaryfee << " $";
	cout << endl;
}

void W_show_data(int W_searchkey)      //show worker data
{
	int k = W_searchkey;
	cout << "id number: " << w[k].w_id << endl;
	cout << "worker name: " << w[k].w_name << endl;
	cout << "worker salary: " << w[k].w_salaryfee << " $";
	cout << endl;
}

void search_student(int searchkey)  //search student with id num
{
	for (int i = 0;i <= n;i++)
	{
		if (st[i].st_id == searchkey)
		{
			cout << "----------------------------------------" << endl;
			show_data(i);
			cout << "----------------------------------------" << endl;
		}
	}
}

void search_colleague(int C_searchkey)  //search colleague with id num
{
	for (int j = 0;j <= m;j++)
	{
		if (c[j].c_id == C_searchkey)
		{
			cout << "----------------------------------------" << endl;
			C_show_data(j);
			cout << "----------------------------------------" << endl;
		}
	}
}

void search_worker(int W_searchkey)  //search worker with id num
{
	for (int k = 0;k <= l;k++)
	{
		if (w[k].w_id == W_searchkey)
		{
			cout << "----------------------------------------" << endl;
			W_show_data(k);
			cout << "----------------------------------------" << endl;
		}
	}
}

int add_student()
{
	cout << "Enter The Total Number of Students: ";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		get_data(i);
		FEE = FEE + st[i].st_fee;
	}
	return FEE;
	system("CLS");
	cout << endl;
	system("pause");
	main();          //Return to menu
}

int add_colleague()
{
	cout << "Enter The Total Number of colleagues: ";
	cin >> m;
	for (int j = 0;j < m;j++)
	{
		C_get_data(j);
		colleagueFEE = colleagueFEE + c[j].c_salaryfee;
	}
	return colleagueFEE;
	system("CLS");
	cout << endl;
	system("pause");
	main();          //Return to menu
}

int add_worker()
{
	cout << "Enter The Total Number of workers: ";
	cin >> l;
	for (int k = 0;k < l;k++)
	{
		W_get_data(k);
		workerFEE = workerFEE + w[k].w_salaryfee;
	}
	return workerFEE;
	system("CLS");
	cout << endl;
	system("pause");
	main();          //Return to menu
}