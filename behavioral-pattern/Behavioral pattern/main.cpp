#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ComputerSystem {
public:
	void openFile(const string& file) { cout << "Открываем файл: " << file << endl; }
	void shutdown() { cout << "Выключаем комп" << endl; }
	void launchBrowser() { cout << "Запускаем компьютер" << endl; }
};

class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class OpenFileCommand : public Command {
private:
	ComputerSystem* system;
	string fileName;
public:
	OpenFileCommand(ComputerSystem* system, const string& fileName) : system(system), fileName(fileName) {}
	void execute() override { system->openFile(fileName); }
	void undo() override { cout << "Закрываем файл: " << fileName << endl; }
};

class ShutdownCommand : public Command {
private:
	ComputerSystem* system;
public:
	ShutdownCommand(ComputerSystem* system) : system(system) {}
	void execute() override { system->shutdown(); }
	void undo() override { cout << "Включаем?" << endl; }
};

class LaunchBrowserCommand : public Command {
private:
	ComputerSystem* system;
public:
	LaunchBrowserCommand(ComputerSystem* system) : system(system) {}
	void execute() override { system->launchBrowser(); }
	void undo() override { cout << "Закрываем браузер" << endl; }
};

class RestardCommand : public Command {
private:
	ComputerSystem* system;
public:
	RestardCommand(ComputerSystem* system) : system(system) {}
	void execute() override { cout << "Перезапускается пк!" << endl; }
	void undo() override { cout << "Остановка перезапуска пк!" << endl; }
};

class RemoteControl {
private:
	vector<Command*> commands;
public:
	void addCommand(Command* cmd) { commands.push_back(cmd); }
	void pressButton() {
		for (Command* cmd : commands) {
			cmd->execute();
		}
	}
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