public class LFCounterAlgo
{
	public static void main(String[] args) {
		int counterTemp = 0;
		for(;;) {
			System.out.println(counterTemp + " temp");
			counterTemp = updateCounter(counterTemp);
		}
	}

	public static int updateCounter(int previousCounter) {
    	if(previousCounter < 1) {
      		return ++previousCounter;
     	}
     	else {
    	  return 0;
    	}
    }
}

