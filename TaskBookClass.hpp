#ifndef TASK_BOOK_CLASS_HPP
#define TASK_BOOK_CLASS_HPP

#include "TaskClass.hpp"
#include "utils.hpp"
#include <algorithm>
#include <regex>

class TaskBook {
private:
	static std::vector<std::string> keyWords;
	std::vector<Task>				tasks_;
public:

	//constructors
	TaskBook();
	TaskBook(const TaskBook &) = delete;
	
	//methoods
	void ADD(const std::string &);
	void DONE(const std::string &name);
	void DELETE(const std::string &name);
	void UPDATE(const std::string &);
	void SELECT(const std::string &regex);
	//operators
	
	//operator '='
	operator=(const TaskBook &) = delete;
	
	// destructors
	~TaskBook();
private:
	Task _getTask(const std::string &);
	std::vector<Task> _searchTask(std::vector<Task> tasks, const std::string &param, const std::string &logic, const std::string &regex);
};

std::vector<std::string> TaskBook::keyWords{"name", "description", "date", "category", "status"};

#include "TaskBookClass.cpp"

#endif