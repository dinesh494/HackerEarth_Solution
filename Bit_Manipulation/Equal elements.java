import java.io.BufferedReader; 
import java.io.InputStreamReader; 
import java.util.*; 
class TestClass { 
    public static void main(String args[] ) throws Exception { 
        Scanner input = new Scanner(System.in); 
        int t = input.nextInt(); 
        for(int i =0; i<t; i++){ 
            int n = input.nextInt(); 
            int a[] = new int[n]; 
            int evenCount=0; 
            int oddCount=0; 
            for(int j=0 ; j<n ; j++){ 
                a[j]= input.nextInt(); 
                if(a[j]%2==0){ evenCount++; } 
                else { oddCount++; } } 
                if(evenCount<oddCount){ 
                    System.out.println(evenCount); } 
                    else { System.out.println(oddCount); } } } }