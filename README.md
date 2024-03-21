# ATM
Un ATM dispune de o colecție de n tipuri de bancnote având valorile v1, v2, …., vn,
fiecare tip de bancnotă fiind disponibilă în număr de k1, k2, … kn exemplare. Se cere
dezvoltarea unei aplicații care simulează tranzacțiile zilnice înregistrate la acel
bancomat.
Cerințe de proiectare și cerințe funcționale:
C1: Se va folosi TAD Colectie pentru stocarea colecției de bancnote
disponibile la acel ATM
C2: Se vor inregistra tranzacții de forma: idTranzactie, suma, tipul bancnotelor cu care
s-a platit suma suma si numarul acestora.
Exemplu:
suma=260, tipurile de bancnote 100, 50, 10 disponibile în 50, 45, 100 exemplare
Suma suma se va plăti cu 200=2*100 + 1*50+1*10
C3: ATM-ul să ofere utilizatorului posibilitatea alegerii unei modalități de plată, prin
afișarea tuturor posibilităților de plată a sume suma cu bancnotele disponibile
C4: Se vor defini clasele: Colecție, Tranzacție, ATM
C5: Program Principal care instantiază un obiect de tipul ATM și afișează un meniu
pentru rezolvarea cerințelor C1-C3
