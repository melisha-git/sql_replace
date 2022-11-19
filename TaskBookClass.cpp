#ifndef TASK_BOOK_CLASS_CPP
#define TASK_BOOK_CLASS_CPP
#include "TaskBookClass.cpp"

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

void TaskBook::SELECT(const std::string &regex) {
	std::vector<Task> copy = this->tasks_;
	std::vector<std::string> vRegex = split(regex, " and ");
	std::regex reg("[<=,>=,<,>,=]");
	std::regex likeReg("like");
	std::smatch match;

	for (auto str : vRegex) {
		if (!std::regex_search(str, match, reg) && !std::regex_search(str, match, likeReg)) {
			return ;
		}
		std::string param = std::regex_replace(match.prefix().str(), std::regex("^[ ]*(.*?)[ ]*$"), "$1");
		std::string logic = std::regex_replace(match.str(), std::regex(" "), "");
		std::string regexString = std::regex_replace(match.suffix().str(), std::regex("^[ ]*(.*?)[ ]*$"), "$1");
		copy = _searchTask(copy, param, logic, regexString);
	}
	for (const Task &t : copy) {
		std::cout << t << std::endl;
	}
}

//operators

// destructors
TaskBook::~TaskBook() {
	/*for (Task t : this->tasks_) {
		std::cout << t << std::endl;
	}*/
}

Task TaskBook::_getTask(const std::string &listTask) {
	Task task;
	std::string line = std::string();
	std::string paramName;
	std::vector<std::string> vTask = split(listTask, " ");

	for (int i = 0; i < vTask.size(); ++i) {
		if (std::find(TaskBook::keyWords.begin(), TaskBook::keyWords.end(), vTask[i]) != TaskBook::keyWords.end()) {
			paramName = vTask[i];
			line = std::string();
			continue ;
		}
		if (line != std::string())
			line += " ";
		line += vTask[i];
		task.set(paramName, line);
	}
	return task;
}

std::vector<Task> TaskBook::_searchTask(std::vector<Task> tasks, const std::string &param, const std::string &logic, const std::string &regex) {
	std::vector<Task> result;
	for (auto it = tasks.begin(); it != tasks.end(); ++it) {
		if (logic == "=" && it->get(param) == regex)
			result.push_back(*it);
		if (logic == ">=" && it->get(param) >= regex)
			result.push_back(*it);
		if (logic == "<=" && it->get(param) <= regex)
			result.push_back(*it);
		if (logic == ">" && it->get(param) > regex)
			result.push_back(*it);
		if (logic == "<" && it->get(param) < regex)
			result.push_back(*it);
		if (logic == "!=" && it->get(param) != regex)
			result.push_back(*it);
		if (logic == "like" && (it->get(param).find(regex)) != -1)
			result.push_back(*it);
	}
	return result;
}


#endif