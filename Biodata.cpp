//Code Pengisian Biodata
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

struct User {
    string nama;
    int umur;
    char gender;
    double tb;
    double bb;
    int aktivitas;
};

//Display Menu yang Akan Dipilih Pengguna
void displayMenu() {
    cout << "\n---------------------------\n";
    cout << "        DIETRACKER\n";
    cout << "Simple Diet Planning System\n";
    cout << "---------------------------\n";
    cout << "1. Input Data User\n";
    cout << "2. Display User Profile\n";
    cout << "3. Calculate BMI\n";
    cout << "4. Nutrition Calculator\n";
    cout << "5. Calorie Target\n";
    cout << "6. Food Recommendation\n";
    cout << "0. Exit Program\n";
    cout << "---------------------------\n";
    cout << "Masukkan Pilihan Anda: ";
}

//Pengguna Memasukkan Data
void inputprofile(User &user) {
    cout << "\n---------------------------\n";
    cout << "    INPUT USER PROFILE\n";
    cout << "---------------------------\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Masukkan Nama" << right << setw(17) << ": ";
    getline(cin, user.nama);
    
    cout << "Masukkan Umur" << right << setw(17) << ": ";
    cin >> user.umur;

    cout << "Masukkan Jenis Kelamin (L/P): ";
    cin >> user.gender;

    cout << "Masukkan Tinggi Badan (cm)" << right << setw(4) << ": ";
    cin >> user.tb;

    cout << "Masukkan Berat Badan (kg)" << right << setw(5) << ": ";
    cin >> user.bb;

    cout << "\nLevel Aktivitas:\n";
    cout << "1. Tidak Aktif\n";
    cout << "2. Sedikit Aktif\n";
    cout << "3. Cukup Aktif\n";
    cout << "4. Sangat Aktif\n";
    cout << "5. Ekstra Aktif\n";
    cout << "Pilih Level Aktivitas" << right << setw(9) << ": ";
    cin >> user.aktivitas;

    cout << "\n---------------------------\n";
    cout << "  Data Berhasil Disimpan!\n";
    cout << "---------------------------\n";
}

//Tampilan Profil Pengguna
void displayProfile(const User &user) {
    cout << "\n---------------------------\n";
    cout << "       USER PROFILE\n";
    cout << "---------------------------\n";

    cout << "Nama" << right << setw(13) << ": " << user.nama << endl;
    cout << "Umur" << right << setw(13) << ": " <<  user.umur << " tahun" << endl;
    cout << "Jenis Kelamin" << right << setw(4) << ": " << user.gender << endl;
    cout << "Tinggi Badan" << right << setw(5) << ": " << user.tb << " cm" << endl;
    cout << "Berat Badan" << right << setw(6) << ": " <<  user.bb << " kg" << endl;
    cout << "Level Aktivitas: " << user.aktivitas << endl;
}