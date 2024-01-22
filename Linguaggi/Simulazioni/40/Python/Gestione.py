import argparse

from Veicolo import Veicolo
from Auto import Auto
from Furgone import Furgone
from Cliente import Cliente
from Noleggio import Noleggio

class Gestione:
    def __init__(self, arg):
        self._arg = arg
        
    def main(self):
        veicoli = []
        clienti = []
        codiceTarga = {}
        codiceCosto = {}
        
        try:
            f = open("veicoli.txt");
            line = f.readline().strip()
            
            while(line != ''):
                tok = line.split()
                codice = int(tok[0])
                tipo = tok[1]
                targa = tok[2]
                
                modello = f.readline().strip()
                marca = f.readline().strip()
                
                line = f.readline().strip()
                if tipo == 'auto':
                    tok = line.split()
                    cilindrata = int(tok[0])
                    bagagliaio = float(tok[1])
                    costo = float(f.readline().strip())
                    
                    auto = Auto(codice, targa, modello, marca, costo, cilindrata, bagagliaio)
                    veicoli.append(auto)
                elif tipo == 'furgone':
                    categoria = line
                    
                    line = f.readline().strip()
                    tok = line.split()
                    posti = int(tok[0])
                    vano = bool(tok[1])
                    costo = float(f.readline().strip())
                    
                    furgone = Furgone(codice, targa, modello, marca, costo, categoria, posti, vano)
                    veicoli.append(furgone)
                    
                codiceTarga[codice] = targa
                    
                line = f.readline().strip()
            f.close()
        except IOError as e:
            print(e)
        except Exception as e:
            print(e)
            
        try:
            f = open("clienti.txt");
            line = f.readline().strip()
            
            while(line != ''):
                nomeCognome = line
                cliente = Cliente(nomeCognome)
                line = f.readline().strip()
                tok = line.split()
                i = 0
                while i<len(tok):
                    codice = int(tok[i])
                    targa = codiceTarga[codice]
                    
                    giorni = int(tok[i+1])
                    
                    noleggio = Noleggio(targa, giorni)
                    cliente.addNoleggio(noleggio)
                    
                    i+=2
                clienti.append(cliente)
                line = f.readline().strip()
            f.close()   
        except IOError as e:
            print(e)
        except Exception as e:
            print('error', e)
        
        for veicolo in veicoli:
            print(veicolo)
            
        print('separé')
            
        for cliente in clienti:
            print(cliente)
    
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('codice', action='store')
    pa = parser.parse_args()
    g = Gestione(pa.codice)
    g.main()
