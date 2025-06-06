#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class GiaSuc {
protected:
    int soLuong;
public:
    GiaSuc();
    void setSoLuong(int);
    int getSoLuong();
    virtual string keu() = 0;
    virtual int sinhCon() = 0;
    virtual int choSua() = 0;
    virtual string loai() = 0;
    virtual ~GiaSuc() {}
};

GiaSuc::GiaSuc() {
    soLuong = 0;
}

void GiaSuc::setSoLuong(int sl) {
    soLuong = sl;
}

int GiaSuc::getSoLuong() {
    return soLuong;
}

class Bo : public GiaSuc {
public:
    string keu();
    int sinhCon();
    int choSua();
    string loai();
};

string Bo::keu() {
    return "Bò: Ò... Ò...";
}

int Bo::sinhCon() {
    int tong = 0;
    for (int i = 0; i < soLuong; i++)
        tong += rand() % 2 + 1;
    return tong;
}

int Bo::choSua() {
    int tong = 0;
    for (int i = 0; i < soLuong; i++)
        tong += rand() % 21;
    return tong;
}

string Bo::loai() {
    return "Bò";
}

class Cuu : public GiaSuc {
public:
    string keu();
    int sinhCon();
    int choSua();
    string loai();
};

string Cuu::keu() {
    return "Cừu: Beee... Beee...";
}

int Cuu::sinhCon() {
    int tong = 0;
    for (int i = 0; i < soLuong; i++)
        tong += rand() % 2 + 1;
    return tong;
}

int Cuu::choSua() {
    int tong = 0;
    for (int i = 0; i < soLuong; i++)
        tong += rand() % 6;
    return tong;
}

string Cuu::loai() {
    return "Cừu";
}

class De : public GiaSuc {
public:
    string keu();
    int sinhCon();
    int choSua();
    string loai();
};

string De::keu() {
    return "Dê: Eeee... Eeee...";
}

int De::sinhCon() {
    int tong = 0;
    for (int i = 0; i < soLuong; i++)
        tong += rand() % 2 + 1;
    return tong;
}

int De::choSua() {
    int tong = 0;
    for (int i = 0; i < soLuong; i++)
        tong += rand() % 11;
    return tong;
}

string De::loai() {
    return "Dê";
}

int main() {
    srand(time(0));
    Bo bo;
    Cuu cuu;
    De de;

    int slBo, slCuu, slDe;
    cin >> slBo >> slCuu >> slDe;

    bo.setSoLuong(slBo);
    cuu.setSoLuong(slCuu);
    de.setSoLuong(slDe);

    cout << bo.keu() << endl;
    cout << cuu.keu() << endl;
    cout << de.keu() << endl;

    int boCon = bo.sinhCon();
    int cuuCon = cuu.sinhCon();
    int deCon = de.sinhCon();

    int suaBo = bo.choSua();
    int suaCuu = cuu.choSua();
    int suaDe = de.choSua();

    cout << bo.loai() << ": so con = " << boCon << ", sua = " << suaBo << " lit" << endl;
    cout << cuu.loai() << ": so con = " << cuuCon << ", sua = " << suaCuu << " lit" << endl;
    cout << de.loai() << ": so con = " << deCon << ", sua = " << suaDe << " lit" << endl;
}