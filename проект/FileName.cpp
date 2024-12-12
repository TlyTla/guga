#include <iostream>
#include <Windows.h>
#define ����� return 0;
#include<string>
#include<iomanip>
#include<cstdlib>

//���
int userCount = 2;
bool isadmin = false;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passArr = new std::string[userCount]{ "admin", "user" };


//�����
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];

//�����
double cash = 40000;
double cashMoney{};
double webMoney{};

//���
int checkSize = 1;
std::string* nameCheckArr = new std::string[checkSize];
int* countCheckArr = new int[checkSize];
double* priceCheckArr = new double[checkSize];
double* totalPriceCheckArr = new double[checkSize];


void Start();
bool password();
bool IsNumber(std::string string);
void CreateStaticStorage();
void ShowAdminMenu();
void ShowUserMenu();
void ShowStorage(int mode = 0);
int Getid(int mode = 0);
void RefillProduct();
void RemoveProduct();
void ChangePrice();
void ChangeStorage();
void Getline(std::string& stringName);

void AddNewProduct();
void EditProduct();
void DeleteProduct();

void ChangeEmployee();
void AddNewEmployee();
void EditEmployee();
void DeleteEmployee();

void Selling();
void AddNewCheckSize();
void PrintCheck(double &totalSum);

void Income();

bool CloseShift();



//���� ������� ������
template<typename Arr>
void FillStorege(Arr staticArr[], Arr dynamicArr[], int staticSize);



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();
	delete[]loginArr;
	delete[]passArr;
	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;
	delete[]totalPriceCheckArr;
	delete[]countCheckArr;
	delete[]countCheckArr;
	delete[]priceCheckArr;

	�����;
}

void Start()
{
	
	std::cout << "\t\tPoint\n\n";


	if (password() == true)
	{
		if (isadmin == true)
		{
			std::string choose;
			while (true)
			{
				std::cout << "1 - ������������ ������� �����\n2 - ������� �����\n����: ";
				Getline(choose);
				if (choose == "1")
				{
					CreateStaticStorage();
					break;
				}
				else if (choose == "2")
				{
					//������������ �����
					break;
				}
				else
				{
					std::cout << "\n\n������ �����\n\n";
				}
			}
			//�������� ���������� ����
			ShowAdminMenu();
		}
		else
		{
			CreateStaticStorage();
			ShowUserMenu();

		}
	}
	else
	{
		std::cerr << "LoginErr\n";
	}
}

bool password()
{
	std::string login, parol;

	while (true)
	{
		std::cout << "������� �����: ";
		std::getline(std::cin, login, '\n');

		std::cout << "������� ������: ";
		std::getline(std::cin, parol, '\n');

		if (login == loginArr[0] && parol == passArr[0])
		{
			std::cout << "����������� ������������: " << loginArr[0] << "\n\n";
			isadmin = true;
			return true;
		}

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[i] && parol == passArr[i])
			{
				std::cout << "����������� ������������: " << loginArr[i] << "\n\n";
				isadmin = true;
				return true;
			}
		}
	}

	system("cls");
	std::cout << "�������� ����� ��� ������.\n\n";
}

bool IsNumber(std::string string)
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
	}
	return true;
}

