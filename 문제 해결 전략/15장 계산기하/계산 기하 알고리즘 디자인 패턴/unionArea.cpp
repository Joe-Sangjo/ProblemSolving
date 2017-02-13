#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Rectangle{
	int x1, y1, x2, y2;
};
int unionArea(const vector<Rectangle>& rects){

	if(rects.empty()) return 0;

	typedef pair<int, pair<int, int> > Event;

	vector<Event> events;
	vector<int> ys;

	for(int i = 0; i < rects.size(); i++){
		ys.push_back(rects[i].y1);
		ys.push_back(rects[i].y2);
		events.push_back(Event(rects[i].x1, make_pair(1, i)));
		events.push_back(Event(rects[i].x2, make_pair(-1, i)));
	}

	sort(ys.begin(), ys.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());

	sort(events.begin(), events.end());

	int ret = 0;

	vector<int> count(ys.size() - 1, 0);
	for(int i = 0 ; i < events.size(); i++){
		int x = events[i].first, delta = events[i].second.first;
		int rectangle = events[i].second.second;

		int y1 = rects[rectangle].y1, y2 = rects[rectangle].y2;

		for(int j = 0 ; j < ys.size(); j++){
			if(y1 <= ys[j] && ys[j] < y2){
				count[j] += delta;
			}
		}

		int cutLength = 0; 

		for(int j = 0; j < ys.size() - 1 ; j++){
			if(count[j] > 0)
				cutLength += ys[j + 1] - ys[j];
		}

		if(i + 1 < events.size())
			ret += cutLength * (events[i + 1].first - x);
	}

	return ret;

}

int main(){
	freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);








	return 0;
}