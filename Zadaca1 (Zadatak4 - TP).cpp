//Pretpostavimo da u nekoj reèenici želimo da istaknemo neke rijeèi ili fraze tako što æemo ih
//staviti u zagradu. U ovom zadatku cilj je napisati funkciju “IstakniFraze” koji æe automatizirati
//ovaj proces. Prvi parametar ove funkcije je neki string (tj. njegov tip je “std::string”) koji
//sadrži reèenicu u kojoj treba istaknuti rijeèi ili fraze. Drugi parametar je vektor stringova (tj.
//vektor èiji su elementi tipa “std::string”) koji sadrži popis rijeèi odnosno fraza koje treba
//istaknuti. Funkcija treba da kao rezultat vrati modificiranu reèenicu u kojoj je svaka rijeè
//odnosno fraza iz spiska stavljena u zagrade. Na primjer, ukoliko se kao prvi parametar funkciji
//proslijedi reèenica “Izasla je prva zadaca iz predmeta Tehnike programiranja, a ovih dana
//ocekujemo i jos zadaca iz drugih predmeta”, a kao drugi parametar vektor koji sadrži stringove
//“zadaca”, “Tehnike programiranja”, “drugih predmeta” i “meso od sira”, kao rezultat treba da se
//dobije string koji sadrži reèenicu “Izasla je prva (zadaca) iz predmeta (Tehnike programiranja), a
//ovih dana ocekujemo i jos (zadaca) iz (drugih predmeta)”. Iz primjera je vidljivo i to da ukoliko
//se neka od fraza ne pronaðe nigdje unutar zadane reèenice (poput “meso od sira” u prethodnom
//primjeru), ne treba da se desi ništa posebno.
//Funkcija “IstakniFraze” ne treba biti posebno inteligentna. Princip na kojem ona treba da radi
//je prosto da se za svaki string koji se nalazi unutar vektora koji je drugi parametar funkcije traže
//sva njegova eventualna pojavljivanja kao podstringa unutar stringa koji je prvi parametar. Za
//svako takvo pojavljivanje, oko njega se dodaju zagrade, i to bi u suštini bilo sve. Dakle, po takvom
//rješenju, “Tehnike programiranja”, zatim “Tehnike programiranja” (sa 4 razmaka izmeðu dvije
//rijeèi), te “ Tehnike programiranja “ (sa nekoliko razmaka na poèetku i kraju) tretiraju se kao
//razlièite fraze. Bolje bi bilo da nije tako, ali bi se bez toga funkcija dodatno zakomplicirala, i
//studenti to ne trebaju da rade. Takoðer, “zadaca” i “Zadaca” su razlièite stvari, odnosno poreðenje
//treba biti osjetljivo na razliku imeðu velikih i malih slova.
//Napisanu funkciju demonstrirajte u testnom programu u kojem se traži da se sa tastature unese
//neka reèenica, a zatim skupina rjieèi odnosno fraza. Rijeèi odnosno fraze se unose jedna po jedna,
//pri èemu se nakon svake rijeèi odnosno fraze pritišæe ENTER. Unos rijeèi/fraza prestaje kada se
//samo naprazno pritisne ENTER, bez ièega unesenog. Po okonèanju unosa, program treba da ispiše
//unesenu reèenicu sa istaknutim rijeèima/frazama, koja se dobija pozivom napisane funkcije.
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
