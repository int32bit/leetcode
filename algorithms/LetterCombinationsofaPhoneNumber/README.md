## Letter Combinations of a Phone Number

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
![](keypad.png)
```
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
```
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

## Solution

```cpp
class Solution {
	public:
		Solution() {
			map['2'] = "abc";
			map['3'] = "def";
			map['4'] = "ghi";
			map['5'] = "jkl";
			map['6'] = "mno";
			map['7'] = "pqrs";
			map['8'] = "tuv";
			map['9'] = "wxyz";
		}
		vector<string> letterCombinations(string digits) {
			vector<string> result;
			if (digits.size() == 0) {
				return result;
			}
			for (char c : digits) {
				result = generate(result, c);
			}
			return result;
		}
		vector<string> generate(vector<string> current, char digit) {
			vector<string> result;
			if (current.size() > 0) {
				for (char c : map[digit]) {
					for_each(current.begin(), current.end(), [&result, c](string s){result.push_back(s + c);});
				}
			} else {
				for (char c : map[digit])
					result.push_back(string() + c);
			}
			return result;
		}
	private:
	    unordered_map<char, string> map;
};
```
