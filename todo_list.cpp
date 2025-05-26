#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to hold task details
struct Task {
    string description;
    bool completed;
};

// Function to add a new task
void addTask(vector<Task>& tasks) {
    string taskDescription;
    cout << "Enter the task description: ";
    cin.ignore();  // To clear the input buffer
    getline(cin, taskDescription);  // Get full line of input as task description
    
    Task newTask = {taskDescription, false};  // Add task as not completed
    tasks.push_back(newTask);  // Add the task to the list
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list!" << endl;
    } else {
        cout << "\nTo-Do List:\n";
        for (int i = 0; i < tasks.size(); ++i) {
            cout << (i + 1) << ". " << tasks[i].description 
                 << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number!" << endl;
    } else {
        tasks[taskNumber - 1].completed = true;  // Mark the task as completed
        cout << "Task marked as completed!" << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number!" << endl;
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);  // Remove the task from the list
        cout << "Task removed successfully!" << endl;
    }
}

// Function to display the menu and handle user input
void displayMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<Task> tasks;  // Vector to store tasks
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
