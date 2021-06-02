// 1880 单词纠错
// 1.0 秒 131,072.0 KB 5 分 1级题
// 现在大多数的文本编辑器都的单词究错功能，即你输入的单词不能够在词典中找到的话，他就会建议你修改，然后给出几个候选项。

// 现在我们就要来写一个生成候选项的算法。

// 具体算法是这样的，如果输入的单词能够在字典中找到，那么就不用推荐，否则就在字典中找那些能够通过修改一个字母得到目标单词的选项作为推荐。

// 修改一个字母包括删除一个字母，添加一个字母，以及把单词中的某个位置的字母进行替换。

#include <cstdio>
#include <cstring>

struct Word
{
	char str[21];
	int len;
}word[15001];

char can[150001][21];

int main()
{
	char s[21];
	int i, j, k, canSum, len, flg, flg1, sum = -1;
	while (scanf("%s", word[++sum].str) && strcmp(word[sum].str, "#"))
		word[sum].len = strlen(word[sum].str);
	while (scanf("%s", s) && strcmp(s, "#"))
	{
		canSum = 0;
		flg1 = 0;
		len = strlen(s);
		for (i = 0; i < sum; i++)
		{
			flg = 0, j = 0, k = 0;
			if (len - word[i].len == 1)
			{
				for (j = 0, k = 0; j < len && k < len - 1; j++)
				{
					if (s[j] != word[i].str[k])
						flg++;
					else
						k++;
				}
				if (j == k)
					flg++;
			}
			else if (len - word[i].len == -1)
			{
				for (j = 0, k = 0; j < len && k < len + 1; k++)
				{
					if (s[j] != word[i].str[k])
						flg++;
					else
						j++;
				}
				if (j == k)
					flg++;
			}
			else if (len == word[i].len)
			{
				for (int j = 0; j < len; j++)
					if (s[j] != word[i].str[j])
						flg++;
				if (flg == 0)
					break;
			}

			if (flg == 1)
				strcpy(can[canSum++], word[i].str);
		}
		if (i < sum)
			printf("%s is correct", s);
		else
		{
			printf("%s:", s);
			for (int k = 0; k < canSum; k++)
				printf(" %s", can[k]);
		}
		printf("\n");
	}
	return 0;
}



