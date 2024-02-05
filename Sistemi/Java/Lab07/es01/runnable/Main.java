
public class Main {
  
	// massimo numero di Thread
	final static int N = 3;

	public static void main(String args[]) {
		Accumulatore acc = new Accumulatore(0.0);
   
		Thread ct[] = new Thread[N];
		for (int i = 0; i < N; i++) {
			ct[i] = new Thread(new CounterThread(acc));
			ct[i].start();
		}
 
		for(int i=0; i < N; i++) {
			try {
				ct[i].join();
			} catch(InterruptedException e) {
				e.printStackTrace();
			} 
		}
	
		System.out.println("Thread MAIN accumulatore vale: " + acc.getValue());
	}
  
}