#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void ChangeCapital(string& a, string& b, map<string, string>& cc) 
{ //добавляем столицу в страну
	if (cc[a] == "") 
	{ //если страны еще нет...
		cc[a] = b; //добавим страну и столицу заодно, простой инициализацией
		cout << "Introduce new country " << a << " with capital " << b << endl; //выведем соответствующее сообщение
	}
	else if (b == cc[a]) { //если страна есть с такой же сталицей...
		cout << "Country " << a << " hasn't changed its capital" << endl; //напишем что не можем добавить
	}
	else { //иначе 
		cout << "Country " << a << " has changed its capital from " << cc[a] << " to " << b << endl; // напишем что мы поменяли столицу на новую
		cc[a] = b; //и поменяем старую столицу на новую
	}
}

void Rename(string& a, string& b, map<string, string>& cc)
{ //переименуем страну
	map<string, string> ccCopy = cc; //не стал заморачиваться и создал копию
	if (a == b || "" == ccCopy[a] || "" != ccCopy[b]) 
	{ //если названия равны или старой страны еще нет или новая уже есть,
		cout << "Incorrect rename, skip" << endl; // то пишем, что все плохо
	}
	else if ("" != cc[a]) { //иначе, если старая страна есть, то
		cout << "Country " << a << " with capital " << cc[a] << " has been renamed to " << b << endl; //пишем что переименовали страну
		auto i = cc[a]; //скопирую название столицы в стране
		cc.erase(a); //сотру старую страну из памяти горожан
		cc[b] = i; //создам новую страну со старой столицей
	}
}

void About(const string& a, const map<string, string>& cc) { //выведу инфу о стране
	map<string, string> ccCopy = cc; // сначала скопирую 
	if ("" != ccCopy[a]) { //если в стране что-то есть, то 
		cout << "Country " << a << " has capital " << ccCopy[a] << endl; //выведем что есть
	}
	else
	{ //иначе
		cout << "Country " << a << " doesn't exist" << endl; //напишем что там ничего нет, и страны тоже )))
	}
}
void Dump(const map<string, string>& cc) { //тут просто выводим всё что есть
	if (cc.size() == 0) 
	{ //если размер равен 0, то 
		cout << "There are no countries in the world" << endl; //напишем, что ничего нет
	}
	else { //иначе
		for (const auto& i : cc) { //переберем все пары в списке
			cout << i.first << "/" << i.second << " "; //и напишем страну и город
		}
		cout << endl;
	}
}

int main() 
{
	setlocale(0, "Russian");
	int i;
	cin >> i; //прочитаем сколько строк надо вводить
	string command; // это начало комманды
	map<string, string> cc;
	for (i; i > 0; i--)
	{ // какую цифру ввели вначале, столько раз и повторяем цикл
		cin >> command; //считываем команду
		if (command == "CHANGE_CAPITAL")
		{ //дальше проверяем какая команда написана и  
			string country, new_capital;
			cin >> country >> new_capital; //если надо, считываем дополнительные значения
			ChangeCapital(country, new_capital, cc); //выполняем соответствующую функцию
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