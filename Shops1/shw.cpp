#include <cstdlib>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <Windows.h>

//логин
int userCount = 2;
bool isAdmin = false;
std::string* loginArr = new std::string[userCount]{ "admin","user" };
std::string* passArr = new std::string[userCount]{ "admin","user" };

//склад
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];

//деньги
double cash = 10000;
double cashMoney{};
double webMoney{};

//чеки
int checkSize = 1;
std::string* nameCheckArr = new std::string[checkSize];
int* countCheckArr = new int[checkSize];
double* priceCheckArr = new double[checkSize];
double* totalPriceCheckArr = new double[checkSize];


//функции
void Start();
bool Login();
bool IsNumber(std::string string);
void CreateStaticStorage();
void CreateDynamicStorage();
void ShowAdminMenu();
void ShowUserMenu();
void ShowStorage(int mode = 0);
void RefillProducts();
void RemoveProducts();
void ChangeStorage();
void ChangeEmployee();
void ChangePrice();
int GetID(int mode = 0);

void AddNewProduct();
void EditProduct();
void DeleteProduct();

void AddNewEmployee();
void EditEmployee();
void DeleteEmployee();

void Selling();
void AddNewCheckSize();
void Discounts(double totalSum, double priceCheckArr[], int count, int checkSize);
void PrintCheck(double& totalSum, double& Sum);
void Income();
bool CloseShift();


void Getline(std::string& stringName);

template <typename Arr>
void FillStorage(Arr staticArr[], Arr dynamicArr[], int staticSize);

//-----MAIN-----
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	std::cout << "\t\tBlinkChains\n\n";
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

	return 0;

}
//-----MAIN-----

