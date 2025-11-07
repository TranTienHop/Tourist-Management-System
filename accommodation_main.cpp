#include <iostream>
#include <vector>
#include <string>
#include "accommodation.h"

using namespace std;

void menuHotel(vector<Accommodation*>& list) {
    int choice;

    do {
        cout << "\n====== MENU HOTEL ======\n";
        cout << "1. Them Hotel\n";
        cout << "2. Hien thi Hotel\n";
        cout << "3. Cap nhat Hotel\n";
        cout << "4. Xoa Hotel\n";
        cout << "5. Tim kiem Hotel\n";
        cout << "6. Luu vao file\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        if (choice == 1) {
            Hotel* h = new Hotel();
            h->input();
            list.push_back(h);
        }

        else if (choice == 2) {
            cout << "\n==== DANH SACH HOTEL ====\n";
            for (auto a : list)
                if (dynamic_cast<Hotel*>(a))
                    a->display();
        }

        else if (choice == 3) {
            string id;
            cout << "Nhap ma hotel muon cap nhat: ";
            getline(cin, id);

            for (auto a : list)
                if (Hotel* h = dynamic_cast<Hotel*>(a))
                    if (h->get_accommodation_id() == id)
                        h->update();
        }

        else if (choice == 4) {
            string id;
            cout << "Nhap ma hotel muon xoa: ";
            getline(cin, id);

            for (auto a : list)
                if (Hotel* h = dynamic_cast<Hotel*>(a))
                    if (h->get_accommodation_id() == id)
                        h->remove();
        }

        else if (choice == 5) {
            string name;
            cout << "Nhap ten hotel: ";
            getline(cin, name);

            for (auto a : list)
                if (Hotel* h = dynamic_cast<Hotel*>(a))
                    if (h->get_name().find(name) != string::npos)
                        h->display();
        }

        else if (choice == 6) {
            for (auto a : list)
                if (Hotel* h = dynamic_cast<Hotel*>(a))
                    h->save_to_file();
        }

    } while (choice != 0);
}

void menuMotel(vector<Accommodation*>& list) {
    int choice;

    do {
        cout << "\n====== MENU MOTEL ======\n";
        cout << "1. Them Motel\n";
        cout << "2. Hien thi Motel\n";
        cout << "3. Cap nhat Motel\n";
        cout << "4. Xoa Motel\n";
        cout << "5. Tim kiem Motel\n";
        cout << "6. Luu vao file\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        if (choice == 1) {
            Motel* m = new Motel();
            m->input();
            list.push_back(m);
        }

        else if (choice == 2) {
            cout << "\n==== DANH SACH MOTEL ====\n";
            for (auto a : list)
                if (dynamic_cast<Motel*>(a))
                    a->display();
        }

        else if (choice == 3) {
            string id;
            cout << "Nhap ma motel muon cap nhat: ";
            getline(cin, id);

            for (auto a : list)
                if (Motel* m = dynamic_cast<Motel*>(a))
                    if (m->get_accommodation_id() == id)
                        m->update();
        }

        else if (choice == 4) {
            string id;
            cout << "Nhap ma motel muon xoa: ";
            getline(cin, id);

            for (auto a : list)
                if (Motel* m = dynamic_cast<Motel*>(a))
                    if (m->get_accommodation_id() == id)
                        m->remove();
        }

        else if (choice == 5) {
            string name;
            cout << "Nhap ten motel: ";
            getline(cin, name);

            for (auto a : list)
                if (Motel* m = dynamic_cast<Motel*>(a))
                    if (m->get_name().find(name) != string::npos)
                        m->display();
        }

        else if (choice == 6) {
            for (auto a : list)
                if (Motel* m = dynamic_cast<Motel*>(a))
                    m->save_to_file();
        }

    } while (choice != 0);
}


int main() {
    vector<Accommodation*> list;
    int choice;

    readFromFile("Accommodation.txt", list);

    do {
        cout << "\n========== MENU CHINH ==========\n";
        cout << "1. Quan ly Hotel\n";
        cout << "2. Quan ly Motel\n";
        cout << "3. Hien thi tat ca\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            menuHotel(list);
            break;

        case 2:
            menuMotel(list);
            break;

        case 3:
            cout << "\n===== DANH SACH TAT CA =====\n";
            for (auto a : list) {
                a->display();
                cout << "\n---------------------------\n";
            }
            break;

        case 0:
            cout << "Thoat chuong trinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
            break;
        }
    } while (choice != 0);

    for (auto a : list) delete a;
    list.clear();

    return 0;
}


