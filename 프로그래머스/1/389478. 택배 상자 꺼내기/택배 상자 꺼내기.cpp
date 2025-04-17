#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int position;
    if (((num - 1) / w) % 2 == 0)
    {
        bool flag = true;
        position = (num - 1) % w + 1;

        while (num <= n)
        {
            if (flag)
                num += (w * 2 - position * 2 + 1);
            else
                num += position * 2 - 1;

            flag = !flag;
            answer++;
        }
    }
    else
    {
        bool flag = false;
        position = w - ((num - 1) % w);

        while (num <= n)
        {
            if (flag)
                num += (w * 2 - position * 2 + 1);
            else
                num += position * 2 - 1;

            flag = !flag;
            answer++;
        }
    }
    return answer;
}