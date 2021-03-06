// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	set<string> s;
	while (n--) {
		string name, status;
		cin >> name >> status;
		if (status == "enter") {
			s.insert(name);
		}
		else if(status == "leave"){
			s.erase(s.find(name));
			
		}
	}
	for (auto it = s.rbegin(); it != s.rend(); it++) {
		cout << *it << '\n';
	}
	return 0;
}
 