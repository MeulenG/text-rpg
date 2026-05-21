#include <stdio.h>
#include <iostream>   
#include <sstream>   
#include <string>

void Run() {
    std::string sentence = "C++ is powerful";  
    std::string word;                         
    std::stringstream ss(sentence);            
    // Extract words from the stringstream one by one until no more words left
    while (ss >> word) {
        std::cout << word << std::endl;             
    }
    ss.clear();
}

void GameLoop() {
    Run();
}


int main() {
    GameLoop();
}