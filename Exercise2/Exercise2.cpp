#include <iostream>
using namespace std;

class bidangDatar {
private:
    int x; // variabel untuk menyimpan input dari lingkaran maupun bujursangkar
public:
    bidangDatar() { // constructor
        x = 0;
    }
    virtual void input() = 0; // fungsi yang menerima input dan mengirim input melalui fungsi setX untuk disimpan di x
    virtual float Luas(int a) = 0; // fungsi untuk menghitung luas
    virtual float Keliling(int a) = 0; // fungsi untuk menghitung keliling
    void setX(int a) { // fungsi untuk memberi/mengirim nilai pada x
        this->x = a;
    }
    int getX() { // fungsi untuk membaca/mengambil nilai dalam x
        return x;
    }
};

class Lingkaran : public bidangDatar {
public:
    void input() {
        cout << "Masukkan jejari: ";
        int r;
        cin >> r;
        setX(r);
    }

    float Luas(int r) {
        return 3.14 * r * r;
    }

    float Keliling(int r) {
        return 2 * 3.14 * r;
    }
};

class Bujursangkar : public bidangDatar {
public:
    void input() {
        cout << "Masukkan sisi: ";
        int s;
        cin >> s;
        setX(s);
    }

    float Luas(int s) {
        return s * s;
    }

    float Keliling(int s) {
        return 4 * s;
    }
};

int main() {
    bidangDatar* a;

    cout << "Lingkaran dibuat" << endl;
    a = new Lingkaran();
    a->input();
    int r = a->getX();
    cout << "Luas Lingkaran = " << a->Luas(r) << endl;
    cout << "Keliling Lingkaran = " << a->Keliling(r) << endl;

    cout << "\nBujursangkar dibuat" << endl;
    a = new Bujursangkar();
    a->input();
    int s = a->getX();
    cout << "Luas Bujursangkar = " << a->Luas(s) << endl;
    cout << "Keliling Bujursangkar = " << a->Keliling(s) << endl;

    delete a;
    return 0;
}