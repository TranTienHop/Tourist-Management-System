#include"CongTy.h"
#include"DoanhThu.h"
#include"ThongKe.h"
#include <iomanip>
using namespace std;

CongTy::CongTy() {

}
CongTy::~CongTy() {}

void CongTy::doc_file() {
	cout << "\n=== DANG DOC DU LIEU TU CAC FILE ===\n";

	ds_khach_hang.doc_file();
	ds_nhan_vien.doc_file();
	ds_phuong_tien.doc_file();
	ds_dia_danh.doc_file();
	ds_luu_tru.doc_file();
	ds_thanh_toan.doc_file();
	ds_dich_vu.doc_file(ds_khach_hang, ds_nhan_vien,ds_phuong_tien,ds_dia_danh,ds_luu_tru, ds_thanh_toan);

	cout << "\n=== DA HOAN TAT QUA TRINH DOC FILE ===\n";
}
void CongTy::hien_thi_menu_khach_hang() {
	ds_khach_hang.hien_thi_menu_khach_hang();
}

void CongTy::hien_thi_menu_nhan_vien() {
	ds_nhan_vien.hien_thi_menu_nhan_vien();
}
void CongTy::hien_thi_menu_phuong_tien() {
	ds_phuong_tien.hien_thi_menu_phuong_tien();
}

void CongTy::hien_thi_menu_dia_danh() {
	ds_dia_danh.hien_thi_menu_dia_danh();
}

void CongTy::hien_thi_menu_luu_tru() {
	ds_luu_tru.hien_thi_menu_luu_tru();
}

void CongTy::hien_thi_menu_thanh_toan() {
	ds_thanh_toan.hien_thi_menu_thanh_toan();
}
void CongTy::hien_thi_menu_dich_vu() {
	ds_dich_vu.hien_thi_menu_dich_vu();
}
void CongTy::hien_thi_menu_doanh_thu() {
	DoanhThu::hien_thi_menu_doanh_thu(ds_dich_vu, ds_thanh_toan, ds_khach_hang);
}

void CongTy::hien_thi_menu_thong_ke() {
	ThongKe::hien_thi_menu_thong_ke(ds_khach_hang, ds_nhan_vien, ds_phuong_tien, ds_dia_danh, ds_luu_tru, ds_dich_vu);
}

void CongTy::nhap() {
	int chon;
	do {
		cout << "\n=== ADMIN NHAP DU LIEU ===\n";
		cout << "1. Nhap danh sach khach hang\n";
		cout << "2. Nhap danh sach nhan vien\n";
		cout << "3. Nhap danh sach phuong tien\n";
		cout << "4. Nhap danh sach dia danh\n";
		cout << "5. Nhap danh sach luu tru\n";
		cout << "6. Nhap danh sach thanh toan\n";
		cout << "7. Nhap danh sach dich vu\n";
		cout << "0. Thoat\n";
		cout << "Nhap lua chon: ";
		cin >> chon;
		cin.ignore();

		switch (chon) {
		case 1: {
			KhachHang* kh = new KhachHang();
			kh->nhap();
			ds_khach_hang.them(kh);
			ds_khach_hang.hien_thi();
			break;
		}
		case 2: {
			int loai;
			std::cout << "Chon loai nhan vien (1. Cham soc, 2. Huong dan): ";
			std::cin >> loai;
			std::cin.ignore();
			switch (loai) {
			case 1: {
				NhanVienChamSoc* nv = new NhanVienChamSoc();
				nv->nhap();
				ds_nhan_vien.them(nv);
				ds_nhan_vien.hien_thi();
				break;
			}
			case 2: {
				HuongDanVien* hdv = new HuongDanVien();
				hdv->nhap();
				ds_nhan_vien.them(hdv);
				ds_nhan_vien.hien_thi();
				break;
			}
			default:
				std::cout << "Loai nhan vien khong hop le!\n";
			}
			break;
		}
		case 3: {
			int loai;
			std::cout << "Chon loai phuong tien (1. May bay, 2. Xe khach, 3. Xe hoi): ";
			std::cin >> loai;
			std::cin.ignore();

			PhuongTien* pt = nullptr;
			switch (loai) {
			case 1: pt = new MayBay(); break;
			case 2: pt = new XeKhach(); break;
			case 3: pt = new XeHoi(); break;
			default:
				std::cout << "Loai phuong tien khong hop le!\n";
				break;
			}

			if (pt) {
				pt->nhap();
				ds_phuong_tien.them(pt);
				ds_phuong_tien.hien_thi();
			}
			break;
		}
		case 4: {
			DiaDanh* dd = new DiaDanh();
			dd->nhap();
			ds_dia_danh.them();
			ds_dia_danh.hien_thi();
			break;
		}
		case 5: {
			int loai;
			std::cout << "Chon loai luu tru (1. Khach San, 2. Nha Nghi): ";
			std::cin >> loai;
			std::cin.ignore();

			LuuTru* luu_tru = nullptr;
			switch (loai) {
			case 1: luu_tru = new KhachSan(); break;
			case 2: luu_tru = new NhaNghi(); break;
			default:
				std::cout << "Loai luu tru khong hop le!\n";
				break;
			}

			if (luu_tru) {
				luu_tru->nhap();
				ds_luu_tru.them(luu_tru);
				ds_luu_tru.hien_thi();
			}
			break;
		}
		case 6: {
			ThanhToan* tt = new ThanhToan();
			tt->nhap();
			ds_thanh_toan.them();
			ds_thanh_toan.hien_thi();
			break;
		}
		case 7: {
			DatDichVu* dv = new DatDichVu();
			dv->nhap();           
			ds_dich_vu.them();  
			ds_dich_vu.hien_thi(); 
			break;
		}
		case 0:
			std::cout << "Thoat khoi che do nhap.\n";
			break;
		default:
			std::cout << "Lua chon khong hop le. Vui long nhap lai.\n";
		}

	} while (chon != 0);
}

