#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
* @brief Интерфейс персонажа
*/
class Character {
public:
	/**
	* @brief Возвращает уникальный тип персонажа
	* @return string Уникальный тип
	*/
	virtual string getType() = 0;


	/**
	* @brief Возвращает максимальное количество жизней персонажа
	* @return int Максимальное количество жизней
	*/
	virtual int getHealth() = 0;

	virtual void attack() = 0;
};

/**
* @brief Реализация класса мага
* Наследует интерфейс персонажа
*/
class Mage : public Character {
public:
	/**
	* @brief Возвращает уникальный тип персонажа
	* @return string Уникальный тип
	*/
	string getType() override { return "Mage"; }
	void attack() override { cout << "Маг уничтожает хромасому врага!" << endl; }


	/**
	* @brief Возвращает максимальное количество жизней персонажа
	* @return int Максимальное количество жизней
	*/
	int getHealth() override { return 100; }
};


/**
* @brief Реализация класса воина
* Наследует интерфейс персонажа
*/
class Warrior : public Character {
public:
	/**
	* @brief Возвращает уникальный тип персонажа
	* @return string Уникальный тип
	*/
	string getType() override { return "Warrior"; }

	/**
	* @brief Скрипт атаки персонажа
	*/
	void attack() override { cout << "Воин махает мечом!" << endl; }


	/**
	* @brief Возвращает максимальное количество жизней персонажа
	* @return int Максимальное количество жизней
	*/
	int getHealth() override { return 90; }
};


/**
* @brief Реализация класса рыцаря
* Наследует интерфейс персонажа
*/
class Knight : public Character {
public:
	/**
	* @brief Возвращает уникальный тип персонажа
	* @return string Уникальный тип
	*/
	string getType() override { return "Knight"; }

	/**
	* @brief Скрипт атаки персонажа
	*/
	void attack() override { cout << "Рыцарь атакует копьём!" << endl; }


	/**
	* @brief Возвращает максимальное количество жизней персонажа
	* @return int Максимальное количество жизней
	*/
	int getHealth() override { return 80; }
};


/**
* @brief Реализация класса лучника
* Наследует интерфейс персонажа
*/
class Archer : public Character {
public:
	/**
	* @brief Возвращает уникальный тип персонажа
	* @return string Уникальный тип
	*/
	string getType() override { return "Archer"; }

	/**
	* @brief Скрипт атаки персонажа
	*/
	void attack() override { cout << "Лучник выпускает дождь стрел!" << endl; }


	/**
	* @brief Возвращает максимальное количество жизней персонажа
	* @return int Максимальное количество жизней
	*/
	int getHealth() override { return 70; }
};

/**
* @brief Абстрактный класс фабрики персонажей
*/
class CharacterFactory {
public:
	/**
	* @brief Не реализованная функция создания персонажа.
	* @return Character* Указатель на персонажа
	*/
	virtual Character* createCharacter() = 0;
	
	/**
	* @brief Функция тестирующая персонажа. 
	* Имеет реализацию по умолчанию.
	*/
	void spawnAndAttack() {
		Character* character = createCharacter();
		cout << "Создан персонаж с типом " << character->getType() << " (" << character->getHealth() << " hp)" << endl;
		character->attack();
		delete character;
	}
};

/**
* @brief Реализация фабрики магов.
* Наследует абстрактный класс фабрики персонаже
*/
class MageFactory : public CharacterFactory {
public:
	/**
	* @brief Реализация функции создания мага. Создаёт мага.
	* @return Character* Указатель на мага.
	*/
	Character* createCharacter() override { return new Mage(); }
};

/**
* @brief Реализация фабрики воинов.
* Наследует абстрактный класс фабрики персонаже
*/
class WarriorFactory : public CharacterFactory {
public:
	/**
	* @brief Реализация функции создания воина. Создаёт воина.
	* @return Character* Указатель на воина.
	*/
	Character* createCharacter() override { return new Warrior(); }
};

/**
* @brief Реализация фабрики рыцарей.
* Наследует абстрактный класс фабрики персонаже
*/
class KnightFactory : public CharacterFactory {
public:
	/**
	* @brief Реализация функции создания рыцаря. Создаёт рыцаря.
	* @return Character* Указатель на рыцаря.
	*/
	Character* createCharacter() override { return new Knight(); }
};

/**
* @brief Реализация фабрики лучников.
* Наследует абстрактный класс фабрики персонаже
*/
class ArcherFactory : public CharacterFactory {
public:
	/**
	* @brief Реализация функции создания лучника. Создаёт лучника.
	* @return Character* Указатель на лучника.
	*/
	Character* createCharacter() override { return new Archer(); }
};

int main() {
	setlocale(0, "ru");

	CharacterFactory* clownFactory = new MageFactory();

	for (short int i = 0; i < 10; i++)
		clownFactory->spawnAndAttack();

	clownFactory = new WarriorFactory();

	for (short int i = 0; i < 10; i++)
		clownFactory->spawnAndAttack();

	clownFactory = new ArcherFactory();

	for (short int i = 0; i < 10; i++)
		clownFactory->spawnAndAttack();

	clownFactory = new KnightFactory();

	for (short int i = 0; i < 10; i++)
		clownFactory->spawnAndAttack();

	delete clownFactory;
}