#include "Hash.h"

int main()
{
    std::cout << "Hello World!\n";

    Hash* hashTable = new Hash();

    std::string line;
    std::ifstream rfile;

    rfile.open("words.txt");

    if (rfile.is_open()) 
    {
        while (std::getline(rfile, line)) 
        {
            hashTable->Insert(line, 1);
        }
        rfile.close();
    }

    std::ofstream f;
    f.open("output.txt");

    for (size_t i = 0; i < hashTable->getLength(); i++)
    {
        for (size_t j = 0; j < hashTable->getTable().at(i).size(); j++)
        {
            f << hashTable->getTable().at(i).at(j).first << " " << hashTable->getTable().at(i).at(j).second << std::endl;
            //std::cout << hashTable->getTable().at(i).at(j).first << " " << hashTable->getTable().at(i).at(j).second << std::endl;
        }
    }
    std::cout << hashTable->Count();

    f.close();

    //hashTable->Insert("n", 15);
    //hashTable->Insert("na", 15);
    //hashTable->Insert("nah", 15);

    //int val;
    //int count = hashTable->Count();
    //bool neco = hashTable->TryGetValue("na", val);

    //std::cout << std::endl << count << neco <<  val << std::endl;

    //hashTable->Remove("na");

    //count = hashTable->Count();
    //neco = hashTable->TryGetValue("na", val);

    //std::cout << std::endl << count << neco << val << std::endl;
}
