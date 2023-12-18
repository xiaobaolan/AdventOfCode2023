#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>
int main()
{
    int total_sum = 0;
    std::string line;
    std::ifstream text_file ("day_one.txt");
    std::vector<std::string> file_content;
    if (text_file.is_open()) {
        while (getline(text_file, line)) {
            file_content.push_back(line);
            //std::cout << line << std::endl;
            //find first digit
            char first_digit = ' ';
            char last_digit = ' ';
            for (int i = 0; i < line.size(); i++) {
                if (std::isdigit(line[i])) {
                    first_digit = line[i];
                    break;
                }
            }
            //find last digit 
            for (int i = line.size(); i >= 0; i--) {
                if (std::isdigit(line[i])) {
                    last_digit = line[i];
                    break;
                }
            }
            std::string number;
            number += first_digit;
            number += last_digit;
            total_sum += std::stoi(number);
        }
    }
    else {
        std::cout << "Unable to open file.";
    }
    std::cout << "The total sum is: " << total_sum;
    text_file.close();
}
