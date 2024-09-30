#pragma once
#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <numeric>
#include <iostream>

class Stack {
private:
    std::vector<int> elements;

public:
    // Check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Push an integer onto the stack
    void push(int value) {
        elements.push_back(value);
    }

    // Pop an integer from the stack
    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty, cannot pop.");
        }
        elements.pop_back();
    }

    // Get the top element of the stack
    int top() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty, no top element.");
        }
        return elements.back();
    }

    // Calculate the average value of the stack elements
    double average() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty, cannot compute average.");
        }
        double sum = std::accumulate(elements.begin(), elements.end(), 0);
        return sum / elements.size();
    }

    // Display the stack elements (for testing purposes)
    void display() const {
        std::cout << "Stack elements: ";
        for (const int& elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

#endif // STACK_H
