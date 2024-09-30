#include <iostream>
#include <vector>
#include <stdexcept>
#include <numeric> // For std::accumulate
using namespace std; 

class Stack { //create a stack 
private:
    std::vector<int> elements; //use a vectors elements to create the stack 

public:
    // Check if the stack is empty
    bool isEmpty() const { //logic for bool empty 
        return elements.empty(); //return that the stack is empty 
    }

    // Push an integer onto the stack
    void push(int value) { //use built in vector push
        elements.push_back(value);
    }

    // Pop an integer from the stack
    void pop() { //use built in vector pop function 
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty, cannot pop."); //throw the exception that the stack is empty 
        }
        elements.pop_back();
    }

    // Get the top element of the stack
    int top() const { // use built in vector top function 
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty, no top element."); //throw the expection that the vector is empty 
        }
        return elements.back();
    }

    // Calculate the average value of the stack elements
    double average() const { //create a number function to check average 
        if (isEmpty()) { //throw the vector is empty exception 
            throw std::runtime_error("Stack is empty, cannot compute average.");
        }
        double sum = std::accumulate(elements.begin(), elements.end(), 0); //calculate the sum of the numbers by adding up the value of the items 
        return sum / elements.size(); //divide the sum by the size of the stack 
    }

    // Display the stack elements (for testing purposes)
    void display() const {
        std::cout << "Stack elements: "; // print stack elements 
        for (const int& elem : elements) { //print the elements 
            cout << elem << " ";
        }
        cout << std::endl; //formatting for the display 
    }
};

int main() { //main function of the program 
    int num_1 = 0; //define 3 varibles for user inputs in the stack 
    int num_2 = 0; 
    int num_3 = 0;
    Stack stack;

    // 1) Create a stack object
    std::cout << "Stack created." << std::endl;

    // 2) Check if the stack is empty
    std::cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    // 3) Insert some integer values onto the stack
    cout << "Please insert a number to add to the stack: ";
    cin >> num_1; 
    cout << "Please insert a number to add to the stack: ";
    cin >> num_2; 
    cout << "Please insert a number to add to the stack: ";
    cin >> num_3; 

    stack.push(num_1); //push the user inputs into the stack 
    stack.push(num_2);
    stack.push(num_3);
    stack.display(); // Display the stack

    // 4) Remove an element from the stack
    stack.pop();
    stack.display(); // Display the stack after popping

    // 5) Find the top of the stack
    try {
        cout << "Top of the stack: " << stack.top() << std::endl; // print the top of the stack 
    }
    catch (const std::exception& e) { //catch the exception of if there is nothing in the stack 
        cout << e.what() << std::endl;
    }

    // 6) Find the average value of the stack elements
    try {
        cout << "Average of stack elements: " << stack.average() << std::endl; // print the average stack 
    }
    catch (const std::exception& e) { //throw the exception on if the stack is empty 
        cout << e.what() << std::endl;
    }

    return 0;
}
