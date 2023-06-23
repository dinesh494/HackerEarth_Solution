import java.util.*;

class TestClass {

   public static void main(String args[] ) throws Exception {

       // Write your code here

       Scanner sc = new Scanner(System.in);

       int t = sc.nextInt();

       for(int i=0;i<t;i++){

           int n = sc.nextInt();

           int c01 = sc.nextInt();

           int c10 = sc.nextInt();

 

           int no_of_1_at_odd = 0;

           int no_of_0_at_odd = 0;

           int no_of_1_at_even = 0;

           int no_of_0_at_even = 0;

 

           long cost_at_odd =0;

           long cost_at_even =0;

 

           for(int j=0;j<n;j++){            

               if(j%2 != 0){

                   int k = sc.nextInt();

                   if(k == 0)

                       no_of_0_at_odd++;

                   else    

                       no_of_1_at_odd++;

               }

               else{

                   int k = sc.nextInt();

                   if(k == 0)

                       no_of_0_at_even++;

                   else    

                       no_of_1_at_even++;

               }

           }

           cost_at_odd = ((long)no_of_0_at_odd*(long)c01) + ((long)no_of_1_at_even*(long)c10);

           cost_at_even = ((long)no_of_1_at_odd*(long)c10) + ((long)no_of_0_at_even*(long)c01);

 

           System.out.println(Math.min(cost_at_odd,cost_at_even));

       }

 

   }

}

 