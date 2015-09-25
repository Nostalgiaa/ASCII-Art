/**
 * @file ASCIIArt.cpp
 * @Codingame ASCII Art puzzle solution
 *
 * This solution receives the input and converts the string into an ASCII
 * representation of the input string
 *
 * @author Tom Williams (williamscodes)
 * @version 1.0
 */

// Include directives 
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// Function declarations
vector<string> createInputVector(vector<string> container, int charHeight);
vector<string> convertMessage(vector<string> ascii, string alpha, string line, int charLength, int charHeight);
void output(vector<string> answer, int charHeight);

int main()
{
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
	vector<string> alphaASCIIText;
	vector<string> answer;
	int intLength, intHeight;
	string width, height, textLine;

	getline(cin, width);
	getline(cin, height);
	getline(cin, textLine);

	intLength = atoi(width.c_str());
	intHeight = atoi(height.c_str());
	
	alphaASCIIText = createInputVector(alphaASCIIText, intHeight);
	answer = convertMessage(alphaASCIIText, alpha, textLine, intLength, intHeight);
	
	output(answer, intHeight);
	
  return 0;
}

 /**
 * @brief Stores the string input into the vector
 * @return vector<string> with the index set to the input height of the ASCII output
 *
 * Creates the input vector from the input line for manipulation throughout the program
 */
vector<string> createInputVector(vector<string> container, int charHeight)
{	
	for(int counter = 0; counter < charHeight; ++counter)
	{
		string line;
		getline(cin, line);
		container.push_back(line);
	}
	
	return container;
}

 /**
 * @brief Converts the input string into an ASCII output
 * @return vector<string> containing the ASCII output to be displayed
 *
 * Constructs the ASCII output based on the input created from the input vector
 */
vector<string> convertMessage(vector<string> ascii, string alpha, string line, int charLength, int charHeight)
{
	vector<string> output(charHeight, "");
	for(int counter = 0; counter < line.length(); ++counter)
	{
		char s = toupper(line[counter]);
		
	    // IF the value of s is out of bounds set value to wild card value of ?
		if((s < 'A') or (s > 'Z'))
		{
			s = '?';
		}
		// Set index to the location of s within the alpha lookup string
        int index = alpha.find(s);
        
        // FOR every element in ascii create output as converted line value and insert into output vector in index
		for(int index = 0; index < charHeight; ++index)
		{
			// Creates a string of input width and length in index
			string convertedLine = ascii[index].substr(index*charLength, charLength);
			output[index] += convertedLine;
		}
	}
	
	return output;
}

 /**
 * @brief Determines if the input is odd or even
 * @return the result of modulo division on the input
 *
 * Determines if the input is odd or even and returns the remainder of modulo division
 */
void output(vector<string> answer, int charHeight)
{
	for(int counter = 0; counter < charHeight; ++counter)
	{
		cout << answer[counter] << endl;
	}
}
