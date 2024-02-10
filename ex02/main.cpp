#include "MutantStack.tpp"



int main() {
    MutantStack<int> mstack;
    std::cout << "Pushing elements onto the stack..." << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    
    std::cout << "Iterating through the stack:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    
    MutantStack<int> copiedStack = mstack;
    std::cout << "Copied stack size: " << copiedStack.size() << std::endl;

    
    MutantStack<int> assignedStack;
    assignedStack = mstack;
    std::cout << "Assigned stack size: " << assignedStack.size() << std::endl;

    
    MutantStack<int> emptyStack;
    std::cout << "Empty stack size: " << emptyStack.size() << std::endl;
    if (!emptyStack.size()) {
        std::cout << "Stack is empty as expected." << std::endl;
    }

    std::cout << "Iterating in reverse (simulated):" << std::endl;
    if (!mstack.empty()) {
        for (MutantStack<int>::iterator it = --mstack.end(); it != --mstack.begin(); --it) {
            std::cout << *it << std::endl;
            if (it == mstack.begin()) break; // Prevents infinite loop
        }
    }

    std::stack<int> s(mstack);
    std::cout << "Standard stack created from MutantStack, size: " << s.size() << std::endl;

    return 0;
}


// main from the subject
// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << "top: " << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << "size: " << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }