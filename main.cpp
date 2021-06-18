#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>

using namespace std;

char syntax[7] = "+-*/()";
string answer = "";

bool gotit(vector<float> a){
	return (a.size() == 1 && a[0] == 24? true:false);
}

bool dfs(vector<float> a){
	if(gotit(a)){
		cout << a[0] << endl;
		return true;
	}
	else if(a.size() > 1){
		for(int i = 0;i < (int)a.size() - 1;i++){
			for(int j = i + 1;j < (int)a.size();j++){
				vector<float> b;
				float x = a[i], y = a[j];
				for(int k = 0;k < (int)a.size();k++){
					if(k == i || k == j);
					else b.push_back(a[k]);
				}
				b.push_back(x + y);
				if(dfs(b)){
					cout << x << "+" << y << endl;
					return true;
				}
				b.pop_back();
				b.push_back(x - y);
				if(dfs(b)){
					cout << x << "-" << y << endl;
					return true;
				}
				b.pop_back();
				b.push_back(x * y);
				if(dfs(b)){
					cout << x << "*" << y << endl;
					return true;
				}
				b.pop_back();
				b.push_back(x / y);
				if(dfs(b)){
					cout << x << "/" << y << endl;
					return true;
				}
			}
		}
		return false;
	}
	else return false;
}

void solve(){
	vector<float> a;
	a.resize(4);
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	dfs(a);
}

int main(){
	while(1)solve();
	return 0;
}

