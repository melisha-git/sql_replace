#ifndef TASK_CLASS_CPP
#define TASK_CLASS_CPP

#include "TaskClass.hpp"

// constructors

Task::Task(std::string name = std::string(), std::string description = std::string(), 
		std::string date = std::string(), std::string category = std::string(), bool status = false) :
		name_(name), description_(description), date_(date), category_(category), status_(status) {}
	
Task::Task(const Task &other) {
	*this = other;
}
	
// gets and sets
std::string Task::getName() const {
	return this->name_;
}

void Task::setName(const std::string &name) {
	this->name_ = name;
}

std::string Task::getDescription() const {
	return this->description_;
}

void Task::setDescription(const std::string &description) {
	this->description_ = description;
}

std::string Task::getDate() const {
	return this->date_;
}

void Task::setDate(const std::string &date) {
	this->date_ = date;
}

std::string Task::getCategory() const {
	return this->category_;
}

void Task::setCategory(const std::string &category) {
	this->category_ = category;
}

bool Task::getStatus() const {
	return this->status_;
}

void Task::setStatus(bool status) {
	this->status_ = status;
}

//operators

//operator '='
Task& Task::operator=(const Task &other) {
	this->name_ = other.getName();
	this->description_ = other.getDescription();
	this->date_ = other.getDate(); 
	this->category_ = other.getCategory();
	this->status_ = other.getStatus();
	return *this;
}

//logic operators 
bool Task::operator<(const Task &other) const {
	return this->name_ < other.getName();
}

bool Task::operator>(const Task &other) const {
	return this->name_ > other.getName();
}

bool Task::operator==(const Task &other) const {
	return this->name_ == other.getName();
}

bool Task::operator<=(const Task &other) const {
	return this->name_ <= other.getName();
}

bool Task::operator>=(const Task &other) const {
	return this->name_ >= other.getName();
}

//destructor
Task::~Task() {}

// operator '<<'
std::ostream& operator<<(std::ostream &os, const Task &task) {
	std::string taskStr = task.getName() + " " + task.getDescription() + " " 
	+ task.getDate() + " " + task.getCategory() + " ";
	taskStr += task.getStatus() ? "on" : "off";
	os << taskStr;
	return os;
}

#endif