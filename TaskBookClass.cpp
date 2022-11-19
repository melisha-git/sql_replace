#ifndef TASK_BOOK_CLASS_CPP
#define TASK_BOOK_CLASS_CPP
#include "TaskBookClass.cpp"

std::vector<std::string> split(const std::string &str, char delim) {
	std::vector<std::string> res;
	std::stringstream ss(str);
	std::string word;
	
	while (std::getline(ss, word, ' '))
		res.push_back(word);
	return res;
}

//constructors
TaskBook::TaskBook() {}

//methoods

void TaskBook::ADD(const std::string &listTask) {
	this->tasks_.push_back(this->_getTask(listTask));
}

void TaskBook::DONE(const std::string &name) {
	auto pos = std::find(this->tasks_.begin(), this->tasks_.end(), Task(name));
	if (pos != this->tasks_.end())
		pos->setStatus(true);
}

void TaskBook::DELETE(const std::string &name) {
	auto pos = std::find(this->tasks_.begin(), this->tasks_.end(), Task(name));
	if (pos != this->tasks_.end())
		this->tasks_.erase(pos);
}

void TaskBook::UPDATE(const std::string &listTask) {
	Task task = this->_getTask(listTask);
	auto pos = std::find(this->tasks_.begin(), this->tasks_.end(), task);
	if (pos != this->tasks_.end()) {
		this->DELETE(task.getName());
		this->tasks_.push_back(task);
	}
}

//operators

// destructors
TaskBook::~TaskBook() {
	for (Task t : this->tasks_) {
		std::cout << t << std::endl;
	}
}

Task TaskBook::_getTask(const std::string &listTask) {
	Task task;
	std::string line = std::string();
	std::string paramName;
	std::vector<std::string> vTask = split(listTask, ' ');

	for (int i = 0; i < vTask.size(); ++i) {
		if (std::find(TaskBook::keyWords.begin(), TaskBook::keyWords.end(), vTask[i]) != TaskBook::keyWords.end()) {
			paramName = vTask[i];
			line = std::string();
			continue ;
		}
		if (line != std::string())
			line += " ";
		line += vTask[i];
		if (paramName == "name")
			task.setName(line);
		if (paramName == "description")
			task.setDescription(line);
		if (paramName == "date")
			task.setDate(line);
		if (paramName == "category")
			task.setCategory(line);
	}
	return task;
}

#endif