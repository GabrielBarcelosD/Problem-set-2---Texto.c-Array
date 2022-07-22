#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int letterscount = 0;
    int wordcount = 1;
    int sentencecount = 0;


    for (int i = 0; i < strlen(text); i++)
    {
       if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
       {
           letterscount++;
       }
       else if (text[i] == ' ')
       {
           wordcount++;
       }
       else if (text[i] == '.' || text[i] == '!' || text[i] == '?' || text[i] == '=')
       {
           sentencecount++;
       }
       
    }
            printf("letras: %i; palavras: %i; sentencas: %i\n", letterscount, wordcount, sentencecount);
            
            
             float calculation = (0.0588 * letterscount / wordcount * 100) - (0.296 *  sentencecount / wordcount  * 100) - 15.8; 
    int index = round(calculation);  
    
     if (index < 1)   
    {
        printf("Before Grade 1\n");  
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");  
    }
    else
    {
        printf("Grade %i\n", index); 
    }
}
            

