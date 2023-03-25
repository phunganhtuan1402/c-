#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<vector>
using namespace std;

class SinhVien
{
private:
    uint8_t id;
    char TenHocSinh[20];
    char GioiTinh[4];
    uint8_t TuoiHocSinh;
    double diemToan;
    double diemLy;
    double diemHoa;
    double diemTB;
    char  hocLuc[11];
public:
    SinhVien(const char ten[], const char gioiTinh[],const uint8_t tuoi,
    const double diemToan,const double diemLy,const double diemHoa); // constructor
    void setTenHocSinh(const char ten[]);
    void setGioiTinh(const char gioi_tinh[]);
    void setTuoiHocSinh(int tuoi);
    void setdiemToan(double toan);
    void setdiemLy(double ly);
    void setdiemHoa(double hoa);

    int get_id();
    char *getTenHocSinh();
    char *getGioiTinh();
    int getTuoiHocSinh();
    float getdiemToan();
    float getdiemLy();
    float getdiemHoa();
    double getdiemTB();
    char *getHocLuc();
};
/*---------ID sinh vien --------*/
int SinhVien::get_id()
{
    return id;
}
/*-----------------TEN-------------------*/
void SinhVien::setTenHocSinh(const char ten[])
{
    strcpy(TenHocSinh, ten);
}
char* SinhVien::getTenHocSinh()
{
    return TenHocSinh;
}
/*-----------------GIOI TINH--------------*/
void SinhVien::setGioiTinh(const char gioiTinh[])
{
    if ((strcmp((char*)"Nam", gioiTinh) != 0) && (strcmp((char*)"Nu", gioiTinh) != 0))
    {
        printf("Error!! Gioi tinh khong hop le.\n");
    }
    else
    {
        strcpy(GioiTinh, gioiTinh);
    }
}
char* SinhVien::getGioiTinh()
{
    return GioiTinh;
}
/*-----------------TUOI---------------------*/
void SinhVien::setTuoiHocSinh(int tuoi){
    TuoiHocSinh = tuoi;
    }
int SinhVien::getTuoiHocSinh() {
    return TuoiHocSinh;
}
/*-------------------------DIEM TOAN--------------*/
void SinhVien::setdiemToan(double toan){
    diemToan = toan;
}
 float SinhVien::getdiemToan(){
    return diemToan;
 }
 /*-------------------------DIEM LY-----------------*/
void SinhVien::setdiemLy(double ly){
    diemToan = ly;
}
 float SinhVien::getdiemLy(){
    return diemLy;
 }
 /*-------------------------DIEM HOA--------------*/
 void SinhVien::setdiemHoa(double hoa){
    diemHoa = hoa;
}
 float SinhVien::getdiemHoa(){
    return diemHoa;
 }
 /*-------------------------DIEM TB----------------*/
 double SinhVien:: getdiemTB(){
    return (diemToan+diemLy+diemHoa)/3;
 }
 /*-------------------------HOC LUC--------------*/
