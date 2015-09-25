#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

vector<string> createInputVector(int charHeight);
vector<string> convertMessage(vector<string> ascii, string alpha, string line, int charHeight);
void output(vector<string> answer);

int main()
{
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
	vector<string> alphaASCIIText;
	vector<string> output;
	int intLength, intHeight;
	string width, height, textLine;

	getline(cin, intLength);
	getline(cin, intHeight);
	getline(cin, textLine);

	intLength = atoi(intLength.c_str());
	intHeight = atoi(intHeight.c_str());
	
	alphaASCIIText = createInputVector(intHeight)
	output = convertMessage(alphaASCIIText, );


	
  output(answer);
	
  return 0;
}

vector<string> createInputVector(int charHeight)
{
	vector<string> container;
	
	for(int counter = 0; counter < intHeight; ++counter)
	{
		string line;
		getline(cin, line);
		container.push_back(line);
	}
	
	return container;
}

vector<string> convertMessage(vector<string> ascii, string alpha, string line, int charHeight)
{
	vector<string> output(H, "");
	for(int counter = 0; counter < line.length(); ++counter)
	{
		char s = toupper(line[counter]);
		int index = alpha.find(s);
	
		if((s < 'A') or (s > 'Z'))
		{
			s = '?';
		}
    
		for(int j = 0; j < charHeight; ++j)
		{
			string convertedLine = ascii[j].substr(index*L, L);
			output[j] += convertedLine;
		}
	}
}

void output(vector<string> answer)
{
	for(int counter : answer)
	{
		cout << counter << endl;
	}
}
