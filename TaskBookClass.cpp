#ifndef TASK_BOOK_CLASS_CPP
#define TASK_BOOK_CLASS_CPP
#include "TaskBookClass.cpp"

//constructors
TaskBook::TaskBook() {}

//methoods

void TaskBook::ADD(const std::string &listTask) {
	std::map<int, std::string> positions = {{listTask.find("name"), "name"}, 
	{listTask.find("description"), "description"}, {listTask.find("date"), "date"}, 
	{listTask.find("category"), "category"}};
	
	Task t(listTask.substr(listTask.find("name ") + 5, 
	listTask.find("decription") - listTask.find("name") - 5));
	std::cout << t << std::endl;
}

void TaskBook::DONE(const std::string &name) {
	auto pos = std::find(this->tasks_.begin(), this->tasks_.end(), Task(name));
	if (pos != this->tasks_.end())
		pos->setStatus(true);
}
//operators

// destructors
TaskBook::~TaskBook() {}

#endif