#ifndef TASK_CLASS_HPP
#define TASK_CLASS_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <map>
#include <functional>

// Класс - задача

class Task {
private:
    std::string	name_;
    std::string	description_;
    std::string	date_;
    std::string	category_;
    bool		status_;
public:
    //Конструкторы
    Task(const Task &);
    Task(std::string name, std::string description, 
		std::string date, std::string category, bool status);
    
    // Гетеры и сетеры
    std::string getName() const;
    void setName(const std::string &);
    
    std::string getDescription() const;
    void setDescription(const std::string &);
    
    std::string getDate() const;
    void setDate(const std::string &);
    
    std::string getCategory() const;
    void setCategory(const std::string &);
    
    bool getStatus() const;
    void setStatus(bool);
    
	// Гет и Сет по названию парамеира
	std::string get(const std::string &key) const ;
	void set(const std::string &key, const std::string &);
	
	//Операторы
	
    //Оператор '='
    Task & operator=(const Task &);
    
    //Логические операторы сравнения
    bool operator<(const Task &) const;
    bool operator>(const Task &) const;
    bool operator==(const Task &) const;
    bool operator<=(const Task &) const;
    bool operator>=(const Task &) const;
    
    //Деструктор
    ~Task();
};

// Оператор вывода в консоль
std::ostream& operator<<(std::ostream &, const Task &);

#include "TaskClass.cpp"

#endif