#ifndef TASK_CLASS_CPP
#define TASK_CLASS_CPP

#include "TaskClass.hpp"

//Конструкторы

Task::Task(std::string name = std::string(), std::string description = std::string(), 
		std::string date = std::string(), std::string category = std::string(), bool status = false) :
		name_(name), description_(description), date_(date), category_(category), status_(status) {
		}
	
Task::Task(const Task &other) {
	*this = other;
}

// Гетеры и сетеры
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

// Гет по ключевому названию параметра
std::string Task::get(const std::string &key) const {
	return key == "name" ? getName() : key == "description" ? getDescription() : 
	key == "date" ? getDate() : key == "category" ? getCategory() : std::string();
}

// Сет по ключевому названию параметра
void Task::set(const std::string &key, const std::string &word) {
	return key == "name" ? setName(word) : key == "description" ? setDescription(word) : 
	key == "date" ? setDate(word) : setCategory(word);
}

//Операторы

//Оператор копирования
Task& Task::operator=(const Task &other) {
	this->name_ = other.getName();
	this->description_ = other.getDescription();
	this->date_ = other.getDate(); 
	this->category_ = other.getCategory();
	this->status_ = other.getStatus();
	return *this;
}

//Логические операторы сравнения
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

//Деструктор
Task::~Task() {}

//Оператор вывода в консоль
std::ostream& operator<<(std::ostream &os, const Task &task) {
	os.width(20);
	os << task.getName() << "|";
	os.width(20);
	os << task.getDescription() << "|";
	os.width(20);
	os << task.getDate() << "|";
	os.width(20);
	os << task.getCategory() << "|";
	os.width(20);
	if (task.getStatus())
		os << "on" << "|";
	else
		os << "off" << "|";
	return os;
}

#endif