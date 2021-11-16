#include "Hash.h"

Hash::Hash()
{
	this->length = 1024;
    this->table.resize(this->length);
}

Hash::Hash(int _length)
{
	this->length = _length;
    this->table.resize(this->length);
}

Hash::~Hash()
{
}

int Hash::getLength()
{
    return this->length;
}

std::vector<std::vector<std::pair<std::string, int>>> &Hash::getTable()
{
    return this->table;
}

unsigned long Hash::hashFunction(const char* s)
{
    unsigned long h = 0, high;
    while (*s)
    {
        h = (h << 4) + *s++;
        if (high = h & 0xF0000000)
            h ^= high >> 24;
        h &= ~high;
    }
    return h;
}

void Hash::Insert(std::string Key, int Value)
{
    int index = hashFunction(Key.c_str()) % this->length;

    std::pair<std::string, int> tmp;
    tmp.first = Key;
    tmp.second = Value;

    for (size_t i = 0; i < this->table.at(index).size(); i++)
    {
        if (this->table.at(index).at(i).first == Key)
        {
            this->table.at(index).at(i).second++;               // pocitani cetnosti, da se upravit pro normalni funkcnost
            return;
        }
    }

    this->table.at(index).push_back(tmp);
}

bool Hash::ContainsKey(std::string Key)
{
    int index = hashFunction(Key.c_str()) % this->length;
    
    for (size_t i = 0; i < this->table.at(index).size(); i++)
    {
        if (this->table.at(index).at(i).first == Key)
        {
            return true;
        }
    }

    return false;
}

void Hash::Remove(std::string Key)
{
    int index = hashFunction(Key.c_str()) % this->length;

    for (size_t i = 0; i < this->table.at(index).size(); i++)
    {
        if (this->table.at(index).at(i).first == Key)
        {
            this->table.at(index).erase(table.at(index).begin() + i);
            this->table.at(index).shrink_to_fit();
        }
    }
}

bool Hash::TryGetValue(std::string Key, int& Value)
{
    int index = hashFunction(Key.c_str()) % this->length;

    for (size_t i = 0; i < this->table.at(index).size(); i++)
    {
        if (this->table.at(index).at(i).first == Key)
        {
            Value = this->table.at(index).at(i).second;
            return true;
        }
    }
    
    Value = NULL;
    return false;
}

int Hash::Count()
{
    int count = 0;
    
    for (size_t i = 0; i < this->length; i++)
    {
        count += this->table.at(i).size();
    }
    
    return count;
}

int Hash::Size()
{
    return this->length;
}

double Hash::Alpha()
{
    return Count() / Size();
}
