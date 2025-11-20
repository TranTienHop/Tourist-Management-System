#include"CongTy.h"

int main() {

    CongTy compiny;
    compiny.doc_file();

    int lua_chon;

    do {
        cout << "\n========= CHUONG TRINH QUAN LY DU LICH =========\n";
        cout << "1. Che Do Admin\n";
        cout << "2. Quan ly khach hang\n";
        cout << "3. Quan ly nhan vien\n";
        cout << "4. Quan ly phuong tien\n";
        cout << "5. Quan ly dia danh\n";
        cout << "6. Quan ly luu tru\n";
        cout << "7. Quan ly thanh toan\n";
        cout << "8. Quan ly dich vu\n";
        cout << "9. Quan li doanh thu\n";
        cout << "10. Thong ke\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "===============================================\n";
        cout << "Nhap che do: ";
        cin >> lua_chon;
        cin.ignore(); 

        switch (lua_chon) {
        case 1:
            cout << "\n=== CHE DO: ADMIN ===\n";
            compiny.hien_thi_menu_admin();
            break;
        case 2:
            cout << "\n=== CHE DO: QUAN LY KHACH HANG ===\n";
            compiny.hien_thi_menu_khach_hang();
            break;
        case 3:
            cout << "\n=== CHE DO: QUAN LY NHAN VIEN ===\n";
            compiny.hien_thi_menu_nhan_vien();
            break;
        case 4:
            cout << "\n=== CHE DO: QUAN LY PHUONG TIEN ===\n";
            compiny.hien_thi_menu_phuong_tien();
            break;
        case 5:
            cout << "\n=== CHE DO: QUAN LY DIA DANH ===\n";
            compiny.hien_thi_menu_dia_danh();
            break;
        case 6:
            cout << "\n=== CHE DO: QUAN LY LUU TRU ===\n";
            compiny.hien_thi_menu_luu_tru();
            break;
        case 7:
            cout << "\n=== CHE DO: QUAN LY THANH TOAN ===\n";
            compiny.hien_thi_menu_thanh_toan();
            break;
        case 8:
            cout << "\n=== CHE DO: QUAN LY DICH VU ===\n";
            compiny.hien_thi_menu_dich_vu();
            break;
        case 9:
            cout << "\n=== CHE DO: QUAN LY DOANH THU ===\n";
            compiny.hien_thi_menu_doanh_thu();
            break;
        case 10:
            cout << "\n=== CHE DO: THONG KE ===\n";
            compiny.hien_thi_menu_thong_ke();
            break;
        case 0:
            cout << "\nDa thoat chuong trinh. Tam biet!\n";
            break;
        default:
            cout << "\nLua chon khong hop le. Vui long thu lai!\n";
            break;
        }
    } while (lua_chon != 0);

    return 0;

}
