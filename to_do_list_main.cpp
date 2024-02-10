#include <iostream>
#include <vector>
#include <string>
struct Task {
    std::string description;
    bool completed;
};
class ToDoList {
private:
    std::vector<Task> tasks;
public:
    void addTask(const std::string& description) {
        Task newTask = {description, false};
        tasks.push_back(newTask);
        std::cout << "Task added successfully.\n";
    }
    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
            return;
        }
        std::cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description << " - "
                      << (tasks[i].completed ? "Completed" : "Pending") << "\n";
        }
    }
    void markTaskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task removed successfully.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};
int main() {
    ToDoList toDoList;
    int choice;

    do {
        std::cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();
                std::string description;
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                size_t index;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> index;
                toDoList.markTaskCompleted(index);
                break;
            }
            case 4: {
                size_t index;
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
                toDoList.removeTask(index);
                break;
            }
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    return 0;
}
