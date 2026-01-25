#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    string tenSach;
    int id;

    Book() {}
    Book(int id, string ten) : id(id), tenSach(ten) {}

    void input() {
        cout << "Nhap ID sach: ";
        cin >> id;
        cin.ignore();
        cout << "Nhap ten sach: ";
        getline(cin, tenSach);
    }

    void display() {
        cout << "ID: " << id << " - Ten: " << tenSach << endl;
    }
};

class BookManager {
private:
    Book p[100];
    int size;

public:
    BookManager() {
        size = 0;
    }

    void hienThi() {
        cout << "\n--- DANH SACH SACH ---\n";
        if (size == 0) {
            cout << "Danh sach trong!\n";
        } else {
            for (int i = 0; i < size; i++) {
                p[i].display();
            }
        }
    }

    void themMoi() {
        if (size >= 100) {
            cout << "Danh sach da day!\n";
            return;
        }
        cout << "\n--- THEM SACH MOI ---\n";
        Book b;
        b.input();
        p[size] = b;
        size++;
        cout << "Them thanh cong!\n";
    }

    void capNhat() {
        int id;
        cout << "\nNhap ID sach can sua: ";
        cin >> id;
        
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (p[i].id == id) {
                cout << "Nhap thong tin moi:\n";
                cin.ignore(); 
                cout << "Nhap ten sach moi: "; 
                getline(cin, p[i].tenSach);
                cout << "Cap nhat thanh cong!\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "Khong tim thay ID nay!\n";
    }

    void xoa() {
        int id;
        cout << "\nNhap ID sach can xoa: ";
        cin >> id;

        int index = -1;
        for (int i = 0; i < size; i++) {
            if (p[i].id == id) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int i = index; i < size - 1; i++) {
                p[i] = p[i + 1];
            }
            size--;
            cout << "Xoa thanh cong!\n";
        } else {
            cout << "Khong tim thay ID nay!\n";
        }
    }
};

int main() {
    BookManager manager;
    int choice;

    do {
        cout << "\n=================== MENU ===================\n";
        cout << "1. Hien thi danh sach\n";
        cout << "2. Them moi sach\n";
        cout << "3. Cap nhat thong tin\n";
        cout << "4. Xoa sach\n";
        cout << "0. Thoat\n";
        cout << "\n============================================\n";
		cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.hienThi(); break;
            case 2: manager.themMoi(); break;
            case 3: manager.capNhat(); break;
            case 4: manager.xoa(); break;
            case 0: cout << "Tam biet!"; break;
            default: cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}
