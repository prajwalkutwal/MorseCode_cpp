// PRJ - Console Morse Code App - 2006 - C. S. Germany
// Uses parallel arrays to convert Morse Code to ASCII and ASCII to Morse Code

//---------------------------------------------------------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

// Parallel Arrays below match ASCII characters to Morse Code Sequences
// One is an array of type char for single letters, the other an array of strings

// IMP IMP IMP IMP IMP: The Best implementation can be achieved through the use of unordered_map<string,string>

char MorseLetter[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                      'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

char *MorseCharacterSequence[] = {".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ", ".... ",
                                  ".. ", ".--- ", ".-.- ", ".-.. ", "-- ", "-. ", "--- ", ".--. ",
                                  "--.- ", ".-. ", "... ", "- ", "..- ", "...- ", ".-- ", "-..- ",
                                  "-.-- ", "--.. ", "  "};

//---------------------------------------------------------------------------------------------------------------------------

void ConvertToMorse(const char *MessageInASCII)
{
   // Note: Changed from "size_t", which is an unsigned short integer
   int i, j;
   string AccumulatedString;

   for (i = 0; MessageInASCII[i]; ++i)
   {
      // Note: The expression (sizeof ACharArray / sizeof *ACharArray) will
      // automatically calculate the length of the array, like array.length in JavaScript.
      for (j = 0; j < (sizeof MorseLetter / sizeof *MorseLetter); ++j)
      {
         if (toupper(MessageInASCII[i]) == MorseLetter[j])
         {
            AccumulatedString = AccumulatedString + MorseCharacterSequence[j];
            break;
         }
      }
   }
   cout << "\n"
        << AccumulatedString << "\n";
}

//---------------------------------------------------------------------------------------------------------------------------

void ConvertToASCII(const char *MessageInMorse)
{
   int i, j;
   string AccumulatedString;
   for (i = 0; MessageInMorse[i];)
   {
      for (j = 0; j < (sizeof MorseCharacterSequence / sizeof *MorseCharacterSequence); ++j)
      {
         // strlen() =   Returns the number of characters in string before the terminating null-character
         int MorseStringSize = strlen(MorseCharacterSequence[j]);

         // The memcmp() function compares n bytes of two regions of memory, treating each byte
         // as an unsigned character.
         if (memcmp(MorseCharacterSequence[j], &MessageInMorse[i], MorseStringSize) == 0)
         {
            // this means some corresponding char in ascii is found
            AccumulatedString = AccumulatedString + MorseLetter[j];
            i += MorseStringSize;
            break;
         } // ends if
      }
   }
   cout << "\n"
        << AccumulatedString << "\n";
}

//---------------------------------------------------------------------------------------------------------------------------

void Test()
{
   char ASCIItext[] = "Hello World";
   char MorseCode[] = ".... . .-.. .-.. ---   .-- --- .-. .-.. -.. ";

   cout << "\n\n";
   cout << "Morse Code is: ";
   ConvertToMorse(ASCIItext);
   cout << "\n\n";
   cout << "ASCII Translation is: ";
   ConvertToASCII(MorseCode);
}

//---------------------------------------------------------------------------------------------------------------------------

void GetMorse()
{
   char ASCIIPhrase[100];
   cout << "\n\nEnter an ASCII string to convert to Morse Code:\t";
   cin.ignore(); // necessary to prevent getline problems
   cin.getline(ASCIIPhrase, 100);
   ConvertToMorse(ASCIIPhrase);
}

//---------------------------------------------------------------------------------------------------------------------------

void GetASCII()
{
   char MorsePhrase[100];

   cout << "\n\nImportant: Enter a Morse string to convert to ASCII. Make sure you\n"
        << "separate each morse letter sequence with a space, separate whole words\n"
        << "with 3 spaces, and add a space at the end before pressing \"Enter\":\n\n";
   cin.ignore(); // necessary to prevent getline problems
   cin.getline(MorsePhrase, 100);
   ConvertToASCII(MorsePhrase);
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
   char choice;

   cout << "\nMorse to ASCII Converter\n\n";

   while (choice != 'q')
   {
      cout << "\n\nMorse to ASCII Converter 1.0 Menu:\n\n"
           << "(Q)uit\n"
           << "(M)orse to ASCII Conversion\n"
           << "(A)SCII to Morse Conversion\n"
           << "(T)est System\n\n";

      cin >> choice;

      switch (toupper(choice))
      {
      case 'Q':
         choice = 'q';
         break;
      case 'M':
         GetASCII();
         break;
      case 'A':
         GetMorse();
         break;
      case 'T':
         Test();
         break;
      default:
         cout << "Invalid response.";
         break;
      }
   }

   cout << "\n\nExiting program...\n\n";
   system("PAUSE");
   return 0;
}

//---------------------------------------------------------------------------------------------------------------------------