//ФУНКЦИИ
void Start() {
	if (Login() == true)
		if (isAdmin == true) {
			std::string choose;
			while (true)
			{
				std::cout << "1 - Использовать готовый склад\n2 - Создать склад\n Ввод: ";
				Getline(choose);
				if (choose == "1") {
					CreateStaticStorage();
					break;
				}
				else if (choose == "2")
				{
					CreateDynamicStorage();
					break;
				}
				else
				{
					std::cout << "\n\nВведите корректно...\n\n";
				}
			}
			ShowAdminMenu();
		}


		else
		{
			CreateStaticStorage();
			ShowUserMenu();
		}
	else
	{
		std::cerr << "Ты как умудрился, лошара?..";
	}
}
bool Login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "Логин: ";
		Getline(login);
		std::cout << "Пароль: ";
		Getline(pass);

		if (login == loginArr[0] && pass == passArr[0]) {
			std::cout << "Авторизация: " << loginArr[0] << "\n\n";
			isAdmin = true;
			return true;
		}

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[0] && pass == passArr[i]) {
				std::cout << "Авторизация: " << loginArr[i] << "\n\n";
				isAdmin = false;
				return true;
			}

		}

		system("cls");
		std::cout << "Неверный логин или пароль\n\n";
	}
}
bool IsNumber(std::string string)
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
		return true;
	}
}
void CreateStaticStorage() {
	const int tempSize = 10;
	int tempId[tempSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string tempName[tempSize]{
	"Дошик с курицей",
	"Дошик с говядиной",
	"Дошик с грибами",
	"Дошик с овощами",
	"Дошик с сыром",
	"Дошик с креветкой",
	"Дошик острый",
	"Дошик восточный",
	"Чан рамен с курицей",
	"Чан рамен с говядиной"
	};
	int tempCount[tempSize]{ 13, 65, 53, 62, 36, 67, 64, 23, 56, 51 };
	double tempPrice[tempSize]{ 34.0, 34.0, 40.0, 35.0, 50.0, 60.0, 55.0, 75.0, 90.0, 90.0 };
	FillStorage(tempId, idArr, tempSize);
	FillStorage(tempName, nameArr, tempSize);
	FillStorage(tempCount, countArr, tempSize);
	FillStorage(tempPrice, priceArr, tempSize);
}

void CreateDynamicStorage()
{
	size = 0;
	AddNewProduct();
}

void ShowStorage(int mode)
{
	system("cls");
	if (mode == 0)
	{
		std::cout << "ID\t" << "Название\t\t\t" << "Количество\t" << "Цена\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
		}
		system("pause");
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << "Название\t\t\t" << "Количество\t" << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << "\n";
		}
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << "Название\t\t\t" << "Цена\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << "\t" << priceArr[i] << "\n";
		}
	}
	else if (mode == 3)
	{
		std::cout << "ID\t" << "Название\t\t\t" << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << "\t" << "\n";
		}
	}
	else
	{
		std::cerr << "\nMenuModeError\n";
	}

}
void RefillProducts()
{
	std::string choose, chooseCount;
	int id = 0, count;

	while (true)
	{
		system("cls");
		std::cout << "Пополнение склада\n\n";
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID(0);
			while (true)
			{
				std::cout << "Количество товара для пополнения: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount)) {
					count = std::stoi(chooseCount);
					if (count > 0 && count <= 1000) {
						countArr[id - 1] += count;
						std::cout << "\n\nТовар успешно пополнен\n\n";
						Sleep(1000);
						break;
					}
					else
					{
						std::cout << "\nНекорректное ID\n";
					}
				}
				else
				{
					std::cout << "Ошибка, дон";
				}
			}

		}
		else if (choose == "0")
		{
			break;
		}


	}
}
void RemoveProducts()
{
	std::string choose, chooseCount;
	int id = 0, count;

	while (true)
	{
		system("cls");
		std::cout << "Списание товара\n\n";
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID(0);
			while (true)
			{
				std::cout << "Количество товара для списания: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount)) {
					count = std::stoi(chooseCount);
					if (count > 0 && count <= countArr[id - 1]) {
						countArr[id - 1] -= count;
						std::cout << "\n\nТовар успешно списан\n\n";
						Sleep(1000);
						break;
					}
					else
					{
						std::cout << "\nНекорректное ID\n";
					}
				}
				else
				{
					std::cout << "Ошибка, дон";
				}
			}

		}
		else if (choose == "0")
		{
			break;
		}


	}
}
void AddNewProduct() {
	std::string choose, nameStr, priceStr, countStr;
	while (true)
	{
		system("cls");
		std::cout << "Добавление товара\n\n";
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			int* tempID = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempID[i] = idArr[i];
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
				idArr[i] = tempID[i];
				countArr[i] = tempCount[i];
				priceArr[i] = tempPrice[i];
				nameArr[i] = tempName[i];
			}

			while (true)
			{
				std::cout << "Введите название нового товара: ";
				Getline(nameStr);
				if (nameStr.size() > 2 && nameStr.size() <= 60)
				{
					nameArr[size - 1] = nameStr;
					break;
				}
				else
				{
					std::cout << "\nОшибка дон! От 3 до 60 символов!\n";
				}
			}

			while (true)
			{
				std::cout << "Количество нового товара: ";
				Getline(countStr);
				if (IsNumber(countStr))
				{
					if (std::stoi(countStr) >= 0 && std::stoi(countStr) <= 1000) {
						countArr[size - 1] = std::stoi(countStr);
						break;
					}
					else {
						std::cout << "\nОшибка ввода\n";
					}
				}
				else
				{
					std::cout << "\nОшибка ввода\n";
				}
			}

			while (true)
			{
				std::cout << "Цена нового товара: ";
				Getline(priceStr);
				if (IsNumber(priceStr))
				{
					if (std::stod(priceStr) >= 0 && std::stod(priceStr) <= 10000.0) {
						priceArr[size - 1] = std::stod(priceStr);
						break;
					}
					else {
						std::cout << "\nОшибка ввода\n";
					}
				}
				else
				{
					std::cout << "\nОшибка ввода\n";
				}
			}

			idArr[size - 1] = size;

			std::cout << idArr[size - 1] << "\t" << std::left << std::setw(30) << nameArr[size - 1] << "\t" << countArr[size - 1] << "\t" << "\t" << priceArr[size - 1] << "\n\n";
			std::cout << "Новый товар успешно добален";

			delete[] tempID;
			delete[] tempCount;
			delete[] tempPrice;
			delete[] tempName;

			Sleep(3000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nОшибка дон\n";
		}
	}
}
void EditProduct()
{
	std::string choose, newName;
	int id = 0;

	while (true) {
		system("cls");
		std::cout << "Редактирование товара\n\n";
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(3);
			id = GetID(0);
			while (true)
			{
				std::cout << "Введите новое название продукта: ";
				Getline(newName);
				if (newName.size() > 2 && newName.size() <= 60)
				{
					nameArr[id - 1] = newName;
					break;
				}
				else
				{
					std::cout << "\nОшибка дон! От 3 до 60 символов!\n";
				}
			}
			std::cout << "\nНазвание изменено\n";
			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			break;
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
		std::cout << "Удаление товара\n\n";
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(3);
			int* tempID = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempID[i] = idArr[i];
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

			id = GetID(0);

			for (int i = 0, j = 0; i < size, j < size + 1; i++, j++)
			{
				if (j == id - 1)
				{
					if (id == size + 1)
					{
						break;
					}
					j++;
					idArr[i] = tempID[i];
					countArr[i] = tempCount[j];
					priceArr[i] = tempPrice[j];
					nameArr[i] = tempName[j];
				}
				else
				{
					idArr[i] = tempID[i];
					countArr[i] = tempCount[j];
					priceArr[i] = tempPrice[j];
					nameArr[i] = tempName[j];
				}
			}



			std::cout << "Товар успешно удалён";

			delete[] tempID;
			delete[] tempCount;
			delete[] tempPrice;
			delete[] tempName;

			Sleep(3000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nОшибка дон\n";
		}
	}
}
void AddNewEmployee()
{
	std::string choose, newLogin, newPass;
	int id = 0, count;
	while (true)
	{
		system("cls");
		std::cout << "Добавление нового сотрудника\n\n";
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
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
				std::cout << "Введите логин нового пользователя: ";
				Getline(newLogin);
				if (newLogin.size() > 4 && newLogin.size() <= 15)
				{
					loginArr[userCount - 1] = newLogin;
					break;
				}
				else
				{
					std::cout << "\nОшибка дон! От 4 до 15 символов!\n";
				}
			}

			while (true)
			{
				std::cout << "Введите пароль нового пользователя: ";
				Getline(newPass);
				if (newPass.size() > 4 && newPass.size() <= 15)
				{
					passArr[userCount - 1] = newPass;
					break;
				}
				else
				{
					std::cout << "\nОшибка дон! От 4 до 15 символов!\n";
				}
			}

			std::cout << "Новый пользователь успешно добален";

			delete[] tempPass;
			delete[] tempLogin;

			Sleep(2000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nОшибка дон\n";
		}
	}

}
void EditEmployee()
{
	std::string choose, currentPass, newPass;
	int id = 0;

	while (true) {
		system("cls");
		std::cout << "Редактирование данных сотрудника\n\n";
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			id = GetID(1);
			while (true)
			{
				std::cout << "Введите пароль пользователя " << loginArr[id - 1] << "\0 - Выход\nВвод: ";
				Getline(currentPass);
				if (currentPass == passArr[id - 1])
				{
					while (true)
					{
						std::cout << "Введите новый пароль пользователя: ";
						Getline(newPass);
						if (newPass.size() > 4 && newPass.size() <= 15)
						{
							passArr[id - 1] = newPass;
							std::cout << "\nПароль успешно изменён\n";
							break;
						}
						else
						{
							std::cout << "\nОшибка дон! От 4 до 15 символов!\n";
						}
					}
				}
				else if (currentPass == "0")
				{
					break;
				}
				else
				{
					std::cout << "\nОшибка дон!\n";
				}
			}
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
		std::cout << "Удаление сотрудников\n\n";
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);

		if (userCount <= 1) {
			std::cout << "Тайлера. Здесь. Нет.";
			Sleep(1000);
			break;
		}
		if (choose == "1")
		{
			for (int i = 1; i < userCount; i++)
			{
				std::cout << i << " " << loginArr[i] << "\n";
			}
			std::cout << std::endl;
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


			id = GetID(1);

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



			std::cout << "Сотрудник успешно удалён";

			delete[] tempLogin;
			delete[] tempPass;

			Sleep(3000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nОшибка дон\n";
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
		std::cout << "1 - Начать новую продажу\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			delete[]totalPriceCheckArr;
			delete[]nameCheckArr;
			delete[]countCheckArr;
			delete[]priceCheckArr;

			checkSize = 1;
			totalSum = 0;

			totalPriceCheckArr = new double[size];
			countCheckArr = new int[size];
			priceCheckArr = new double[size];
			nameCheckArr = new std::string[size];

			while (true)
			{
				system("cls");
				ShowStorage();
				std::cout << "Введите ID товара или\"exit\" для завершения покупок\n\nВвод: ";
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
						std::cout << "Введите кол-во " << nameArr[id - 1] << " для покупки: ";
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
							}
							else
							{
								std::cout << "\nОшибка кол-во\n";
								Sleep(1000);
							}
						}
						else
						{
							std::cout << "\nОшибка ввода\n";
							Sleep(1000);
						}
					}
					else
					{
						std::cout << "\nОшибка ID\n";
						Sleep(1000);
					}
				}
				else
				{
					std::cout << "\nОшибка ввода\n";
					Sleep(1000);
				}
			}
			if (!isFirst)
			{
				Discounts(totalSum, priceCheckArr, count, checkSize);
				while (true)
				{
					std::cout << "Выберите способ оплаты:\n1 - Наличные\n2 - Безналичный\nВвод:";

					Getline(choosePay);
					if (choosePay == "1")
					{
						std::cout << "Введите количество наличных: ";
						Getline(money);
						if (IsNumber(money))
						{
							if (std::stod(money) >= totalSum || std::stod(money) - totalSum <= cash)
							{
								std::cout << "\nОплата прошла успешно\n";
								std::cout << "\nСдача: " << std::stod(money) - totalSum << "\n";
								cash -= std::stod(money) - totalSum;
								cash += std::stod(money);
								cashMoney += std::stod(money);
								Sleep(1000);
								break;
							}
							else if (std::stod(money) < totalSum)
							{
								std::cout << "\nНедостаточно средств\n";
								Sleep(1000);
							}
							else
							{
								std::cout << "\nНедостататочно средств для сдачи\n";
								Sleep(1000);
							}
						}
					}
					else if (choosePay == "2")
					{
						system("cls");
						std::cout << "\nПриложите карту\n";
						std::cout << "\nСоединение с банком\n";
						for (size_t i = 0; i < rand() % 5 + 3; i++)
						{
							std::cout << ". ";
							Sleep(750);
						}
						std::cout << "\nОплата прошла успешно\n";
						webMoney += totalSum;
						break;
					}
					else
					{
						std::cout << "\nОшибка ввода\n";
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
			std::cout << "\nОшибка ввода\n";
			Sleep(800);
		}
	}
}
void AddNewCheckSize()
{
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

	delete[] tempTotalPrice;
	delete[] tempCount;
	delete[] tempPrice;
	delete[] tempName;

}
void Discounts(double totalSum, double priceCheckArr[], int count, int checkSize)
{
	int minPrice = 1000000;
	int countFree{};
	double Sum = totalSum;
	std::cout << "\t\tСкидка!\n" << "1)Если ваш чек выходит на сумму больше 1500р то скидка 5%.\n"
		<< "2)Если вы покупаете шесть упаковок лапши - самая дешевая из них в подарок.\n\n";
	if (totalSum >= 1500)
	{
		totalSum = totalSum * 0.95;
	}
	if (count >= 5)
	{
		for (int i = 0; i < checkSize; i++)
		{
			if (priceCheckArr[i] <= minPrice)
			{
				minPrice = priceCheckArr[i];
			}
		}
		countFree = count / 5;
		totalSum -= countFree * minPrice;
	}

	PrintCheck(totalSum, Sum);
}

