/**
 * @file 290.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-21
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/word-pattern/
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution
{
public:
  bool wordPattern(string pattern, string s)
  {
    unordered_map<char, string> charToWord;
    unordered_map<string, char> wordToChar;
    istringstream iss(s);
    string word;
    int i = 0;
    while (iss >> word)
    {
      if (i == pattern.length())
      {
        return false;
      }
      char currentChar = pattern[i];
      if (charToWord.find(currentChar) == charToWord.end() && wordToChar.find(word) == wordToChar.end())
      {
        charToWord[currentChar] = word;
        wordToChar[word] = currentChar;
      }
      else if (charToWord[currentChar] != word || wordToChar[word] != currentChar)
      {
        return false;
      }
      i++;
    }
    return i == pattern.length();
  }
};
