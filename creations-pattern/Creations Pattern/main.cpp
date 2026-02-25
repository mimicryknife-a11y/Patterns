#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Character {
public:
	virtual string getType() = 0;
	virtual void attack() = 0;
};

class Mage : public Character {
public:
	string getType() override { return "Mage"; }
	void attack() override { cout << "Маг уничтожает хромасому врага!" << endl; }
};

class Warrior : public Character {
public:
	string getType() override { return "Warrior"; }
	void attack() override { cout << "Воин махает мечом!" << endl; }
};

class Archer : public Character {
public:
	string getType() override { return "Archer"; }
	void attack() override { cout << "Лучник выпускает дождь стрел!" << endl; }
};

class CharacterFactory {
public:
	virtual Character* createCharacter() = 0;
	void spawnAndAttack() {
		Character* character = createCharacter();
		cout << "Создан персонаж с типом " << character->getType() << endl;
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

	delete clownFactory;
}