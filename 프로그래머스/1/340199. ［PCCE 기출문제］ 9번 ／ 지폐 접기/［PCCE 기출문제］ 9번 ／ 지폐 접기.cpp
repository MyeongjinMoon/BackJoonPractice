#include <string>
#include <vector>

using namespace std;

bool CheckHorizontal(vector<int> wallet, vector<int> bill)
{
	if (wallet[0] >= bill[0])
		if (wallet[1] >= bill[1])
			return true;
	return false;
}
bool CheckVertical(vector<int> wallet, vector<int> bill)
{
	if (wallet[0] >= bill[1])
		if (wallet[1] >= bill[0])
			return true;
	return false;
}
void FoldBill(vector<int>& bill)
{
	if (bill[0] > bill[1])
		bill[0] /= 2;
	else
		bill[1] /= 2;
}
int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int x, y;
    
    while (!(CheckHorizontal(wallet, bill) || CheckVertical(wallet, bill)))
    {
        FoldBill(bill);
        answer++;
    }
    
    return answer;
}