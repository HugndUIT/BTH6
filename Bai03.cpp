#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SinhVien {
protected:
    string Ma, HoTen, DiaChi;
    int SoTinChi;
    float DiemTB;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual bool TotNghiep() = 0;
    float GetDiemTB();
    virtual string GetLoai() = 0;
};

void SinhVien::Nhap() {
    getline(cin, Ma);
    getline(cin, HoTen);
    getline(cin, DiaChi);
    cin >> SoTinChi >> DiemTB;
    cin.ignore();
}

void SinhVien::Xuat() {
    cout << Ma << " " << HoTen << " " << DiaChi << " " << SoTinChi << " " << DiemTB << " ";
}

float SinhVien::GetDiemTB() {
    return DiemTB;
}

class CaoDang : public SinhVien {
private:
    float DiemTN;
public:
    void Nhap();
    void Xuat();
    bool TotNghiep();
    string GetLoai();
};

void CaoDang::Nhap() {
    SinhVien::Nhap();
    cin >> DiemTN;
    cin.ignore();
}

void CaoDang::Xuat() {
    SinhVien::Xuat();
    cout << DiemTN << "\n";
}

bool CaoDang::TotNghiep() {
    return SoTinChi >= 120 && DiemTB >= 5 && DiemTN >= 5;
}

string CaoDang::GetLoai() {
    return "CD";
}

class DaiHoc : public SinhVien {
private:
    string TenLuanVan;
    float DiemLV;
public:
    void Nhap();
    void Xuat();
    bool TotNghiep();
    string GetLoai();
};

void DaiHoc::Nhap() {
    SinhVien::Nhap();
    getline(cin, TenLuanVan);
    cin >> DiemLV;
    cin.ignore();
}

void DaiHoc::Xuat() {
    SinhVien::Xuat();
    cout << TenLuanVan << " " << DiemLV << "\n";
}

bool DaiHoc::TotNghiep() {
    return SoTinChi >= 170 && DiemTB >= 5 && DiemLV >= 5;
}

string DaiHoc::GetLoai() {
    return "DH";
}

int main() {
    vector<SinhVien*> DS;
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        int Loai;
        cin >> Loai;
        cin.ignore();
        SinhVien* Sv;
        if (Loai == 1)
            Sv = new CaoDang();
        else
            Sv = new DaiHoc();
        Sv->Nhap();
        DS.push_back(Sv);
    }

    for (auto Sv : DS)
        Sv->Xuat();

    for (auto Sv : DS)
        if (Sv->TotNghiep())
            Sv->Xuat();

    for (auto Sv : DS)
        if (!Sv->TotNghiep())
            Sv->Xuat();

    float MaxDaiHoc = -1;
    for (auto Sv : DS)
        if (Sv->GetLoai() == "DH" && Sv->GetDiemTB() > MaxDaiHoc)
            MaxDaiHoc = Sv->GetDiemTB();
    for (auto Sv : DS)
        if (Sv->GetLoai() == "DH" && Sv->GetDiemTB() == MaxDaiHoc)
            Sv->Xuat();

    float MaxCaoDang = -1;
    for (auto Sv : DS)
        if (Sv->GetLoai() == "CD" && Sv->GetDiemTB() > MaxCaoDang)
            MaxCaoDang = Sv->GetDiemTB();
    for (auto Sv : DS)
        if (Sv->GetLoai() == "CD" && Sv->GetDiemTB() == MaxCaoDang)
            Sv->Xuat();

    int CD_Fail = 0, DH_Fail = 0;
    for (auto Sv : DS) {
        if (Sv->GetLoai() == "CD" && !Sv->TotNghiep()) CD_Fail++;
        if (Sv->GetLoai() == "DH" && !Sv->TotNghiep()) DH_Fail++;
    }
    cout << CD_Fail << " " << DH_Fail << endl;
}