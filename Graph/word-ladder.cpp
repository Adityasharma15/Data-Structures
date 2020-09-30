// 127. Word Ladder

// A simple bfs solution
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
      unordered_set<string> dict(wordList.begin(), wordList.end());
      queue<string> words;
      words.push(beginWord);
      int transformations = 1;

      while(!words.empty())
      {
         int size = words.size();

         for(int i = 0; i<size; i++) {
         string word = words.front();
         words.pop();
         // we will not traverse to this again
         dict.erase(word);

         if(word == endWord)
             return transformations;

         for(int i = 0; i<word.size(); i++) {
              char orig = word[i];

              for(int j = 0; j<26; j++)
              {
                  word[i] = 'a' + j;

                  if(dict.find(word) != dict.end())
                    words.push(word);
              }

             word[i] = orig;
           }
         }

          transformations++;
      }

      return 0;
    }
};
