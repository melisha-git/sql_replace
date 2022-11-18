#include "TaskBookClass.hpp"

int main() {
	/*Task task("first");
	task.setDescription("My first task");
	Task task2(task);
	std::cout << task2 << std::endl;*/
	TaskBook tasks;
	tasks.ADD("name SUPER MEGA TASK date 11.12.2022 00:00");
	tasks.ADD("name SS TASK date 13.12.2022 00:00");
	tasks.DONE("SUPER MEGA TASK");
	tasks.ADD("name ABV TASK date 13.12.2022 00:00");
	tasks.DELETE("SS TASK");
	std::cout << "HI" << std::endl;
	return (0);
}