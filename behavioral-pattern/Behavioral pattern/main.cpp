#include <iostream>
#include <vector>
#include <string>

using namespace std;


/**
* @brief Класс компьютера
*/
class ComputerSystem {
public:

	/**
	* @brief Открывает файл
	* @param file Название файла
	*/
	void openFile(const string& file) { cout << "Открываем файл: " << file << endl; }
	
	/**
	* @brief Выключает компьютер
	*/
	void shutdown() { cout << "Выключаем комп" << endl; }

	/**
	* @brief Включаем браузер
	*/
	void launchBrowser() { cout << "Запускаем браузер" << endl; }
};

/**
* @brief Интерфейс команды
*/
class Command {
public:

	/**
	* @brief Функция выполнения команды
	*/
	virtual void execute() = 0;

	/**
	* @brief Функция отмены команды
	*/
	virtual void undo() = 0;
};

/**
* @brief Команды открытия файла
* Наследует интерфейс команды
*/
class OpenFileCommand : public Command {
private:
	ComputerSystem* system;
	string fileName;
public:

	/**
	* @brief Конструктор команды
	* @return system Указатель на систему
	* @return string Название файла
	*/
	OpenFileCommand(ComputerSystem* system, const string& fileName) : system(system), fileName(fileName) {}

	/**
	* @brief Функция выполнения команды
	*/
	void execute() override { system->openFile(fileName); }

	/**
	* @brief Функция отмены команды
	*/
	void undo() override { cout << "Закрываем файл: " << fileName << endl; }
};

/**
* @brief Команды выключения компьютера
* Наследует интерфейс команды
*/
class ShutdownCommand : public Command {
private:
	ComputerSystem* system;
public:

	/**
	* @brief Конструктор команды
	* @return system Указатель на систему
	*/
	ShutdownCommand(ComputerSystem* system) : system(system) {}

	/**
	* @brief Функция выполнения команды
	*/
	void execute() override { system->shutdown(); }

	/**
	* @brief Функция отмены команды
	*/
	void undo() override { cout << "Включаем?" << endl; }
};

/**
* @brief Команды открытия браузера
* Наследует интерфейс команды
*/
class LaunchBrowserCommand : public Command {
private:
	ComputerSystem* system;
public:

	/**
	* @brief Конструктор команды
	* @return system Указатель на систему
	*/
	LaunchBrowserCommand(ComputerSystem* system) : system(system) {}

	/**
	* @brief Функция выполнения команды
	*/
	void execute() override { system->launchBrowser(); }

	/**
	* @brief Функция отмены команды
	*/
	void undo() override { cout << "Закрываем браузер" << endl; }
};

/**
* @brief Команды перезапуска команды
* Наследует интерфейс команды
*/
class RestardCommand : public Command {
private:
	ComputerSystem* system;
public:

	/**
	* @brief Конструктор команды
	* @return system Указатель на систему
	*/
	RestardCommand(ComputerSystem* system) : system(system) {}

	/**
	* @brief Функция выполнения команды
	*/
	void execute() override { cout << "Перезапускается пк!" << endl; }

	/**
	* @brief Функция отмены команды
	*/
	void undo() override { cout << "Остановка перезапуска пк!" << endl; }
};

/**
* @brief Класс управления командами
*/
class RemoteControl {
private:
	vector<Command*> commands;
public:

	/**
	* @brief Добавляет команду в очередь
	* @param cmd Команда
	*/
	void addCommand(Command* cmd) { commands.push_back(cmd); }

	/**
	* @brief Запускает все команды
	*/
	void pressButton() {
		for (Command* cmd : commands) {
			cmd->execute();
		}
	}

	/**
	* @brief Отменяет последнюю команду и удаляет её из очереди
	*/
	void undoLast() {
		if (!commands.empty()) {
			commands.back()->undo();
			commands.pop_back();
		}
	}
};

int main() {
	setlocale(0, "ru");

	ComputerSystem* pc = new ComputerSystem();

	OpenFileCommand* ofc = new OpenFileCommand(pc, "main.cpp");
	ShutdownCommand* sdc = new ShutdownCommand(pc);
	LaunchBrowserCommand* lbc = new LaunchBrowserCommand(pc);
	RestardCommand* rc = new RestardCommand(pc);

	RemoteControl* controller = new RemoteControl();
	controller->addCommand(ofc);
	controller->addCommand(sdc);
	controller->addCommand(lbc);
	controller->addCommand(rc);

	controller->pressButton();
	controller->undoLast();

	delete controller;
	delete rc;
	delete lbc;
	delete sdc;
	delete ofc;
	delete pc;

	ComputerSystem* pc1 = new ComputerSystem();
	OpenFileCommand* ofc1 = new OpenFileCommand(pc1, "main.cpp");
	ofc1->execute();
	ofc1->undo();
	OpenFileCommand* ofc2 = new OpenFileCommand(pc1, "images/logo.");
	ofc2->execute();
	ofc2->undo();
}