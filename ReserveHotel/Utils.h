#pragma once
#include <string>
#include <iostream>
class Utils
{
public:
	template<typename T>
	static T UserChoice(const std::string _msg);
};

template<typename T>
T Utils::UserChoice(const std::string _msg)
{
	T _input;
	std::cout << _msg << std::endl;
	std::cin >> _input;
	return _input;
}
