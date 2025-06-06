#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVien {
protected:
    string HoTen;
    string NgaySinh;
    float Luong;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhLuong() = 0;
    float GetLuong();
    string GetNgaySinh();
    virtual string GetLoai() = 0;
};

void NhanVien::Nhap() {
    getline(cin, HoTen);
    getline(cin, NgaySinh);
}

void NhanVien::Xuat() {
    cout << HoTen << " " << NgaySinh << " " << Luong << " ";
}

float NhanVien::GetLuong() {
    return Luong;
}

string NhanVien::GetNgaySinh() {
    return NgaySinh;
}

class NVSX : public NhanVien {
private:
    int SoSanPham;
    float LuongCanBan;
public:
    void Nhap();
    void Xuat();
    void TinhLuong();
    string GetLoai();
};

void NVSX::Nhap() {
    NhanVien::Nhap();
    cin >> LuongCanBan;
    cin >> SoSanPham;
    cin.ignore();
}

void NVSX::Xuat() {
    NhanVien::Xuat();
    cout << "SX\n";
}

void NVSX::TinhLuong() {
    Luong = LuongCanBan + SoSanPham * 5000;
}

string NVSX::GetLoai() {
    return "SX";
}

class NVVP : public NhanVien {
private:
    int SoNgay;
public:
    void Nhap();
    void Xuat();
    void TinhLuong();
    string GetLoai();
};

void NVVP::Nhap() {
    NhanVien::Nhap();
    cin >> SoNgay;
    cin.ignore();
}

void NVVP::Xuat() {
    NhanVien::Xuat();
    cout << "VP\n";
}

void NVVP::TinhLuong() {
    Luong = SoNgay * 100000;
}

string NVVP::GetLoai() {
    return "VP";
}

int main() {
    vector<NhanVien*> DanhSach;
    int SoNV, Chon;
    cin >> SoNV;
    cin.ignore();

    for (int i = 0; i < SoNV; i++) {
        cin >> Chon;
        cin.ignore();
        NhanVien* Nv;
        if (Chon == 1)
            Nv = new NVSX();
        else
            Nv = new NVVP();
        Nv->Nhap();
        Nv->TinhLuong();
        DanhSach.push_back(Nv);
    }

    for (auto Nv : DanhSach)
        Nv->Xuat();

    float TongLuong = 0;
    for (auto Nv : DanhSach)
        TongLuong += Nv->GetLuong();
    cout << TongLuong << endl;

    float MinLuong = 1e9;
    NhanVien* NvMin = nullptr;
    for (auto Nv : DanhSach)
        if (Nv->GetLoai() == "SX" && Nv->GetLuong() < MinLuong) {
            MinLuong = Nv->GetLuong();
            NvMin = Nv;
        }
    if (NvMin)
        NvMin->Xuat();

    string NgayNhoNhat = "99/99/9999";
    NhanVien* NvMaxTuoi = nullptr;
    for (auto Nv : DanhSach)
        if (Nv->GetLoai() == "VP" && Nv->GetNgaySinh() < NgayNhoNhat) {
            NgayNhoNhat = Nv->GetNgaySinh();
            NvMaxTuoi = Nv;
        }
    if (NvMaxTuoi)
        NvMaxTuoi->Xuat();
}