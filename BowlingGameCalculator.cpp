/*
This is a program that calculates a bowling league’s average bowling scores. It reads input data from a file with names and scores from it.

Program Requirements:
Must use three arrays:
	a one-dimensional array to store the bowler's names.
	a (parallel) two-dimensional array to store the bowling scores.
	one-dimensional array to store the bowler's average score.

Program must contain at least the following functions:
	A function called GetBowlingData to read and store data into two arrays. The function should take as input parameters the file name
	and both empty arrays, which it should fill from the file (BowlingScores.txt   Download BowlingScores.txt)
	and return a status of either success or failure (i.e true or false).

	A function called GetAverageScore that is used to calculate the average bowling score.
	The function should take as input the populated arrays and return the average score of each bowler in a separate array.

	A function called PrettyPrintResults to output the results, i.e., bowler name, scores and average.

- Don't use Vectors or any other newfangled container, use only old school C arrays like in the book.
- Use repetition structures (loops) in your functions to perform calculations and printing. Remember "dimensions = loops". So, a 2-dimensional array will
- Don't use magic numbers. Instead use global constants at the top of the program under the includes.
- And as always include lots of meaningful comments so that I can follow your logic and know that you understand the program you wrote.
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

// const varables
const int SUBTRACT_ONE = 1;
// text
const string ANALYZING_TEXT = "Analyzing text file ";
const string UNABLE_OPEN = "Unable to open requested file.";
const string SUCCESSFUL_OPEN = "File open successfuly.";
const string DEFAULT_FILE = "BowlingScores.txt";
const string USER_PROMPT_1 = "If you wish to use the default file please type 'D' and hit enter.";
const string USER_PROMPT_2 = "Other wise enter the desired file to be used.";
const string ASKING_USERINPUT = "Please enter file name: ";
// array sizes
const int INDEX_ONE_SIZE = 10;
const int INDEX_TWO_SIZE = 5;
// numbers used for the second index of a 2d array 
const int ZERO_INDEX = 0;
const int ONE_INDEX = 1;
const int TWO_INDEX = 2;
const int THREE_INDEX = 3;
const int FOUR_INDEX = 4;
// devide amount
const int DIVIDE_TWO = 2;
const int DIVIDE_FIVE = 5;
// Header constants
const char ASTERISK_FILL = '*';
const int HEADER_WIDTH = 60;
const string WELCOME = " Bowling Average Calculator ";
// Pretty Print Constants
const int SPACE_WIDTH = 40;
const int NAME_WIDTH = 15;
const int SCORES_WIDTH = 30;
const int AVERAGE_WIDTH = 14;
const char SPACE_FILL = ' ';
const char MINUS_FILL = '-';
const char LINE_FILL = '|';
const char COLON_SYMBOL = ':';
const string NAME = "Name:";
const string SCORES = "Scores:";
const string AVERAGE = "Average:";
const string COMMA = ", ";



// function definitions
bool GetBowlingData(int bowlerS[][INDEX_TWO_SIZE], string names[INDEX_ONE_SIZE], string userInput);
void GetAverageScore(int bowlerS[][INDEX_TWO_SIZE], int bowlerA[INDEX_ONE_SIZE]);
void PrettyPrintResults(int bowlerS[][INDEX_TWO_SIZE], int bowlerA[INDEX_ONE_SIZE], string names[INDEX_ONE_SIZE]);
void HeaderDisplayer(); // Used to create the diplay the header.

int main()
{
	// stroing data from file
	string bowlerNames[INDEX_ONE_SIZE];
	int bowlerScores[INDEX_ONE_SIZE][INDEX_TWO_SIZE];
	// used to store the avrage scores.
	int bowerlsScoreAvrage[INDEX_ONE_SIZE];

	// Other varaibles
	string userInput = " ";
	bool hasFile;

	// Dsiplaying header function.
	HeaderDisplayer();

	// The user can use the defalt "BowlingScores.txt" if they press d for default
	// other wise the user can input their own Bowling Scores document.
	cout << USER_PROMPT_1 << endl;
	cout << USER_PROMPT_2 << endl << endl;
	cout << ASKING_USERINPUT;
	cin >> userInput;
	if (userInput == "d" || userInput == "D")
		userInput = DEFAULT_FILE;

	// This where GetBowlingData gets called up
	// if the function retruns false it retruns -1 to main and closes the program
	hasFile = GetBowlingData(bowlerScores, bowlerNames, userInput);
	if (hasFile == false)
	{
		return -1;
	}

	GetAverageScore(bowlerScores, bowerlsScoreAvrage);
	PrettyPrintResults(bowlerScores, bowerlsScoreAvrage, bowlerNames);

	// end of program
	system("pause");
	return 0;
}

// 
bool GetBowlingData(int bowlerS[][INDEX_TWO_SIZE], string names[INDEX_ONE_SIZE], string userInput)
{
	int index = 0;
	ifstream inFile;
	// loading file
	inFile.open(userInput);
	cout << ANALYZING_TEXT << endl;

	// checks if file is valid
	if (!inFile)
	{
		cout << UNABLE_OPEN << endl;
		system("pause");
		return false;

	}
	else
	{
		cout << SUCCESSFUL_OPEN << endl;
	}
	// getting values form file
	// While loop is used so the loop will stop till the loop reaches end of file.
	// since there was only 4 indexs in the second array index defantion I just loaded them
	// one at a time in the bowlerScores array in stead of having another loop settingling that.
	while (inFile)
	{

		inFile >> names[index];
		inFile >> bowlerS[index][ZERO_INDEX];
		inFile >> bowlerS[index][ONE_INDEX];
		inFile >> bowlerS[index][TWO_INDEX];
		inFile >> bowlerS[index][THREE_INDEX];
		inFile >> bowlerS[index][FOUR_INDEX];
		index++;
	}
	// function ends and closes file.
	inFile.close();
	return true;
}

// Grabs the 4 scores from the first idex of the Two Dimensional arrary.
void GetAverageScore(int bowlerS[][INDEX_TWO_SIZE], int bowlerA[INDEX_ONE_SIZE])
{
	// getting avrage scores
	//  did not really needed to split the varables like this from the for loop this was a remment of soultion I worked on before.
	// I did not save it so I did not put it on the bottem. But I was thinking that I might have had to do some index skipping but that was not the case.
	int indexTwo = 0;
	int indexOne = 0;

	// place holder for adding up all the scores
	int average = 0;

	// looping the first index definition
	for (indexOne = 0; indexOne < INDEX_ONE_SIZE; indexOne++)
	{
		average = 0; // resets back to zero so it wont mess up the other scores.

		for (indexTwo = 0; indexTwo < INDEX_TWO_SIZE; indexTwo++)
		{
			// adding up all the scores and keeps adding it while looping in the seccond index definition.
			average = average + bowlerS[indexOne][indexTwo];
		}

		average = average / DIVIDE_FIVE;
		bowlerA[indexOne] = average;
	}
}

// Makes a pretty console spread sheet
void PrettyPrintResults(int bowlerS[][INDEX_TWO_SIZE], int bowlerA[INDEX_ONE_SIZE], string names[INDEX_ONE_SIZE])
{
	// varibals 
	int nameLength = 0; // Used to spacing when formating when displaying the data

	string currentName, score1, score2, score3, score4, score5, scoreFormmated, scoreAverage;
	system("cls");
	HeaderDisplayer();
	// Creates to top portion of the console spread sheet 
	cout << setfill(MINUS_FILL) << setw(HEADER_WIDTH) << MINUS_FILL << endl;
	cout << setfill(SPACE_FILL) << LINE_FILL << NAME << right << setw(NAME_WIDTH - NAME.length()) << LINE_FILL
		<< SCORES << right << setw(SCORES_WIDTH - SCORES.length()) << LINE_FILL
		<< AVERAGE << right << setw(AVERAGE_WIDTH - AVERAGE.length()) << LINE_FILL << endl;

	for (int i = 0; i < INDEX_ONE_SIZE; i++)
	{
		score1 = to_string(bowlerS[i][ZERO_INDEX]);
		score2 = to_string(bowlerS[i][ONE_INDEX]);
		score3 = to_string(bowlerS[i][TWO_INDEX]);
		score4 = to_string(bowlerS[i][THREE_INDEX]);
		score5 = to_string(bowlerS[i][FOUR_INDEX]);

		// takes all 4 scores and formats them in to a single string for easy of use.
		scoreFormmated = score1 + COMMA + score2 + COMMA + score3 + COMMA + score4 + COMMA + score5 + COLON_SYMBOL;

		scoreAverage = to_string(bowlerA[i]);
		currentName = names[i];

		// makes a line of mins
		cout << setfill(MINUS_FILL) << setw(HEADER_WIDTH) << MINUS_FILL << endl;
		// formatted name score and average score.
		cout << setfill(SPACE_FILL) << LINE_FILL << currentName << right << setw(NAME_WIDTH - currentName.length()) << LINE_FILL
			<< scoreFormmated << right << setw(SCORES_WIDTH - scoreFormmated.length()) << LINE_FILL
			<< scoreAverage << right << setw(AVERAGE_WIDTH - scoreAverage.length()) << LINE_FILL << endl;
		// when the program reaches the end it makes a line at the bottom to complete the look.
		if (i == INDEX_ONE_SIZE - SUBTRACT_ONE)
			cout << setfill(MINUS_FILL) << setw(HEADER_WIDTH) << MINUS_FILL << endl << endl;
	}
}


// This function was made so i dont have to copy it mulitple times in my code it just displays the sign of the program
// at the top of the console.
void HeaderDisplayer()
{
	int welcomeLength = (HEADER_WIDTH - WELCOME.length()) / DIVIDE_TWO;

	// Header
	cout << left << setw(HEADER_WIDTH) << setfill(ASTERISK_FILL) << ASTERISK_FILL << endl;
	cout << left << setw(welcomeLength) << setfill(ASTERISK_FILL) << ASTERISK_FILL;
	cout << WELCOME;
	cout << right << setw(welcomeLength) << setfill(ASTERISK_FILL) << ASTERISK_FILL;
	cout << endl;
	cout << left << setw(HEADER_WIDTH) << setfill(ASTERISK_FILL) << ASTERISK_FILL << endl << endl;
}