void CreateStaticStorage()
{
	const int tempSize = 10;
	int tempid[tempSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string tempName[tempSize]
	{
		"Nike Air force 1",
		"Dunk sb",
		"Nike Air Jordan 1",
		"Nike Air Jordan 3",
		"Nike Air Jordan 4",
		"Nike Air Jordan 5",
		"Asics Gel",
		"Adidas campus",
		"Nike Air Max 97",
		"Nike Air Max 90"
	};
	int tempCount[tempSize]{ 10,8,30,2,23,7,4,15,13,8 };
	double tempPrice[tempSize]{ 10000.0, 13000.0, 15000.0, 14000.0, 20000.0, 25000.0, 8000.0, 9000.0, 19000.0, 11000.0 };
	FillStorege(tempid, idArr, tempSize);
	FillStorege(tempName, nameArr, tempSize);
	FillStorege(tempCount, countArr, tempSize);
	FillStorege(tempPrice, priceArr, tempSize);
}

template<typename Arr>
void FillStorege(Arr staticArr[], Arr dynamicArr[], int staticSize)
{
	for (int i = 0; i < staticSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

void ShowAdminMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������ �������\n";
		std::cout << "2 - �������� �����\n";
		std::cout << "3 - ��������� �����\n";
		std::cout << "4 - ������� �� ������\n";
		std::cout << "5 - �������� ����\n";
		std::cout << "6 - ��������� ������\n";
		std::cout << "7 - ��������� �����������\n";
		std::cout << "8 - ����� � �������\n";
		std::cout << "0 - ������� �����\n\n";
		std::cout << "����: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "1")
		{
			Selling();
		}
		else if (choose == "2")
		{
			ShowStorage();
			system("pause");
		}
		else if (choose == "3")
		{
			RefillProduct();
		}
		else if (choose == "4")
		{
			RemoveProduct();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeEmployee();
		}
		else if (choose == "8")
		{
			Income();
		}
		else if (choose == "0")
		{
			if (CloseShift())
			{
				break;
			}
		}
		else
		{
			std::cout << "\n������\n";
			Sleep(100);
		}
	}
}

void ShowUserMenu()
{
	std::string choose;

	while (true)
	{
		system("cls");
		std::cout << "1 - ������ �������\n";
		std::cout << "2 - �������� �����\n";
		std::cout << "3 - ��������� �����\n";
		std::cout << "4 - ������� �� ������\n";
		std::cout << "5 - ����� � �������\n";
		std::cout << "0 - ������� �����\n\n";
		std::cout << "����: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "1")
		{
			Selling();
		}
		else if (choose == "2")
		{
			ShowStorage();
			system("pause");
		}
		else if (choose == "3")
		{
			RefillProduct();
		}
		else if (choose == "4")
		{
			RemoveProduct();
		}
		else if (choose == "5")
		{
			Income();
		}
		else if (choose == "0")
		{
			if (CloseShift())
			{
				break;
			}
		}
		else
		{
			std::cout << "\n������\n";
			Sleep(100);
		}
	}
}

void ShowStorage(int mode)
{
	system("cls");
	if (mode == 0)
	{
		std::cout << "ID\t" << "��������\t\t\t" << "���-��\t" << "����\n";

		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
		}
		system("pause");
	}
	else if (mode == 1)//����� ��� ����
	{
		std::cout << "ID\t" << "��������\t\t\t" << "���-��\n";

		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\n";
		}
	}
	else if (mode == 2)//����� ��� ���-�� 
	{
		std::cout << "ID\t" << "��������\t\t\t" << "����\n";

		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << priceArr[i] << "\n";
		}
	}
	else if (mode == 3)//����� ��������
	{
		std::cout << "ID\t" << "��������\n";

		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\n";
		}
	}
	else
	{
		std::cerr << "\nMenuModeError\n";
	}
}

