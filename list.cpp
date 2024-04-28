#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>
#include <algorithm>

std::vector<std::string> line_to_vector( std::string line)
{
    std::stringstream ss(line);
    std::vector<std::string> words;
    std::string word;

    while(std::getline(ss, word, ' '))
    {
        words.push_back(word);
    }
    return words;
}

int main()
{
    std::vector<std::vector<std::string>> list;
    std::fstream file;
    file.open("list.txt");
    std::string line;
    std::map<std::vector<std::string>, int> combinationCounts;
    std::map<std::string, int> products;

    while(std::getline(file, line))
    {
        list.push_back(line_to_vector(line));
    }

    for(int j = 0; j < list.size(); j++)
    {
        for(int i = 0; i < list[j].size(); i++)
        {
            products[list[j][i]] += 1;
        }
    }


    for(std::map<std::string,int>::iterator it = products.begin(); it != products.end(); it++)
    {
        float ratio = (float((it->second)) / float((list.size())));
        int ratio2 = ratio * 100;
        std::cout << it->first << " " << std::setprecision(2) << ratio2 << "%";
        std::cout << '\n';
    }

    return 0;
}