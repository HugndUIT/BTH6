#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GiaoDich {
protected:
    string Ma, Ngay;
    float DonGia, DienTich, ThanhTien;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhTien() = 0;
    float GetThanhTien();
    string GetNgay();
    virtual string GetLoai() = 0;
};

void GiaoDich::Nhap() {
    getline(cin, Ma);
    getline(cin, Ngay);
    cin >> DonGia >> DienTich;
    cin.ignore();
}

void GiaoDich::Xuat() {
    cout << Ma << " " << Ngay << " " << DonGia << " " << DienTich << " " << ThanhTien << " ";
}

float GiaoDich::GetThanhTien() {
    return ThanhTien;
}

string GiaoDich::GetNgay() {
    return Ngay;
}

class GiaoDichDat : public GiaoDich {
private:
    char Loai;
public:
    void Nhap();
    void Xuat();
    void TinhTien();
    string GetLoai();
};

void GiaoDichDat::Nhap() {
    GiaoDich::Nhap();
    cin >> Loai;
    cin.ignore();
}

void GiaoDichDat::Xuat() {
    GiaoDich::Xuat();
    cout << Loai << "\n";
}

void GiaoDichDat::TinhTien() {
    if (Loai == 'A')
        ThanhTien = DienTich * DonGia * 1.5;
    else
        ThanhTien = DienTich * DonGia;
}

string GiaoDichDat::GetLoai() {
    return "Dat";
}

class GiaoDichNha : public GiaoDich {
private:
    string LoaiNha, DiaChi;
public:
    void Nhap();
    void Xuat();
    void TinhTien();
    string GetLoai();
};

void GiaoDichNha::Nhap() {
    GiaoDich::Nhap();
    getline(cin, LoaiNha);
    getline(cin, DiaChi);
}

void GiaoDichNha::Xuat() {
    GiaoDich::Xuat();
    cout << LoaiNha << " " << DiaChi << "\n";
}

void GiaoDichNha::TinhTien() {
    if (LoaiNha == "cao cap")
        ThanhTien = DienTich * DonGia;
    else
        ThanhTien = DienTich * DonGia * 0.9;
}

string GiaoDichNha::GetLoai() {
    return "Nha";
}

class GiaoDichCanHo : public GiaoDich {
private:
    string MaCan;
    int Tang;
public:
    void Nhap();
    void Xuat();
    void TinhTien();
    string GetLoai();
};

void GiaoDichCanHo::Nhap() {
    GiaoDich::Nhap();
    getline(cin, MaCan);
    cin >> Tang;
    cin.ignore();
}

void GiaoDichCanHo::Xuat() {
    GiaoDich::Xuat();
    cout << MaCan << " " << Tang << "\n";
}

void GiaoDichCanHo::TinhTien() {
    if (Tang == 1)
        ThanhTien = DienTich * DonGia * 2;
    else if (Tang >= 15)
        ThanhTien = DienTich * DonGia * 1.2;
    else
        ThanhTien = DienTich * DonGia;
}

string GiaoDichCanHo::GetLoai() {
    return "CanHo";
}

int main() {
    vector<GiaoDich*> DanhSach;
    int So, Loai;
    cin >> So;
    cin.ignore();
    for (int i = 0; i < So; i++) {
        cin >> Loai;
        cin.ignore();
        GiaoDich* Gd;
        if (Loai == 1)
            Gd = new GiaoDichDat();
        else if (Loai == 2)
            Gd = new GiaoDichNha();
        else
            Gd = new GiaoDichCanHo();
        Gd->Nhap();
        Gd->TinhTien();
        DanhSach.push_back(Gd);
    }

    for (auto Gd : DanhSach)
        Gd->Xuat();

    int DemDat = 0, DemNha = 0, DemCanHo = 0;
    for (auto Gd : DanhSach) {
        string Loai = Gd->GetLoai();
        if (Loai == "Dat") DemDat++;
        if (Loai == "Nha") DemNha++;
        if (Loai == "CanHo") DemCanHo++;
    }
    cout << DemDat << " " << DemNha << " " << DemCanHo << endl;

    float Tong = 0; int Dem = 0;
    for (auto Gd : DanhSach)
        if (Gd->GetLoai() == "CanHo") {
            Tong += Gd->GetThanhTien();
            Dem++;
        }
    if (Dem > 0)
        cout << Tong / Dem << endl;

    float Max = 0;
    GiaoDich* GdMax = nullptr;
    for (auto Gd : DanhSach)
        if (Gd->GetLoai() == "Nha" && Gd->GetThanhTien() > Max) {
            Max = Gd->GetThanhTien();
            GdMax = Gd;
        }
    if (GdMax)
        GdMax->Xuat();

    for (auto Gd : DanhSach)
        if (Gd->GetNgay().find("/12/2024") != string::npos)
            Gd->Xuat();
}