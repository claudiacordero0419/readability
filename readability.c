#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int calc_number_of_letters(string);
int calc_number_of_words(string);
int calc_number_of_sentences(string);


int main(void)
{


    string get_paragraph = get_string("type in paragraph: ");
    int letters = calc_number_of_letters(get_paragraph);
    int words = calc_number_of_words(get_paragraph);
    int sentences = calc_number_of_sentences(get_paragraph);


    float avg_letters = ((float)letters / words) * 100;
    float avg_sentences = ((float)sentences / words) * 100;

    double formula = (0.0588 * avg_letters) - (0.296 * avg_sentences) - (15.8);
    formula = round(formula);

    if (formula < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (formula > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        formula = floor(formula);
        printf("Grade %d\n", (int)formula);
    }
}

int calc_number_of_letters(string text)
{
    int n = strlen(text);
    int letter_count = 0;
    for(int i = 0; i < n; i++)
    {
         if (isalpha(text[i]))
         {
            letter_count++;
         }
    }
    return letter_count;
}

int calc_number_of_words(string space)
{
    int n = strlen(space);
    int word_count = 1;
    for(int i = 0; i < n; i++)
    {
        if (space[i] == ' ')
        {
            word_count++;
        }

    }
    return word_count;
}


int calc_number_of_sentences(string punctuation)
{
    int n = strlen(punctuation);
    int sentence_count = 0;
    for(int i = 0; i < n; i++)
    {
        if(punctuation[i] == '!'|| punctuation[i] == '.'|| punctuation[i] == '?')
        {
            sentence_count++;
        }


     }
    return sentence_count;

}


