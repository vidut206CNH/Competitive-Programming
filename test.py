from sys import stdin,stdout

input = stdin.readline
n = int(input())
l = list(map(int,input().split()))

mark = [-1]*(100005) 
# khi xet j chay tu 1->n, mark[i] la chi so cua gia tri i gan nhat voi j
ans = 10000 #khoang cach gan nhat giua 2 phan tu bang nhau
for i in range(0,n):
	if mark[l[i]] != -1:
		ans = min(ans, i - mark[l[i]]);
		mark[l[i]] = i;
	else: mark[l[i]] = i
	
if(ans != 1000000): stdout.write(str(ans))
else: stdout.write(str(-1))
