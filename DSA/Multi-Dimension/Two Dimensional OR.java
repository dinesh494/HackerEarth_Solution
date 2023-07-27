import java.util.*;
import java.lang.*;
import java.io.*;
 
public class TestClass {
    static int mod = (int)1e9+7;
		
    public static void main (String[] args) throws java.lang.Exception {
        PrintWriter out=new PrintWriter(System.out);
        FastReader sc = new FastReader();
        int testCases=1;
//		testCases=sc.nextInt();
        while(testCases-->0) {
        	int n=sc.nextInt();
			int m=sc.nextInt();
			int grid[][]=new int[n][m];
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++) grid[i][j]=sc.nextInt();
			}
			int dp[][][]=new int[32][n+1][m+1];
			for(int bit=0;bit<32;bit++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=m;j++){
						int val=grid[i-1][j-1];
						dp[bit][i][j]=dp[bit][i-1][j]+dp[bit][i][j-1]-dp[bit][i-1][j-1]+((val>>bit)&1);						
					}
				}
			}
        	
			int q=sc.nextInt();
			while(q-->0) {
				int a=sc.nextInt();
				int b=sc.nextInt();
				int c=sc.nextInt();
				int d=sc.nextInt();
				int ans=0;
				for(int i=31;i>=0;i--) {
					int bit = dp[i][c][d]-dp[i][a-1][d]-dp[i][c][b-1]+dp[i][a-1][b-1];
					if(bit>=1) ans |=(1<<i);
				}
				out.println(ans);
						
			}
        	
        	
        }
        
        out.close();
	}
    
 
 
	static class Tree{
    	int seg[];
    	int n;
    	public Tree() {
    		this.n=(int)3e5+1;
    		this.seg = new int[4*n];
    	}
    	public void update(int idx,int value) {
    		update(idx,value,0,n-1,1);
    	}
    	private void update(int dest,int value,int start,int end,int index) {
    		if(start>end) return;
    		if(start==end && dest==start) {
    			seg[index]=value;
    			return;
    		}
    		int mid=(start+end)/2;
    		if(dest>mid) update(dest,value,mid+1,end,2*index+1);
    		else update(dest,value,start,mid,2*index);
    		seg[index]=Math.max(seg[2*index], seg[2*index+1]);
    	}
    	public  int query(int l,int r) {
    		return query(l,r,0,n-1,1);
    	}
    	private int query(int l,int r,int start,int end,int index) {
    		if(start>=l && end<=r) return seg[index];
    		if(start>r || end<l ) return 0;
    		int mid=(start+end)/2;
    		int a=query(l,r,start,mid,2*index);
    		int b=query(l,r,mid+1,end,2*index+1);
    		return Math.max(a, b);
    	}
    }
    public static long power(long a,long b) {
    	long prd=1;
    	while(b>0) {
    		if(b%2==0) {
    			b/=2;
    			a=(a*a)%mod;
    		} else {
    			b--;
    			prd=(prd*a)%mod;
    		}
    	}
    	return prd;
    }
    
    static class DSU{
		int parent[];
		int rank[];
		int size[];
		public DSU(int n) {
			this.parent = new int[n];
			this.rank = new int[n];
			size=new int[n];
			for(int i=0;i<n;i++) size[i]=1;
			for(int i=0;i<n;i++) parent[i]=i;
		}
		public int find(int x) {
			if(parent[x]==x) return x;
			return parent[x]=find(parent[x]);
		}
		public boolean union(int x,int y) {
			int px = find(x);
			int py = find(y);
			if(px == py) {
				return false;
			}
			if(rank[px]>rank[py]) {
				parent[py]=px;
				size[px]+=size[py];
			}
			else if(rank[py]>rank[px]) {
				parent[px]=py;
				size[py]+=size[px];
			}
			else {
				rank[px]++;
				parent[py]=px;
				size[px]+=size[py];
			}
			return true;
 
		}
	}
	
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;
 
		public FastReader() {
			br = new BufferedReader(
					new InputStreamReader(System.in));
		}
 
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
 
		int nextInt() {
			return Integer.parseInt(next());
		}
 
		long nextLong() {
			return Long.parseLong(next());
		}
 
		double nextDouble() {
			return Double.parseDouble(next());
		}
 
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
	
 
}