
public class Main {
    final static int N = 5;

    public static void main(String[] args) {

        Magazzino magazzino = new Magazzino();
        Operatore op[] = new Operatore[N];

        for (int i = 0; i < N; i++) {
            op[i] = new Operatore(magazzino);
            op[i].start();
        }

        for (int i = 0; i < N; i++) {
            try {
                op[i].join();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
