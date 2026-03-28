
#include <iostream>
#include <ctime>
using namespace std;

enum enOperationType
{
    Addition = 1,
    Subtraction = 2,
    Multiplication = 3,
    Division = 4,
    MixOp = 5
};
enum enQuestionLevel
{
    Easy = 1,
    Medium = 2,
    Hard = 3,
    MixLevel = 4
};

struct stQuestion
{
    short Number1;
    short Number2;
    enOperationType OperationType;
    enQuestionLevel QuestionLevel;
    short CorrectAnswer;
    short PlayerAnswer;
    bool AnswerResult;
};
struct stQuiz
{
    stQuestion questionList[10];
    short NumberOfQuestions = 0;
    short RightAnswersCount = 0;
    short WrongAnswersCount = 0;
    enOperationType OperationType;
    enQuestionLevel QuestionLevel;
    bool Pass;
};

int ReadPositiveNumber(string message)
{
    int number;
    do
    {
        cout << message;
        cin >> number;
    } while (number <= 0);
    return number;
}
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
short ReadNumberOfQuestions()
{
    short numberOfQuestions;
    do
    {
        numberOfQuestions = ReadPositiveNumber("Enter how many questions do you want to answer from 1 to 10 : ");
    } while (numberOfQuestions < 1 || numberOfQuestions > 10);
    return numberOfQuestions;
}
enQuestionLevel ReadQuestionsLevel()
{
    short questionsLevel;
    do
    {
        questionsLevel = ReadPositiveNumber("Enter Questions Level : [1] Easy, [2] Medium, [3] Hard, [4] Mix : ");
    } while (questionsLevel > 4 || questionsLevel < 1);
    return (enQuestionLevel)questionsLevel;
}
enOperationType ReadOperationType()
{
    short operationType;
    do
    {
        operationType = ReadPositiveNumber("Enter Operation Type : [1] Addition, [2] Subtraction, [3] Multiplication, [4] Division, [5] Mix : ");
    } while (operationType > 5 || operationType < 1);
    return (enOperationType)operationType;
}

void ChangeScreenColor(bool RightAnswer)
{
    if (RightAnswer)
        system("color 2F");
    else
        system("color 4F");
}

void ClearScreen()
{
    system("cls");
    system("color 0F");
}

char OperationTypeChar(enOperationType operationType)
{
    char arrOperationTypeChars[4] = {'+', '-', '*', '/'};
    return arrOperationTypeChars[operationType - 1];
}

string OperationTypeName(enOperationType operationType)
{
    string arrOperationTypeNames[5] = {"Addition", "Subtraction", "Multiplication", "Division", "Mix"};
    return arrOperationTypeNames[operationType - 1];
}

string QuestionLevelName(enQuestionLevel questionLevel)
{
    string arrQuestionLevelNames[4] = {"Easy", "Medium", "Hard", "Mix"};
    return arrQuestionLevelNames[questionLevel - 1];
}

short CheckQuestionAnswer(stQuestion question)
{
    switch (question.OperationType)
    {
    case enOperationType::Addition:
        return question.Number1 + question.Number2;
    case enOperationType::Subtraction:
        return question.Number1 - question.Number2;
    case enOperationType::Multiplication:
        return question.Number1 * question.Number2;
    case enOperationType::Division:
        return question.Number1 / question.Number2;
    default:
        return 0;
    }
}

bool PassOrFail(stQuiz quiz)
{
    return (quiz.RightAnswersCount > quiz.WrongAnswersCount);
}

enOperationType QuestionOperationType(stQuiz quiz)
{
    return (quiz.OperationType == enOperationType::MixOp) ? (enOperationType)RandomNumber(1, 4) : quiz.OperationType;
}

void ShowFinalResultScreen(string ResultMassage)
{
    cout << "\n\n\t\t----------------------------------------------------------------------------------\n\n";
    cout << "\t\t                             +++ Final Result is " << ResultMassage << " +++                             \n\n";
    cout << "\t\t----------------------------------------------------------------------------------\n\n";
}
void ShowWelcomeScreen()
{
    cout << "\n\n\t\t----------------------------------------------------------------------------------\n\n";
    cout << "\t\t                             +++ W e l c o m e  T o +++                             \n";
    cout << "\t\t                                  M a t h  G a m e                             \n\n";
    cout << "\t\t----------------------------------------------------------------------------------\n\n";
}
void showEndExamScreen()
{
    system("color 0F");
    cout << "\n\n\t\t----------------------------------------------------------------------------------\n\n";
    cout << "\t\t                             +++ E n d  E x a m +++                             \n\n";
    cout << "\t\t----------------------------------------------------------------------------------\n\n";
}

void CountQuestionResult(stQuiz &quiz, bool RightAnswer)
{
    if (RightAnswer)
        quiz.RightAnswersCount++;
    else
        quiz.WrongAnswersCount++;
}

