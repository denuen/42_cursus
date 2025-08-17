#include "PmergeMe.hpp"
#include <iostream>
#include <set>
#include <sstream>

PmergeMe::PmergeMe() : vec(), lst(), vecTime(0.0), listTime(0.0) {
}

PmergeMe::PmergeMe(const std::string& input)
	: vec(), lst(), vecTime(0.0), listTime(0.0) {

	if (input.empty())
		throw std::runtime_error("Error: input must be non-empty.");
	std::istringstream iss(input);
	std::string		   strValue;
	std::set<int>	   seen;
	char*			   endptr;
	long			   value;

	while (iss >> strValue) {
		errno = 0;
		value = std::strtol(strValue.c_str(), &endptr, 10);
		if (endptr == strValue.c_str() || *endptr != '\0' || errno == ERANGE
			|| value < 0 || value > std::numeric_limits<int>::max()) {
			throw std::runtime_error("Error: invalid input value: " + strValue);
		} else if (seen.find(value) == seen.end()) {
			seen.insert(static_cast<int>(value));
			vec.push_back(static_cast<int>(value));
			lst.push_back(static_cast<int>(value));
		}
	}
}

PmergeMe::PmergeMe(const PmergeMe& p)
	: vec(p.vec), lst(p.lst), vecTime(p.vecTime), listTime(p.listTime) {
}

PmergeMe& PmergeMe::operator=(const PmergeMe& p) {
	if (this != &p) {
		vec		 = p.vec;
		lst		 = p.lst;
		vecTime	 = p.vecTime;
		listTime = p.listTime;
	}
	return (*this);
}

void PmergeMe::sortVector() {



}

void PmergeMe::sortList() {



}

void PmergeMe::setVector(const std::vector<int>& v) {
	if (v.empty()) {
		throw std::runtime_error("Error: cannot assign vector to "
								 "PmergeMe::vec. Vector must be non-empty");
	}

	std::vector<int> tmp;
	std::set<int>	 seen;

	for (size_t i = 0; i < v.size(); i++) {
		if (v.at(i) < 0) {
			throw std::runtime_error(
				"Error: cannot assign vector to PmergeMe::vec. Vector numbers "
				"must be non-negative");
		}
		if (seen.find(v.at(i)) == seen.end()) {
			tmp.push_back(v.at(i));
			seen.insert(v.at(i));
		}
	}
	vec = tmp;
}

void PmergeMe::setList(const std::list<int>& l) {
	if (l.empty()) {
		throw std::runtime_error("Error: cannot assign list to PmergeMe::lst. "
								 "List must be non-empty");
	}
	std::list<int>::const_iterator end = l.end();
	std::list<int>				   tmp;
	std::set<int>				   seen;

	for (std::list<int>::const_iterator i = l.begin(); i != end; i++) {
		if (*i < 0) {
			throw std::runtime_error(
				"Error: cannot assign list to PmergeMe::lst. List numbers must "
				"be non-negative");
		}
		if (seen.find(*i) == seen.end()) {
			tmp.push_back(*i);
			seen.insert(*i);
		}
	}
	lst = tmp;
}

void PmergeMe::printVector() {

	size_t size = vec.size();

	if (!size) {
		throw std::runtime_error("Error: cannot display empty containers.");
	}

	for (size_t i = 0; i < size; i++) {
		std::cout << vec.at(i) << " ";
	}
}

void PmergeMe::printList() {

	std::list<int>::const_iterator end = lst.end();

	if (lst.empty()) {
		throw std::runtime_error("Error: cannot display empty containers.");
	}

	for (std::list<int>::const_iterator i = lst.begin(); i != end; i++) {
		std::cout << *i << " ";
	}
}

void PmergeMe::reset() {
	vec.clear();
	lst.clear();
	vecTime = listTime = 0.0;
}

PmergeMe::~PmergeMe() {
}
