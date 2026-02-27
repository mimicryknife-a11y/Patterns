#include <iostream>
#include <string>

using namespace std;

/**
* @brief Интерфейс напитка
*/
class Beverage {
public:
	/**
	* @brief Получает описание напитка
	* @return string Описание
	*/
	virtual string getDescription() = 0;

	/**
	* @brief Получает стоимость напитка
	* @return double Стоимость напитка
	*/
	virtual double getCost() = 0;
};

/**
* @brief Напиток экспрессо
* Наследует интерфейс напитка
*/
class Espresso : public Beverage {
public:
	/**
	* @brief Получает описание напитка
	* @return string Описание
	*/
	string getDescription() override { return "Вкусна!"; }

	/**
	* @brief Получает стоимость напитка
	* @return double Стоимость напитка
	*/
	double getCost() override { return 7.77; }
};

/**
* @brief Напиток чай
* Наследует интерфейс напитка
*/
class Tea : public Beverage {
public:
	/**
	* @brief Получает описание напитка
	* @return string Описание
	*/
	string getDescription() override { return "Китайский чай!"; }

	/**
	* @brief Получает стоимость напитка
	* @return double Стоимость напитка
	*/
	double getCost() override { return 1.23; }
};


/**
* @brief Декоратор напитка
* Наследует интерфейс напитка
*/
class CondimentDecorator : public Beverage {
protected:
	Beverage* beverage;
public:
	/**
	* @brief Конструктор напитка
	* @param beverage напиток родитель
	*/
	CondimentDecorator(Beverage* beverage) : beverage(beverage) {}

	/**
	* @brief Получает описание родителя
	* @return string Возвращает описание родителя
	*/
	string getDescription() override { return beverage->getDescription(); }

	/**
	* @brief Получает стоимость родителя
	* @return double Возвращает стоимость родителя
	*/
	double getCost() override { return beverage->getCost(); }
};

/**
* @brief Молоко (Декоратор напитка)
* Наследует декоратор напитка
*/
class Milk : public CondimentDecorator {
public:
	/**
	* @brief Конструктор напитка
	* @param beverage напиток родитель
	*/
	Milk(Beverage* beverage) : CondimentDecorator(beverage) {}

	/**
	* @brief Получает описание родителя добавляя своё
	* @return string Возвращает описание родителя добавляя своё
	*/
	string getDescription() override { return beverage->getDescription() + " [Молоко]"; }

	/**
	* @brief Получает стоимость родителя добавляя свою
	* @return double Возвращает стоимость родителя добавляя свою
	*/
	double getCost() override { return beverage->getCost() + 0.05; }
};

/**
* @brief Сахар (Декоратор напитка)
* Наследует декоратор напитка
*/
class Sugar : public CondimentDecorator {
public:
	/**
	* @brief Конструктор напитка
	* @param beverage напиток родитель
	*/
	Sugar(Beverage* beverage) : CondimentDecorator(beverage) {}

	/**
	* @brief Получает описание родителя добавляя своё
	* @return string Возвращает описание родителя добавляя своё
	*/
	string getDescription() override { return beverage->getDescription() + " [Сахароза]"; }

	/**
	* @brief Получает стоимость родителя добавляя свою
	* @return double Возвращает стоимость родителя добавляя свою
	*/
	double getCost() override { return beverage->getCost() + 0.02; }
};

/**
* @brief Сироп (Декоратор напитка)
* Наследует декоратор напитка
*/
class Syrup : public CondimentDecorator {
public:
	/**
	* @brief Конструктор напитка
	* @param beverage напиток родитель
	*/
	Syrup(Beverage* beverage) : CondimentDecorator(beverage) {}

	/**
	* @brief Получает описание родителя добавляя своё
	* @return string Возвращает описание родителя добавляя своё
	*/
	string getDescription() override { return beverage->getDescription() + " [Сироп]"; }

	/**
	* @brief Получает стоимость родителя добавляя свою
	* @return double Возвращает стоимость родителя добавляя свою
	*/
	double getCost() override { return beverage->getCost() + 0.15; }
};

/**
* @brief Золотая какашка (Декоратор напитка)
* Наследует декоратор напитка
*/
class GoldenPoop : public CondimentDecorator {
public:
	/**
	* @brief Конструктор напитка
	* @param beverage напиток родитель
	*/
	GoldenPoop(Beverage* beverage) : CondimentDecorator(beverage) {}

	/**
	* @brief Получает описание родителя добавляя своё
	* @return string Возвращает описание родителя добавляя своё
	*/
	string getDescription() override { return beverage->getDescription() + " [100% натуральный шоколад]"; }

	/**
	* @brief Получает стоимость родителя добавляя свою
	* @return double Возвращает стоимость родителя добавляя свою
	*/
	double getCost() override { return beverage->getCost() + 3.0; }
};

int main() {
	setlocale(0, "ru");

	CondimentDecorator* myCoffee = new GoldenPoop(new Milk(new Espresso()));
	cout << "Ваше кофе: " << myCoffee->getDescription() << endl;
	cout << "Цена кофе: " << myCoffee->getCost() << "$" << endl;

	myCoffee = new Syrup(new Milk(new Tea()));
	cout << "Ваше кофе: " << myCoffee->getDescription() << endl;
	cout << "Цена кофе: " << myCoffee->getCost() << "$" << endl;

	delete myCoffee;
}