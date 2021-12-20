import java.util.*;

class vi extends ArrayList<Integer> {};

public class A {
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) {
		System.out.println(new A().solve());
	}
	
	int B = in.nextInt();
	int n1 = in.nextInt();
	int n2 = in.nextInt();
	int n = 0;
	
	Integer[] Price = new Integer[n1+n2+2];
	Integer[] Value = new Integer[n1+n2+2];
	Integer[] Visited = new Integer[n1+n2+2];
	Integer[] MinPrice = new Integer[1<<B]; {
		for (int i=0; i<MinPrice.length; i++)
		MinPrice[i] = 0x3c3c3c3c;
	}
	vi[] a = new vi[n1+n2+2]; 
	
	{
		for (int i=1; i<=n1+n2; i++) {
			a[i] = new vi();
			Visited[i] = 0;
		}
	}
	
	void bfs(Integer u, int Color) {
		LinkedList<Integer> qu = new LinkedList<Integer>();
		Visited[u]=Color; qu.add(u);
		while (qu.size() != 0) {
			u = qu.poll();
			Value[u]|=Color;
			
			for (int v: a[u])
			if (Visited[v]!=Color) {
				Visited[v] = Color;
				qu.add(v);
			}
		}
	}
	
	/*void visit(int u, int Color) {
		if (Visited[u]!=null && Visited[u]==Color) return;
		Visited[u] = Color;
		Value[u] |= Color;
		for (int v: a[u])
		visit(v, Color);
	}*/
	
	int solve() {
		for (int i=0; i<B; i++) {
			for (int j=in.nextInt(); j>=1; j--) {
				int u = ++n;
				Price[u] = in.nextInt();
				Value[u] = 1<<i;
			}
		}
		for (int i=0; i<n2; i++) {
			int u = ++n;
			Price[u] = in.nextInt();
			for (int j=in.nextInt(); j>=1; j--)
				a[in.nextInt()].add(u);
			Value[u] = 0;
		}
		//for (int i=1; i<=n1; i++)
		//	visit(i, Value[i]);
		for (int i=1; i<=n1; i++)
			bfs(i, Value[i]);
		//for (int i=1; i<=n; i++)
		//	System.out.println(Price[i] + " " + Value[i] + " " + a[i]);
		for (int i=1; i<=n; i++)
			MinPrice[Value[i]] = Math.min(MinPrice[Value[i]], Price[i]);
		for (int i=0; i<(1<<B); i++)
		for (int j=0; j<(1<<B); j++)
			MinPrice[i|j] = Math.min(MinPrice[i|j], MinPrice[i] + MinPrice[j]);
		return MinPrice[(1<<B)-1];
	}
}

