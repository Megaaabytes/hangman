#include <iostream>
#include <ctime>
#include <vector>
#define null ""

using namespace std;

string GenerateUnderscores(const int wordLength)
{
    string result;

    for (int i = 0; i < wordLength; i++)
    {
        result += "_";
        result += 32;
    }

    return result;
}

int main(void)
{
    const string words[] = {null, "concatenate", "truncate", "defenestrate", "define", "procedure", "process", "success", "failure", "gamer", "made", "no", "yes", "horror", "gaming", "mega", "byte", "lucky", "space", "mango", "stupid", "crap", "game", "hang", "position", "number", "digit", "joint", "vector", "christmas", "trinitrotoluene", "kerosene", "gasoline", "see", "problems", "facetious", "anaphylaxis", "antidisestablishmentarianism", "quaternion", "gone", "itinerary", "superior", "solar"};
    int lives = 9;

    srand(time(0));

    const int chosenWord = rand() % 41 + 1;
    const int wordLength = words[chosenWord].length();
    unsigned int lettersGuessed = 0;
    const string word = words[chosenWord];

    cout << GenerateUnderscores(wordLength) << endl;

    vector<char> guessedLetters;
    vector<char> wordConcatenated;

    for(char c : word)
    {
        wordConcatenated.push_back('_');
    }

    while(lives != 0)
    {
        string input;
        cin >> input;

        if(input.length() > 1)
        {
            input = null;
            cout << "Input can only be a letter!" << endl;
        }
        else
        {
            char letter = input[0];

            vector<char> matches;
            bool gotMatch = false;
            bool letterAlreadyGuessed = false;

            for(char c : guessedLetters)
            {
                if(c == letter)
                {
                    letterAlreadyGuessed = true;
                    break;
                }
            }

            if(!letterAlreadyGuessed)
            {
                for(int i = 0; i < word.length(); i++)
                {
                    char c = word[i];

                    if(letter == c)
                    {
                        matches.push_back(letter);
                        gotMatch = true;
                        wordConcatenated[i] = c;

                        lettersGuessed++;
                        guessedLetters.push_back(letter);

                    }
                    else
                    {
                        matches.push_back(wordConcatenated[i]);
                    }
                }

                if(gotMatch)
                {
                    for (int i = 0; i < matches.size(); i++)
                    {
                        cout << matches[i] << (char)32;
                    }

                    cout << endl;
                }
                else
                {
                    gotMatch = false;
                    guessedLetters.push_back(letter);
                    lives--;
                    cout << "Incorrect guess! You have " << lives << " guesses left." << endl;
                }
            }
            else
            {
                cout << "You already guessed that letter!" << endl;
            }
        }

        if(lettersGuessed == wordLength)
        {
            cout << "Congratulations! You guessed the word." << endl;
            cout << "The word was: " << word << endl;

            exit(EXIT_SUCCESS);
        }
    }

    cout << "It appears you didnt guess the word!" << endl;
    cout << "The word was: " << word << endl;

    return 0;
}
