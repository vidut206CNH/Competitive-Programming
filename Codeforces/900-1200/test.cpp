n = int(input())
cnt = 0;
int i=1;
while i*i<=n:
	if n%i==0:
		cnt += 2
		if i*i==n: cnt -= 1
	i+=1
print(cnt)