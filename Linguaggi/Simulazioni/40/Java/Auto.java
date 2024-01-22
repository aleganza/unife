public class Auto extends Veicolo {
    protected int cilindrata;
    protected double capienza;

    public Auto(int codice, String targa, String modello, String marca, double costo, int cilindrata, double capienza) {
        super(codice, targa, modello, marca, costo);
        this.cilindrata = cilindrata;
        this.capienza = capienza;
    }

    public String toString() {
        return "automobile\t"
               +super.toString()+"\t"
               +this.cilindrata+"\t"
               +this.capienza+"\t-\t-\t-\t";
    }
}
