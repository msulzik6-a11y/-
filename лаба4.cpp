#include <iostream>


// ЗАДАЧА А


char* my_strrchr(const char* string, int c) {
    const char* last = nullptr;

    while (*string != '\0') {
        if (*string == (char)c) {
            last = string;
        }
        string++;
    }

    if ((char)c == '\0') {
        return (char*)string;
    }

    return (char*)last;
}


// ЗАДАЧА В


bool hasAllUniqueChars(const char* start, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (start[i] == start[j]) {
                return false;
            }
        }
    }
    return true;
}

void findFirstWordWithUniqueChars(const char* str) {
    int i = 0;
    
    while (str[i] != '\0') {
        while (str[i] == ' ') {
            i++;
        }

        if (str[i] == '\0') {
            break;
        }

        int start = i;

        while (str[i] != '\0' && str[i] != ' ') {
            i++;
        }

        int length = i - start;

        if (hasAllUniqueChars(&str[start], length)) {
            std::cout << "First word with unique characters: ";
            for (int k = 0; k < length; k++) {
                std::cout << str[start + k];
            }
            std::cout << std::endl;
            return;
        }
    }

    std::cout << "No matching word found." << std::endl;
}



int main() {
    
    std::cout << "TASK A" << std::endl;
    
    char taskABuffer[301];
    char target;

    std::cout << "Enter a string for Task A: ";
    std::cin.getline(taskABuffer, 301);

    std::cout << "Enter a character to search for: ";
    std::cin >> target;

    std::cin.ignore(10000, '\n');

    char* result = my_strrchr(taskABuffer, target);

    if (result != nullptr) {
        std::cout << "String: \"" << taskABuffer << "\"" << std::endl;
        std::cout << "Last occurrence of '" << target << "' found at index: " 
                  << (result - taskABuffer) << std::endl;
    } else {
        std::cout << "Character '" << target << "' not found." << std::endl;
    }

    std::cout << "TASK B " << std::endl;
    
    char taskBBuffer[301];
    std::cout << "Enter a string (up to 300 characters): ";
    std::cin.getline(taskBBuffer, 301);

    findFirstWordWithUniqueChars(taskBBuffer);

    return 0;
}