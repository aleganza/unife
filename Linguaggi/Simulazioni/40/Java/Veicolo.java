public class Veicolo {
    protected int codice;
    protected String targa;
    protected String modello;
    protected String marca;
    protected double costo;

    public Veicolo(int codice, String targa, String modello, String marca, double costo) {
        this.codice = codice;
        this.targa = targa;
        this.modello = modello;
        this.marca = marca;
        this.costo = costo;
    }

    public String toString() {
        return this.targa+"\t"+
               this.codice+"\t"+
               this.modello+"\t"+
               this.marca+"\t"+
               this.costo;
    }
}
