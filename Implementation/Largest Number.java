import java.util.*; 
class longest { 
    public static void main(String[] args) { 
        try (Scanner in = new Scanner(System.in)) {
            long n = in.nextLong(); 
            long k = in.nextLong(); 
            System.out.println(maxnumber(n, k));
        } 
    } // Function to return the // largest number possible 
    static long maxnumber(long n, long k) { 
        for (long j = 0; j < k; j++) { 
            long ans = 0; long i = 1; 
            while (n / i > 0) { 
                long temp = (n / (i * 10)) * i + (n % i); i *= 10; 
                ans = Math.max(ans, temp); 
            } 
            n = ans; 
        } return n; 
    }   
}