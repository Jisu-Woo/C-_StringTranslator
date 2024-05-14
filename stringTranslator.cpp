#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	int n;
	cin >> n;

	string str[101];
	int cnt = 0;


	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}


	for (int i = 0; i < n; i++) { 
		//바뀐 부분을 세는 카운터
		cnt = 0;
		string tempstr;

		for (int j = 0; j < str[i].length(); j++) {
			if (int(str[i].at(j)) >= 97 && int(str[i].at(j)) <= 122) {
				tempstr += str[i][j];

				continue;
			}
			else if (str[i].at(j) == '\\') {
				if (str[i].at(j + 1) == '\'' && j+1 < str[i].length()) {
					tempstr += 'v';
					//다음칸은 건너뛰기
					j++;

				}
				else {
					tempstr += 'w';
					//다다음칸까지 건너뛰기
					j += 2;
				}
				
			
				cnt++;
			}
			else {
				switch (str[i].at(j)) {
				case '@':
					tempstr += 'a';
					break;
				case '[':
					tempstr += 'c';
					break;
				case '!':
					tempstr += 'i';
					break;
				case ';':
					tempstr += 'j';
					break;
				case '^':
					tempstr += 'n';
					break;
				case '0':
					tempstr += 'o';
					break;
				case '7':
					tempstr += 't';
					break;
				default:
					break;
				}
				cnt++;
			}

		}
		if (cnt == 0) {
			cout << str[i] << endl;
		}
		else if(float(cnt) >= str[i].length() / 2.0) {
			cout << "I don't understand" << endl;
		}
		else {
			cout << tempstr << endl;
		}	
	}

	return 0;

}
