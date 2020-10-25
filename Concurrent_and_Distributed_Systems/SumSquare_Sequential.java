import java.lang.Math;
import java.util.concurrent.ThreadLocalRandom;

public class SumSquare_Sequential{
	public static void main(String args[]){

        final long startTime = System.currentTimeMillis();

    	int N = 10000000,sum = 0;
    	int[] numArray = new int[N];
    	for (int i = 0; i < N; i++){
    		numArray[i] = ThreadLocalRandom.current().nextInt(1, 5);
    	}

    	for (int value : numArray) {
        	sum += Math.pow(value,2);
    	}
    	System.out.println(sum);

        final long endTime = System.currentTimeMillis();
        System.out.println(endTime-startTime);
	}
    
}

// Time: 0.086s 
