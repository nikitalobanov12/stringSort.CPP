// g++ -pedantic -Wall -Wextra -std=c++17 StringSort.cpp

//input/output
#include <iostream>
//to be able to use strings
#include <string>
//the random functionality is based on this
#include <ctime>
//to be able to use vectors
#include <vector>


//part 1 of the assignment
// returns a string of 16 random uppercase and lowercase letters
void random_string(std::string &s)
{
    // all the uppercase and lowercase letters in the alphabet
    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // makes the random factor truly random
    srand(time(0));
    for (int i = 0; i < 16; i++)
    {
        // picks a random number between 1 and 52 since there are 52 capital+lowercase letters in the alphabet
        int random = rand() % 52;
        // adds the random letter to the string
        s += alphabet[random];
    }
}
// this function is limited due to the fact that it randomizes based on the time value,
// if you run it twice in the same second you will get the same results
//this is not that big of an issue for this application since i do not need to run it more then once

//pt 2. sort the string with the lowercase letters coming first
void sort_string(std::string &s)
{
    // creates a vector of strings to hold the lowercase and uppercase letters
    std::vector<std::string> letters;
    // creates a string to hold the lowercase letters
    std::string lower = "";
    // creates a string to hold the uppercase letters
    std::string upper = "";
    //need to set s.length() to a variable so i do not get an error message when initializing
    int length = s.length();

    // iterates through the string
    for (int i = 0; i < length; i++)
    {
        // if the letter is lowercase
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            // add it to the lowercase string
            lower += s[i];
        }
        // if the letter is uppercase
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            // add it to the uppercase string
            upper += s[i];
        }
    }
    // add the lowercase and uppercase strings to the vector
    //the lowercase letters get pushed in first because they come first in the sorted string
    letters.push_back(lower);
    letters.push_back(upper);
    // set the string to the lowercase letters
    s = letters[0];
    // add the uppercase letters to the string
    s += letters[1];
}



int main()
{
    std::string s;
    random_string(s);
    std::cout << "the randomized string: "<< s << std::endl;
    sort_string(s);
    std::cout << "the sorted string: " << s << std::endl;
    return 0;
}

/* Sample output:
$ g++ -pedantic -Wall -Wextra -std=c++17 StringSort.cpp


$ ./a
the randomized string: sYKLsFpBfThRTgTx
the sorted string: sspfhgxYKLFBTRTT


$ ./a
the randomized string: zkGeVySfaDyBltfi
the sorted string: zkeyfayltfiGVSDB


$ ./a
the randomized string: CViJnZKPCrGtPvTE
the sorted string: inrtvCVJZKPCGPTE


$ ./a
the randomized string: JifcRbvlxTWdhIgo
the sorted string: ifcbvlxdhgoJRTWI


what happens when you run it twice in the same second:
$ ./a
the randomized string: NrYiSRxGXsdSxCDe
the sorted string: rixsdxeNYSRGXSCD

$ ./a
the randomized string: NrYiSRxGXsdSxCDe
the sorted string: rixsdxeNYSRGXSCD
*/