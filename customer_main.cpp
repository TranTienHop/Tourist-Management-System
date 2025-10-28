#include"customer.h"
using namespace std;


    int main() {
        CustomerList customers;

        // 1. Tự động đọc danh sách khách hàng từ file khi bắt đầu
        customers.load_from_file("customer.txt");
        cout << "Danh sach khach hang hien tai:\n";
        customers.display_all();

        int choice;
        string id;

        do {
            cout << "\n===== QUAN LY KHACH HANG =====\n";
            cout << "1. Them khach hang\n";
            cout << "2. Hien thi tat ca khach hang\n";
            cout << "3. Tim khach hang theo ID\n";
            cout << "4. Cap nhat khach hang\n";
            cout << "5. Xoa khach hang\n";
            cout << "6. Luu danh sach vao file\n";
            cout << "7. Doc danh sach tu file\n";
            cout << "0. Thoat\n";
            cout << "Chon chuc nang: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
            case 1: {
                Customer c;
                c.input();
                customers.add_customer(c);
                break;
            }
            case 2:
                customers.display_all();
                break;
            case 3:
                cout << "Nhap ID khach hang can tim: ";
                getline(cin, id);
                {
                    Node* found = customers.search_by_id(id);
                    if (found)
                        found->data.display();
                    else
                        cout << "Khong tim thay khach hang!\n";
                }
                break;
            case 4:
                cout << "Nhap ID khach hang can cap nhat: ";
                getline(cin, id);
                customers.update_customer(id);
                break;
            case 5:
                cout << "Nhap ID khach hang can xoa: ";
                getline(cin, id);
                customers.remove_customer(id);
                break;
            case 6:
                customers.save_to_file("customer.txt");
                cout << "Da luu danh sach vao customer.txt\n";
                break;
            case 7:
                customers.load_from_file("customer.txt");
                cout << "Da doc danh sach tu customer.txt\n";
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Nhap lai!\n";
            }
        } while (choice != 0);

        return 0;
    }


