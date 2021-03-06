#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "FileManagerUtils.hpp"

//
// This function parses a file to get keywords' values
//
std::map<std::string, std::string> FileManagerUtils::parseFileKeyValue(const std::string &fileName,
								       std::vector<std::string> keyWords)
{
    std::string	buffer;
    std::ifstream file(fileName.c_str());
    bool findWord;
    std::map<std::string, std::string> result;

    if (!file) {
	std::cerr << "Error can not open file " << fileName << std::endl;
	return result;
    }
    file.seekg(0, std::ios::beg);
    while (getline(file, buffer, ':'))
    {
        findWord = false;

        for (unsigned int i = 0; i < keyWords.size() && !findWord; ++i)
	{
            if (buffer.compare(keyWords[i]) == 0)
	    {
                getline(file, buffer);
                buffer.erase(0, 1);
                result[keyWords[i]] = buffer;
                findWord = true;
            }
        }
        if (!findWord)
	{
            getline(file, buffer);
	}
    }
    for (std::vector<std::string>::iterator it = keyWords.begin() ; it != keyWords.end(); ++it)
    {
	if (result.find(*it) == result.end())
	    std::cerr << "Cannot find the word \"" << *it << "\" in file " << fileName << std::endl;
    }
    file.close();
    return result;
}

//
// This function create a file with write and read access
//
std::fstream *FileManagerUtils::createFile(const std::string filePath)
{
    std::fstream *file = new std::fstream(filePath.c_str(), std::ios_base::in |
    					  std::ios_base::out | std::ios_base::trunc);

    if (!file->is_open())
        std::cerr << "Error cannot create file" << std::endl;
    return file;
}
