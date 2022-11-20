#include "TaskBookClass.hpp"

// Алгоритм - получаю строку, отделяю команду от параметров, отправляю в методы класса задачника
/* 
* Не знаю, будуту ли читать комментари, очень хочу к вам в компанию...
* Готов в не рабочее время отдельно работать над Хард скилами, ежедневно прокачивая себя
* Именно ваши проекты заинтересовали, так как работа над драйверами сильно прокачает меня
*/
int main() {
	TaskBook tasks;
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss(line);
		std::string command;
		std::getline(ss, command, ' ');
		std::getline(ss, line);
		if (command == "add" || command == "ADD")
			tasks.ADD(line);
		else if (command == "delete" || command == "DELETE")
			tasks.DELETE(line);
		else if (command == "update" || command == "UPDATE")
			tasks.UPDATE(line);
		else if (command == "done" || command == "DONE")
			tasks.DONE(line);
		else if (command == "select" || command == "SELECT") {
			std::vector<std::string> vLine = split(line, " ");
			if (vLine[0] != "*") {
				std::cout << std::endl;
				line.clear();
				continue ;
			}
			if (vLine.size() >= 2 && vLine[1] == "where") {
				line = line.substr(line.find("where") + 6);
				tasks.SELECT(line);
			}
			else
				tasks.SELECT();
		}
		else
			std::cerr << "Command " << command << " not found\n";
		line.clear();
	}
	return (0);
}