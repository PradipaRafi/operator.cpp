#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk input nomor telepon
void inputNumber(string &phoneNumber) {
    cout << "Masukkan nomor telepon: ";
    cin >> phoneNumber;
}

// Fungsi untuk input jumlah pulsa
void inputCredit(int &credit) {
    cout << "Masukkan jumlah pulsa: ";
    cin >> credit;
}

// Fungsi untuk konfirmasi pengiriman
bool confirm() {
    char choice;
    cout << "Konfirmasi pengiriman? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

// Fungsi untuk mengirim pulsa
void sendCredit(const string &phoneNumber, int credit) {
    cout << "Mengirim pulsa sebesar " << credit << " ke nomor " << phoneNumber << endl;
}

int main() {
    string phoneNumber;
    int credit;
    int menuChoice;
    bool confirmation;

    while (true) {
        // Menu utama
        cout << "1. Input Nomor Telepon" << endl;
        cout << "2. Input Pulsa" << endl;
        cout << "3. Konfirmasi" << endl;
        cout << "4. Kirim Pulsa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menuChoice;

        switch (menuChoice) {
            case 1:
                inputNumber(phoneNumber);
                break;
            case 2:
                inputCredit(credit);
                break;
            case 3:
                confirmation = confirm();
                break;
            case 4:
                if (confirmation) {
                    sendCredit(phoneNumber, credit);
                } else {
                    cout << "Pengiriman dibatalkan." << endl;
                }
                break;
            case 5:
                return 0; // Keluar dari program
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}