#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int lives;

void riddleOne();
void riddleTwo();
void riddleThree();
void riddleFour();
void changes();
void endOfGameFail();
bool isNumber(string userInput);

int main() {


    string name;
    //string answerOne;

    cout << "Welcome to Riddles!" << endl;
    cout << "Please enter your name: " << endl;

    getline(cin, name);
    while (name.empty()) {
        cout << "Please enter a name that contains at least 1 character." << endl;
        getline(cin, name);
    }
    

    cout << "Hello " << name << "!" << endl;

    cout << "You will have 3 lives to answer 4 riddles. If you answer incorrectly, you will " <<
    "lose a life. You cannot regain any lost lives. Each answer will have a set of 4 " <<
    "answers for you to choose from and there is only 1 correct answer for each " <<
    "question. Here is the first riddle." << endl;

    //lives = 3;

    riddleOne();

    

    return 0;
}

void riddleOne() {
    string answerOne;
    bool correctOne = false;

    lives = 3;

    while (!correctOne && lives > 0) {
        cout << "Lives left: " << lives << endl;
        cout << "Riddle #1: " << endl; //Riddle 1
        cout << "A man is standing in front of a painting of a man, and he tells us the " <<
        "following: \"Brothers and sisters have I none, but this man's father is my father's " <<
        "son\". Who is on the painting?" << endl;
        //Answers riddle 1
        cout << "A. His father" << endl << "B. He himself" << endl << "C. His son" << endl;

        cin >> answerOne;

        if (answerOne == "A" || answerOne == "a") {
            --lives;
            correctOne = false;
            cout << "Your answer is incorrect. You have lost a life and have " << lives << " remaining. Try again!" << endl;
        }
        else if (answerOne == "B" || answerOne == "b") {
            --lives;
            correctOne = false;
            cout << "Your answer is incorrect. You have lost a life and have " << lives << " remaining. Try again!" << endl;
        }
        else if (answerOne == "C" || answerOne == "c") {
            correctOne = true;
            if (lives == 1) {
                cout << "Your answer is correct! You have " << lives << " life left and here is the next question." << endl;
            }
            else {
                cout << "Your answer is correct! You have " << lives << " lives left and here is the next question." << endl;
            }
        }
        else { //error check if user enters anything other than the answers
            cout << "Please enter either A, B, or C as an answer." << endl;
            correctOne = false;
        }
    }
    if (lives == 0) {
        endOfGameFail();
    }
    else if (lives > 0) {
        riddleTwo();
    }

    return;
}

void riddleTwo() {
    string answerTwo;
    bool correctTwo = false;

    while (!correctTwo && lives > 0) {
        cout << "Lives left: " << lives << endl;
        cout << "Riddle #2: " << endl; //Riddle 2
        cout << "If a redhouse is made of red bricks, and a yellowhouse is made of yellow " <<
        "bricks, and a bluehouse is made of blue bricks, what is a greenhouse made of? " << endl;
        //Answers riddle 2
        cout << "A. Glass" << endl << "B. Green Bricks" << endl << "C. Wood" << endl;

        cin >> answerTwo;

        if (answerTwo == "A" || answerTwo == "a") { //Correct Answer
            correctTwo = true;
            if (lives == 1) {
                cout << "Your answer is correct! You have " << lives << " life left and here is the next question." << endl;
            }
            else {
                cout << "Your answer is correct! You have " << lives << " lives left and here is the next question." << endl;
            }
        }
        else if (answerTwo == "B" || answerTwo == "b") {
            --lives;
            correctTwo = false;
            cout << "Your answer is incorrect. You have lost a life and have " << lives << " remaining. Try again!" << endl;
        }
        else if (answerTwo == "C" || answerTwo == "c") {
            --lives;
            correctTwo = false;
            cout << "Your answer is incorrect. You have lost a life and have " << lives << " remaining. Try again!" << endl;
        }
        else { //error check if user enters anything other than the answers
            cout << "Please enter either A, B, or C as an answer." << endl;
            correctTwo = false;
        }
    }
    if (lives == 0) {
        endOfGameFail();
    }
    else if (lives > 0) {
        riddleThree();
    }

    return;
}

void riddleThree() {
    string answerThree;
    bool correctThree = false;

    while (!correctThree && lives > 0) {
        cout << "Lives left: " << lives << endl;
        cout << "Riddle #3: " << endl; //Riddle 3
        cout << "10 fish are in a tank! " << endl << " 2 drown, 4 swim away, and 3 die" << endl <<
        "How many are left? Enter a number." << endl;

        cin >> answerThree;

        if (isNumber(answerThree) == false) {
            correctThree = false;
            cout << "Please enter a valid integer number." << endl;
        }
        else if (answerThree == "10") { 
            correctThree = true;
            if (lives == 1) {
                cout << "Your answer is correct! You have " << lives << " life left and here is the next question." << endl;
            }
            else {
                cout << "Your answer is correct! You have " << lives << " lives left and here is the next question." << endl;
            }
        }
        else {
            --lives;
            correctThree = false;
            cout << "Your answer is incorrect. You have lost a life and have " << lives << " remaining. Try again!" << endl;
        }
    }
    if (lives == 0) {
        endOfGameFail();
    }
    else if (lives > 0) {
        riddleFour();
    }

    return;
}

void riddleFour() {
    string answerFour;
    bool correctFour = false;

    while (!correctFour && lives > 0) {
        cout << "Lives left: " << lives << endl;
        cout << "Riddle #4: " << endl; //Riddle 4
        cout << "What five-letter word becomes shorter when you add two letters to it? " << endl;

        cin >> answerFour;

        if (isNumber(answerFour) == false) {
            for (int i = 0; i < answerFour.size(); ++i) {
                answerFour[i] = tolower(answerFour[i]);
            }
        }

        if (answerFour == "short") { //Correct Answer
            correctFour = true;
            if (lives == 1) {
                cout << "Your answer is correct!" << endl;
            }
            else {
                cout << "Your answer is correct!" << endl;
            }
        }
        else {
            --lives;
            correctFour = false;
            cout << "Your answer is incorrect. You have lost a life and have " << lives << " remaining. Try again!" << endl;
        }
    }
    if (lives == 0) {
        endOfGameFail();
    }
    else if (lives > 0) {
        wonGame();
    }

    return;
}

void wonGame() {

    if (lives == 1) {
        cout << "Congratulations! You have beat the game with " << lives << " life remaining." << endl;
    }
    else {
        cout << "Congratulations! You have beat the game with " << lives << " lives remaining." << endl;
    }

    return;
}

bool isNumber(string userInput) {
    for (int i = 0; i < userInput.size(); ++i) {
        if (isdigit(userInput[i]) == false) {
            return false;
        }
    }

    return true;
}

//if user fails to answer all the riddles within 3 lives
void endOfGameFail() {

    string tryAgain;

    cout << "You lost all your lives before answering all the riddles. " << endl; 
    cout << "Would you like to try again (y/n)?" << endl;

    cin >> tryAgain;
    if (tryAgain == "y") {
        riddleOne();
    }
    else if (tryAgain == "n") {
        exit(0);
    }
    else {
        cout << "Please enter y or n as your answer." << endl;
    }

    return;
}