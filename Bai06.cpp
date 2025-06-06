#include <iostream>
#include <vector>
#include <string>
using namespace std;

class KhachHang {
protected:
    string ten;
    int soLuong;
    int donGia;
public:
    void nhap();
    virtual double tinhTien() = 0;
    virtual string loai() = 0;
    virtual ~KhachHang() {}
    string getTen();
};

void KhachHang::nhap() {
    cin >> ten >> soLuong >> donGia;
}

string KhachHang::getTen() {
    return ten;
}

class KhachHangA : public KhachHang {
public:
    void nhap();
    double tinhTien();
    string loai();
};

void KhachHangA::nhap() {
    KhachHang::nhap();
}

double KhachHangA::tinhTien() {
    double tien = soLuong * donGia;
    tien += tien * 0.1;
    return tien;
}

string KhachHangA::loai() {
    return "A";
}

class KhachHangB : public KhachHang {
    int namThanThiet;
public:
    void nhap();
    double tinhTien();
    string loai();
};

void KhachHangB::nhap() {
    KhachHang::nhap();
    cin >> namThanThiet;
}

double KhachHangB::tinhTien() {
    double khuyenMai = namThanThiet * 0.05;
    if (khuyenMai > 0.5) khuyenMai = 0.5;
    double tien = soLuong * donGia;
    tien *= (1 - khuyenMai);
    tien += tien * 0.1;
    return tien;
}

string KhachHangB::loai() {
    return "B";
}

class KhachHangC : public KhachHang {
public:
    void nhap();
    double tinhTien();
    string loai();
};

void KhachHangC::nhap() {
    KhachHang::nhap();
}

double KhachHangC::tinhTien() {
    double tien = soLuong * donGia * 0.5;
    tien += tien * 0.1;
    return tien;
}

string KhachHangC::loai() {
    return "C";
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    vector<KhachHang*> ds;

    for (int i = 0; i < x; i++) {
        KhachHang* kh = new KhachHangA();
        kh->nhap();
        ds.push_back(kh);
    }
    for (int i = 0; i < y; i++) {
        KhachHang* kh = new KhachHangB();
        kh->nhap();
        ds.push_back(kh);
    }
    for (int i = 0; i < z; i++) {
        KhachHang* kh = new KhachHangC();
        kh->nhap();
        ds.push_back(kh);
    }

    for (KhachHang* kh : ds) {
        cout << kh->getTen() << " " << kh->loai() << " " << kh->tinhTien() << endl;
    }

    for (KhachHang* kh : ds) {
        delete kh;
    }
}