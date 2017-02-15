#ifndef MMYSTER_H_INCLUDED
#define MMYSTER_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

void getDico(std::vector<std::string>& dico, std::string inFile);

std::string getWord (std::vector<std::string>& dico);

std::string mix(std::string word);

void guess(std::string word, std::string newWord);

bool playAgain();

#endif // MMYSTER_H_INCLUDED