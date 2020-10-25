import java.lang.Math;
import java.util.concurrent.ThreadLocalRandom;
import java.lang.Thread;

public class SumSquare_Concurrent{
	public static void main(String args[]){
        final long startTime = System.currentTimeMillis();

    	int N = 10000000,sum = 0;
    	int[] numArray = new int[N];
    	for (int i = 0; i < N; i++){
    		numArray[i] = ThreadLocalRandom.current().nextInt(1, 5);
    	}

    	sum = sum(numArray);
    	System.out.println(sum);

        final long endTime = System.currentTimeMillis();
        System.out.println(endTime-startTime);
	}

    public static int sum(int[] numArray) {
        // Create two "summers" to run as separate threads
        halfSum leftSum = new halfSum(numArray, 0);
        halfSum rightSum = new halfSum(numArray, 1);
        Thread leftThread = new Thread(leftSum);
        Thread rightThread = new Thread(rightSum);
        
        // Run the threads
        leftThread.start();
        rightThread.start();
        
        // Wait for the threads to finish
        try {
            leftThread.join();
            rightThread.join();
        } catch (InterruptedException ie) {}
        
        // Combine the results of the two threads
        int left  = leftSum.getSum();
        int right = rightSum.getSum();
        return left + right;
    }
}

class halfSum implements Runnable{

    int[] numArray;
    int half,sum = 0;

    public void run(){
        if (this.half == 0){
            for(int i = 0; i < numArray.length / 2; i++){
                sum += Math.pow(this.numArray[i],2);
            }
        }else{
            for(int i = numArray.length / 2; i < numArray.length; i++){
                sum += Math.pow(this.numArray[i],2);
            }
        }
    }

    public halfSum(int[] numArray,int half){
        this.numArray = numArray;
        this.half = half;
    }

    public int getSum(){
        return this.sum;
    }
}

// Time: 0.074s
