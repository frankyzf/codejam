#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <unordered_map>
using namespace std;

string testpath = "C:/Users/tjuzf_000/workspace/codejam/testdata/";

void itemList(std::istream& istr){
    int cases, credit, itemnum, n;
    vector<int> items;
    istr >> cases;
    ofstream of(testpath+"test.out");
    for (int i = 0; i < cases; ++i) {
        istr >> credit >> itemnum;
        items.clear();
        for (int j = 0; j < itemnum; ++j) {
            istr >>n;
            items.push_back(n);
        }
        cout << "credit:" << credit << " itemnum:" << itemnum << endl ;
        vector<int> test(items);
        sort(test.begin(), test.end());
        for(auto& item: test)
            cout << item << endl;

        int k = 0, j = test.size()-1;
        int diff = numeric_limits<int>::max();
        int a = test[k], b = test[j];
        while(k < j){
            auto sum = test[k] + test[j];
            if(sum == credit){
                a = test[k];
                b = test[j];
                break;
            }
            else if(sum < credit){
                if(diff > credit - sum){
                    diff = credit - sum;
                    a = test[k];
                    b = test[j];
                }
               ++ k;
            }
            else{
                --j;
            }
        }
        cout <<"ab:" <<  a << " " <<  b << endl;
        int an = distance(items.begin(), find(items.begin(), items.end(), a))+1;
        int bn = items.size() - distance(items.rbegin(), find(items.rbegin(), items.rend(), b));
        if(an > bn){
            swap(an, bn);
        }
        of << "Case #" << i+1 << ": " << an << " " << bn << endl;

    }
}



void reverseWord(ifstream& ifstr){
    int cases;
    string buf;
    getline(ifstr, buf);
    cases = atoi(buf.c_str());

    ofstream ofstr(testpath+"test.out");
    for (int i = 0; i < cases; ++i) {
        string str;
        getline(ifstr, str);
        cout << "str:" << str << endl;
        reverse(str.begin(), str.end());
        string res;
        int pos = 0;
        while(pos != string::npos){
            auto endpos = str.find(' ', pos);
            string word;
            if(endpos == string::npos){
                word = str.substr(pos);
                pos = string::npos;
            }
            else{
                word = str.substr(pos, endpos - pos);
                pos = endpos + 1;
            }
            reverse(word.begin(), word.end());
            res += word;
            cout << " word:" << word << endl;
            res += " ";
        }
        ofstr << "Case #" << i+1 << ": " << res << endl;
    }
}



void t9spell(ifstream& ifstr){
	unordered_map<char, string> mm{ {'a', "2"}, {'b' , "22"}, {'c' , "222"}, {'d' , "3"}, {'e' , "33"}, {'f' , "333"}, {'g' ,  "4"}, {'h' ,  "44"}, {'i' ,  "444"}, {'j' ,  "5"}, {'k' ,  "55"}, {'l' ,  "555"}, {'m' ,  "6"}, {'n' ,  "66"}, {'o' ,  "666"}, {'p' ,  "7"}, {'q' ,  "77"}, {'r' , "777"}, {'s' , "7777"}, {'t' ,  "8"}, {'u' ,  "88"}, {'v' ,  "888"}, {'w' ,  "9"}, {'x' ,  "99"}, {'y' ,  "999"}, {'z' ,  "9999"}, {' ', "0"} };
    string str;
    int n;
    getline(ifstr,str);
    n = atoi(str.c_str());
	ofstream ofstr(testpath + "test.out");
	char lastch = '\01';
    for (int i = 0; i < n; ++i) {
		getline(ifstr, str);
		cout << " str:" << str;
		string res;
		for (auto ch : str) {
			if (mm[ch][0] == lastch) {
				res += " ";
			}
			res += mm[ch];
			lastch = mm[ch][mm[ch].size()-1];
		}
		cout << " res:" << res << endl;

		ofstr << "Case #" << i + 1 << ": " << res << endl;
    }
}

int main() {
    ifstream ifstr(testpath+"A-small-practice.in");
	itemList(ifstr);
    return 0;
}