bool CheckPlayNewGameAgain()
{
    char playAgain;
    do
    {
        cout << "\t\tDo you want to play again ? [Y/N] : ";
        cin >> playAgain;
    } while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'n' && playAgain != 'N');
    return (playAgain == 'n' || playAgain == 'N') ? false : true;
}

void PrintQuizFinalResult(stQuiz quiz)
{
    quiz.Pass ? system("color 2F") : system("color 4F");
    ShowFinalResultScreen(quiz.Pass ? "PASS :-)" : "FAIL :-(");
    cout << "\n\n\t\t-------------------------------- [ Game Results ] --------------------------------\n\n";
    cout << "\t\tGame Questions     : " << quiz.NumberOfQuestions;
    cout << "\n\t\tQuestions Level    : " << QuestionLevelName(quiz.QuestionLevel);
    cout << "\n\t\tOperation Type     : " << OperationTypeName(quiz.OperationType);
    cout << "\n\t\tRight Answers      : " << quiz.RightAnswersCount;
    cout << "\n\t\tWrong Answers      : " << quiz.WrongAnswersCount;
    cout << "\n\n\t\t----------------------------------------------------------------------------------\n\n";
}

void GenerateQuestionNumbersValue(stQuestion &question)
{
    switch (question.QuestionLevel)
    {
    case enQuestionLevel::Easy:
        question.Number1 = RandomNumber(1, 10);
        question.Number2 = RandomNumber(1, 10);
        break;
    case enQuestionLevel::Medium:
        question.Number1 = RandomNumber(11, 50);
        question.Number2 = RandomNumber(11, 50);
        break;
    case enQuestionLevel::Hard:
        question.Number1 = RandomNumber(51, 100);
        question.Number2 = RandomNumber(51, 100);
        break;
    default:
        question.Number1 = RandomNumber(1, 10);
        question.Number2 = RandomNumber(1, 10);
        break;
    }
}

stQuestion GenerateQuestion(stQuiz quiz)
{
    stQuestion question;
    question.OperationType = QuestionOperationType(quiz);
    if (quiz.QuestionLevel == enQuestionLevel::MixLevel)
        question.QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
    else
        question.QuestionLevel = quiz.QuestionLevel;
    GenerateQuestionNumbersValue(question);
    question.CorrectAnswer = CheckQuestionAnswer(question);
    return question;
}
void GenerateGuizQuestions(stQuiz &quiz)
{
    for (short question = 0; question < quiz.NumberOfQuestions; question++)
    {
        quiz.questionList[question] = GenerateQuestion(quiz);
    }
}

void PrintTheQuestion(short questionNumber, stQuiz &quiz)
{
    cout << "\n\nQuestion [" << questionNumber + 1 << "/" << quiz.NumberOfQuestions << "] : \n";
    cout << quiz.questionList[questionNumber].Number1 << "\n"
         << quiz.questionList[questionNumber].Number2 << " " << OperationTypeChar(quiz.questionList[questionNumber].OperationType) << "\n";
    cout << "-------------\n";
}

void PrintQuestionResult(stQuestion question)
{
    if (question.AnswerResult)
    {
        cout << "\nRight Answer :)\n";
        ChangeScreenColor(true);
    }
    else
    {
        cout << "\nWrong Answer :(\n";
        cout << "The Right Answer is : " << question.CorrectAnswer << "\n";
        ChangeScreenColor(false);
    }
}

void AskQuestion(stQuestion &question)
{
    cin >> question.PlayerAnswer;
    question.AnswerResult = (question.PlayerAnswer == question.CorrectAnswer);
}

void AskAndCorrectQuestionListAnswers(stQuiz &quiz)
{
    for (short question = 0; question < quiz.NumberOfQuestions; question++)
    {
        PrintTheQuestion(question, quiz);
        AskQuestion(quiz.questionList[question]);
        PrintQuestionResult(quiz.questionList[question]);
        CountQuestionResult(quiz, quiz.questionList[question].AnswerResult);
    }
    quiz.Pass = PassOrFail(quiz);
}

void OpenNewQuiz()
{
    stQuiz quiz;
    quiz.NumberOfQuestions = ReadNumberOfQuestions();
    quiz.QuestionLevel = ReadQuestionsLevel();
    quiz.OperationType = ReadOperationType();
    GenerateGuizQuestions(quiz);
    AskAndCorrectQuestionListAnswers(quiz);
    PrintQuizFinalResult(quiz);
}

void StartGame()
{
    bool playAgain = true;
    do
    {
        ClearScreen();
        ShowWelcomeScreen();
        OpenNewQuiz();
        playAgain = CheckPlayNewGameAgain();

    } while (playAgain);
    showEndExamScreen();
}

int main()
{
    srand((unsigned)time(0));
    StartGame();
}