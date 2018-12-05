#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void ChangeCapital(string& a, string& b, map<string, string>& cc) 
{ //��������� ������� � ������
	if (cc[a] == "") 
	{ //���� ������ ��� ���...
		cc[a] = b; //������� ������ � ������� ������, ������� ��������������
		cout << "Introduce new country " << a << " with capital " << b << endl; //������� ��������������� ���������
	}
	else if (b == cc[a]) { //���� ������ ���� � ����� �� ��������...
		cout << "Country " << a << " hasn't changed its capital" << endl; //������� ��� �� ����� ��������
	}
	else { //����� 
		cout << "Country " << a << " has changed its capital from " << cc[a] << " to " << b << endl; // ������� ��� �� �������� ������� �� �����
		cc[a] = b; //� �������� ������ ������� �� �����
	}
}

void Rename(string& a, string& b, map<string, string>& cc)
{ //����������� ������
	map<string, string> ccCopy = cc; //�� ���� �������������� � ������ �����
	if (a == b || "" == ccCopy[a] || "" != ccCopy[b]) 
	{ //���� �������� ����� ��� ������ ������ ��� ��� ��� ����� ��� ����,
		cout << "Incorrect rename, skip" << endl; // �� �����, ��� ��� �����
	}
	else if ("" != cc[a]) { //�����, ���� ������ ������ ����, ��
		cout << "Country " << a << " with capital " << cc[a] << " has been renamed to " << b << endl; //����� ��� ������������� ������
		auto i = cc[a]; //�������� �������� ������� � ������
		cc.erase(a); //����� ������ ������ �� ������ �������
		cc[b] = i; //������ ����� ������ �� ������ ��������
	}
}

void About(const string& a, const map<string, string>& cc) { //������ ���� � ������
	map<string, string> ccCopy = cc; // ������� �������� 
	if ("" != ccCopy[a]) { //���� � ������ ���-�� ����, �� 
		cout << "Country " << a << " has capital " << ccCopy[a] << endl; //������� ��� ����
	}
	else
	{ //�����
		cout << "Country " << a << " doesn't exist" << endl; //������� ��� ��� ������ ���, � ������ ���� )))
	}
}
void Dump(const map<string, string>& cc) { //��� ������ ������� �� ��� ����
	if (cc.size() == 0) 
	{ //���� ������ ����� 0, �� 
		cout << "There are no countries in the world" << endl; //�������, ��� ������ ���
	}
	else { //�����
		for (const auto& i : cc) { //��������� ��� ���� � ������
			cout << i.first << "/" << i.second << " "; //� ������� ������ � �����
		}
		cout << endl;
	}
}

int main() 
{
	setlocale(0, "Russian");
	int i;
	cin >> i; //��������� ������� ����� ���� �������
	string command; // ��� ������ ��������
	map<string, string> cc;
	for (i; i > 0; i--)
	{ // ����� ����� ����� �������, ������� ��� � ��������� ����
		cin >> command; //��������� �������
		if (command == "CHANGE_CAPITAL")
		{ //������ ��������� ����� ������� �������� �  
			string country, new_capital;
			cin >> country >> new_capital; //���� ����, ��������� �������������� ��������
			ChangeCapital(country, new_capital, cc); //��������� ��������������� �������
		}
		else if (command == "RENAME")
		{ 
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			Rename(old_country_name, new_country_name, cc);
		}
		else if (command == "ABOUT")
		{
			string country;
			cin >> country;
			About(country, cc);
		}
		else if (command == "DUMP")
		{
			Dump(cc);
		}
	}
	system("pause");
	//return 0;
}