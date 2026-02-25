#include <iostream>
#include <string>

using namespace std;

class Beverage {
public:
	virtual string getDescription() = 0;
	virtual double getCost() = 0;
};

class Espresso : public Beverage {
public: 
	string getDescription() override { return "Вкусна!"; }
	double getCost() override { return 7.77; }
};

class CondimentDecorator : public Beverage {
protected:
	Beverage* beverage;
public:
	CondimentDecorator(Beverage* beverage) : beverage(beverage) {}
	string getDescription() override { return beverage->getDescription(); }
	double getCost() override { return beverage->getCost(); }
};

class Milk : public CondimentDecorator {
public:
	Milk(Beverage* beverage) : CondimentDecorator(beverage) {}
	string getDescription() override { return beverage->getDescription() + " [Молоко]"; }
	double getCost() override { return beverage->getCost() + 0.05; }
};

class Sugar : public CondimentDecorator {
public:
	Sugar(Beverage* beverage) : CondimentDecorator(beverage) {}
	string getDescription() override { return beverage->getDescription() + " [Сахароза]"; }
	double getCost() override { return beverage->getCost() + 0.02; }
};

class Syrup : public CondimentDecorator {
public:
	Syrup(Beverage* beverage) : CondimentDecorator(beverage) {}
	string getDescription() override { return beverage->getDescription() + " [Сироп]"; }
	double getCost() override { return beverage->getCost() + 0.15; }
};

class GoldenPoop : public CondimentDecorator {
public:
	GoldenPoop(Beverage* beverage) : CondimentDecorator(beverage) {}
	string getDescription() override { return beverage->getDescription() + " [Ты не хочешь этого знать!]"; }
	double getCost() override { return beverage->getCost() + 3.0; }
};

int main() {
	setlocale(0, "ru");

	CondimentDecorator* myCoffee = new GoldenPoop(new Milk(new Espresso()));
	cout << "Ваше кофе: " << myCoffee->getDescription() << endl;
	cout << "Цена кофе: " << myCoffee->getCost() << "$" << endl;

	delete myCoffee;
}