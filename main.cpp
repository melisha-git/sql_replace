#include "TaskBookClass.hpp"

int main() {
	TaskBook tasks;
	tasks.ADD("name SUPER MEGA TASK date 11.12.2022 00:00");
	tasks.ADD("name SS TASK date 13.12.2022 00:00");
	tasks.DONE("SUPER MEGA TASK");
	tasks.ADD("name ABV TASK date 13.12.2022 00:00");
	tasks.DELETE("SS TASK");
	tasks.UPDATE("name ABV TASK description MY ABV FIRST TASK date 13.12.2022 00:00");
	std::cout << "HI" << std::endl;
	return (0);
}