int Getid(int mode)
{
	std::string stringID;
	int result{};
	int currentSize = 0;
	if (mode == 1)
	{
		currentSize = userCount;
	}
	else if (mode == 0)
	{
		currentSize = size;
	}

	while (true)
	{
		std::cout << "������� ID: ";
		Getline(stringID);
		if (IsNumber(stringID))
		{
			result = std::stoi(stringID);
			if (result > 0 && result <= currentSize)
			{
				return result;
			}
			else
			{
				std::cout << "\n������������ ID\n";
			}
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}

void RefillProduct()
{
	std::string choose, chooseCount;
	int id = 0, count;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n������: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = Getid();
			while (true)
			{
				std::cout << "������� ���-�� ������ ��� ����������: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count >= 0 && count <= 1000)
					{
						countArr[id - 1] += count;
						std::cout << "\n\n����� ������� ��������\n\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}

void RemoveProduct()
{
	std::string choose, chooseCount;
	int id = 0, count;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n������: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = Getid();
			while (true)
			{
				std::cout << "������� ���-�� ������ ��� ��������: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count >= 0 && count <= countArr[id - 1])
					{
						countArr[id - 1] -= count;
						std::cout << "\n\n����� ������� ��������\n\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}

}

void ChangePrice()
{
	std::string choose, choosePrice;
	int id = 0;
	double price{};
	while (true)
	{
		system("cls");
		std::cout << "��������� ����\n\n";
		std::cout << "1 - ������\n0 - ������\n\n������: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = Getid();
			while (true)
			{
				std::cout << "������� ����� ����: ";
				Getline(choosePrice);
				if (IsNumber(choosePrice))
				{
					price = std::stod(choosePrice);
					if (price >= 0 && price <= 1000000.0)
					{
						priceArr[id - 1] = price;
						std::cout << "\n\n����� ������� ��������\n\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}

}

void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "��������� ������\n\n";
		std::cout << "1 - ���������� ������ ������\n2 - �������������� ���������\n3 - �������� ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			AddNewProduct();
		}
		else if (choose == "2")
		{
			EditProduct();
		}
		else if (choose == "3")
		{
			DeleteProduct();
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}

void Getline(std::string& stringName)
{
	std::getline(std::cin, stringName, '\n');
}

void AddNewProduct()
{
	std::string choose, nameStr, priceStr, countStr;
	while (true)
	{
		system("cls");
		std::cout << "���������� ������ ������\n\n";
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);

		if (choose == "1")
		{
			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[]idArr;
			delete[]nameArr;
			delete[]countArr;
			delete[]priceArr;

			size++;

			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];

			for (int i = 0; i < size - 1; i++)
			{
				idArr[i] = tempId[i];
				countArr[i] = tempCount[i];
				priceArr[i] = tempPrice[i];
				nameArr[i] = tempName[i];
			}

			while (true)
			{
				std::cout << "������� �������� ������ ������:";
				Getline(nameStr);
				if (nameStr.size() <= 60 && nameStr.size() > 1)
				{
					nameArr[size - 1] = nameStr;
					break;
				}
				std::cout << "\n������ �����. �� 2 �� 60 ��������\n";
			}

			while (true)
			{
				std::cout << "������� ���-�� ������ ������:";
				Getline(countStr);
				if (IsNumber(countStr))
				{
					if (std::stoi(countStr) >= 0 && std::stoi(countStr) <= 1000)
					{
						countArr[size - 1] = std::stoi(countStr);
						break;
					}
					else
					{
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}

			while (true)
			{
				std::cout << "������� ���� ������ ������:";
				Getline(priceStr);
				if (IsNumber(priceStr))
				{
					if (std::stod(priceStr) >= 0 && std::stod(priceStr) <= 1000000.0)
					{
						priceArr[size - 1] = std::stod(priceStr);
						break;
					}
					else
					{
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}

			idArr[size - 1] = size;

			std::cout << idArr[size - 1] << "\t" << std::left << std::setw(30) << nameArr[size - 1]
				<< "\t" << countArr[size - 1] << "\t" << priceArr[size - 1] << "\n\n";
			std::cout << "����� ����� ������� ��������\n";

			delete[]tempId;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;

			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}


void DeleteProduct()
{
	std::string choose;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "�������� ������\n\n";
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);

		if (choose == "1")
		{
			ShowStorage(3);
			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[]idArr;
			delete[]nameArr;
			delete[]countArr;
			delete[]priceArr;

			size--;

			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];

			id = Getid();

			for (int i = 0, j = 0; i < size, j < size + 1; i++, j++)
			{
				if (j == id - 1)
				{
					if (id == size + 1)
					{
						break;
					}
					j++;
					idArr[i] = tempId[i];
					countArr[i] = tempCount[j];
					priceArr[i] = tempPrice[j];
					nameArr[i] = tempName[j];
				}
				else
				{
					idArr[i] = tempId[i];
					countArr[i] = tempCount[j];
					priceArr[i] = tempPrice[j];
					nameArr[i] = tempName[j];
				}

			}
			std::cout << "����� ������� ������\n";

			delete[]tempId;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;

			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(800);
		}
	}
}

void ChangeEmployee()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "��������� �����������\n\n";
		std::cout << "1 - ���������� ������ ����������\n2 - �������������� ������, ������\n3 - �������� ����������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			AddNewEmployee();
		}
		else if (choose == "2")
		{
			EditEmployee();
		}
		else if (choose == "3")
		{
			if (userCount > 1)
			{
				DeleteEmployee();
			}
			else
			{
				std::cout << "��� ������������ ��� ��������\n";
				Sleep(500);
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(800);
		}
	}
}

void AddNewEmployee()
{
	std::string choose, newLogin, newPass;
	int  id = 0;

	while (true)
	{
		system("cls");
		std::cout << "���������� ������ ����������\n\n";
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);

		if (choose == "1")
		{
			std::string* tempLogin = new std::string[userCount];
			std::string* tempPass = new std::string[userCount];


			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passArr[i];
			}

			delete[]loginArr;
			delete[]passArr;


			userCount++;

			loginArr = new std::string[userCount];
			passArr = new std::string[userCount];

			for (int i = 0; i < userCount - 1; i++)
			{
				loginArr[i] = tempLogin[i];
				passArr[i] = tempPass[i];
			}

			while (true)
			{
				std::cout << "������� ����� ������ ������������:";
				Getline(newLogin);
				if (newLogin.size() <= 15 && newLogin.size() >= 4)
				{
					loginArr[userCount - 1] = newLogin;
					break;
				}
				std::cout << "\n������ �����. �� 4 �� 15 ��������\n";
			}

			while (true)
			{
				std::cout << "������� ������ ������ ������������:";
				Getline(newPass);
				if (newPass.size() <= 15 && newPass.size() >= 4)
				{
					passArr[userCount - 1] = newPass;
					break;
				}
				std::cout << "\n������ �����. �� 4 �� 15 ��������\n";
			}
			std::cout << "����� ������������ ������� ��������\n";

			delete[]tempPass;
			delete[]tempLogin;
			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}

void EditProduct()
{
	std::string choose, newName;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "�������������� ������\n\n";
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(3);
			id = Getid();
			while (true)
			{
				std::cout << "������� ����� �������� ������";
				Getline(newName);
				if (newName.size() <= 60 && newName.size() > 1)
				{
					nameArr[id - 1] = newName;
					break;
				}
				std::cout << "\n������ �����. �� 2 �� 60 ��������\n";
			}
			std::cout << "�������� ��������\n";
			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(800);
		}
	}
}


void EditEmployee()
{
	std::string choose, currentPass, newPass;
	int id = 0;
	while (true)
	{
		system("cls");
		std::cout << "�������������� ������� ����������\n\n";
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			id = Getid(1);
			while (true)
			{
				std::cout << "������� ������� ������ �������=������: " << loginArr[id - 1] << "\n0 - �����\n�����: ";
				Getline(currentPass);
				if (currentPass == passArr[id - 1])
				{
					while (true)
					{
						std::cout << "������� ����� ������ ������������:" << loginArr[id - 1] << ": ";
						Getline(newPass);
						if (newPass.size() <= 15 && newPass.size() >= 4)
						{
							passArr[id - 1] = newPass;
							std::cout << "������� ������� �������\n";
							break;
						}
						std::cout << "\n������ �����. �� 4 �� 15 ��������\n";
					}
				}
				else if (currentPass == "0")
				{
					break;
				}
				else
				{
					std::cout << "\n�������� ������\n";
				}
			}
		}
		else if (choose == "0")
		{

		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}

void DeleteEmployee()
{
	std::string choose;
	int id{};
	while (true)
	{
		system("cls");
		std::cout << "�������� ����������\n\n";
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (userCount <= 1)
		{
			std::cout << "������������� ������ ���\n";
			Sleep(1000);
			break;
		}

		if (choose == "1")
		{
			for (int i = 1; i < userCount; i++)
			{
				std::cout << i << " " << loginArr[i] << "\n";
			}
			std::cout << "\n";

			std::string* tempLogin = new std::string[userCount];
			std::string* tempPass = new std::string[userCount];


			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passArr[i];
			}

			delete[]loginArr;
			delete[]passArr;

			userCount--;

			loginArr = new std::string[userCount];
			passArr = new std::string[userCount];

			id = Getid(1);

			loginArr[0] = tempLogin[0];
			passArr[0] = tempPass[0];



			for (int i = 1, j = 1; i < userCount, j < userCount + 1; i++, j++)
			{
				if (j == id)
				{
					if (id == userCount)
					{
						break;
					}
					j++;
					loginArr[i] = tempLogin[j];
					passArr[i] = tempPass[j];
				}
				else
				{
					loginArr[i] = tempLogin[j];
					passArr[i] = tempPass[j];
				}

			}
			std::cout << "������������ ������� ������\n";

			delete[]tempLogin;
			delete[]tempPass;

			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(800);
		}
	}
}

void Selling()
{
	std::string choose, chooseID, chooseCount, choosePay, money;
	bool isFirst = true; 
	int id{}, count{};
	double totalSum{};
	
	while (true)
	{
		system("cls");
		std::cout << "1 - ������ ����� �������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			totalSum = 0;
			isFirst = true;

			delete[]totalPriceCheckArr;
			delete[]nameCheckArr;
			delete[]countCheckArr;
			delete[]priceCheckArr;
		
			checkSize = 1;

			totalPriceCheckArr = new double[size];
			countCheckArr = new int[size];
			priceCheckArr = new double[size];
			nameCheckArr = new std::string[size];

			while (true)
			{
				system("cls");
				ShowStorage();
				std::cout << "������� ID ������ ���\"exit\" ��� ���������� �������\n\n����: ";
				Getline(chooseID);
				if (chooseID == "exit")
				{
					break;
				}
				else if (IsNumber(chooseID))
				{
					id = std::stoi(chooseID);
					if (id > 0 && id <= size)
					{
						std::cout << "������� ���-�� " << nameArr[id - 1] << " ��� �������: ";
						Getline(chooseCount);
						if (IsNumber(chooseCount))
						{
							count = std::stoi(chooseCount);
							if (count >= 0 && count <= countArr[id - 1])
							{
								if (isFirst)
								{
									nameCheckArr[checkSize - 1] = nameArr[id - 1];
									countCheckArr[checkSize - 1] = count;
									priceCheckArr[checkSize - 1] = priceArr[id - 1];
									totalPriceCheckArr[checkSize - 1] = count * priceArr[id - 1];
									isFirst = false;
									//�������� �� ������
									countArr[id - 1] -= count;
									totalSum += count * priceArr[id - 1];
								}
								else
								{
									AddNewCheckSize();
									nameCheckArr[checkSize - 1] = nameArr[id - 1];
									countCheckArr[checkSize - 1] = count;
									priceCheckArr[checkSize - 1] = priceArr[id - 1];
									totalPriceCheckArr[checkSize - 1] = count * priceArr[id - 1];
									countArr[id - 1] -= count;
									totalSum += count * priceArr[id - 1];
								}
								Sleep(600);
							}
							else
							{
								std::cout << "\n������ ���-��\n";
								Sleep(1000);
							}
						}
						else
						{
							std::cout << "\n������ �����\n";
							Sleep(1000);
						}
					}
					else
					{
						std::cout << "\n������ ID\n";
						Sleep(1000);
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
					Sleep(1000);
				}
			}
			if (!isFirst)
			{
				//����� ����
				PrintCheck(totalSum);

				while (true)
				{
					std::cout << "�������� ������ ������\n1 - ��������\n2 - �����������\n����: ";
					Getline(choosePay);
					if (choosePay == "1")
					{
						std::cout << "������� ���-�� ��������: ";
						Getline(money);
						if (IsNumber(money))
						{
							if (std::stod(money) >= totalSum || std::stod(money) - totalSum <= cash)
							{
								std::cout << "\n������ ������ �������\n";
								std::cout << "���� �����: " << std::stod(money) - totalSum << "\n";
								cash -= std::stod(money) - totalSum;
								cash += std::stod(money);
								cashMoney += std::stod(money);
								Sleep(1500);
								break;
							}
							else if(std::stod(money) < totalSum)
							{
								std::cout <<"\n������������ �������\n";
								Sleep(1000);
							}
							else
							{
								std::cout << "\n� ����� ������������ ������� ��� �����\n";
								Sleep(1000);
							}
						}
						else
						{
							std::cout << "\n������ �����\n";
							Sleep(1000);
						}
					}
					else if (choosePay == "2")
					{
						system("cls");
						std::cout << "��������� �����\n";
						std::cout << "���������� � ������\n";
						for (int i = 0; i < rand() % 5 + 3; i++)
						{
							std::cout << ". "; 
							Sleep(750);
						}
						std::cout << "\n���������� �������\n";
						std::cout << "\n������ ������ �������\n";
						webMoney += totalSum;
						Sleep(1500);
						break;
					}
					else
					{
						std::cout << "\n������ �����\n";
						Sleep(1000);
					}
				}

			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ �����\n";
			Sleep(1000);
		}
	}
}

void AddNewCheckSize()
{
	std::string choose;
	int* tempCount = new int[checkSize];
	double* tempTotalPrice = new double[checkSize];
	double* tempPrice = new double[checkSize];
	std::string* tempName = new std::string[checkSize];

	for (int i = 0; i < checkSize; i++)
	{
		tempTotalPrice[i] = totalPriceCheckArr[i];
		tempCount[i] = countCheckArr[i];
		tempPrice[i] = priceCheckArr[i];
		tempName[i] = nameCheckArr[i];
	}

	delete[]totalPriceCheckArr;
	delete[]nameCheckArr;
	delete[]countCheckArr;
	delete[]priceCheckArr;

	checkSize++;

	totalPriceCheckArr = new double[checkSize];
	countCheckArr = new int[checkSize];
	priceCheckArr = new double[checkSize];
	nameCheckArr = new std::string[checkSize];

	for (int i = 0; i < checkSize - 1; i++)
	{
		totalPriceCheckArr[i] = tempTotalPrice[i];
		countCheckArr[i] = tempCount[i];
		priceCheckArr[i] = tempPrice[i];
		nameCheckArr[i] = tempName[i];
	}

	delete[]tempTotalPrice;
	delete[]tempCount;
	delete[]tempPrice;
	delete[]tempName;
}

void PrintCheck(double &totalSum)
{	
	std::cout << "N\t" << std::left << std::setw(30) << "��������" << "\t���� �� ��\t��� - ��\t�����\n";
	for (int i = 0; i < checkSize; i++)
	{
		std::cout << "N" << i + 1 << " \t" << std::left << std::setw(30) << nameCheckArr[i]
			<< "\t" << priceCheckArr[i] << "\t\t*  " << countCheckArr[i]
			<< "\t\t" << totalPriceCheckArr[i] << "\n";
	}
	std::cout << "\n�������� �����: " << totalSum << "\n\n";
}

void Income()
{
	std::cout << "������ � �����: " << cash << "\n";
	std::cout << "������ �� �������� �����: " << cashMoney << "\n";
	std::cout << "������ �� ����������� �����: " << webMoney << "\n";
	std::cout << "�������� �������: " << cashMoney + webMoney << "\n\n";
	system("pause");
}

bool CloseShift()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������� �����\n0 - ������\n\n������: ";
		Getline(choose);
		if (choose == "1")
		{
			Income();
			std::cout << "\n����� �������.";
			system("pause");
			return true;
		}
		else if (true)
		{
			return false;
		}
		else
		{
			std::cout << "\n������ �����\n";
		}
	}
}
