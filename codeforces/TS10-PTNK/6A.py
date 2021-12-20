a,b = map(int,input().split())


# Function to find HCF the Using Euclidian algorithm
def lcm(x, y):   
	res = x*y
	while(y):
		x, y = y, x % y
	return int(res/x)
ans = int(lcm(a,b) - (a+b));
print(str(ans))