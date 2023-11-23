#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;

struct People
{
	int arriveTime;
	int processTime;
	People(int aa = 0, int pp = 0)
	{
		arriveTime = aa;
		processTime = pp;
	}
};

int main()
{
	int num, wins;
	cin >> num;
	vector<People>peoples(num);
	
	for(int i = 0; i < num; ++i)
	{
		cin >> peoples[i].arriveTime >> peoples[i].processTime;
	}
	cin >> wins;
	vector<int> lastTime(wins);  // 存放i号窗口目前最后的时间
	vector<queue<People>> queues(wins); // 第i队列对应第i号窗口
	int maxWaitTime = -1, totalWaitTime = 0;
	for(int i = 0; i < num; ++i)
	{
		int done = 0;
		for(int j = 0; j < wins; ++j)
		{
			if(queues[j].empty())
			{
				queues[j].push(peoples[i]);
				lastTime[j] = peoples[i].arriveTime + peoples[i].processTime;
				done = 1;
				break;
			}
		}
		if(done)              // 有空闲窗口，直接插入
			continue;
		for(int j = 0; j < wins; ++j)
		{
			if(lastTime[j] <= peoples[i].arriveTime)
			{
				queues[j].push(peoples[i]);
				lastTime[j] = peoples[i].arriveTime + peoples[i].processTime;
				queues[j].pop();
				done = 1;
				break;
			}
		}
		if(done)              // 有窗口已经处理完成，无须等待
			continue;
		int currWindow = 0;       // 判断哪个窗口等待时间短
		for(int j = 1; j < wins; ++j)
		{
			if(lastTime[currWindow] > lastTime[j])
				currWindow = j;
		}
		int waitTime = lastTime[currWindow] - peoples[i].arriveTime;
		maxWaitTime = max(maxWaitTime, waitTime);
		totalWaitTime += waitTime;
		queues[currWindow].push(People(peoples[i].arriveTime, peoples[i].processTime + lastTime[currWindow]));
		queues[currWindow].pop();
		lastTime[currWindow] += peoples[i].processTime;
	}
	int ans = 0;
	for(int i = 0; i < wins; ++i)
		ans = max(ans, lastTime[i]);
	cout << fixed << setprecision(1) 
		<< totalWaitTime * 1.0 / num << ' '
		<< maxWaitTime << ' '
		<< ans << endl;
	return 0;
}