#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVien {
protected:
    string maNV, hoTen, sdt, email;
    int tuoi;
    double luongCoBan;
public:
    virtual void nhap();
    virtual void xuat();
    virtual double tinhLuong() = 0;
    virtual string loaiNV() = 0;
    virtual ~NhanVien() {}
};

void NhanVien::nhap() {
    cin >> maNV >> hoTen >> tuoi >> sdt >> email >> luongCoBan;
}

void NhanVien::xuat() {
    cout << maNV << " " << hoTen << " " << tuoi << " " << sdt << " " << email << " " << luongCoBan << " ";
}

class LapTrinhVien : public NhanVien {
    int gioOT;
public:
    void nhap();
    void xuat();
    double tinhLuong();
    string loaiNV();
};

void LapTrinhVien::nhap() {
    NhanVien::nhap();
    cin >> gioOT;
}

void LapTrinhVien::xuat() {
    NhanVien::xuat();
    cout << gioOT << " " << tinhLuong() << endl;
}

double LapTrinhVien::tinhLuong() {
    return luongCoBan + gioOT * 200000;
}

string LapTrinhVien::loaiNV() {
    return "LTV";
}

class KiemChungVien : public NhanVien {
    int soLoi;
public:
    void nhap();
    void xuat();
    double tinhLuong();
    string loaiNV();
};

void KiemChungVien::nhap() {
    NhanVien::nhap();
    cin >> soLoi;
}

void KiemChungVien::xuat() {
    NhanVien::xuat();
    cout << soLoi << " " << tinhLuong() << endl;
}

double KiemChungVien::tinhLuong() {
    return luongCoBan + soLoi * 50000;
}

string KiemChungVien::loaiNV() {
    return "KCV";
}

int main() {
    vector<NhanVien*> ds;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string loai;
        cin >> loai;
        NhanVien* nv;
        if (loai == "LTV") nv = new LapTrinhVien();
        else nv = new KiemChungVien();
        nv->nhap();
        ds.push_back(nv);
    }

    for (auto nv : ds) nv->xuat();

    double tong = 0;
    for (auto nv : ds) tong += nv->tinhLuong();
    double tb = tong / ds.size();

    for (auto nv : ds)
        if (nv->tinhLuong() < tb)
            nv->xuat();

    double maxL = ds[0]->tinhLuong();
    for (auto nv : ds)
        if (nv->tinhLuong() > maxL)
            maxL = nv->tinhLuong();
    for (auto nv : ds)
        if (nv->tinhLuong() == maxL)
            nv->xuat();

    double minL = ds[0]->tinhLuong();
    for (auto nv : ds)
        if (nv->tinhLuong() < minL)
            minL = nv->tinhLuong();
    for (auto nv : ds)
        if (nv->tinhLuong() == minL)
            nv->xuat();

    double maxLTV = -1;
    for (auto nv : ds)
        if (nv->loaiNV() == "LTV" && nv->tinhLuong() > maxLTV)
            maxLTV = nv->tinhLuong();
    for (auto nv : ds)
        if (nv->loaiNV() == "LTV" && nv->tinhLuong() == maxLTV)
            nv->xuat();

    double maxKCV = -1;
    for (auto nv : ds)
        if (nv->loaiNV() == "KCV" && nv->tinhLuong() > maxKCV)
            maxKCV = nv->tinhLuong();
    for (auto nv : ds)
        if (nv->loaiNV() == "KCV" && nv->tinhLuong() == maxKCV)
            nv->xuat();

    for (auto nv : ds) delete nv;
}