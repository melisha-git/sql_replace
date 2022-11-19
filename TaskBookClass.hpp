#ifndef TASK_BOOK_CLASS_HPP
#define TASK_BOOK_CLASS_HPP

#include "TaskClass.hpp"
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>

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
	//operators
	
	//operator '='
	operator=(const TaskBook &) = delete;
	
	// destructors
	~TaskBook();
private:
	Task _getTask(const std::string &);
};

std::vector<std::string> TaskBook::keyWords{"name", "description", "date", "category", "status"};

#include "TaskBookClass.cpp"

#endif