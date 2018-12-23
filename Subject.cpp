#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Subject {
private:
    string subjectName, isCorrect;
    double score = 0, correctAnswer = 0, totalAnswer = 0;
    vector<string> answerKeys;                    // Trim() to rid white space | Use index to grade specific subjects

public:
    Subject(string subjectName){            // Constructor | To do: Have another variable in constructor for file path (
        this->subjectName = subjectName;
    };

    /* Returns the name of subject */
    string getSubjectName(void) {
        return subjectName;
    }

    int getTotalAnswer(void){
        return totalAnswer;
    }

    int getCorrectAnswer(void){
        return correctAnswer;
    }

    int getScore(void){
        return score;
    }

    /* For testing */
    string getIsCorrect(void){
        return isCorrect;
    }

    string getAnswerKey(int testNumber){
        return answerKeys[testNumber-1];
    }

    /* For testing: Adds answers to the key vector */
    void addAnswerKey (string answers) {
        this->answerKeys.push_back(answers);
    };

    void grade (int testNumber, string studentAnswers) {
        int index = testNumber - 1;
        string answers = answerKeys[index];
        for (int i = 0; i < studentAnswers.size(); i++) {
            totalAnswer++;
            if (studentAnswers[i] == answers[i]) {
                correctAnswer++;
                isCorrect += 'C';
            }
            else  isCorrect += 'X';
        }
    }

    /* Calculates the score of a section */
    int calculateScore(void) {
        score = tolower((correctAnswer / totalAnswer) * 36);
        return score;
    }
};

