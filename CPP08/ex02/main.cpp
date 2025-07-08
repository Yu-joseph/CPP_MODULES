#include "MutantStack.hpp"

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl; // should be 17
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl; //should be 1
// 	mstack.push(3); //*
// 	mstack.push(5); //*
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		// std::cout << "******" << *it << std::endl;
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

// 5 3 5 737 0
// #include <iostream>
// #include <string>
// #include "MutantStack.hpp"

int main()
{
	// Subject's test
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "\nIterating stack:\n";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	std::stack<int> s(mstack); // Test conversion

	// Extra tests 🔽

	// std::cout << "\n🔁 Reverse iteration:\n";
	// for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
	// 	std::cout << *rit << std::endl;

	std::cout << "\n Const iteration:\n";
	const MutantStack<int> constStack = mstack;
	for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit)
		std::cout << *cit << std::endl;

	// std::cout << "\n Testing with strings:\n";
	MutantStack<std::string> strStack;
	strStack.push("hello");
	strStack.push("world");
	for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
		std::cout << *it << std::endl;

	// std::cout << "\n Testing with empty stack:\n";
	MutantStack<double> emptyStack;
	std::cout << "Empty? " << (emptyStack.empty() ? "Yes" : "No") << std::endl;

	return 0;
}


// 5
// 3
// 5