#include <bits/stdc++.h>
using namespace std;

constexpr int sizik = 1000*1001;

int n, k;
int mini = 0;
std::vector<int> p, w;

bool check(long long x) {
    // dokładnie x mocy do wykorzystania..
    if(x<mini) {
        return false;
    }

    // ok powinno być proste co nie?
    // może jakieś sumy pref?
    // nie no..

    // no, raczej dp jakiś
    // należy zamienić k żarówek (zawsze można p[i]->p[i]);

    // może podwójny bs?

    // mamy posortowane..

    // człowiecze..
    // chcemy jakoś najdroższy z najtańszym, a najtańszy z najdroższym

    // no mamy jedynie k do zamiany..
    // przeto spróbujmy

    // po pierwsze trzeba pewne żarówki zdegradować

    long long init = 0;
    for(const auto&a:p) {
        init += a;
    }

    // może dla każdej żarówki obliczyć ile mogą zasilić pokoi
    // (nie zmieniając mocy)

    // ja byłbym pierwej podkręcił żarówki, te co nie domagają.
    // a potem zdegradował te co domagają
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    std::cin >> n >> k;

    p=std::vector<int>(n),w=std::vector<int>(n);
    for(auto&a:p) {
        std::cin >> a;
    }
    for(auto&a:w) {
        std::cin >> a;
        mini+=a;
    }

    std::sort(p.begin(), p.end());
    std::sort(w.begin(), w.end());

    // mamy posortowane.. i co dalej?
    // spr, które TRZEBA WYMIENIĆ (tzn. mają zbyt małą moc)

    // nie no
    // chyba nieoptymalne?

    // Nie chcemy wymieniać najtańszych, ale najdroższe..

    for(int i = 0; i < n; i++) {
        if(p[i]<w[i]) {
            p[i]=w[i];
            k--;
        }
    }

    if(k<0) {
        std::cout << "NIE\n";
    }

    // ok mamy już wszystko ok, to jak zoptymalizować do końca?

    // chcemy z każdej żarówki usunąć najwięcej mocy jak to tylko możliwe
    // czy przypisanie żarówek, takie, że p[i]->w[i] jest optymalne?
    // odpowiedź to: Nie.
    // chcemy teraz, ażeby najtańsza była z najdroższym, a
    // najdroższa z najtańszą (jak to tylko możliwe)

    /*
    long long sum=0;
    for(int i = 0; i < n; i++) {
        sum+=p[i];
    }
    */

    // może to binsearch??
    // spr czy można zdobyć moc k
    // jeśli można k to można każdą większą.
    // tak czy siak optymalne jest posortować - to na pewno..
    // dobra jedziem bin searchem..

    //std::cout << sum << '\n';

    long long po=0,ko=INT64_MAX,s=0;
    while(po<ko) {
        s=(po+ko)/2;
        if(check(s)) {
            ko=s;
        } else {
            po=s+1;
        }
    }

    std::cout << po << '\n';
}
