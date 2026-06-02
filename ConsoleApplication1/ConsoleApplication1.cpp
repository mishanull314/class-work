#include <iostream>
#include <string>
#include <vector>

static const int maxCountTasks = 100;
static std::string taskList[maxCountTasks];
static int priorities[maxCountTasks];
static int statuses[maxCountTasks];
static int taskCount = 0;

void AddTask(std::string taskList[], int priorities[], int statuses[], int& taskCount) {
	std::string task;
	std::cout << "Add task: ";
	std::getline(std::cin >> std::ws, task);;
	taskList[taskCount] = task;

	std::cout << "Enter priority(1-3): ";
	int priority = -1;
	while (!(std::cin >> priority) || !(priority <= 3 && 1 <= priority)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Input error..." << std::endl;
	}
	priorities[taskCount] = priority;
	

	
	taskCount++;
	statuses[taskCount] = 0;

	std::cout << "Task has been added!" << std::endl;
}

void ShowTasks(std::string taskList[], int priorities[], int statuses[], int taskCount) {
	
	for (int i = 0; i < taskCount; i++) {
		std::cout << i + 1 << ". ";

		switch (priorities[i])
		{
		case 1:
			std::cout << "[LOW] ";
			break;

		case 2:
			std::cout << "[MEDIUM] ";
			break;

		case 3:
			std::cout << "[HIGH] ";
			break;

		default:
			break;
		}

		std::cout << taskList[i] << " ";
		
		switch (statuses[i]) {
		case 0:
			std::cout << "- In Progress" << std::endl;
			break;

		case 1:
			std::cout << "- Completed" << std::endl;
			break;
		default:
			break;
		}
	}
	if (taskCount == 0) std::cout << "There are no tasks" << std::endl;
}

void МarkСompleted(std::string taskList[], int priorities[], int statuses[], int taskCount) {
	if (taskCount > 0) {
		ShowTasks(taskList, priorities, statuses, taskCount);
		std::cout << "Choose Task: ";

		int input = -1;
		while (!(std::cin >> input) || !(1 <= input && input <= taskCount + 1)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error: Task not found" << std::endl;
		}
		input--;

		statuses[input] = 1;

		std::cout << "Task: " << taskList[input] << " Completed!" << std::endl;
	}
	else std::cout << "There are no tasks" << std::endl;
	
}

void ShowInmoptartTasks(std::string taskList[], int priorities[], int taskCount) {
	int sum = 0;
	for (int i = 0; i < taskCount; i++) if (priorities[i] == 3) sum++;
	if (sum > 0){
		for (int i = 0; i < taskCount; i++) if (priorities[i] == 3)
			std::cout << i + 1 << ". [HIGH] " << taskList[i] << std::endl;
	}
	else std::cout << "No important tasks found" << std::endl;
		

}

void ShowStatistics(std::string taskList[], int priorities[], int statuses[], int taskCount) {
	if (taskCount > 0) {
		int highCount = 0;
		for (int i = 0; i < taskCount; i++) if (priorities[i] == 3) highCount++;

		int completed = 0;
		for (int i = 0; i < taskCount; i++) if (statuses[i] == 1) completed++;

		int notCompleted = taskCount - completed;

		std::cout << "---Statistics---\nTotal tasks: " << taskCount << "\nCompleted: " << completed << "\nNot Completed: " << notCompleted << "\nImportant tasks: " << highCount << std::endl;
	}
	else std::cout << "There are no tasks" << std::endl;
	}

void DeleteTask(std::string taskList[], int priorities[], int statuses[], int& taskCount) {
	if (taskCount > 0) {
	ShowTasks(taskList, priorities, statuses, taskCount);
		std::cout << "Which task should delete?" << std::endl;

		int delTask = -1;
		while (!(std::cin >> delTask) || !(delTask <= taskCount + 1 && 1 <= delTask)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input error..." << std::endl;
		}
		delTask--;

		for (int i = delTask; i < taskCount; i++) taskList[i] = taskList[i + 1];
		taskCount--;
	}
	

}

void FindTask(std::string taskList[], int taskCount) {
	std::string searchWord = "";
	std::cout << "Enter a word: ";
	std::cin.ignore();
	std::cin >> searchWord;
	bool found = false;

	for (int i = 0; i < taskCount; ++i) {
		if (taskList[i].find(searchWord) != std::string::npos) {
			std::cout << "[" << i + 1 << "] - " << taskList[i] << "\n";
			found = true;
		}
	}

	if (!found) {
		std::cout << "Word not found";
	}
}

void СhangePriorities(std::string taskList[], int priorities[], int statuses[], int taskCount) {
	ShowTasks(taskList, priorities, statuses, taskCount);
	std::cout << "Choose Task: ";
	
	int input = -1;
	while (!(std::cin >> input) || !(1 <= input && input <= taskCount + 1)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Error: Task not found" << std::endl;
	}
	input--;

	std::cout << "Enter priority(1-3): ";
	int priority = -1;
	while (!(std::cin >> priority) || !(priority <= 3 && 1 <= priority)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Input error..." << std::endl;
	}
	priorities[input] = priority;

	std::cout << "The task priority was changed" << std::endl;

}
int main()
{
	while (true) {
		std::system("cls");

		std::cout << "---Main Menu---\n[1] - Add Task\n[2] - Show All Tasks\n[3] - Mark Completed\n[4] - Show Inmoptart Tasks\n[5] - Show Statistics\n[6] - Delete Task\n[7] - Find Task By Word\n[8] - Change Priority\n[0] - Exit" << std::endl;
		std::cout << "Input Action: ";
		int input = -1;
		while (!(std::cin >> input)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input error..." << std::endl;
		}

		switch (input)
		{
		case 0:
			return 0;

		case 1:
			AddTask(taskList, priorities, statuses,  taskCount);
			std::cin.ignore(); 
			std::cout << "To continue, press any key...";
			std::cin.get();
			break;
		
		case 2:
			ShowTasks(taskList, priorities, statuses, taskCount);
			std::cin.ignore();
			std::cout << "To continue, press any key...";
			std::cin.get();
			break;

		case 3:
			МarkСompleted(taskList, priorities, statuses, taskCount);
			std::cin.ignore();
			std::cout << "To continue, press any key...";
			std::cin.get();
			break;

		case 4:
			ShowInmoptartTasks(taskList, priorities, taskCount);
			std::cin.ignore();
			std::cout << "To continue, press any key...";
			std::cin.get();
			break;

		case 5:
			ShowStatistics(taskList, priorities, statuses, taskCount);
			std::cin.ignore();
			std::cout << "To continue, press any key...";
			std::cin.get();
			break;

		case 6:
			DeleteTask(taskList, priorities, statuses, taskCount);
			std::cin.ignore();
			std::cout << "To continue, press any key...";
			std::cin.get();
			break;

		case 7:
			FindTask(taskList, taskCount);
			std::cin.ignore();
			std::cout << "To continue, press any key...";
			std::cin.get();
			break;

		case 8:
			СhangePriorities(taskList, priorities, statuses, taskCount);
			std::cin.ignore();
			std::cout << "To continue, press any key...";
			std::cin.get();
			break;

		default:
			continue;
		}
	}
}

