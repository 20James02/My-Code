import java.util.Scanner;

public class test {
     public static void main(String[] args) {
          Scanner nhap = new Scanner(System.in);
          int a = nhap.nextInt();
          for (int i = 1; i <= a; i++) {
               if (a % i == 0) 
                    System.out.print(i + " ");     
          }
          
     } 
}
