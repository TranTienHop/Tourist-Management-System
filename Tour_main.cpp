#include <iostream>
#include "Tour.h"
using namespace std;

int main() {
    TourList list;
    int choice;
    string id;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Them tour moi\n";
        cout << "2. In danh sach tour\n";
        cout << "3. Xoa tour theo ID\n";
        cout << "4. Sua thong tin tour\n";
        cout << "5. Sap xep theo gia\n";
        cout << "6. Luu danh sach vao file\n";
        cout << "7. Doc danh sach tu file\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            list.add_tour();
            break;
        case 2:
            list.print_all_tours();
            break;
        case 3:
            cout << "Nhap ma tour can xoa: ";
            cin >> id;
            list.delete_tour(id);
            break;
        case 4:
            cout << "Nhap ma tour can sua: ";
            cin >> id;
            list.update_tour(id);
            break;
        case 5:
            list.sort_by_price();
            cout << "Da sap xep theo gia tang dan!\n";
            break;
        case 6:
            list.save_to_file();
            break;
        case 7:
            list.load_from_file();
            break;
        case 0:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}

