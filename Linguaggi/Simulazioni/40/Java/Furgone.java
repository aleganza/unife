public class Furgone extends Veicolo {
    protected String categoria;
    protected int posti;
    protected boolean vano;

    public Furgone(int codice, String targa, String modello, String marca, double costo, String categoria, int posti, boolean vano) {
        super(codice, targa, modello, marca, costo);
        this.categoria = categoria;
        this.posti = posti;
        this.vano = vano;
    }

    public String toString() {
        return "commerciale\t"
               +super.toString()+"\t-\t-\t"
               +this.categoria+"\t"
               +this.posti+"\t"
               +this.vano+"\t";
    }
}
