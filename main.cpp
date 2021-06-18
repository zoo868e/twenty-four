#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>

using namespace std;

char syntax[7] = "+-*/()";
string answer = "";

class num{
	public:
		int up;
		int down;
		num(int up, int down):up{up},down{down}{}
		num(int val):num(val, 1){}
		~num()=default;
		friend ostream& operator<<(ostream& o, const num& x){
			if(x.down != 1)
				o << "(" << x.up << "/" << x.down << ")";
			else
				o << x.up ;
			return o;
		}
};
bool gotit(vector<num> a){
	if(a[0].up % a[0].down)return false;
	else if(a.size() > 1)return false;
	else if(a[0].up / a[0].down != 24)return false;
	else return true;
}


bool dfs(vector<num> a){
/*	cout << a.size() << endl;
	cout << "this turn a : ";
	for(int i = 0;i < (int)a.size();i++){
		cout << a[i] << " ";
	}
	cout << endl;
*/
	for(int i = 0;i < (int)a.size();i++){
		if(a[i].up % a[i].down);
		else {
			a[i].up = a[i].up / a[i].down;
			a[i].down = 1;
		}
	}
	if(a.size() == 1){
		if(gotit(a)){
//			cout << a[0] << endl;
			return true;
		}
		else return false;
	}
	else if(a.size() > 1){
		for(int i = 0;i < (int)a.size();i++){
			for(int j = 0;j < (int)a.size();j++){
				if(j == i)continue;
				vector<num> b;
				num x = a[i], y = a[j];
				for(int k = 0;k < (int)a.size();k++){
					if(k == i || k == j);
					else b.push_back(a[k]);
				}
				bool flag = false;
				if(x.up * y.down + x.down * y.up != 0){
					b.push_back(num(x.up * y.down + x.down * y.up, x.down * y.down));
					flag = true;
				}
				if(dfs(b)){
					cout  << "do this! " << x << "+" << y << endl;
					return true;
				}
				if(flag){
					b.pop_back();
				}
				flag = false;
				if(x.up * y.down - x.down * y.up != 0){
					b.push_back(num(x.up * y.down - x.down * y.up, x.down * y.down));
					flag = true;
				}
				if(dfs(b)){
					cout << "do this! " << x << "-" << y << endl;
					return true;
				}
				if(flag){
					b.pop_back();
				}
				b.push_back(num(x.up * y.up, x.down * y.down));
				if(dfs(b)){
					cout  << "do this! " << x << "*" << y << endl;
					return true;
				}
				b.pop_back();
				b.push_back(num(x.up * y.down, x.down * y.up));
				if(dfs(b)){
					cout  << "do this! " << x << "/" << y << endl;
					return true;
				}
			}
		}
		return false;
	}
	else return false;
}

void solve(){
	vector<num> a;
	int t;
	for(int i = 0;i < 4;i++){
		cin >> t;
		a.push_back(num(t));
	}
	if(!dfs(a))cout << "I can't calculate an answer.\n";
}

int main(){
	while(1)solve();
	return 0;
}

