#pragma once

#include "Generator.h"
#include <iostream>

class IStreamGenerator : public Generator<int>
{
private:
	std::istream& in;

public:
	/**
	* @brief
	* @param in
	*/
	IStreamGenerator(std::istream& in = std::cin);

	/**
	* @brief
	*/
	int generate() override;
};