void PrintCheck(double& totalSum, double& Sum)
{
	std::cout << "\t№\t" << std::left << std::setw(25) << "Название" << "\tЦена\tКол-во\tИтого\n";
	for (int i = 0; i < checkSize; i++) {
		std::cout << "№" << i + 1 << " \t" << std::left << std::setw(30) << nameCheckArr[i] << "\t" << priceCheckArr[i] << "\t\t*  " << countCheckArr[i] << "\t" << totalPriceCheckArr[i] << "\n";
	}
	std::cout << "\nСумма без скидок: " << Sum;
	std::cout << "\nИтоговая сумма: " << totalSum << "\n\n";
}
void Income()
{
	system("cls");
	std::cout << "Деньги в кассе: " << cash << "\n";
	std::cout << "Деньги за наличную оплату: " << cashMoney << "\n";
	std::cout << "Деньги за безнал: " << webMoney << "\n";
	std::cout << "Общий доход: " << cashMoney + webMoney << "\n\n";
	system("pause");

}
bool CloseShift()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Закрыть  смену\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			Income();
			std::cout << "\nСмена закрыта. ББ.\n";
			system("pause");
			return true;
		}
		else if (choose == "0")
		{
			return false;
		}
		else
		{
			std::cout << "\nОшибка дон\n";
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
		std::cout << "Изменение цены\n\n";
		std::cout << "1 - Начать\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID(0);
			while (true)
			{
				std::cout << "Новая цена: ";
				Getline(choosePrice);
				if (IsNumber(choosePrice)) {
					price = std::stod(choosePrice);
					if (price > 0 && price <= 1000.0) {
						priceArr[id - 1] = price;
						std::cout << "\n\nЦена успешно изменена\n\n";
						Sleep(1000);
						break;
					}
					else
					{
						std::cout << "\nНекорректное ID\n";
					}
				}
				else
				{
					std::cout << "Ошибка, дон";
				}
			}

		}
		else if (choose == "0")
		{
			break;
		}


	}
}
void ChangeStorage() {
	std::string choose, chooseCount;
	int id = 0, count;

	while (true)
	{
		system("cls");
		std::cout << "Изменение склада\n\n";
		std::cout << "1 - Добавить новый товар\n2 - Редактировать название\n3 - Удалить товар\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			AddNewProduct();
		}
		else if (choose == "2") {
			EditProduct();
		}
		else if (choose == "3") {
			DeleteProduct();
		}
		else if (choose == "0") {
			break;
		}
		else {
			std::cout << "\nОшибка дон\n";
		}
	}
}
void ChangeEmployee()
{
	std::string choose, chooseCount;
	int id = 0, count;

	while (true)
	{
		system("cls");
		std::cout << "Изменение сотрудников\n\n";
		std::cout << "1 - Добавить нового сотрудника\n2 - Редактировать сотрудника\n3 - Удалить сотрудника\n0 - Отмена\n\nВвод: ";
		Getline(choose);
		if (choose == "1")
		{
			AddNewEmployee();
		}
		else if (choose == "2") {
			EditEmployee();
		}
		else if (choose == "3") {
			if (userCount > 1)
			{
				DeleteEmployee();
			}
			else
			{
				std::cout << "\nНекого удалять\n";
				Sleep(1500);
			}
		}
		else if (choose == "0") {
			break;
		}
		else {
			std::cout << "\nОшибка дон\n";
		}
	}
}
int GetID(int mode)
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
	std::cout << "Введите ID товара: ";
	Getline(stringID);
	if (IsNumber(stringID)) {
		result = std::stoi(stringID);
		if (result > 0 && result <= currentSize) {
			return result;
		}
		else
		{
			std::cout << "\nНекорректное ID\n";
		}
	}
	else
	{
		std::cout << "Ошибка, дон";
	}
}
void Getline(std::string& stringName)
{
	std::getline(std::cin, stringName, '\n');
}
void ShowAdminMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать со склада\n";
		std::cout << "5 - Изменить цену\n";
		std::cout << "6 - Изменить склад\n";
		std::cout << "7 - Изменить сотрудников\n";
		std::cout << "8 - Отчёт о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "\nВвод:";
		Getline(choose);
		if (choose == "1") {
			Selling();
		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefillProducts();
		}
		else if (choose == "4")
		{
			RemoveProducts();
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

		}
		else if (choose == "0")
		{

		}
		else
		{
			std::cout << "\nОшибка ввода\n";
			Sleep(500);
		}
	}
}
void ShowUserMenu() {
	std::string choose;

	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать со склада\n";
		std::cout << "5 - Отчёт о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "\nВвод:";
		std::getline(std::cin, choose, '\n');
		if (choose == "1") {

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefillProducts();
		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "0")
		{

		}
		else
		{
			std::cout << "\nОшибка ввода\n";
			Sleep(500);
		}
	}
}
template<typename Arr>
void FillStorage(Arr staticArr[], Arr dynamicArr[], int staticSize)
{
	for (int i = 0; i < staticSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}
