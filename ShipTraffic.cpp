#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
main() 
{
  int Lanes, Width, Earliest_Time, Latest_Time;
  double Speed_of_Ships, Speed_of_Ferry;
  cout<<"Enter number of Lanes,Width of each lane,Speed_of_ship,Speed_of_ferry,EarliestTime,LatestTime:\n";
  while (cin >> Lanes >> Width >> Speed_of_Ships >> Speed_of_Ferry >> Earliest_Time >> Latest_Time)
	{
    		vector<pair<double, int> > v;
    		v.push_back(make_pair(Earliest_Time, 0));
    		v.push_back(make_pair(Latest_Time, 0));
    		for (int i = 0; i < Lanes; i++) 
		{
      	char ch;
	cout<<"Enter Bounding Directions of Ship along with Length and Position of ship on single Line for "<<Lanes<<" Lanes:\n";
      	int M, L, P;
      	cin >> ch >> M;
      	for (int j = 0; j < M; j++)
 			{
        			cin >> L >> P;
        			if (ch == 'W') P = -P;
      			v.push_back(make_pair(-P/Speed_of_Ships - Width*(i+1)/Speed_of_Ferry, 1));
     				v.push_back(make_pair(-(P-L)/Speed_of_Ships - Width*i/Speed_of_Ferry, -1));
     			 }
    		  }
    sort(v.begin(), v.end());
    double ret = 0.0;
    int cur = 0;
    for (int i = 0; i < v.size(); i++) 
	{
      cur += v[i].second;
      if (cur == 0 && v[i].first >= Earliest_Time && v[i].first < Latest_Time) {
        ret = max(ret, v[i+1].first-v[i].first);
     	 }
    }
    assert(ret > 0.101);
    printf("Largest Gap In Straight Traffic for a safe crossing is :"); 
    printf("%.3lf\n", ret);
  }
}

