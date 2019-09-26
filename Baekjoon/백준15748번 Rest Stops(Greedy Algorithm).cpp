#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool compare(pair<long long, long long> a, pair<long long, long long> b);

int main() {

	long long L, N, rate_farmer, rate_bessie, spot, tastiness;
	long long max_tastiness = 0;
	vector<pair<long long, long long> >spot_tastiness;

	scanf("%lld %lld %lld %lld", &L, &N, &rate_farmer, &rate_bessie);

	for (int i = 0; i < N; i++) {
		scanf("%lld %lld", &spot, &tastiness);
		spot_tastiness.push_back(make_pair(spot, tastiness));
	}
	
	sort(spot_tastiness.begin(), spot_tastiness.end(), compare);
	
	//for(int i = 0; i < N; i++) {
	//    cout << spot_tastiness[i].first << spot_tastiness[i].second << endl;
	//}

	int now = 0;
	for (int i = 0; i < N; i++) {
		if (spot_tastiness[i].first > now) {
			max_tastiness += spot_tastiness[i].second*(rate_farmer*(spot_tastiness[i].first - now) - rate_bessie*(spot_tastiness[i].first - now));
			now = spot_tastiness[i].first;
		}
	}

	cout << max_tastiness << endl;
	//printf("%lld\n", max_tastiness);
}

bool compare(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}