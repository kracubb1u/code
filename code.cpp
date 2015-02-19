package test;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;
import java.util.Arrays;

public final class EXAMPLE {
	static class Circle implements Comparable {
		int x;
		long y;
		float z;
		
		Circle(int x,long y, float z){
			this.x = x;
			this.y = y;
			this.z = z;
		}
		
		@Override
		public int compareTo(Object arg0) {
			Circle another = (Circle) arg0;
			
			if(another.x < x && another.y < y && another.z  < z){
				return 1;
			}
			
			if(another.x > x && another.y > y && another.z  > z){
				return -1;
			}
			
			return 0;
		}
		
	}
	public static void main(String args[]) throws IOException {
		Circle a = new Circle(1,2L,1.00001F);
		Circle b = new Circle(10,10000000L,13.03232323f);
		
		Circle mas[] = new Circle[]{b,a};
		
		
		
		System.out.println(" b == mas[0] == " + (mas[0] == b) + ", a == mas[1] " + (mas[1] == a) );
		
		Arrays.sort(mas);
		
		System.out.println(" b == mas[0] == " + (mas[0] == b) + ", a == mas[1] " + (mas[1] == a) );
	}

}
