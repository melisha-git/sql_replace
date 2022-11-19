#include "TaskBookClass.hpp"

int main() {
	TaskBook tasks;
	tasks.ADD("name SS TASK date 11.12.2022 00:00");
	tasks.ADD("name SS date 13.12.2022 00:00");
	//tasks.DONE("SUPER MEGA TASK");
	tasks.ADD("name ABV TASK date 13.12.2022 00:00");
	//tasks.UPDATE("name ABV description MY ABV FIRST TASK date 13.12.2022 00:00");
	tasks.SELECT("name = SS TASK and date = 11.12.2022 00:00");
	tasks.SELECT("name =SS TASK and date= 11.12.2022 00:00");
	tasks.SELECT("name like TASK and date like 00:00");
	tasks.DELETE("SS TASK");
	//std::cout << "HI" << std::endl;
	return (0);
}