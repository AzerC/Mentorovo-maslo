//Pretpostavimo da u nekoj re�enici �elimo da istaknemo neke rije�i ili fraze tako �to �emo ih
//staviti u zagradu. U ovom zadatku cilj je napisati funkciju �IstakniFraze� koji �e automatizirati
//ovaj proces. Prvi parametar ove funkcije je neki string (tj. njegov tip je �std::string�) koji
//sadr�i re�enicu u kojoj treba istaknuti rije�i ili fraze. Drugi parametar je vektor stringova (tj.
//vektor �iji su elementi tipa �std::string�) koji sadr�i popis rije�i odnosno fraza koje treba
//istaknuti. Funkcija treba da kao rezultat vrati modificiranu re�enicu u kojoj je svaka rije�
//odnosno fraza iz spiska stavljena u zagrade. Na primjer, ukoliko se kao prvi parametar funkciji
//proslijedi re�enica �Izasla je prva zadaca iz predmeta Tehnike programiranja, a ovih dana
//ocekujemo i jos zadaca iz drugih predmeta�, a kao drugi parametar vektor koji sadr�i stringove
//�zadaca�, �Tehnike programiranja�, �drugih predmeta� i �meso od sira�, kao rezultat treba da se
//dobije string koji sadr�i re�enicu �Izasla je prva (zadaca) iz predmeta (Tehnike programiranja), a
//ovih dana ocekujemo i jos (zadaca) iz (drugih predmeta)�. Iz primjera je vidljivo i to da ukoliko
//se neka od fraza ne prona�e nigdje unutar zadane re�enice (poput �meso od sira� u prethodnom
//primjeru), ne treba da se desi ni�ta posebno.
//Funkcija �IstakniFraze� ne treba biti posebno inteligentna. Princip na kojem ona treba da radi
//je prosto da se za svaki string koji se nalazi unutar vektora koji je drugi parametar funkcije tra�e
//sva njegova eventualna pojavljivanja kao podstringa unutar stringa koji je prvi parametar. Za
//svako takvo pojavljivanje, oko njega se dodaju zagrade, i to bi u su�tini bilo sve. Dakle, po takvom
//rje�enju, �Tehnike programiranja�, zatim �Tehnike programiranja� (sa 4 razmaka izme�u dvije
//rije�i), te � Tehnike programiranja � (sa nekoliko razmaka na po�etku i kraju) tretiraju se kao
//razli�ite fraze. Bolje bi bilo da nije tako, ali bi se bez toga funkcija dodatno zakomplicirala, i
//studenti to ne trebaju da rade. Tako�er, �zadaca� i �Zadaca� su razli�ite stvari, odnosno pore�enje
//treba biti osjetljivo na razliku ime�u velikih i malih slova.
//Napisanu funkciju demonstrirajte u testnom programu u kojem se tra�i da se sa tastature unese
//neka re�enica, a zatim skupina rjie�i odnosno fraza. Rije�i odnosno fraze se unose jedna po jedna,
//pri �emu se nakon svake rije�i odnosno fraze priti��e ENTER. Unos rije�i/fraza prestaje kada se
//samo naprazno pritisne ENTER, bez i�ega unesenog. Po okon�anju unosa, program treba da ispi�e
//unesenu re�enicu sa istaknutim rije�ima/frazama, koja se dobija pozivom napisane funkcije.
#include <iostream>
#include <vector>
#include <string>
std::string IstakniFraze (std::string s, std::vector<std::string> v)
{
    for (int i(0); i < v.size(); i++)
        for (int pocetak(0); pocetak <s.size(); pocetak++)
            if (s.substr(pocetak, v[i].size()) == v[i])
            {
                s = s.substr(0, pocetak) + "(" + v[i] + ")" + s.substr(pocetak + v[i].size(), s.size() - (pocetak + v[i].size()));
                pocetak += 2;
            }
    return s;
}
int main()
{
    std::cout << "Unesite recenicu:" << std::endl;
    std::string s, fraza;
    std::getline(std::cin, s);
    std::cout << "Unesite fraze:" << std::endl;
    std::vector<std::string> v;
    while (std::getline(std::cin, fraza)) {
        if (fraza.size() == 0)
            break;
        v.push_back(fraza);
    }
    std::cout << "Recenica nakon modifikacije:\n" << IstakniFraze(s, v);
    return 0;
}
