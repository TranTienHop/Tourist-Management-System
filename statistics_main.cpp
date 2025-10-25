#include<iostream> 
#include"statistics.h"

using namespace std;

 int main() {
    BookingList list;   
    statistics s;           

    int choice;
    do {
        cout << "\n========== MENU THONG KE ==========\n";
        cout << "1. In thong tin thong ke\n"; 
        cout << "2. Cap nhat thong ke\n";
        cout << "3. Xoa thong ke\n";
        cout << "4. Sap xep danh sach booking\n";
        cout << "5. Tim kiem thong ke\n";
        cout << "6. Luu thong ke ra file\n";
        cout << "0. Thoat\n";
        cout << "===================================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\n--- In thong tin thong ke ---\n";
            s.printf_thong_ke();
            break;
        }

        case 2: {
        	cout << "\n--- Cap nhat thong ke ---\n";
            s.update_thong_ke(list);
            cout << "Da cap nhat thong ke thanh cong.\n";
            break;
        }

        case 3: {
            cout << "\n--- Xoa thong ke ---\n";
            s.delete_thong_ke();
            break;
        }

        case 4: {
            cout << "\n--- Sap xep danh sach ---\n";
            int type;
            cout << "1. Theo ma khach hang\n";
            cout << "2. Theo ma tour\n";
            cout << "Chon kieu sap xep: ";
            cin >> type;
            if (type == 1)
                s.sort_customer(list);
            else if (type == 2)
                s.sort_tour(list);
            else
                cout << "Lua chon khong hop le.\n";
            break;
        }

        case 5: {
            cout << "\n--- Tim kiem thong ke ---\n";
            s.search(list);
            break;
        }

        case 6: {
            cout << "\n--- Luu file thong ke ---\n";
            s.save_file_thong_ke();
            break;
        }

        case 0:
            cout << "Thoat chuong trinh.\n";
            break;

        default:
            cout << "Lua chon khong hop le, vui long nhap lai.\n";
        }

    } while (choice != 0);

    return 0;
}


