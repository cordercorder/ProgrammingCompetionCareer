#include <cstdio>
#include <cstring>
int main()
{
	int u;
	int x,y,n;
	int num[22][22];
	scanf ("%d",&u);
	while (u--)
	{
		scanf ("%d",&n);
		memset (num,-1,sizeof(num));
		x = 1;		//1������������ 
		y = n / 2 + 1;
		for (int i = 1 ; i <= n * n ; i++)
		{
			num[x][y] = i;
			x--;		//����б����Ī�� 
			y++;
			if (x == 0 && y == n + 1)		//�����������·� 
			{
				x += 2;
				y--;
			}
			else if (num[x][y] != -1)
			{
				x += 2;
				y--;
			}
			else if (x == 0 && y != n + 1)
			{
				x = n;		//�ϳ����� 
			}
			else if (x != 0 && y == n + 1)
			{
				y = 1;		//�ҳ��� 
			}
		}
		//��� 
		for (int i = 1 ; i <= n ; i++)
		{
			for (int j = 1 ; j <= n ; j++)
			{
				printf ("%4d",num[i][j]);
			}
			printf ("\n");
		}
	}
	return 0;
}
