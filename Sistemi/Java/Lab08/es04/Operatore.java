
public class Operatore extends Thread {

    private Magazzino magazzino;

    public Operatore(Magazzino mag) {
        this.magazzino = mag;
    }

    @Override
    public void run() {
        boolean bulloniExists = magazzino.doesOggettoExist("bulloni");

        if(!bulloniExists) magazzino.createOggetto("bulloni");
        
        System.out.println("Aggiungo 1000");
        magazzino.addQuantity("bulloni", 1000);
        
        System.out.println("Rimuovo 500");
        magazzino.removeQuantity("bulloni", 500);

        System.out.println(magazzino);
    }

}
