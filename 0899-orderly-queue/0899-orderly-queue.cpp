class Solution {
  int minStr(const string&s, int a, int b){
    int n = s.size();
    for (int i = 0; i < n; i++){
      if (s[(a + i) % n] < s[(b + i) % n]) return a;
      if (s[(a + i) % n] > s[(b + i) % n]) return b; 
    }
    return a;
  }
public:
  string orderlyQueue(string s, int k) {
    if (k > 1){
      vector<int> letters(26, 0);
      for (char c : s)
        letters[c - 'a']++;
      string ans = "";
      for (int i = 0; i < 26; i++)
        for (int j = 0; j < letters[i]; j++)
          ans += char('a' + i);
      return ans;
    }
    int min_i = 0;
    for (int i = 1; i < s.size(); i++){
      if (s[i] < s[min_i]) min_i = i;
      else if (s[i] == s[min_i]) min_i = minStr(s, min_i, i);
    }
    return s.substr(min_i) + s.substr(0, min_i);
  }
};