#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 4
#define MAX_LENGTH 100

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    int correctOption;
} QuizQuestion;

void displayQuestion(QuizQuestion q, int questionNumber) {
    printf("Question %d: %s\n", questionNumber + 1, q.question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int main() {
    QuizQuestion quiz[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Paris", "London", "Rome", "Berlin"}, 1},
        {"What is 2 + 2?", {"3", "4", "5", "6"}, 2},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 2},
        {"Who wrote 'To Kill a Mockingbird'?", {"Harper Lee", "Jane Austen", "Mark Twain", "J.K. Rowling"}, 1},
        {"What is the boiling point of water?", {"100°C", "90°C", "80°C", "70°C"}, 1},
    };

    int score = 0;
    int userAnswer;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        displayQuestion(quiz[i], i);
        printf("Your answer (1-4): ");
        scanf("%d", &userAnswer);
        if (userAnswer - 1 == quiz[i].correctOption) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Wrong. The correct answer is: %s\n", quiz[i].options[quiz[i].correctOption]);
        }
        printf("\n");
    }

    printf("Your final score is: %d/%d\n", score, MAX_QUESTIONS);

    return 0;
}
