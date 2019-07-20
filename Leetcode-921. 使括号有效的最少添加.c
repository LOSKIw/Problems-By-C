int minAddToMakeValid(char* S) {
	char *a = S;
	char *b[1000];
	int temp = 0, count = 0;
	while (*a != '\0')
	{
		if (*a == '(')
		{
			temp++;
		}
		else
		{
			if (temp == 0)
				count++;
			else
				temp--;
		}
		a++;
	}
	return temp + count;

}
/*
2019/3/12
一开始做的时候想的太简单，仅仅做了一个计数的方法，用左右括号差的绝对值表示，以为可行，但是相同数目的左右括号不一定是正确的书写，如“)("，因此需要重新思考。
自然运用到了这道题的归类——栈...然而不同于其他的完整的栈的结构，我们仅仅需要做的，就是记录当前剩余未被配对的左括号数目，出现右括号即配对（消去一个）或出现错误（没有剩余的未配对左括号），以此减少运行消耗。最后返回的得是错误数以及剩余未配对左括号数的和。
*/