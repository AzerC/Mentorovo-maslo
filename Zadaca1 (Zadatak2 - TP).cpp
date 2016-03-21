//Neka je A neka matrica formata m*n. Pod p*q ekspanzijom matrice A smatramo novu matricu
//formata mp*nq koja se dobija tako što se svaki element , matrice A zamijeni blokom formata
//p*q pri čemu su svi elementi tog bloka jednaki.
//Napišite funkciju “EkspanzijaMatrice” sa parametra. Prvi parametar je matrica A sa realnim
//elementima koja je organizirana kao vektor vektōrâ realnih brojeva (tj. vektor čiji su elementi
//vektori realnih brojeva, i to tipa “double”), dok su drugi i treći parametar cijeli brojevi i .
//Funkcija treba da kreira i kao rezultat vratip*q ekspanziju matrice A. U slučaju da je neki od
//parametara ili nula ili negativan, funkcija treba da baci izuzetak tipa “domain_error” uz
//prateći tekst “Nelegalni parametri”. U slučaju da prvi parametar nema ispravnu formu matrice,
//odnosno ukoliko svi redovi proslijeđenog vektora vektōrâ nemaju isti broj elemenata, treba
//baciti izuzetak tipa “domain_error” uz prateći tekst “Nekorektna matrica”.
//Napisanu funkciju demonstrirajte u testnom programu u kojem se sa tastature prvo traži unos
//dva cijela broja i , zatim elementi matrice A formata m*n , te konačno dva cijela broja p i q.
//Program nakon toga treba da pozivom napisane funkcije kreira p*q ekspanziju matrice A i da
//ispiše njene elemente na ekran, svaki red u posebnom redu na ekranu. Obavezno predvidite
//hvatanje izuzetaka koji bi eventualno mogli biti bačeni iz funkcije.
//NAPOMENA: U konkretnom testnom programu koji se ovdje traži, izuzetak sa pratećim tekstom
//“Nekorektna matrica” nikad neće biti bačen, s obzirom da će se funkciji iz testnog programa
//uvijek prenositi parametar koji zaista ima strukturu matrice. Međutim, s obzirom da dobro
//napisana funkcija ne treba ništa da zna o tome u kakvom će okruženju biti korištena, funkcija
//mora da se zna “odbraniti” u slučaju da u nju ipak “uđu” neispravni podaci. Štaviše, za vrijeme
//autotestiranja, funkcije se zaista pozivati sa svakakvim ulaznim parametrima, a ne samo onima
//kakve ste vi predvidjeli u testnom programu.
#include <iostream>
#include <vector>
#include <stdexcept>
typedef std::vector<std::vector<double>> MatRealnih;
MatRealnih Napravi_Matricu (int m, int n)
{
    if (m <= 0 && n <= 0)
        throw std::domain_error("Nekorektna matrica");
    return MatRealnih (m, std::vector<double>(n));
}
MatRealnih Elementi_Matrice (MatRealnih mat)
{
    for (int i(0); i < mat.size(); i++)
        for (int j(0); j < mat[i].size(); j++)
            std::cin >> mat[i][j];
    for (int i(1); i < mat.size(); i++)
        if (mat[i].size() != mat[0].size())
            throw std::domain_error("Nekorektna matrica");
    return mat;
}
MatRealnih EkspanzijaMatrice(MatRealnih matA, int p, int q)
{
    if (p <= 0) throw std::domain_error("Nelegalni parametri");
    else if (q <= 0) throw std::domain_error("Nelegalni parametri");
    int red(0), kolona(0);
    MatRealnih matEksp(Napravi_Matricu(matA.size()*p, matA[0].size()*q));
    for (int i(0); i < matA.size(); i++)
    {
        int brojac(0);
        for (int j(0); j < matA[i].size(); j++)
        {
            while (red  < matEksp.size())
            {
                for (int z(kolona); z < matEksp[0].size();)
                {
                    for (int x(red); x < p + red; x++)
                    {
                        for (int y(kolona); y < q + kolona; y++)
                        {
                            matEksp[x][y] = matA[i][j];
                        }
                    }
                    kolona += q;
                    break;
                }
                if (kolona == matEksp[0].size())
                    kolona = 0;
                brojac++;
                break;
            }
            if (brojac == matA[0].size())
            {
                red += p;
            }
        }
    }
    return matEksp;
}
int main()
{
    std::cout << "Unesite dva cijela broja m i n: ";
    try
    {
        int m, n;
        std::cin >> m >> n;
        MatRealnih matA (Elementi_Matrice(Napravi_Matricu(m, n)));

        std::cout << "Unesite dva cijela broja p i q: ";
        try
        {
            int p, q;
            std::cin >> p >> q;
            MatRealnih matEksp (EkspanzijaMatrice(matA, p, q));
            for (int i(0); i < matEksp.size(); i++)
            {
                for (int j(0); j < matEksp[i].size(); j++)
                    std::cout << matEksp[i][j] << " ";
                std::cout << std::endl;
            }
        }
        catch(std::domain_error izuzetak)
        {
            std::cout << izuzetak.what() << std::endl;
        }
    }
    catch(std::domain_error izuzetak)
    {
        std::cout << izuzetak.what() << std::endl;
    }
    return 0;
}

