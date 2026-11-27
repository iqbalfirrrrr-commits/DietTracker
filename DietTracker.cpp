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

double calculateBMI(const User &user) {
    double tinggiMeter = user.tb / 100;

    double bmi = user.bb / (tinggiMeter * tinggiMeter);
    return bmi;
}

void displayBMI(const User &user) {
    cout << "\n---------------------------\n";
    cout << "      BMI CALCULATOR\n";
    cout << "---------------------------\n";

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
        cout << "Kategori : Berat Badan Kurang.\n";
    }

    else if (bmi < 25) {
        cout << "Kategori : Normal.\n";
    }

    else if (bmi < 30) {
        cout << "Kategori : Berat Badan Berlebih.\n";
    }

    else {
        cout << "Kategori : Obesitas.\n";
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

double getActivityFactor(int aktivitas) {
    switch (aktivitas) {
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
    cout << "\n---------------------------\n";
    cout << "      CALORIES TARGET";
    cout << "\n---------------------------\n";

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

    double faktorAktivitas = getActivityFactor(user.aktivitas);

    if (faktorAktivitas == 0) {
        cout << "Level Aktivitas Tidak Valid!\n";
        return;
    }

    double bmr = calculateBMR(user);
    double tdee = calculateTDEE(bmr, faktorAktivitas);

    int goal;

    cout << "\nPilih Tujuan Diet:\n";
    cout << "1. Menjaga Berat Badan\n";
    cout << "2. Menurunkan Berat Badan (estimasi penurunan berat badan)\n";
    cout << "Masukkan Pilihan: "; 
    cin >> goal;

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

    cout << "\n---------------------------\n";
    cout <<"    HASIL CALORIE TARGET";
    cout << "\n---------------------------\n";
    cout << "TDEE" << right << setw(12) << ": " << tdee << " kkal/hari\n";

    if (goal == 1){
        cout << "Tujuan Maintenence\n";
    }
    else {
        cout << "Tujuan        : Weight Loss\n";
        cout << "Defisit Kalori: 300 kkal/hari\n";
    }
    cout << "Target Kalori : " << target << "kkal/hari\n";
    cout << "\nCatatan: Hasil ini hanya estimasi, bukan saran medis.\n";
}

void displayNutrition(const User &user) {
    cout << "\n---------------------------\n";
    cout << "    NUTRITION CALCULATOR";
    cout << "\n---------------------------\n";

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

    double faktorAktifitas = getActivityFactor(user.aktivitas);

    if (faktorAktifitas == 0) {
        cout << "Level Aktivitas Tidak Valid!";
        return;
    }

    double bmr = calculateBMR(user);
    double tdee = calculateTDEE(bmr, faktorAktifitas);

    cout << fixed << setprecision(2);
    cout << "BMR (Basal Metabolic Rate)" << right << setw(13) << ": " << bmr << " kkal/hari" << endl;
    cout << "Faktor Aktivitas" << right << setw(23) << ": " << faktorAktifitas << endl;
    cout << "TDEE (Total Daily Energy Expenditure): " << tdee << " kkal/hari" << endl;
}

void displayRekomendasiMakanan(const User &user) {
    cout << "\n---------------------------\n";
    cout << "    FOOD RECOMMENDATION";
    cout << "\n---------------------------\n";

    if (user.umur < 18) {
        cout << "Rekomendasi berdasarkan kategori BMI dewasa ";
        cout << "tidak berlaku untuk usia di bawah 18 tahun.\n";
        return;
    }

    if (user.tb <= 0 || user.bb <= 0) {
        cout << "Data tinggi atau berat badan tidak valid!\n";
        return;
    }

    double bmi = calculateBMI(user);

    cout << fixed << setprecision(2);
    cout << "BMI Anda: " << bmi << endl;

    string bulking[10] = {
        "Nasi + Ayam + Telur + Tempe         - 650-800 kkal",
        "Roti Gandum + Selai Kacang + Pisang - 350-450 kkal",
        "Smoothie Pisang + Susu + Oat        - 350-500 kkal",
        "Nasi + Daging Sapi + Sayuran        - 550-700 kkal",
        "Ubi Rebus + Telur + Susu            - 350-450 kkal",
        "Nasi + Ayam Goreng + Tempe          - 650-800 kkal",
        "Spaghetti + Daging Cincang          - 500-650 kkal",
        "Nasi + Ikan + Telur Dadar           - 550-700 kkal",
        "Alpukat + Susu + Madu               - 300-450 kkal",
        "Kentang Panggang + Keju + Ayam     - 450-600 kkal"
    };

    string stabil[10] = {
        "Nasi + Ayam Panggang + Sayur - 450-550 kkal",
        "Oatmeal + Pisang + Susu      - 300-400 kkal",
        "Nasi + Ikan Bakar + Sayuran  - 400-500 kkal",
        "Roti Gandum + Telur Rebus    - 250-350 kkal",
        "Tempe + Tahu + Sayuran       - 300-400 kkal",
        "Nasi Merah + Ayam Rebus      - 400-450 kkal",
        "Kentang Rebus + Telur        - 250-300 kkal",
        "Sup Ayam + Sayuran           - 250-350 kkal",
        "Nasi + Pepes Ikan + Lalapan  - 400-500 kkal",
        "Salad Sayur + Telur Rebus   - 200-300 kkal"
    };

    string cutting[10] = {
        "Dada Ayam Panggang + Brokoli    - 250-350 kkal",
        "Telur Rebus + Salad Sayur       - 180-250 kkal",
        "Ikan Kukus + Nasi Merah + Sayur - 350-450 kkal",
        "Yogurt Plain + Buah             - 150-220 kkal",
        "Sup Tahu + Sayuran              - 150-250 kkal",
        "Oatmeal + Apel                  - 200-250 kkal",
        "Kentang Rebus + Dada Ayam       - 250-350 kkal",
        "Tumis Kangkung + Tahu           - 150-220 kkal",
        "Pepes Ikan + Lalapan            - 200-300 kkal",
        "Salad Buah Tanpa Gula Tambahan - 150-250 kkal"
    };

    string *menu;
    string kategori;
    string saran;

    if (bmi < 18.5) {
        menu = bulking;
        kategori = "Berat Badan Kurang (Bulking)";
        saran = "Tambahkan asupan kalori dan protein secara bertahap.";
    }
    else if (bmi < 25) {
        menu = stabil;
        kategori = "Berat Badan Normal (Stabil)";
        saran = "Pertahankan pola makan bergizi dan seimbang.";
    }
    else if (bmi < 30) {
        menu = cutting;
        kategori = "Berat Badan Berlebih (Cutting)";
        saran = "Perhatikan porsi makan dan pilih makanan bergizi seimbang.";
    }
    else {
        menu = cutting;
        kategori = "Obesitas (Cutting)";
        saran = "Utamakan pola makan seimbang dan konsultasikan kebutuhan diet dengan tenaga kesehatan.";
    }

    cout << "Kategori: " << kategori << endl;
    cout << "\n---------------------------\n";
    cout << "    REKOMENDASI MAKANAN";
    cout << "\n---------------------------\n";

    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ". " << menu[i] << endl;
    }

    cout << "\n---------------------------\n";
    cout << "       SARAN MAKANAN";
    cout << "\n---------------------------\n";
    cout << saran << endl;

    cout << "\nCatatan: Kalori merupakan perkiraan dan dapat berubah sesuai porsi serta cara memasak.\n";
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

                case 5:
                    if (profileExists) {
                        displayCaloriesTarget(user);
                    } else {
                        cout << "\nSilahkan Masukkan Data User Terlebih Dahulu!\n";
                    }
                    break;

                case 6:
                    if (profileExists) {
                      displayRekomendasiMakanan(user);
                    } else {
                        cout << "\nSilahkan Masukkan Data User Terlebih Dahulu!\n";
                    }
                    break;

                case 0: 
                    cout << "\n-----------------------------------------\n";
                    cout << "Terima Kasih Telah Menggunakan DIETRACKER";
                    cout << "\n-----------------------------------------\n";
                    break;

                default:
                    cout << "\nPilihan Invalid!\n";
                
        }
    } while (choice != 0);

    return 0;
    
}
