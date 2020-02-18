#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string s, word, max_word;
    int max_count = 1;
    unordered_map<string, int> count;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++)
    {
        if(isalnum(s[i]))
        {
            word += tolower(s[i]);
        }
        if(!isalnum(s[i]) || i == s.size() - 1)
        {
            if(word.size() != 0)
            {
                count[word]++;
                if(count[word] > max_count)
                {
                    max_word = word;
                    max_count = count[word];
                }
                else if(count[word] == max_count)
                {
                    max_word = min(word, max_word);
                }
            }
            word = "";
        }
    }
    cout << max_word << " " << max_count << endl;
}