char * SinhVien::getHocLuc(){
    if(getdiemTB() > 8.0){
        strcpy(hocLuc, "Gioi");
    }
    else if(getdiemTB()> 6.5){
        strcpy(hocLuc, "Kha");
    }
    else if(getdiemTB()> 5){
        strcpy(hocLuc, "Trung Binh");
    }
    else{
        strcpy(hocLuc, "Yeu");
    }
    return hocLuc;
}
/*-------------------------CONTRUCTOR--------------*/
SinhVien::SinhVien(const char ten[], const char gioiTinh[],const uint8_t tuoi,
const double toan,const double ly,const double hoa){
    static uint8_t id = 100;
    SinhVien::id = id;
    id++;
    strcpy(SinhVien::TenHocSinh, ten);
    strcpy(SinhVien::GioiTinh, gioiTinh);
    SinhVien::TuoiHocSinh = tuoi;
    SinhVien::diemToan = toan;
    SinhVien::diemLy = ly;
    SinhVien::diemHoa = hoa;
}
/*-------------------------CLASS MENU--------------*/
class Menu {
private:
    vector<SinhVien> danhSachSinhVien;
public:
    void themSinhVien();
    void capnNhatThongTin();
    void xoaSinhVien();
    void timKiemSinhVien();
    void sapxepSinhVienTheoTen();
    void sapxepSinhVienTheoGPA();
    void hienThiDanhSach(); 

};
/*-------------------------MACRO--------------*/
#define NHAP_THONG_TIN(noiDung, dinhDang, bien, dieuKien) \
do{                                                       \
    printf(noiDung);                                      \
    scanf(dinhDang, bien) ;                               \
}while(dieuKien)      
/*-------------------------THEM SINH VIEN--------------*/                     
void Menu::themSinhVien() {
    char ten[20];
    char gioiTinh[4];
    uint8_t tuoi;
    double diemToan;
    double diemLy;
    double diemHoa;
    int key;
do{
    printf("Khai bao thong tin sinh vien:\n");
    printf("Nhap ten:");
    scanf("%s", &ten);
    printf("Nhap gioi tinh:");
    scanf("%s", &gioiTinh);
    NHAP_THONG_TIN("Nhap tuoi (18-100):", "%d", &tuoi, tuoi < 18 || tuoi > 100);
    NHAP_THONG_TIN("Nhap diem Toan (0-10):", "%lf", &diemToan, diemToan < 0 || diemToan > 10);
    NHAP_THONG_TIN("Nhap diem Ly (0-10):", "%lf", &diemLy, diemLy < 0 || diemLy > 10);
    NHAP_THONG_TIN("Nhap diem Toan (0-10):", "%lf", &diemHoa, diemHoa < 0 || diemHoa > 10);
    SinhVien sv(ten, gioiTinh, tuoi, diemToan, diemLy, diemHoa);
    danhSachSinhVien.push_back(sv);
    printf("Nhap 1 de nhap them sinh vien\n");
    printf("Nhap phim bat ky de quay tro lai menu\n");
    scanf("%d", &key);
}while(key == 1);
}
//----------------Cập nhật thông tin sinh viên----------------------/
void Menu::capnNhatThongTin()
{
    int id;
    int i=0;
    char ten[20];
    char gioiTinh[11];
    int tuoi;
    double diemToan;
    double diemLy;
    double diemHoa;
    
    printf("Nhap id sinh vien can cap nhat thong tin: ");
    scanf("%d", id);
    for(SinhVien sv : danhSachSinhVien)
    {
        if(sv.get_id() ==id)
        {
            printf("Nhap ten: ");
            scanf("%s", ten);
            printf("Nhap gioi tinh(Nam/Nu): ");
            scanf("%s", gioiTinh);

            NHAP_THONG_TIN("Nhap tuoi: ",      "%d",  tuoi,      tuoi<12 || tuoi >100);
            NHAP_THONG_TIN("Nhap diem Toan: ", "%lf", diemToan,  diemToan <0 || diemToan >10);
            NHAP_THONG_TIN("Nhap diem Ly: " ,  "%lf", diemLy  ,  diemLy<0 || diemLy >10);
            NHAP_THONG_TIN("Nhap diem Hoa: ",  "%lf", diemHoa,   diemHoa<0 || diemHoa >10);
            SinhVien s_vien(ten, gioiTinh, tuoi, diemToan, diemLy, diemHoa);
            danhSachSinhVien.push_back(s_vien);
        }
        i++;
        if(i == danhSachSinhVien.size() && sv.get_id()!=id)
        {
            printf("Khong co ID sinh vien %d.\n", id);
        }
    }

}
// ---------------Xoa sinh vien-------------------------------------/
void Menu::xoaSinhVien()
{
    int id;
    int i=0; // biến i để tính thứ tự muốn xóa
    printf("Nhap id sinh vien muon xoa: ");
    scanf("%d", id);
    for (SinhVien sv : danhSachSinhVien)
    {
        if(sv.get_id()==id)
        {
            danhSachSinhVien.erase(danhSachSinhVien.begin()+i); // xóa sinh viên thứ 0 + i trong danh sach svien
            printf("Da xoa sinh vien co id: %d", id);
            return;

        }
        i++; // sau mỗi lần duyệt i tăng 1
        if(i == danhSachSinhVien.size() && sv.get_id()!=id)
        {
            printf("Khong co ID sinh vien %d ma ban muon xoa.\n", id);
        }
    }
    
}
/// ------------Tìm kiếm theo tên---------------------------------------/
void Menu::timKiemSinhVien()
{
    char ten[20];
    int i=0;
    printf("Nhap ten sinh vien ban muon tim kiem: ");
    scanf("%s", &ten);
    for(SinhVien sv : danhSachSinhVien)
    {
       if(strcmp(sv.getTenHocSinh(), ten)==0)
       {
           printf("Thong tin sinh vien can tim:\n");
           printf("ID\t Ten\t Tuoi\t GioiTinh\tToan\t Ly\t Hoa\t GPA\t Hoc_Luc\t\n");
           printf("%d\t %s\t %d\t  %s\t\t%.2lf\t%.2lf\t%.2lf\t %.2lf\t %s\t\n",sv.get_id(), sv.getTenHocSinh(),sv.getTuoiHocSinh(), sv.getGioiTinh(), sv.getdiemToan(), sv.getdiemLy(),sv.getdiemHoa(), sv.getdiemTB(), sv.getHocLuc());
       }
        if(i == danhSachSinhVien.size() && strcmp(sv.getTenHocSinh(), ten)!=0)
        {
            printf("Khong co sinh vien ten %s trong danh sach.\n", ten);
        }
        i++;
    }
}

