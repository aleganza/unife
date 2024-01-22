public class Noleggio {
    protected String targa;
    protected int giorni;
    protected double costo;

    public Noleggio(String targa, int giorni, double costo) {
        this.targa = targa;
        this.giorni = giorni;
        this.costo = costo;
    }

    public double getCostoNoleggio() {
        return this.costo * this.giorni;
    }

    public String toString() {
        return "("+this.targa+" "+this.giorni+")";
    }
}
