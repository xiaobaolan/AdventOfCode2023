#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int findFirstWordDigit(std::string currentLine, int digitPos, std::string wordDigits[]);
int findLastWordDigit(std::string currentLine, int digitPos, std::string wordDigits[]);

int main() {
    std::ifstream infile;
    std::vector<int> numberList;
    std::string wordDigits[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    infile.open("input.txt");
    std::string current_line, current_number;
    int digit_position, word_digit_number;

    while (!infile.eof()) {
        getline(infile, current_line);

        digit_position = current_line.find_first_of("1234567890");
        word_digit_number = findFirstWordDigit(current_line, digit_position, wordDigits);
        if (word_digit_number > 0) {
            current_number += std::to_string(word_digit_number);
        }
        else {
            current_number += current_line[digit_position];
        }

        digit_position = current_line.find_last_of("1234567890");
        word_digit_number = findLastWordDigit(current_line, digit_position, wordDigits);
        if (word_digit_number > 0) {
            current_number += std::to_string(word_digit_number);
        }
        else {
            current_number += current_line[digit_position];
        }
        numberList.push_back(stoi(current_number));
        current_line.clear();
        current_number.clear();
    }
    infile.close();

    int total_sum = 0;
    for (int i = 0; i < numberList.size(); i++) {
        //std::cout << numberList.at(i) << std::endl;
        total_sum += numberList.at(i);
    }

    std::cout << "Sum: " << total_sum << std::endl;
}

int findFirstWordDigit(std::string currentLine, int digitPos, std::string wordDigits[]) {
    int wordDigitPos;
    int index = -1;

    for (int i = 0; i < 9; i++) {
        wordDigitPos = currentLine.find(wordDigits[i]);
        if (wordDigitPos < digitPos && wordDigitPos != std::string::npos) {
            digitPos = wordDigitPos;
            index = i;
        }
    }

    return index + 1;
}

int findLastWordDigit(std::string currentLine, int digitPos, std::string wordDigits[]) {
    int word_digit_position;
    int index = -1;

    for (int i = 0; i < 9; i++) {
        word_digit_position = currentLine.rfind(wordDigits[i]);
        if (word_digit_position > digitPos && word_digit_position != std::string::npos) {
            digitPos = word_digit_position;
            index = i;
        }
    }

    return index + 1;
}
