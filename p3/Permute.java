/*  Permute.java
    Uses recursion to generate all possible permutations of a list.
*/

import java.io.*;

public class Permute {
    private static int size;
    private static int [] list;
    private static int count;
    
    public static void main(String [] args) {
        if(args.length != 1) {
            System.out.println(
            "Usage:  java Permute N");
            System.exit(1);
            }
        size = Integer.parseInt(args[0]);
        count = 0;
        list = new int[size];
        for(int i=0; i < size; i++)
            list[i] = i+1;
            
        permute(0,size-1);
        System.out.println("Called permute " + count + " times");
        }
        
    private static void permute(int first, int last) {   
        if(first == last) { 
            count++;
            for(int i=0; i <= last; i++)
                System.out.print(list[i] + " ");
            System.out.println();
            }
        else {
            for(int i=first; i <= last; i++) {
                swap(first,i);     
                permute(first+1,last);            
                swap(first,i);
            }
        }
    }
    
    private static void swap(int a, int b) {
        int tmp = list[a];
        list[a] = list[b];
        list[b] = tmp;
        }
}            
