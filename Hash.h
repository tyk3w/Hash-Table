#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <stdint.h>
#include <fstream>

#pragma once
class Hash
{
private:
	int length;
	std::vector<std::vector<std::pair<std::string, int>>> table;

public:
	Hash();
	Hash(int _length);
	~Hash();
	int getLength();
	std::vector<std::vector<std::pair<std::string, int>>> &getTable();
	unsigned long hashFunction(const char* s);
	void Insert(std::string Key, int Value);
	bool ContainsKey(std::string Key);
	void Remove(std::string Key);
	bool TryGetValue(std::string Key, int& Value);
	int Count();
	int Size();
	double Alpha();
};
