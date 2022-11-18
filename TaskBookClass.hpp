#ifndef TASK_BOOK_CLASS_HPP
#define TASK_BOOK_CLASS_HPP

#include "TaskClass.hpp"
#include <algorithm>
#include <vector>
#include <map>

class TaskBook {
private:
	std::vector<Task>	tasks_;
public:
	//constructors
	TaskBook();
	TaskBook(const TaskBook &) = delete;
	
	//methoods
	void ADD(const std::string &);
	void DONE(const std::string &);
	//void DELETE(const std::string &);
	//operators
	
	//operator '='
	operator=(const TaskBook &) = delete;
	
	// destructors
	~TaskBook();
};

#include "TaskBookClass.cpp"

#endif