void CongTy::hien_thi() {
	int chon;
	do {
		cout << "\n=== ADMIN HIEN THI DU LIEU ===\n";
		cout << "1. Hien thi danh sach khach hang\n";
		cout << "2. Hien thi danh sach nhan vien\n";
		cout << "3. Hien thi danh sach phuong tien\n";
		cout << "4. Hien thi danh sach dia danh\n";
		cout << "5. Hien thi danh sach luu tru\n";
		cout << "6. Hien thi danh sach thanh toan\n";
		cout << "7. Hien thi danh sach dat dich vu\n";
		cout << "0. Thoat\n";
		cout << "Nhap lua chon: ";
		cin >> chon;
		cin.ignore();

		switch (chon) {
		case 1:
			ds_khach_hang.hien_thi();
			break;
		case 2:
			ds_nhan_vien.hien_thi();
			break;
		case 3:
			ds_phuong_tien.hien_thi();
			break;
		case 4:
			ds_dia_danh.hien_thi();
			break;
		case 5:
			ds_luu_tru.hien_thi();
			break;
		case 6:
			ds_thanh_toan.hien_thi();
			break;
		case 7:
			ds_dich_vu.hien_thi();
			break;
		case 0:
			cout << "Thoat khoi che do hien_thi thi.\n";
			break;
		default:
			cout << "Lua chon khong hop le. Vui long nhap lai.\n";
		}
	} while (chon != 0);
}
void CongTy::tim_kiem() {
	int chon;
	do {
		std::cout << "\n=== ADMIN TIM KIEM DU LIEU ===\n";
		std::cout << "1. Tim kiem khach hang\n";
		std::cout << "2. Tim kiem nhan vien\n";
		std::cout << "3. Tim kiem phuong tien\n";
		std::cout << "4. Tim kiem dia danh\n";
		std::cout << "5. Tim kiem luu tru\n";
		std::cout << "6. Tim kiem thanh toan\n";
		std::cout << "0. Thoat\n";
		std::cout << "Nhap lua chon: ";
		std::cin >> chon;
		std::cin.ignore();

		std::string ma;
		switch (chon) {
		case 1: {
			std::cout << "Nhap ma khach hang can tim: ";
			std::getline(std::cin, ma);
			KhachHang* kq = ds_khach_hang.tim_kiem(ma);
			if (kq) kq->hien_thi();
			else std::cout << "Khong tim thay!\n";
			break;
		}
		case 2: {
			int manv;
			std::cout << "Nhap ma nhan vien can tim: ";
			std::cin >> manv;
			std::cin.ignore();
			NhanVien* kq = ds_nhan_vien.tim_kiem(manv);
			if (kq) kq->hien_thi();
			else std::cout << "Khong tim thay!\n";
			break;
		}
		case 3: {
			std::cout << "Nhap ma phuong tien can tim: ";
			std::getline(std::cin, ma);
			PhuongTien* kq = ds_phuong_tien.tim_kiem(ma);
			if (kq) kq->hien_thi();
			else std::cout << "Khong tim thay!\n";
			break;
		}
		case 4: {
			std::cout << "Nhap ma dia danh can tim: ";
			std::getline(std::cin, ma);
			DiaDanh* kq = ds_dia_danh.tim_kiem(ma);
			if (kq) kq->hien_thi();
			else std::cout << "Khong tim thay!\n";
			break;
		}
		case 5: {
			std::cout << "Nhap ma luu tru can tim: ";
			std::getline(std::cin, ma);
			LuuTru* kq = ds_luu_tru.tim_kiem(ma);
			if (kq) kq->hien_thi();
			else std::cout << "Khong tim thay!\n";
			break;
		}
		case 6: {
			std::cout << "Nhap ma thanh toan can tim: ";
			std::getline(std::cin, ma);
			ThanhToan* kq = ds_thanh_toan.tim_kiem(ma);
			if (kq) kq->hien_thi();
			else std::cout << "Khong tim thay!\n";
			break;
		}
		case 0:
			std::cout << "Thoat khoi che do tim kiem.\n";
			break;
		default:
			std::cout << "Lua chon khong hop le. Vui long nhap lai.\n";
		}
	} while (chon != 0);
}

