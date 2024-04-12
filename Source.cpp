#include <iostream>
#include <string>
#include <vector>
#include <map>

struct dat {
	int val;
	int sum;
};

int main() {
	using namespace std;
	vector<dat> data;
	map<int, int> values;
	long long prev, next, delt, cur, result, sum, rez_sum, rez_delt, beg_v, end_v;
	cur = 0;
	result = 0;

	dat cur_dat;
	cin >> prev;
	cin >> next;
	delt = next - prev;
	sum = delt;
	cur_dat.sum = sum;
	cur_dat.val = prev;
	data.push_back(cur_dat);
	values[delt]++;

	while (cur != -2000000000) {
		cin >> cur;
		if (cur == -2000000000) break;

		prev = next;
		next = cur;
		delt = next - prev;

		cur_dat.sum += delt;
		cur_dat.val = prev;

		data.push_back(cur_dat);
		values[delt]++;
	}

	rez_sum = data.back().sum;
	rez_delt = data.back().val - data.front().val;
	beg_v = data.front().val;
	end_v = data.back().val;
	//cout << "rez_sum:" << rez_sum << "; rez_delt:" << rez_delt << "; beg_v:" << beg_v << "; end_v:" << end_v << endl;
	//cout << "sum first:" << data.front().sum << "; val first:" << data.front().val << endl;

	if (rez_sum != rez_delt) result = 6; //6
	else if (rez_delt == 0) result = 1;//1
	else if (end_v > beg_v) {
		if (values.size() > 1) result = 3;//3 
		else result = 2;//2
	}
	else if (end_v < beg_v) {
		if (values.size() > 1) result = 5;//5 
		else result = 4;//4
	}

	switch (result) {
	case 0:cout << "wrong data"; break;
	case 1:cout << "CONSTANT"; break;
	case 2:cout << "ASCENDING"; break;
	case 3:cout << "WEAKLY ASCENDING"; break;
	case 4:cout << "DESCENDING"; break;
	case 5:cout << "WEAKLY DESCENDING"; break;
	case 6:cout << "RANDOM"; break;
	}
}