//--------------Sắp xếp sinh viên theo GPA-----------------------------/
void Menu::sapxepSinhVienTheoGPA()     // sắp xếp theo thứ tự giảm dần
{   // danhsachSinhVien.size() là kích thước của mảng vector
    for(int i =0; i< danhSachSinhVien.size()-1; i++)//Duyệt vòng lặp bên ngoài từ vị trí đầu tiên đến vị trí trước vị trí cuối cùng của danh sách
    {
        for(int j = i+1; j < danhSachSinhVien.size(); j++)
        {
            if(danhSachSinhVien[i].getdiemTB() > danhSachSinhVien[j].getdiemTB())  //
            {
                SinhVien tg = danhSachSinhVien[i];
                danhSachSinhVien[i]=danhSachSinhVien[j];
                danhSachSinhVien[j]= tg;
            }
        }
    }
}

/// --------------Sắp xếp theo tên ------------------------------------/
void Menu::sapxepSinhVienTheoTen()
{   // danhsachSinhVien.size() là kích thước của mảng vector
    for(int i =0; i< danhSachSinhVien.size()-1; i++)//Duyệt vòng lặp bên ngoài từ vị trí đầu tiên đến vị trí trước vị trí cuối cùng của danh sách
    {
        for(int j = i+1; j < danhSachSinhVien.size(); j++) // duyệt từ phần tử tiếp theo đến hết các phần tử còn lại trong mảng vector 
        {
            if(strcmp(danhSachSinhVien[i].getTenHocSinh(), danhSachSinhVien[j].getTenHocSinh()) > 0)  
            {
                SinhVien tg = danhSachSinhVien[i];
                danhSachSinhVien[i]=danhSachSinhVien[j];
                danhSachSinhVien[j]= tg;
            }
        }
    }
}
/*-------------------------HIEN THI DANH SACH SINH VIEN--------------*/
void Menu::hienThiDanhSach() {
    printf("Hien thi danh sach sinh vien:\n");
    printf("ID\t Ten\t GioiTinh\t Tuoi\t Toan\t Ly\t Hoa\t\n ");
    for (SinhVien sv : danhSachSinhVien) {
        printf("%d\t %s\t %s\t\t %d\t %lf\t %lf\t %lf\t  \n", sv.get_id(), sv.getTenHocSinh(), sv.getGioiTinh(), sv.getTuoiHocSinh(), sv.getdiemToan(), sv.getdiemLy(), sv.getdiemHoa());
    }
}
int main(int argc, char const* argv[])
{
    Menu mn;
    int i=0;
    do {
        printf ("1. Them sinh vien\n");
        printf ("2. Cap nhat thong tin sinh vien\n");
        printf ("3. Xoa sinh vien\n");
        printf ("4. Tim kiem sinh vien theo ten\n");
        printf ("5. Sap Xep Theo GPA\n");
        printf ("6. Sap Xep Theo Ten\n");
        printf ("7. Hien thi danh sach sinh vien\n");
        printf ("8. Thoat\n");
        printf ("Chon mot trong cac cau tren(1-8): ");
        scanf("%d",&i);
        switch(i) {
            case 1:
                mn.themSinhVien();
                mn.hienThiDanhSach();
                break;
            case 2:
                mn.capnNhatThongTin();
                mn.hienThiDanhSach();
                break;
            case 3:
                mn.xoaSinhVien();
                mn.hienThiDanhSach();
                break;
            case 4:
                mn.timKiemSinhVien();
                mn.hienThiDanhSach();
                break;
            case 5:
                mn.sapxepSinhVienTheoGPA(); // theo GPA
                mn.hienThiDanhSach();
                break;
            case 6:
                mn.sapxepSinhVienTheoTen();
                mn.hienThiDanhSach();
                break;
            case 7:
                mn.hienThiDanhSach();
                break;
            case 8:
                printf ("Ket thuc chuong trinh.\n");
                return 0;
            default:
                "Vui long chon mot lua chon hop le.\n";
                break;
        }
    }while(1);
    return 0;
}