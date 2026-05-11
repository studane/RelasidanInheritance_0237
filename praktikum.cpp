#include <iostream>
#include <vector>
using namespace std;

class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    User(string nama, string email) {
        this->id = generateId();
        this->nama = nama;
        this->email = email;
    }

    static int generateId() {
        return ++globalId;
    }

    int getId() {
        return id;
    }

    string getNama() {
        return nama;
    }

    string getEmail() {
        return email;
    }
};

int User::globalId = 0;

class Member : public User {
private:
    bool status;

public:
    Member(string nama, string email, bool status = true)
        : User(nama, email) {
        this->status = status;
    }

    void showProfile() {
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : " << (status ? "Aktif" : "Nonaktif") << endl;
        cout << "------------------------" << endl;
    }

    void setStatus(bool statusBaru) {
        status = statusBaru;
    }

    bool getStatus() {
        return status;
    }
};

class Admin : public User {
public:
    Admin(string nama, string email)
        : User(nama, email) {}

    void showAllMember(vector<Member>& daftarMember) {
        cout << "\n=== Daftar Member ===\n";
        for (int i = 0; i < daftarMember.size(); i++) {
            daftarMember[i].showProfile();
        }
    }

    void toggleActivationMember(Member& member) {
        member.setStatus(!member.getStatus());
        cout << "Status member berhasil diubah!\n";
    }
};

int main() {
    Member m1("Andi", "andi@gmail.com");
    Member m2("Budi", "budi@gmail.com", false);

    vector<Member> daftarMember;
    daftarMember.push_back(m1);
    daftarMember.push_back(m2);

    Admin admin("Super Admin", "admin@gmail.com");

    admin.showAllMember(daftarMember);

    admin.toggleActivationMember(daftarMember[0]);

    admin.showAllMember(daftarMember);

    return 0;
}