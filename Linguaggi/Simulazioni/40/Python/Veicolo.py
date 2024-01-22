
class Veicolo:
    
    def __init__(self, codice, targa, modello, marca, costo):
        self.codice = codice
        self.targa = targa
        self.modello = modello
        self.marca = marca
        self.costo = costo
        
    def __str__(self):
        return str(self.targa) + "\t" +str(self.codice)+"\t"+self.modello+"\t"+self.marca+"\t"+str(self.costo)+"\t"
        
               
