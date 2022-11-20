#ifndef TASK_BOOK_CLASS_HPP
#define TASK_BOOK_CLASS_HPP

#include "TaskClass.hpp"
#include "utils.hpp"
#include <algorithm>
#include <regex>

// Класс, хранящий все задачи

class TaskBook {
private:
	static std::vector<std::string> keyWords;
	std::vector<Task>				tasks_;
public:

	//Конструкторы
	TaskBook();
	TaskBook(const TaskBook &) = delete;
	
	//Методы
	void ADD(const std::string &);
	void DONE(const std::string &name);
	void DELETE(const std::string &name);
	void UPDATE(const std::string &);
	void SELECT(const std::string &regex);
	void SELECT() const ;
	
	//Операторы
	
	//Удалить оператор '='
	operator=(const TaskBook &) = delete;
	
	// Деструктор
	~TaskBook();
private:
	// Функция метода вывода названий колонок
	void _printColumn() const;
	// Создание новой задачи по параметрам
	Task _getTask(const std::string &);
	//Поиск всех задач, удовлетворяющих условию
	std::vector<Task> _searchTask(std::vector<Task> tasks, const std::string &param, const std::string &logic, const std::string &regex);
};

std::vector<std::string> TaskBook::keyWords{"name", "description", "date", "category", "status"};

#include "TaskBookClass.cpp"

#endif