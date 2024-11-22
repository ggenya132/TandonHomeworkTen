#include <iostream>
#include <string>
using namespace std;

const char SPACE = ' ';
string* createWordsArray(string sentence, int& outWordsArrSize) {
    int sizeOfNeededArray = 0;

    for (int i = 0; i < sentence.size(); i++) {
        char currentCharacter = sentence[i];
        if (currentCharacter == SPACE) {
            sizeOfNeededArray++;
        }
    }
    sizeOfNeededArray++;
    string* wordsInSentence = new string[sizeOfNeededArray];
    int currentIndexOfWordsInSentence = 0;
    int indexOfLastWordStart = 0;
    for (int i = 0; i < sentence.size(); i++) {
        char currentCharacter = sentence[i];
        if (currentCharacter == SPACE) {
            wordsInSentence[currentIndexOfWordsInSentence] =
                sentence.substr(indexOfLastWordStart, i - indexOfLastWordStart);
            indexOfLastWordStart = i + 1;
            currentIndexOfWordsInSentence++;
        }
    }
    wordsInSentence[currentIndexOfWordsInSentence] = sentence.substr(
        indexOfLastWordStart, sentence.size() - indexOfLastWordStart);

    outWordsArrSize = sizeOfNeededArray;
    return wordsInSentence;
}
int main() {
    string test = "You Can Do It";
    int numberOfWords = 0;
    string* result = createWordsArray(test, numberOfWords);

    for (int i = 0; i < numberOfWords; i++) {
        cout << *result << endl;
        result++;
    }
    delete[] result;
}