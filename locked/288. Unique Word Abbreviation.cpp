/*
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/

class ValidWordAbbr {
public:
    unordered_set<string> dict;
    unordered_map<string, int> hash;
    string Abbreviation(string s) {
        int len = s.size();
        if (len <= 2) return s;
        return s[0] + to_string(len - 2) + s[len - 1];
    }
    ValidWordAbbr(vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end());
        vector<string>::iterator iter =
        unique(dictionary.begin(), dictionary.end());
        dictionary.erase(iter, dictionary.end());
        hash.clear();
        dict.clear();
        for (string s : dictionary) {
            dict.insert(s);
            hash[Abbreviation(s)]++;
        }
    }
    
    bool isUnique(string word) {
        int n = hash[Abbreviation(word)];
        if (dict.find(word) == dict.end()) {
            return n < 1;
        } else {
            return n <= 1;
        }
    }
};

// Time:  ctor:   O(n), n is number of words in the dictionary.
//        lookup: O(1)
// Space: O(k), k is number of unique words.

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (string& word : dictionary) {
            const string abbr = abbreviation(word);
            lookup_[abbr].emplace(word);
        }
    }
    
    bool isUnique(string word) {
        const string abbr = abbreviation(word);
        return lookup_[abbr].empty() ||
        (lookup_[abbr].count(word) == lookup_[abbr].size());
    }
    
private:
    unordered_map<string, unordered_set<string>> lookup_;
    
    string abbreviation(const string& word) {
        return word.front() + to_string(word.length()) + word.back();
    }
};

// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");