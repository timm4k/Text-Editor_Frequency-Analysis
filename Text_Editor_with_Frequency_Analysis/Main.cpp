#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

class TextProcessor {
public:
    TextProcessor(const std::string& inputText) : text(inputText) {}

    void replaceWord(const std::string& target, const std::string& replacement) {
        size_t pos = 0;
        while ((pos = text.find(target, pos)) != std::string::npos) {
            text.replace(pos, target.length(), replacement);
            pos += replacement.length();
        }
    }

    void capitalizeSentences() {
        bool capitalizeNext = true;
        for (char& ch : text) {
            if (capitalizeNext && std::isalpha(ch)) {
                ch = std::toupper(ch);
                capitalizeNext = false;
            }
            if (ch == '.' || ch == '!' || ch == '?') {
                capitalizeNext = true;
            }
        }
    }

    std::unordered_map<char, int> countCharacterFrequency() const {
        std::unordered_map<char, int> frequencyMap;
        for (char ch : text) {
            if (std::isalpha(ch)) {
                frequencyMap[std::tolower(ch)]++;
            }
        }
        return frequencyMap;
    }

    int countDigits() const {
        int digitCount = 0;
        for (char ch : text) {
            if (std::isdigit(ch)) {
                digitCount++;
            }
        }
        return digitCount;
    }

    void displayResults() const {
        std::cout << "Processed text:\n" << text << "\n\n";
        std::cout << "Character frequency:\n";
        auto frequencyMap = countCharacterFrequency();
        for (const auto& pair : frequencyMap) {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
        std::cout << "Digit count: " << countDigits() << "\n";
    }

private:
    std::string text;
};

int main() {
    std::string inputText;
    std::cout << "Enter text: ";
    std::getline(std::cin, inputText);

    std::string targetWord, replacementWord;
    std::cout << "Enter word to replace: ";
    std::getline(std::cin, targetWord);
    std::cout << "Enter new word: ";
    std::getline(std::cin, replacementWord);

    TextProcessor processor(inputText);

    processor.replaceWord(targetWord, replacementWord);

    processor.capitalizeSentences();

    processor.displayResults();

    return 0;
}
