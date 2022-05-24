
#include <iostream>
#include <Windows.h>

using namespace std;


int Individual_task(int day, int month, int year, int day2, int month2, int year2) {
	int summa = 0;
	summa += abs(day - day2);	

	

	if (year > year2) {
		while (year > year2) {
			year2++;
			if (year2 % 4 == 0)
				summa += 366;
			else
				summa += 365;
		}
	}
	else if (year < year2) {
		while (year < year2) {
			year++;
			if (year % 4 == 0)
				summa += 366;
			else
				summa += 365;
		}
	}

	if (month > month2) {
		while (month > month2) {
			switch (month2) {
			case 1:
			case 3:
			case 7:
			case 8:
			case 12:
			case 10:
			case 5:
				summa += (31 - day) + (day - 1);
				break;
			case 4:
			case 6:
			case 11:
			case 9:
				summa += (30 - day) + (day - 1);
				break;
			default:
				break;
			}
			if (month2 == 2 && year2 % 4 == 0)
				summa += (29 - day) + (day - 1);
			else if (month2 == 2 && year2 % 4 != 0)
				summa += (28 - day) + (day - 1);
			month2++;
		}
	}
	else if (month < month2) {
		while (month < month2) {
			switch (month) {
			case 1:
			case 3:
			case 7:
			case 8:
			case 12:
			case 10:
			case 5:
				summa += (31 - day2) + (day2 - 1);
				break;
			case 4:
			case 6:
			case 11:
			case 9:
				summa += (30 - day2) + (day2 - 1);
				break;
			default:
				break;
			}
			if (month == 2 && year2 % 4 == 0)
				summa += (29 - day2) + (day2 - 1);
			else if (month == 2 && year2 % 4 != 0)
				summa += (28 - day2) + (day2 - 1);
			month++;
		}
	}

	return summa;
}

int main()
{
	int day1, day2, month1, month2, year1, year2;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введите первую дату:\n ";
	cout << "День - "; cin >> day1;
	cout << "Месяц - "; cin >> month1;
	cout << "Год - "; cin >> year1;
	cout << "Введите вторую дату:\n ";
	cout << "День - "; cin >> day2;
	cout << "Месяц - "; cin >> month2;
	cout << "Год - "; cin >> year2;


	cout << "Разница в днях: " << Individual_task(day1, month1, year1, day2, month2, year2);




}