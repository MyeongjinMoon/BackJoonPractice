#include <string>
#include <vector>

using namespace std;

void SetInitTime(int& time)
{
	if ((time % 100) >= 50)
	{
		time += 100;
		int deleteTime = time % 100;
		int curTime = (time % 100 + 10);
		time -= deleteTime;
		time += (curTime - 60);
	}
	else
		time += 10;
}
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for (int i = 0; i < schedules.size(); i++)
    {
        SetInitTime(schedules[i]);
    }
    for (int i = 0; i < schedules.size(); i++)
    {
        int j = 0;
        for (; j < 7; j++)
        {
            if (((j + startday - 1) % 7) > 4)
                continue;
            if (timelogs[i][j] > schedules[i])
                break;
        }
        if (j == 7)
            answer++;
    }
    return answer;
}