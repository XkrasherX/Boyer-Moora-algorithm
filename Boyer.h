#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Boyer_Moore {
private:
    std::string text;
    std::string pattern;
    std::vector<int> stop_sign;

    void badCharHeuristic()
    {
        for (int i = 0; i < (int)pattern.length(); i++)
            stop_sign[(int)pattern[i]] = i;
    }

    void search()
    {
        int m = pattern.size();
        int n = text.size();

        
        int shift_x = 0; //the shift of the pattern with
        // respect to text
        while (shift_x <= (n - m))
        {
            int j = m - 1;

            /* Keep reducing index j of the pattern while
            characters of the pattern and text are
            matching at this shift s */
            while (j >= 0 && pattern[j] == text[shift_x + j])
                j--;

            /* If the pattern is present at the current
            shift, then index j will become -1 after
            the above loop */
            if (j < 0)
            {

                /* Shift the pattern so that the next
                character in the text aligns with the last
                occurrence of it in the pattern.
                The condition s+m < n is necessary for
                the case when the pattern occurs at the end
                of the text */
                shift_x += (shift_x + m < n) ? m - stop_sign[text[shift_x + m]] : 1;
            }
            else
            {
                /* Shift the pattern so that the bad character
                in the text aligns with the last occurrence of
                it in the pattern. The max function is used to
                make sure that we get a positive shift.
                We may get a negative shift if the last
                occurrence of the bad character in the pattern
                is on the right side of the current
                character. */
                shift_x += std::max(1, j - stop_sign[text[shift_x + j]]);
            }
        }
    }

public:
    Boyer_Moore(std::string text, std::string pattern) {
        this->text = text;
        this->pattern = pattern;
        stop_sign.assign(pattern.length(), -1);
        badCharHeuristic();
    }

    //геттери
    std::string getText() const { return text; }
    std::string getPattern() const { return pattern; }
    std::vector<int> getStopSign() const { return stop_sign; }
};





















//#define NO_OF_CHARS 256
//
//
//
//// The preprocessing function for Boyer Moore's
//// bad character heuristic
//void badCharHeuristic(const string& str, int size, int badchar[NO_OF_CHARS])
//{
//    // Initialize all occurrences as -1
//    for (int i = 0; i < NO_OF_CHARS; i++)
//        badchar[i] = -1;
//
//    // Fill the actual value of last occurrence
//    // of a character
//    for (int i = 0; i < size; i++)
//        badchar[(int)str[i]] = i;
//}
//
///* A pattern searching function that uses Bad
//Character Heuristic of Boyer Moore Algorithm */
//void search(const string& txt, const string& pat)
//{
//    int m = pat.size();
//    int n = txt.size();
//
//    int badchar[NO_OF_CHARS];
//
//    /* Fill the bad character array by calling
//    the preprocessing function badCharHeuristic()
//    for the given pattern */
//    badCharHeuristic(pat, m, badchar);
//
//    int s = 0; // s is the shift of the pattern with
//    // respect to text
//    while (s <= (n - m))
//    {
//        int j = m - 1;
//
//        /* Keep reducing index j of the pattern while
//        characters of the pattern and text are
//        matching at this shift s */
//        while (j >= 0 && pat[j] == txt[s + j])
//            j--;
//
//        /* If the pattern is present at the current
//        shift, then index j will become -1 after
//        the above loop */
//        if (j < 0)
//        {
//
//            /* Shift the pattern so that the next
//            character in the text aligns with the last
//            occurrence of it in the pattern.
//            The condition s+m < n is necessary for
//            the case when the pattern occurs at the end
//            of the text */
//            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
//        }
//        else
//        {
//            /* Shift the pattern so that the bad character
//            in the text aligns with the last occurrence of
//            it in the pattern. The max function is used to
//            make sure that we get a positive shift.
//            We may get a negative shift if the last
//            occurrence of the bad character in the pattern
//            is on the right side of the current
//            character. */
//            s += max(1, j - badchar[txt[s + j]]);
//        }
//    }
//}