# Problema 1

Programul citește de la intrare o cheie și un text, verifică dacă ambele 
conțin exclusiv litere ale alfabetului englez, iar în caz contrar afișează 
mesajul „INVALID”. Dacă datele sunt valide, cheia este extinsă până la 
lungimea textului prin repetare ciclică. Criptarea se realizează caracter cu 
caracter, folosind un alfabet format din litere mici și mari, prin deplasarea 
fiecărui caracter din text cu un număr de poziții determinat de caracterul 
corespunzător din cheie, rezultatul fiind afișat la ieșire.

# Problema 2

Programul citește un număr n de perechi formate dintr-un câmp (field) și o 
valoare asociată (value), apoi citește un text (formular) pe o linie 
întreagă. Pentru fiecare pereche, programul caută toate aparițiile câm-
pului în text și le înlocuiește cu valoarea corespunzătoare, doar dacă 
apariția reprezintă un cuvânt întreg, adică este delimitată de caractere 
speciale sau de începutul/sfârșitul șirului. Înlocuirea se face dinamic, 
prin realocarea memoriei pentru text la fiecare substituire, astfel încât 
lungimea rezultatului să fie corect ajustată. La final, programul afișează 
textul modificat și eliberează toată memoria alocată dinamic.

# Problema 3 

Programul generează un șir de caractere aleatoriu de o lungime dată, folo-
sind un seed pentru reproducerea rezultatelor, după care aplică asupra fie-
cărui caracter una dintre trei codificări alese aleator. Prima codificare 
atașează caracterului numărul apariției sale anterioare în șir, folosind 
un vector static pentru contorizare. A doua codificare modifică biții ca-
racterului prin operații pe biți și adaugă numărul de biți setați la 1. 
A treia codificare transformă literele mici în majuscule. Rezultatele 
fiecărei codificări sunt concatenate dinamic într-un șir final, folosind 
realocare de memorie, care este afișat la final. Programul gestionează expli-
cit alocarea și eliberarea memoriei pentru a evita scurgerile de memorie.
