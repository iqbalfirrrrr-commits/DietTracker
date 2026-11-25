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
    int aktifitas;
};

void displayMenu() {
    cout << "\n==============================\n";
    cout << "          DIETRACKER\n";
    cout << "   Simple Diet Planning System\n";
    cout << "==============================\n";

    cout << "1. Input Data User\n";
    cout << "2. Display User Profile\n";
    cout << "3. Calculate BMI\n";
    cout << "4. Nutrition Calculator\n";
    cout << "0. Exit Program\n";

    cout << "------------------------------\n";
    cout << "Masukkan Pilihan Anda: ";
}

void inputprofile(User &user) {
    cout << "\n===== INPUT USER PROFILE =====\n";

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
    cin >> user.aktifitas;

    cout << "\nData Berhasil Disimpan!\n";
}

void displayProfile(const User &user) {
    cout << "\n===== USER PROFILE =====\n";

    cout << "Nama: " << user.nama << endl;
    cout << "Umur: " << user.umur << " tahun" << endl;
    cout << "Jenis Kelamin: " << user.gender << endl;
    cout << "Tinggi Badan: " << user.tb << " cm" << endl;
    cout << "Berat Badan: " << user.bb << " kg" << endl;
    cout << "Level Aktivitas: " << user.aktifitas << endl;
}

double calculateBMI(const User &user) {
    double tinggiMeter = user.tb / 100;

    double bmi = user.bb / (tinggiMeter * tinggiMeter);
    return bmi;
}

void displayBMI(const User &user) {
    cout << "\n===== BMI CALCULATOR =====\n";

    if (user .tb <= 0 || user.bb <= 0) {
        cout << "Data tinggi atau berat badan tidak valid!\n";
        return;
    }
    
    double bmi = calculateBMI(user);

    cout << "Nilai BMI: " << bmi << endl;

    if (user.umur < 18) {
        cout << "Kategori BMI tidak berlaku untuk anak-anak dibawah 18 tahun.\n";
    }

    else if (bmi < 18.5) {
        cout << "Kategori: Berat Badan Kurang.\n";
    }

    else if (bmi < 25) {
        cout << "Kategori: Normal.\n";
    }

    else if (bmi < 30) {
        cout << "Kategori: Berat Badan Berlebih.\n";
    }

    else {
        cout << "Kategori: Obesitas.\n";
    }
}

double calculateBMR(const User &user) {
    double bmr;

    if (user.gender == 'L') {
        bmr = (10 * user.bb) + (6.25 * user.tb) - (5 * user.umur) + 5;
    } else {
        bmr = (10 * user.bb) + (6.25 * user.tb) - (5 * user.umur) - 161;
    }
    return bmr;
}

double getActivityFactor(int aktifitas) {
    switch (aktifitas) {
        case 1:
            return 1.20;
        case 2:
            return 1.375;
        case 3:
            return 1.55;
        case 4:
            return 1.725;
        case 5:
            return 1.9;
        default:
            return 0;
        }
    }

double calculateTDEE(double bmr, double faktorAktifitas) {
    double tdee = bmr * faktorAktifitas;

    return tdee;
}

double calculateCaloriesTarget (double tdee, int goal) {
    double target;

    if (goal == 1) {
        target = tdee;
    } else if (goal == 2) {
        target = tdee - 300;
    } else {
        return 0;
    } 
    return target;
}

void displayCaloriesTarget(const User &user) {
    cout << "\n===== CALORIES TARGET =====\n";

    if (user.umur < 18) {
        cout << "Estimasi target kalori tidak berlaku untuk dibawah 18 tahun.\n";
        return;
    }

    if (user.tb <= 0 || user.bb <= 0) {
        cout << "Data Tinggi Badan atau Berat Badan tidak valid!\n";
        return;
    }

    if (user.gender != 'L' && user.gender != 'l' && user.gender != 'P' && user.gender != 'p') {
        cout << "Jenis Kelamin tidak valid!.\n";
        return;
    }

    double faktorAktifitas = getActivityFactor(user.aktifitas);

    if (faktorAktifitas == 0) {
        cout << "Level Aktivitas Tidak Valid!\n";
        return;
    }

    double bmr = calculateBMR(user);
    double tdee = calculateTDEE(bmr, faktorAktifitas);

    int goal;

    cout << "\nPilih Tujuan Diet:\n";
    cout << "1. Menjaga Berat Badan\n";
    cout << "2. Menurunkan Berat Badan (estimasi penurunan berat badan)\n";
    cout << "Masukkan Pilihan: "; cin >> goal;

    double target = calculateCaloriesTarget(tdee, goal);

    if (target == 0) {
        cout << "Pilihan Tujuan Diet Tidak Valid!\n";
        return;
    }

    if (goal == 2 && target < 1500) {
        cout << "Target hasil perhitungan terlalu rendah. Hubungi pihak Rumah Sakit!\n";
        cout << "Konsultasikan target kalori dengan tenaga kesehatan.\n";
        return;
    }

    cout << fixed << setprecision(2);

    cout << "TDEE: " << tdee << " kkal/hari\n";

    if (goal == 1){
        cout << "Tujuan Maintenence\n";
    }
    else {
        cout << "Tujuan: Weight Loss\n";
        cout << "Defisit Kalori: 300 kkal/hari\n";
    }
    cout << "Target Kalori: " << target << "kkal/hari\n";
    cout << "\nCatatan: Hasil ini hanya estimasi, bukan saran medis.\n";
}

void displayNutrition(const User &user) {
    cout << "\n===== NUTRITION CALCULATOR =====\n";

    if (user.umur < 18) {
        cout << "Perhitungan Tidak berlaku untuk dibawah 18 tahun.";
        return;
    }

    if (user.tb <= 0 || user.bb <= 0) {
        cout << "Data tinggi atau berat badan tidak valid!\n";
        return;
    }

    if (user.gender != 'L' && user.gender != 'l' && user.gender != 'P' && user.gender != 'p') {
        cout << "Data Jenis Tidak Valid!. Gunakan L atau P";
        return;
    }

    double faktorAktifitas = getActivityFactor(user.aktifitas);

    if (faktorAktifitas == 0) {
        cout << "Level Aktivitas Tidak Valid!";
        return;
    }

    double bmr = calculateBMR(user);
    double tdee = calculateTDEE(bmr, faktorAktifitas);

    cout << fixed << setprecision(2);
    cout << "BMR (Basal Metabolic Rate): " << bmr << " kkal/hari" << endl;
    cout << "Faktor Aktivitas: " << faktorAktifitas << endl;
    cout << "TDEE (Total Daily Energy Expenditure): " << tdee << " kkal/hari" << endl;
}
int main () {
    User user;
    int choice = -1;
    bool profileExists = false;

    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                inputprofile(user);
                profileExists = true;
                break;
                
                case 2:
                    if (profileExists) {
                        displayProfile(user);
                } else {
                    cout << "\nData User Belum Dimasukkan!\n";
                }
                break;

                case 3:
                    if (profileExists) {
                        displayBMI(user);
                    } else {
                        cout << "\nSilahkan Masukkan Data User Terlebih Dahulu!\n";
                    }
                    break;

                case 4:
                    if (profileExists) {
                        displayNutrition(user);
                    } else {
                        cout << "\nSilahkan Masukkan Data User Terlebih Dahulu!\n";
                    }
                    break;

                case 0: 
                    cout << "\nTerima Kasih Telah Menggunakan DIETRACKER\n";
                    break;

                default:
                    cout << "\nPilihan Invalid!\n";
                
        }
    } while (choice != 0);

    return 0;
    
}
