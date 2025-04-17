#include <string>
#include <vector>

using namespace std;
int StringToInt(string str)
{
	int temp = 0;
	temp += (str[0] - '0') * 600;
	temp += (str[1] - '0') * 60;
	temp += (str[3] - '0') * 10;
	temp += (str[4] - '0');

	return temp;
}
void IsInOP(int& time, int op_start, int op_end)
{
	if (time >= op_start && time <= op_end)
		time = op_end;
}
void IsLessThanZero(int& time)
{
	if (time < 0)
		time = 0;
}
void IsBiggerThanVideoLen(int& time, int video_len)
{
	if (time >= video_len)
		time = video_len;
}
void ChangeTimeToString(int time, string& answer)
{
	answer[0] = time / 600 + '0';	time %= 600;
	answer[1] = time / 60 + '0';	time %= 60;
	answer[2] = ':';
	answer[3] = time / 10 + '0';	time %= 10;
	answer[4] = time + '0';
}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int video_len_I, pos_I, op_start_I, op_end_I;
    video_len_I = StringToInt(video_len);
    pos_I = StringToInt(pos);
    op_start_I = StringToInt(op_start);
    op_end_I = StringToInt(op_end);

    IsInOP(pos_I, op_start_I, op_end_I);

    for (int i = 0; i < commands.size(); i++)
    {
        string temp = commands[i];

        if (temp == "next")
        {
            pos_I += 10;
            IsBiggerThanVideoLen(pos_I, video_len_I);
        }
        else if (temp == "prev")
        {
            pos_I -= 10;
            IsLessThanZero(pos_I);
        }

        IsInOP(pos_I, op_start_I, op_end_I);
    }

    string answer;
    answer.resize(5);
    ChangeTimeToString(pos_I, answer);
    return answer;
}