void CongTy::sap_xep() {
	int chon;
	do {
		cout << "\n=== ADMIN SAP XEP DU LIEU ===\n";
		cout << "1. Sap xep khach hang\n";
		cout << "2. Sap xep nhan vien\n";
		cout << "3. Sap xep phuong tien\n";
		cout << "4. Sap xep dia danh\n";
		cout << "5. Sap xep luu tru\n";
		cout << "6. Sap xep thanh toan\n";
		cout << "7. Sap xep dich vu (dang bao tri)\n";
		cout << "0. Thoat\n";
		cout << "Nhap lua chon: ";
		cin >> chon;
		cin.ignore();

		switch (chon) {
		case 1:
			ds_khach_hang.bubble_sort_ten();
			break;
		case 2:
			ds_nhan_vien.bubble_sort_ten();
			break;
		case 3:
			ds_phuong_tien.bubble_sort_theo_trang_thai();
			break;
		case 4:
			ds_dia_danh.insertion_sort_gia();
			break;
		case 5:
			ds_luu_tru.bubble_sort_theo_trang_thai();
			break;
		case 6:
			ds_thanh_toan.bubble_sort_loai();
			break;
		case 0:
			cout << "Thoat khoi che do sap xep.\n";
			break;
		default:
			cout << "Lua chon khong hop le. Vui long nhap lai.\n";
		}
	} while (chon != 0);
}

void CongTy::chinh_sua() {
	int chon;
	do {
		cout << "\n=== ADMIN CHINH SUA DU LIEU ===\n";
		cout << "1. Chinh sua khach hang\n";
		cout << "2. Chinh sua nhan vien\n";
		cout << "3. Chinh sua phuong tien\n";
		cout << "4. Chinh sua dia danh\n";
		cout << "5. Chinh sua luu tru\n";
		cout << "6. Chinh sua thanh toan\n";
		cout << "0. Thoat\n";
		cout << "Nhap lua chon: ";
		cin >> chon;
		cin.ignore();

		string ma;
		switch (chon) {
		case 1:
			cout << "Nhap ma khach hang can chinh sua: ";
			getline(cin, ma);
			ds_khach_hang.chinh_sua(ma);
			ds_khach_hang.hien_thi();
			break;
		case 2:
			int mannv;
			cout << "Nhap ma nhan vien can chinh sua: ";
			cin >> mannv;
			ds_nhan_vien.chinh_sua(mannv);
			ds_nhan_vien.hien_thi();
			break;
		case 3:
			cout << "Nhap ma phuong tien can chinh sua: ";
			getline(cin, ma);
			ds_phuong_tien.chinh_sua(ma);
			ds_phuong_tien.hien_thi();
			break;
		case 4:
			cout << "Nhap ma dia danh can chinh sua: ";
			getline(cin, ma);
			ds_dia_danh.chinh_sua(ma);
			ds_dia_danh.hien_thi();
			break;
		case 5:
			cout << "Nhap ma luu tru can chinh sua: ";
			getline(cin, ma);
			ds_luu_tru.chinh_sua(ma);
			ds_luu_tru.hien_thi();
			break;
		case 6:
			cout << "Nhap ma thanh toan can chinh sua: ";
			getline(cin, ma);
			ds_thanh_toan.chinh_sua(ma);
			ds_thanh_toan.hien_thi();
			break;
		case 7:
			cout << "Nhap ma dich vu can chinh sua: ";
			getline(cin, ma);
			this->chinh_sua();
			this->hien_thi();
			break;
		case 0:
			cout << "Thoat khoi che do chinh sua.\n";
			break;
		default:
			cout << "Lua chon khong hop le. Vui long nhap lai.\n";
		}

	} while (chon != 0);
}

void CongTy::hien_thi_menu_admin() {
	int che_do;

	do {
		cout << "\n=== MENU ADMIN ===\n";
		cout << "1. Nhap du lieu\n";
		cout << "2. Hien thi du lieu\n";
		cout << "3. Tim kiem du lieu\n";
		cout << "4. Sap xep du lieu\n";
		cout << "5. Chinh sua du lieu\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "==================================================\n";
		cout << "Nhap che do: ";
		cin >> che_do;
		cin.ignore();

		switch (che_do) {
		case 1:
			this->nhap();
			break;
		case 2:
			this->hien_thi();
			break;
		case 3:
			this->tim_kiem();
			break;
		case 4:
			this->sap_xep();
			break;
		case 5:
			this->chinh_sua();
			break;
		case 0:
			cout << "\nDa thoat chuong trinh. Tam biet!\n";
			break;
		default:
			cout << "\nLua chon khong hop le. Vui long thu lai!\n";
			break;
		}
	} while (che_do != 0);
}

