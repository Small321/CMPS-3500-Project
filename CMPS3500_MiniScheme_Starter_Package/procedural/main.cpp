/*
  / NAME: Henry Arinaga, Alberto Molina, Peter Uzuriaga  /
  / ASGT: CHECKPOINT 1                                  /
  / ORGN: CSUB - CMPS 3500                              /
  / FILE: main.cpp                                      /
  / DATE: 03/29/2026                                    /
*/

#include "tokenizer.h"
#include "parser.h"
#include <iostream>
#include <vector>
#include <string>

std::string read_file(const std::string& path);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./<program_name> <file_name>\n";
        return 0;
    }

    // Example of using the file loader, tokenizer, and parser together
    std::string file_location = std::string("../tests/public/") + argv[1];
    std::string source_code = read_file(file_location);

    std::vector<std::string> token_list = tokenize(source_code);
    std::vector<std::string> parsed_expression = parseTokens(token_list);

    std::cout << "Parsed result:\n";
    for (const auto& t : parsed_expression) {
        std::cout << t << "\n";
    }

    return 0;
}