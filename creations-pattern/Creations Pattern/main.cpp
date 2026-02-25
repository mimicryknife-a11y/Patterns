#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Character {
public:
	virtual string getType() = 0;
	virtual int getHealth() = 0;
	virtual void attack() = 0;
};

class Mage : public Character {
public:
	string getType() override { return "Mage"; }
	void attack() override { cout << "Маг уничтожает хромасому врага!" << endl; }
	int getHealth() override { return 100; }
};

class Warrior : public Character {
public:
	string getType() override { return "Warrior"; }
	void attack() override { cout << "Воин махает мечом!" << endl; }
	int getHealth() override { return 90; }
};

class Knight : public Character {
public:
	string getType() override { return "Knight"; }
	void attack() override { cout << "Рыцарь атакует копьём!" << endl; }
	int getHealth() override { return 80; }
};

class Archer : public Character {
public:
	string getType() override { return "Archer"; }
	void attack() override { cout << "Лучник выпускает дождь стрел!" << endl; }
	int getHealth() override { return 70; }
};

class CharacterFactory {
public:
	virtual Character* createCharacter() = 0;
	void spawnAndAttack() {
		Character* character = createCharacter();
		cout << "Создан персонаж с типом " << character->getType() << " (" << character->getHealth() << " hp)" << endl;
		character->attack();
		delete character;
	}
};

class MageFactory : public CharacterFactory {
public:
	Character* createCharacter() override { return new Mage(); }
};

class WarriorFactory : public CharacterFactory {
public:
	Character* createCharacter() override { return new Warrior(); }
};

class KnightFactory : public CharacterFactory {
public:
	Character* createCharacter() override { return new Knight(); }
};

class ArcherFactory : public CharacterFactory {
public:
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