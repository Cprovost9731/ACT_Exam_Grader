#include "Subject.cpp"
using namespace std;

/* Mobile app for IPad. Use OCR to scan an in-house Scantron / answer document with test version on it => Get studentAnswers and testNumber.
 * To add: Menu, integrate files for storing keys, organized display */


int main() {
    int testNumber, compositeScore = 0;
    string studentAnswer;

    vector<Subject> subject;
    subject.push_back(Subject("English"));  // 75 Q's
    subject.push_back(Subject("Math"));     // 60 Q's
    subject.push_back(Subject("Reading"));  // 40 Q's
    subject.push_back(Subject("Science"));  // 40 Q's

    // Testing Input - 8 Q Exam
    testNumber = 1;
    studentAnswer = "ABCDABCD-ABACABAC-ABCAABCA-BCDABCDA";
    string subjectAnswers[subject.size()];
    while(studentAnswer.find('-') != -1){                      // Turns studentAnswer into an array of substrings, each being an answer to one section of the test
        for (int i = 0; i < subject.size(); i++ ) {
            subjectAnswers[i] = studentAnswer.substr(0, studentAnswer.find_first_of('-'));
            studentAnswer = studentAnswer.substr((studentAnswer.find_first_of('-')+1));
        }
    }

    for (int i = 0; i < subject.size(); i++) {
        if (i == 0) subject[i].addAnswerKey("ABCDABCD");      // English Ans Key: "ABCD ABCD" - miss 0
        else if (i == 1) subject[i].addAnswerKey("ABACABAD"); // Math Ans Key: "ABAC ABAC" - miss 1
        else if (i == 2) subject[i].addAnswerKey("ABCAABDD"); // Reading Ans Key: "ABCA ABCA" - miss 2
        else subject[i].addAnswerKey("BCDABBBB");             // Science Ans Key: "BCDA BCDA" - miss 3
    }

    // Add answer keys, grade student answers, calculate scores
    for (int i = 0; i < subject.size(); i++) {
        subject[i].grade(testNumber, subjectAnswers[i]);
        compositeScore += subject[i].calculateScore();
        if (i == 3) compositeScore = compositeScore / 4;
    }

    // Testing Output
    for (int i = 0; i < subject.size(); i++) {
        //Format between subjects
        if (i != 0) cout << "---------------------------------------" << endl;
        // Display Subjects
        cout << "Subject #" << (i + 1) << " is: " << subject[i].getSubjectName() << endl;
        // Display student answers
        cout << "Student answers for " << subject[i].getSubjectName() << " are: " << subjectAnswers[i] << endl;
        // Display answer keys
        cout << "Answer key for " << subject[i].getSubjectName() << " is: " << subject[i].getAnswerKey(testNumber) << endl;
        // Display answer keys
        cout << "Incorrect answers for " << subject[i].getSubjectName() << " are: " << subject[i].getIsCorrect() << endl;
        // Display section score
        cout << subject[i].getSubjectName() << " score is: " << subject[i].getScore() << endl;
        // Display Composite Score
        if (i == 3) cout << "---------------------------------------" << endl << "Composite score is: " << compositeScore;
        }
    return 0;
}

