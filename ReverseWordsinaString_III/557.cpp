class Solution
{
public:
  string reverseWords(string s)
  {
    std::istringstream iss(s);
    std::vector<std::string> words;

    std::string word;
    while (iss >> word)
    {
      std::reverse(word.begin(), word.end());
      words.push_back(word);
    }

    std::string result;
    for (const std::string &w : words)
    {
      result += w + ' ';
    }

    if (!result.empty())
    {
      result.pop_back();
    }
    
    return result;
  }
};