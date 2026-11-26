#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

struct user
{
    string nama;
    int umur;
    char gender;
    double tb;
    double bb;
    int aktivitas;
};

void profile(user &user){
    cout << left << setw(10) << "\nInput User Profile\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukkan Nama: ";
    getline(cin, user.nama);

    cout << "Masukkan Umur: ";
    cin >> user.umur;

    cout << "Masukkan Jenis Kelamin (L/P): ";
    cin >> user.gender;

    cout << "Masukkan Tinggi Badan (cm): ";
    cin >> user.tb;

    cout << "Masukkan Berat Badan (kg): ";
    cin >> user.bb;
        cout << "\nLevel Aktivitas:\n";
    cout << "1. Tidak Aktif\n";
    cout << "2. Sedikit Aktif\n";
    cout << "3. Cukup Aktif\n";
    cout << "4. Sangat Aktif\n";
    cout << "5. Ekstra Aktif\n";

    cout << "Pilih Level Aktivitas: ";
    cin >> user.aktivitas;

    cout << "\nData Berhasil Disimpan!\n";
}

void displayProfile(const user &user) {
    cout << "\n===== USER PROFILE =====\n";

    cout << "Nama: " << user.nama << endl;
    cout << "Umur: " << user.umur << " tahun" << endl;
    cout << "Jenis Kelamin: " << user.gender << endl;
    cout << "Tinggi Badan: " << user.tb << " cm" << endl;
    cout << "Berat Badan: " << user.bb << " kg" << endl;
    cout << "Level Aktivitas: " << user.aktivitas << endl;
}

int main(){

}