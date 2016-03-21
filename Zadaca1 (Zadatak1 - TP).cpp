//Cijeli brojevi sa cifara koji su jednaki sumi -tih stepena svih svojih cifara u teoriji brojeva se
//nazivaju Armstrongovi ili narcisoidni brojevi. Ovi brojevi su vrlo rijetki (ima ih ukupno svega 88, a
//svega oko 30-ak ih ima koji su veličine takve da mogu stati u tip “int”). Primjeri takvih brojeva su
//Napravite funkciju “ArmstrongoviBrojevi” koja ima dva cjelobrojna parametra (tipa "int"), nazovimo ih recimo i
//, koja kao rezultat vraća vektor čiji su elementi svi Armstrongovi brojevi u opsegu od do
//uključivo, sortirani u rastući poredak. Na primjer, za = 3000000 i = 10000000, funkcija treba
//da vrati vektor čiji su elementi 4 1 1 , 9 1 i 9926315 (ovo su Armstrongovi brojevi u
//navedenom opsegu).
//Napisanu funkciju demonstrirajte u testnom programu koji traži da se sa tastature unesu brojevi
//i , a koji će nakon toga pozvati napisanu funkciju i na osnovu njenog rezultata ispisati sve
//Armstrongove brojeve u opsegu od i uključivo (u rastućem poretku), međusobno razdvojene
//zarezom (iza posljednjeg elementa ne treba stajati zarez). Ukoliko u zadanom opsegu nema niti
//jedan Armstrongov broj, treba da se ispiše poruka “Nema Armstrongovih brojeva u traženom
//opsegu”.
//NAPOMENA: Funkcija “ArmstrongoviBrojevi” mora se zasnivati na stvarnom testiranju da li je
//broj Armstrongov ili ne (prema njegovoj definiciji). Recimo, ne dolazi u obzir rješenje da neko u
//neki niz ili vektor upiše spisak svih Armstrongovih brojeva koji mogu stati u tip “int” (a takav
//spisak se može naći recimo na internetu) i da onda samo “vadi” brojeve iz spiska koji leže u
//zahtijevanom opsegu.
#include <iostream>
#include <vector>

std::vector<int> ArmstrongoviBrojevi(int p, int q)
{
        std::vector<int> v;
        if (p > q) {
                int temp(p);
                p = q;
                q = temp;
        }
        else if (p < 0 && q >= 0)
                p = 0;
        else if (p < 0 && q < 0)
                return v;
        for (int i(p); i <= q; i++) {
                int broj(i), broj1(i), brojac(0);
                int suma1(0);
                while (broj != 0) {
                        brojac++;
                        broj/=10;
                }
                while (broj1 != 0) {
                        int suma(1);
                        for (int i(0); i < brojac; i++)
                        suma = suma * (broj1%10);
                        suma1 += suma;
                        broj1/=10;
                }
                if (suma1 == i)
                        v.push_back(i);
        }
        return v;
}
int main()
{
        std::cout << "Unesite dva broja: " ;
        int p, q;
        std::cin >> p >> q;
        if (p > q) {
                int temp(p);
                p = q;
                q = temp;
        }
        if (p < 0 && q >= 0)
                p = 0;
        std::vector<int> v(ArmstrongoviBrojevi(p, q));
        if (v.size() == 0)
                std::cout << "Nema Armstrongovih brojeva u trazenom opsegu";
        else {
                std::cout << "Armstrongovi brojevi u opsegu [" << p << ", " << q << "]: ";
                for (int i(0); i < v.size(); i++) {
                        if (i == v.size() - 1)
                                std::cout << v[i];
                        else
                                std::cout << v[i] << ",";
                }
        }
        return 0;
}
