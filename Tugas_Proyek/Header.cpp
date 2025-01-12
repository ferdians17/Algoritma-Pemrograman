#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>
#include <commctrl.h>
#include <vector>
#include <sstream>
#include <iomanip>
#include <random>
#include <fstream>

//MENU ADMIN
#define ADMIN_MASUK 1100
#define PROSES_MASUK 1101
#define ADMIN_DAFTAR 1200
#define PROSES_DAFTAR 1201
#define ADMIN_KELUAR 1300
//MENU MAHASISWA
#define MAHASISWA_TAMBAH 2100
#define MAHASISWA_SIMPAN 2101
#define MAHASISWA_DATA 2200
#define MAHASISWA_BEDIT 2300
#define MAHASISWA_PEMBARUAN 2301
#define MAHASISWA_BDEL 2400
//MENU PENILAIAN
#define PENILAIAN_TAMBAH 3100
#define PENILAIAN_SIMPAN 3101
#define PENILAIAN_CARI 3102
#define PENILAIAN_DATA 3200
#define PENILAIAN_BEDIT 3300
#define PENILAIAN_PEMBARUAN 3301
#define PENILAIAN_BDEL 3400
//MENU PRINT
#define PRINT_MAHASISWA 4000
#define PRINT_PENILAIAN 4001
//MENU INFORMASI
#define INFORMASI_TIM 5100
#define INFORMASI_PENGGUNAAN 5200
//MENU TUTUP
#define TUTUP 6000

using namespace std;

//DATA ADMIN
struct admin
{
	string user, pass;
}Admin[3];

//DATA MAHASISWA
struct mahasiswa
{
	string npm, nama, program;
}Mahasiswa[100];

//DATA NILAI
struct nilai
{
	string id, npm, kode, mataKuliah, semester, huruf,
		   tugas, quiz, uts, uas, akhir;
} Nilai[100];

HWND username, password;
HWND npm, nama, program;
HWND id, kode, mataKuliah, semester, huruf,
	 tugas, quiz, uts, uas;
HWND dataMahasiswa, dataNilai;

bool statusLogin = false;
string idx;
		
vector<admin> vecAdmin;
vector<mahasiswa> vecMahasiswa;
vector<nilai> vecNilai;

//MENU UTAMA
void _menu(HWND hw)
{
	HMENU menu = CreateMenu();
	
	HMENU admin = CreateMenu();
	AppendMenu(admin, MF_STRING, ADMIN_MASUK, "Masuk");
	AppendMenu(admin, MF_STRING, ADMIN_DAFTAR, "Mendaftar");
	AppendMenu(admin, MF_SEPARATOR, 0, "");
	AppendMenu(admin, MF_STRING, ADMIN_KELUAR, "Keluar");
	
	HMENU mahasiswa = CreateMenu();
	AppendMenu(mahasiswa, MF_STRING, MAHASISWA_TAMBAH, "Tambah Mahasiswa");
	AppendMenu(mahasiswa, MF_STRING, MAHASISWA_DATA, "Data Mahasiswa");
	
	HMENU penilaian = CreateMenu();
	AppendMenu(penilaian, MF_STRING, PENILAIAN_TAMBAH, "Tambah Penilaian");
	AppendMenu(penilaian, MF_STRING, PENILAIAN_DATA, "Data Penilaian");
	
	HMENU informasi = CreateMenu();
	AppendMenu(informasi, MF_STRING, INFORMASI_TIM, "Informasi Tim");
	AppendMenu(informasi, MF_STRING, INFORMASI_PENGGUNAAN, "Informasi Penggunaan");
	
	HMENU cetak = CreateMenu();
	AppendMenu(cetak, MF_STRING, PRINT_MAHASISWA, "Cetak Data Mahasiswa");
	AppendMenu(cetak, MF_STRING, PRINT_PENILAIAN, "Cetak Data Penilaian");

	AppendMenu(menu, MF_POPUP, (UINT_PTR)admin, "ADMIN");
	AppendMenu(menu, MF_POPUP, (UINT_PTR)mahasiswa, "MAHASISWA");
	AppendMenu(menu, MF_POPUP, (UINT_PTR)penilaian, "PENILAIAN");
	AppendMenu(menu, MF_POPUP, (UINT_PTR)cetak, "PRINT");
	AppendMenu(menu, MF_POPUP, (UINT_PTR)informasi, "INFORMASI");
	AppendMenu(menu, MF_POPUP, TUTUP, "TUTUP");
	
	if(statusLogin == false)
	{
		EnableMenuItem(menu, ADMIN_KELUAR, MF_GRAYED);
		EnableMenuItem(menu, (UINT_PTR)mahasiswa, MF_GRAYED);
		EnableMenuItem(menu, MAHASISWA_TAMBAH, MF_GRAYED);
		EnableMenuItem(menu, MAHASISWA_DATA, MF_GRAYED);
		EnableMenuItem(menu, (UINT_PTR)penilaian, MF_GRAYED);
		EnableMenuItem(menu, PENILAIAN_TAMBAH, MF_GRAYED);
		EnableMenuItem(menu, PENILAIAN_DATA, MF_GRAYED);
		EnableMenuItem(menu, (UINT_PTR)cetak, MF_GRAYED);
		EnableMenuItem(menu, PRINT_MAHASISWA, MF_GRAYED);
		EnableMenuItem(menu, PRINT_PENILAIAN, MF_GRAYED);
	}
	else
	{
		EnableMenuItem(menu, ADMIN_MASUK, MF_GRAYED);
		EnableMenuItem(menu, ADMIN_DAFTAR, MF_GRAYED);
	}
	
	SetMenu(hw, menu);
}

void bersihkan(HWND hw)
{
	HWND baru = GetWindow(hw, GW_CHILD);
	while (baru) {
		HWND lanjut = GetWindow(baru, GW_HWNDNEXT);
		DestroyWindow(baru);
		baru = lanjut;
	}
}	
              
void idX()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(101, 999);
	int id = distrib(gen);
	idx = to_string(id);
}

void _printMahasiswa(HWND hw)
{
	idX();
	string filename = "cetak_"+idx+".dat";

    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cout << "Error: Tidak dapat membuka file!" << endl;
        return;
    }
    
	file << "NPM \tNAMA LENGKAP \t\tPROGRAM STUDI" << endl;
    
    for(auto& mhs:vecMahasiswa)
    {
    	file << mhs.npm << "\t" << mhs.nama << "\t\t\t" << mhs.program << endl;
	}

    file.close();
    
    ifstream xfile(filename);
    if (!xfile.is_open()) {
        cout << "Error: Tidak dapat membuka file!" << endl;
    }

    ofstream tempFile("temp_print.txt");
    string line;

    while (getline(xfile, line)) {
        tempFile << line << endl;
    }

    xfile.close();
    tempFile.close();

    int status = system("notepad /p temp_print.txt");
    if (status == 0) {
        MessageBox(hw, "Data dikirim ke printer!", "Berhasil", MB_OK | MB_ICONINFORMATION);
    } else {
        MessageBox(hw, "Proses Cetak gagal!", "Gagal", MB_OK | MB_ICONERROR);
    }

    remove("temp_print.txt");
}

void _printNilai(HWND hw)
{
	idX();
	string filename = "nilai_"+idx+".dat";

    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cout << "Error: Tidak dapat membuka file!" << endl;
        return;
    }HWND id, kode, mataKuliah, semester, huruf,
	 tugas, quiz, uts, uas;
    
	file << "ID \tNPM \tNAMA LENGKAP \t\tPROGRAM STUDI \t\tKODE \tMATA KULIAH \t\tSEMESTER \tNILAI TUGAS \tNILAI QUIZ \tNILAI UTS \tNILAI UAS \tNILAI TOTAL \tNILAI HURUF" << endl;
    
    for(auto& n:vecNilai)
    {
    	for(auto& mhs:vecMahasiswa)
    	{
    		if(strcmp(n.npm.c_str(), mhs.npm.c_str()) == 0)
    		{
    			file << n.id << "\t" << mhs.nama << "\t\t\t" << mhs.program << "\t\t\t";
    			file << n.kode << "\t" << n.mataKuliah << "\t\t\t" << n.semester << "\t\t";
    			file << n.tugas << "\t\t" << n.quiz << "\t\t" << n.uts << "\t\t" << n.uas << "\t\t";
    			file << n.akhir << "\t\t" << n.huruf << "\n";
			}
		}
	}

    file.close();
    
    ifstream xfile(filename);
    if (!xfile.is_open()) {
        cout << "Error: Tidak dapat membuka file!" << endl;
    }

    ofstream tempFile("temp_print.txt");
    string line;

    while (getline(xfile, line)) {
        tempFile << line << endl;
    }

    xfile.close();
    tempFile.close();

    int status = system("notepad /p temp_print.txt");
    if (status == 0) {
        MessageBox(hw, "Data dikirim ke printer!", "Berhasil", MB_OK | MB_ICONINFORMATION);
    } else {
        MessageBox(hw, "Proses Cetak gagal!", "Gagal", MB_OK | MB_ICONERROR);
    }

    remove("temp_print.txt");
}

void _masuk(HWND hw)
{
	bersihkan(hw);
	CreateWindow("static", "ADMINISTRATOR", WS_VISIBLE | WS_CHILD | SS_CENTER,330,10,240,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Username :", WS_VISIBLE | WS_CHILD | SS_LEFT,330,40,90,24,hw, NULL, NULL, NULL);
	username = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,420,40,150,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Password :", WS_VISIBLE | WS_CHILD | SS_LEFT,330,64,90,24,hw, NULL, NULL, NULL);
	password = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,420,64,150,24,hw, NULL, NULL, NULL);
	
	CreateWindow("button", "Masuk", WS_VISIBLE | WS_CHILD | SS_LEFT,420,90,150,24,hw, (HMENU)PROSES_MASUK, NULL, NULL);
}

void _cekMasuk(HWND hw)
{
	char user[100], pass[100];
	bool status = false;
	
	GetWindowText(username, user, 100);
	GetWindowText(password, pass, 100);

	for(auto& adm:vecAdmin)
	{
		if(strcmp(adm.user.c_str(), user) == 0 && strcmp(adm.pass.c_str(), pass) == 0)
		{
			statusLogin = true;
			status = true;
			_menu(hw);
			MessageBox(hw, "Proses masuk berhasil!", "Berhasil", MB_OK | MB_ICONINFORMATION);
			SendMessage(hw, WM_COMMAND, MAHASISWA_DATA, 0);
		}
	}
	
	if(status == false)
	{
		MessageBox(hw, "Proses masuk tidak berhasil!", "Gagal", MB_OK | MB_ICONERROR);
	}
}

void _daftar(HWND hw)
{
	bersihkan(hw);
	CreateWindow("static", "ADMINISTRATOR", WS_VISIBLE | WS_CHILD | SS_CENTER,330,10,240,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Username :", WS_VISIBLE | WS_CHILD | SS_LEFT,330,40,90,24,hw, NULL, NULL, NULL);
	username = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,420,40,150,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Password :", WS_VISIBLE | WS_CHILD | SS_LEFT,330,64,90,24,hw, NULL, NULL, NULL);
	password = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,420,64,150,24,hw, NULL, NULL, NULL);
	
	CreateWindow("button", "Daftar", WS_VISIBLE | WS_CHILD | SS_LEFT,420,90,150,24,hw, (HMENU)PROSES_DAFTAR, NULL, NULL);
}

void _cekDaftar(HWND hw)
{
	char user[100], pass[100];
	
	GetWindowText(username, user, 100);
	GetWindowText(password, pass, 100);
	size_t jumlah = vecAdmin.size();
	
	if(jumlah < 3)
	{	
		vecAdmin.push_back({user, pass});
		
		if(vecAdmin.size() > jumlah)
		{
			MessageBox(hw, "Pendaftaran berhasil!", "Berhasil", MB_OK | MB_ICONINFORMATION);
			SendMessage(hw, WM_COMMAND, ADMIN_MASUK, 0);
		}
		else MessageBox(hw, "Pendaftaran Akun baru tidak berhasil!", "Gagal", MB_OK | MB_ICONERROR);
	}
	else MessageBox(hw, "Administator melebihin batas!", "Gagal", MB_OK | MB_ICONERROR);
}

//MAHASISWA

void _mahasiswaTambah(HWND hw)
{
	bersihkan(hw);
	CreateWindow("static", "MAHASISWA BARU", WS_VISIBLE | WS_CHILD | SS_CENTER,230,10,420,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "NPM :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,40,150,24,hw, NULL, NULL, NULL);
	npm = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,40,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Nama Lengkap :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,64,150,24,hw, NULL, NULL, NULL);
	nama = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,64,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Program Studi :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,86,150,24,hw, NULL, NULL, NULL);
	program = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,86,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("button", "Simpan", WS_VISIBLE | WS_CHILD | SS_LEFT,380,110,270,24,hw, (HMENU)MAHASISWA_SIMPAN, NULL, NULL);
}

void _mahasiswaUbah(HWND hw)
{
	int index = ListView_GetNextItem(dataMahasiswa, -1, LVNI_SELECTED);
	int no = 0;
    if (index != -1) {
        char _npm[100];
        ListView_GetItemText(dataMahasiswa, index, 1, _npm, 100);
        
        for(auto& mhs:vecMahasiswa)
        {
        	if(strcmp(_npm, mhs.npm.c_str()) == 0)
        	{	
				bersihkan(hw);
        		
				CreateWindow("static", "PERUBAHAN DATA MAHASISWA", WS_VISIBLE | WS_CHILD | SS_CENTER,230,10,420,24,hw, NULL, NULL, NULL);
				
				CreateWindow("static", "NPM :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,40,150,24,hw, NULL, NULL, NULL);
				npm = CreateWindow("static", mhs.npm.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,40,270,24,hw, NULL, NULL, NULL);
				
				CreateWindow("static", "Nama Lengkap :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,64,150,24,hw, NULL, NULL, NULL);
				nama = CreateWindow("edit", mhs.nama.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,64,270,24,hw, NULL, NULL, NULL);
				
				CreateWindow("static", "Program Studi :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,86,150,24,hw, NULL, NULL, NULL);
				program = CreateWindow("edit", mhs.program.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,86,270,24,hw, NULL, NULL, NULL);
				
				CreateWindow("button", "Perbarui", WS_VISIBLE | WS_CHILD | SS_LEFT,380,110,270,24,hw, (HMENU)MAHASISWA_PEMBARUAN, NULL, NULL);
			}
			no++;
		}
    }
}

void _mahasiswaPembaruan(HWND hw)
{
	char _npm[100], _nama[100], _program[100];
	
	GetWindowText(npm, _npm, 100);
	GetWindowText(nama, _nama, 100);
	GetWindowText(program, _program, 100);
	
	int no = 0;
	bool status = false;
	
	for(auto& mhs:vecMahasiswa)
	{		
		if(strcmp(_npm, mhs.npm.c_str()) == 0)
		{
			vecMahasiswa[no].nama = _nama;
			vecMahasiswa[no].program = _program;
			MessageBox(hw, "Perubahan berhasil!", "Berhasil", MB_OK | MB_ICONINFORMATION);
			SendMessage(hw, WM_COMMAND, MAHASISWA_DATA, 0);
			status = true;
		}
		no++;
	}
	
	if(status == false) MessageBox(hw, "Perubahan data tidak berhasil!", "Gagal", MB_OK | MB_ICONERROR);
}

void _mahasiswaSimpan(HWND hw)
{
	char _npm[100], _nama[100], _program[100];
	
	GetWindowText(npm, _npm, 100);
	GetWindowText(nama, _nama, 100);
	GetWindowText(program, _program, 100);
	size_t jumlah = vecMahasiswa.size();
	
	if(jumlah < 100)
	{	
		vecMahasiswa.push_back({_npm, _nama, _program});
		
		if(vecMahasiswa.size() > jumlah)
		{
			MessageBox(hw, "Pendaftaran berhasil!", "Berhasil", MB_OK | MB_ICONINFORMATION);
			SendMessage(hw, WM_COMMAND, MAHASISWA_DATA, 0);
		}
		else MessageBox(hw, "Pendaftaran Akun baru tidak berhasil!", "Gagal", MB_OK | MB_ICONERROR);
	}
	else MessageBox(hw, "Administator melebihin batas!", "Gagal", MB_OK | MB_ICONERROR);
}

void _mahasiswaDelete(HWND hw)
{
	int index = ListView_GetNextItem(dataMahasiswa, -1, LVNI_SELECTED);
	int no = 0;
    if (index != -1) {
        char _npm[100];
        ListView_GetItemText(dataMahasiswa, index, 1, _npm, 100);
        
        for(auto& mhs:vecMahasiswa)
        {
        	if(strcmp(_npm, mhs.npm.c_str()) == 0)
        	{
		        ListView_DeleteItem(dataMahasiswa, index);
		        vecMahasiswa.erase(vecMahasiswa.begin() + no);
				MessageBox(hw, "Data berhasil dihapus!", "Berhasil", 0);
			}
			no++;
		}
    }
}

void _mahasiswaData(HWND hw)
{
	bersihkan(hw);
	CreateWindow("button", "Tambah", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | SS_CENTER,230,10,100,24,hw, (HMENU)MAHASISWA_TAMBAH, NULL, NULL);
	CreateWindow("button", "Ubah", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | SS_CENTER,331,10,100,24,hw, (HMENU)MAHASISWA_BEDIT, NULL, NULL);
	CreateWindow("button", "Hapus", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | SS_CENTER,432,10,100,24,hw, (HMENU)MAHASISWA_BDEL, NULL, NULL);
	
	CreateWindow("static", "Data Mahasiswa", WS_VISIBLE | WS_CHILD | SS_CENTER,230,45,420,24,hw, NULL, NULL, NULL);
	dataMahasiswa = CreateWindow(WC_LISTVIEW, "Data Mahasiswa", WS_CHILD | WS_VISIBLE | LVS_REPORT,230,67,420,400,hw, NULL, NULL, NULL);
	
	LVCOLUMN kolom;
	kolom.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	
	kolom.iSubItem = 0;
	kolom.pszText = "No.";
	kolom.cx = 50;
	ListView_InsertColumn(dataMahasiswa, 0, &kolom);
	
	kolom.iSubItem = 1;
	kolom.pszText = "NPM";
	kolom.cx = 50;
	ListView_InsertColumn(dataMahasiswa, 1, &kolom);
	
	kolom.iSubItem = 2;
	kolom.pszText = "Nama Lengkap";
	kolom.cx = 160;
	ListView_InsertColumn(dataMahasiswa, 2, &kolom);
	
	kolom.iSubItem = 3;
	kolom.pszText = "Program Studi";
	kolom.cx = 160;
	ListView_InsertColumn(dataMahasiswa, 3, &kolom);
	
	LVITEM baris;
	baris.mask = LVIF_TEXT;
	int no = 0;
	
	if(vecMahasiswa.size() > 0)
	{
		for(auto& mhs:vecMahasiswa)
		{
			baris.iItem = static_cast<int>(no);
			baris.iSubItem = 0;
			baris.pszText = const_cast<LPSTR>(to_string(no+1).c_str());
			ListView_InsertItem(dataMahasiswa, &baris);
			ListView_SetItemText(dataMahasiswa, no,1, const_cast<LPSTR>(mhs.npm.c_str()));
			ListView_SetItemText(dataMahasiswa, no,2, const_cast<LPSTR>(mhs.nama.c_str()));
			ListView_SetItemText(dataMahasiswa, no,3, const_cast<LPSTR>(mhs.program.c_str()));
			no++;
		}	
	}
	else
	{
		baris.iItem = no;
		baris.iSubItem = 0;
		baris.pszText = "";
		ListView_InsertItem(dataMahasiswa, &baris);
		ListView_SetItemText(dataMahasiswa, no,2, "Data masih kosong!");
	}
	
	CreateWindow("static", "Pilih No untuk Mengubah atau Menghapus", WS_VISIBLE | WS_CHILD | SS_CENTER,230,467,420,24,hw, NULL, NULL, NULL);
}

//PENILAIAN
void _nilaiTambah(HWND hw)
{
	bersihkan(hw);
	CreateWindow("static", "Nilai MAHASISWA", WS_VISIBLE | WS_CHILD | SS_CENTER,230,10,420,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "NPM :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,40,150,24,hw, NULL, NULL, NULL);
	npm = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,40,200,24,hw, NULL, NULL, NULL);
	CreateWindow("button", "Search", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,580,40,70,24,hw, (HMENU)PENILAIAN_CARI, NULL, NULL);
	
	CreateWindow("static", "Nama Lengkap :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,64,150,24,hw, NULL, NULL, NULL);
	nama = CreateWindow("static", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,64,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Program Studi :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,86,150,24,hw, NULL, NULL, NULL);
	program = CreateWindow("static", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,86,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Kode Mata Kuliah :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,110,150,24,hw, NULL, NULL, NULL);
	kode = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,110,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Mata Kuliah :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,134,150,24,hw, NULL, NULL, NULL);
	mataKuliah = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,134,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Semester :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,158,150,24,hw, NULL, NULL, NULL);
	semester = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,158,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Nilai Tugas :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,182,150,24,hw, NULL, NULL, NULL);
	tugas = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,182,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Nilai Quiz :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,206,150,24,hw, NULL, NULL, NULL);
	quiz = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,206,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Nilai UTS :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,230,150,24,hw, NULL, NULL, NULL);
	uts = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,230,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("static", "Nilai UAS :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,254,150,24,hw, NULL, NULL, NULL);
	uas = CreateWindow("edit", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,254,270,24,hw, NULL, NULL, NULL);
	
	CreateWindow("button", "Simpan", WS_VISIBLE | WS_CHILD | SS_LEFT,380,278,270,24,hw, (HMENU)PENILAIAN_SIMPAN, NULL, NULL);
}

void _nilaiCari(HWND hw)
{
	char _nama[100], _program[100], _npm[100];
	GetWindowText(npm, _npm, 100);
	
	_nilaiTambah(hw);
	
	for(auto& mhs:vecMahasiswa)
	{
	 	if(strcmp(_npm, mhs.npm.c_str()) == 0)
	 	{
			SetWindowText(npm, mhs.npm.c_str());
			SetWindowText(nama, mhs.nama.c_str());
			SetWindowText(program, mhs.program.c_str());
		}
	}
}

void _nilaiSimpan(HWND hw)
{
	char _npm[100], _kode[100], _mataKuliah[100], _semester[100],
		_tugas[100], _quiz[100], _uts[100], _uas[100];
	
	GetWindowText(npm, _npm, 100);
	GetWindowText(kode, _kode, 100);
	GetWindowText(mataKuliah, _mataKuliah, 100);
	GetWindowText(semester, _semester, 100);
	GetWindowText(tugas, _tugas, 100);
	GetWindowText(quiz, _quiz, 100);
	GetWindowText(uts, _uts, 100);
	GetWindowText(uas, _uas, 100);
	idX();
	
	for(auto& mhs:vecMahasiswa)
	{
		if( strcmp(_npm, mhs.npm.c_str()) == 0 )
		{
			float akhir;
			string huruf;
			stringstream ubah;
			size_t awal = vecNilai.size();
			
			akhir = (0.1 * atof(_tugas)) + (0.15 * atof(_quiz)) + (0.25 * atof(_uts)) + (0.5 * atof(_uas));
			ubah << fixed << setprecision(2) << akhir;
			
			if(akhir >= 85 && akhir <= 100) huruf = "A";
			else if(akhir >= 70 && akhir < 85) huruf = "B";
			else if(akhir >= 60 && akhir < 70) huruf = "C";
			else if(akhir >= 50 && akhir < 60) huruf = "D";
			else if(akhir >= 0 && akhir < 50) huruf = "E";
			else huruf = "-";
			
			vecNilai.push_back({
				idx,
				_npm, _kode, _mataKuliah, _semester, huruf,
				_tugas, _quiz, _uts, _uas, ubah.str()
			});
			
			if(vecNilai.size() > awal)
			{
				MessageBox(hw, "Permintaan telah di proses", "Info", MB_OK | MB_ICONINFORMATION);
				SendMessage(hw, WM_COMMAND, PENILAIAN_DATA, 0);
			}
			else MessageBox(hw, "Permintaan tidak berhsil di proses", "Gagal", MB_OK | MB_ICONERROR);
		}
	}
}

void _nilaiUbah(HWND hw)
{
	int index = ListView_GetNextItem(dataNilai, -1, LVNI_SELECTED);
	int no = 0;
    if (index != -1) {
        char _ID[100];
        ListView_GetItemText(dataNilai, index, 1, _ID, 100);
        
        for(auto& n:vecNilai)
        {
        	for(auto& mhs:vecMahasiswa)
	        {
	        	if(strcmp(_ID, n.id.c_str()) == 0 && strcmp(n.npm.c_str(), mhs.npm.c_str()) == 0)
	        	{
					bersihkan(hw);
					CreateWindow("static", "Nilai MAHASISWA", WS_VISIBLE | WS_CHILD | SS_CENTER,230,10,420,24,hw, NULL, NULL, NULL);
					
					CreateWindow("static", "NPM / ID :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,40,150,24,hw, NULL, NULL, NULL);
					npm = CreateWindow("static", n.npm.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,40,200,24,hw, NULL, NULL, NULL);
					id = CreateWindow("static", _ID, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,580,40,70,24,hw, (HMENU)PENILAIAN_CARI, NULL, NULL);
					
					CreateWindow("static", "Nama Lengkap :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,64,150,24,hw, NULL, NULL, NULL);
					nama = CreateWindow("static", mhs.nama.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,64,270,24,hw, NULL, NULL, NULL);
					
					CreateWindow("static", "Program Studi :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,86,150,24,hw, NULL, NULL, NULL);
					program = CreateWindow("static", mhs.program.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,86,270,24,hw, NULL, NULL, NULL);
					
					CreateWindow("static", "Kode Mata Kuliah :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,110,150,24,hw, NULL, NULL, NULL);
					kode = CreateWindow("edit", n.kode.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,110,270,24,hw, NULL, NULL, NULL);
					
					CreateWindow("static", "Mata Kuliah :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,134,150,24,hw, NULL, NULL, NULL);
					mataKuliah = CreateWindow("edit", n.mataKuliah.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,134,270,24,hw, NULL, NULL, NULL);
					
					CreateWindow("static", "Semester :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,158,150,24,hw, NULL, NULL, NULL);
					semester = CreateWindow("edit", n.semester.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,158,270,24,hw, NULL, NULL, NULL);
					
					CreateWindow("static", "Nilai Tugas :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,182,150,24,hw, NULL, NULL, NULL);
					tugas = CreateWindow("edit", n.tugas.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,182,270,24,hw, NULL, NULL, NULL);
					
					CreateWindow("static", "Nilai Quiz :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,206,150,24,hw, NULL, NULL, NULL);
					quiz = CreateWindow("edit", n.quiz.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,206,270,24,hw, NULL, NULL, NULL);
					
					CreateWindow("static", "Nilai UTS :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,230,150,24,hw, NULL, NULL, NULL);
					uts = CreateWindow("edit", n.uts.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,230,270,24,hw, NULL, NULL, NULL);
					
					CreateWindow("static", "Nilai UAS :", WS_VISIBLE | WS_CHILD | SS_LEFT,230,254,150,24,hw, NULL, NULL, NULL);
					uas = CreateWindow("edit", n.uas.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT,380,254,270,24,hw, NULL, NULL, NULL);
					
					CreateWindow("button", "Simpan", WS_VISIBLE | WS_CHILD | SS_LEFT,380,278,270,24,hw, (HMENU)PENILAIAN_PEMBARUAN, NULL, NULL);
				}
			}
			no++;
		}
    }
}

void _nilaiPembaruan(HWND hw)
{
	char _ID[100], _npm[100], _kode[100], _mataKuliah[100], _semester[100],
		_tugas[100], _quiz[100], _uts[100], _uas[100];
	
	GetWindowText(id, _ID, 100);
	GetWindowText(npm, _npm, 100);
	GetWindowText(kode, _kode, 100);
	GetWindowText(mataKuliah, _mataKuliah, 100);
	GetWindowText(semester, _semester, 100);
	GetWindowText(tugas, _tugas, 100);
	GetWindowText(quiz, _quiz, 100);
	GetWindowText(uts, _uts, 100);
	GetWindowText(uas, _uas, 100);
	
	int no = 0;
	bool status = false;
	
	for(auto& n:vecNilai)
	{		
		if(strcmp(_npm, n.npm.c_str()) == 0)
		{
			float akhir;
			string huruf;
			stringstream ubah;
			
			akhir = (0.1 * atof(_tugas)) + (0.15 * atof(_quiz)) + (0.25 * atof(_uts)) + (0.5 * atof(_uas));
			ubah << fixed << setprecision(2) << akhir;
			
			if(akhir >= 85 && akhir <= 100) huruf = "A";
			else if(akhir >= 70 && akhir < 85) huruf = "B";
			else if(akhir >= 60 && akhir < 70) huruf = "C";
			else if(akhir >= 50 && akhir < 60) huruf = "D";
			else if(akhir >= 0 && akhir < 50) huruf = "E";
			else huruf = "-";
			
			vecNilai[no] = {
				idx,
				_npm, _kode, _mataKuliah, _semester, huruf,
				_tugas, _quiz, _uts, _uas, ubah.str()
			};
			MessageBox(hw, "Perubahan berhasil!", "Berhasil", MB_OK | MB_ICONINFORMATION);
			SendMessage(hw, WM_COMMAND, PENILAIAN_DATA, 0);
			status = true;
		}
		no++;
	}
	
	if(status == false) MessageBox(hw, "Perubahan data tidak berhasil!", "Gagal", MB_OK | MB_ICONERROR);
}

void _nilaiDelete(HWND hw)
{
	int index = ListView_GetNextItem(dataNilai, -1, LVNI_SELECTED);
	int no = 0;
    if (index != -1) {
        char _ID[100];
        ListView_GetItemText(dataNilai, index, 1, _ID, 100);
        
        for(auto& n:vecNilai)
        {
        	if(strcmp(_ID, n.id.c_str()) == 0)
        	{
		        ListView_DeleteItem(dataNilai, index);
		        vecNilai.erase(vecNilai.begin() + no);
				MessageBox(hw, "Data berhasil dihapus!", "Berhasil", 0);
			}
			no++;
		}
    }
}

void _nilaiData(HWND hw)
{
//	static HWND dataNilai;
	bersihkan(hw);
	CreateWindow("button", "Tambah", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | SS_CENTER,230,10,100,24,hw, (HMENU)PENILAIAN_TAMBAH, NULL, NULL);
	CreateWindow("button", "Ubah", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | SS_CENTER,331,10,100,24,hw, (HMENU)PENILAIAN_BEDIT, NULL, NULL);
	CreateWindow("button", "Hapus", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | SS_CENTER,432,10,100,24,hw, (HMENU)PENILAIAN_BDEL, NULL, NULL);
	
	CreateWindow("static", "Data Mahasiswa", WS_VISIBLE | WS_CHILD | SS_CENTER,30,45,900,24,hw, NULL, NULL, NULL);
	dataNilai = CreateWindow(WC_LISTVIEW, "Data Mahasiswa", WS_CHILD | WS_VISIBLE | LVS_REPORT,30,67,900,400,hw, NULL, NULL, NULL);	
	
	LVCOLUMN kolom;
	kolom.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	
	kolom.iSubItem = 0;
	kolom.pszText = "No.";
	kolom.cx = 50;
	ListView_InsertColumn(dataNilai, 0, &kolom);
	
	kolom.iSubItem = 1;
	kolom.pszText = "ID";
	kolom.cx = 50;
	ListView_InsertColumn(dataNilai, 1, &kolom);
	
	kolom.iSubItem = 2;
	kolom.pszText = "NPM";
	kolom.cx = 50;
	ListView_InsertColumn(dataNilai, 2, &kolom);
	
	kolom.iSubItem = 3;
	kolom.pszText = "Nama Lengkap";
	kolom.cx = 100;
	ListView_InsertColumn(dataNilai, 3, &kolom);
	
	kolom.iSubItem = 4;
	kolom.pszText = "Program Studi";
	kolom.cx = 100;
	ListView_InsertColumn(dataNilai, 4, &kolom);
	
	kolom.iSubItem = 5;
	kolom.pszText = "Kode";
	kolom.cx = 50;
	ListView_InsertColumn(dataNilai, 5, &kolom);
	
	kolom.iSubItem = 6;
	kolom.pszText = "Mata Kuliah";
	kolom.cx = 100;
	ListView_InsertColumn(dataNilai, 6, &kolom);
	
	kolom.iSubItem = 7;
	kolom.pszText = "Semester";
	kolom.cx = 75;
	ListView_InsertColumn(dataNilai, 7, &kolom);
	
	kolom.iSubItem = 8;
	kolom.pszText = "Tugas";
	kolom.cx = 50;
	ListView_InsertColumn(dataNilai, 8, &kolom);
	
	kolom.iSubItem = 9;
	kolom.pszText = "Quiz";
	kolom.cx = 50;
	ListView_InsertColumn(dataNilai, 9, &kolom);
	
	kolom.iSubItem = 10;
	kolom.pszText = "UTS";
	kolom.cx = 50;
	ListView_InsertColumn(dataNilai, 10, &kolom);
	
	kolom.iSubItem = 11;
	kolom.pszText = "UAS";
	kolom.cx = 50;
	ListView_InsertColumn(dataNilai, 11, &kolom);
	
	kolom.iSubItem = 12;
	kolom.pszText = "Total";
	kolom.cx = 50;
	ListView_InsertColumn(dataNilai, 12, &kolom);
	
	kolom.iSubItem = 13;
	kolom.pszText = "Keterangan";
	kolom.cx = 75;
	ListView_InsertColumn(dataNilai, 13, &kolom);
	
	LVITEM baris;
	baris.mask = LVIF_TEXT;
	int no = 0;

	if(vecNilai.size() > 0)
	{
		for(auto& n:vecNilai)
		{
			for(auto& mhs:vecMahasiswa)
			{
				if(strcmp(n.npm.c_str(), mhs.npm.c_str()) == 0)
				{
					baris.iItem = static_cast<int>(no);
					baris.iSubItem = 0;
					baris.pszText = const_cast<LPSTR>(to_string(no+1).c_str());
					ListView_InsertItem(dataNilai, &baris);
					ListView_SetItemText(dataNilai, no,1, const_cast<LPSTR>(n.id.c_str()));
					ListView_SetItemText(dataNilai, no,2, const_cast<LPSTR>(n.npm.c_str()));
					ListView_SetItemText(dataNilai, no,3, const_cast<LPSTR>(mhs.nama.c_str()));
					ListView_SetItemText(dataNilai, no,4, const_cast<LPSTR>(mhs.program.c_str()));
					ListView_SetItemText(dataNilai, no,5, const_cast<LPSTR>(n.kode.c_str()));
					ListView_SetItemText(dataNilai, no,6, const_cast<LPSTR>(n.mataKuliah.c_str())); 
					ListView_SetItemText(dataNilai, no,7, const_cast<LPSTR>(n.semester.c_str()));
					ListView_SetItemText(dataNilai, no,8, const_cast<LPSTR>(n.tugas.c_str()));
					ListView_SetItemText(dataNilai, no,9, const_cast<LPSTR>(n.quiz.c_str()));
					ListView_SetItemText(dataNilai, no,10, const_cast<LPSTR>(n.uts.c_str()));
					ListView_SetItemText(dataNilai, no,11, const_cast<LPSTR>(n.uas.c_str()));
					ListView_SetItemText(dataNilai, no,12, const_cast<LPSTR>(n.akhir.c_str()));
					ListView_SetItemText(dataNilai, no,13, const_cast<LPSTR>(n.huruf.c_str()));
					no++;
				}
			}
		}
	}
	else
	{
		baris.iItem = no;
		baris.iSubItem = 0;
		baris.pszText = "";
		ListView_InsertItem(dataNilai, &baris);
		ListView_SetItemText(dataNilai, no,3, "Data masih kosong!");
	}
	CreateWindow("static", "Pilih No untuk Menghapus atau Mengubah Data", WS_VISIBLE | WS_CHILD | SS_CENTER,30,467,900,24,hw, NULL, NULL, NULL);
}

void _cetak()
{
}

void _tim(HWND hw)
{
	bersihkan(hw);
	CreateWindow("static", "KELOMPOK 2", WS_VISIBLE | WS_CHILD | SS_CENTER,30,10,900,24,hw, NULL, NULL, NULL);
	CreateWindow("static", "Anggota:\n\n Fittra Ferdiansyah \n Angel Nurfadilah \n Febry Manalu \n Aldy",
	 WS_VISIBLE | WS_CHILD | SS_CENTER,30,34,900,320,hw, NULL, NULL, NULL);
}

void _tutorial(HWND hw)
{
	string konten = "ADMINISTRATOR \n\nUntuk masuk kedalam sistem secara default dapat menggunakan username \"admin\" dan password \"admin\" \n";
	konten +="Pengguna juga dapat membuat Akun baru melalui ADMIN > Mendaftar \n\n";
	konten +="PENILAIAN \n\n-Sebelum dapat menginput data nilai, pengguna diharuskan menginputkan data mahasiswa. \n";
	konten +="-Kemudian, silahkan klik pada menu PENILAIAN > Tambah Penilaian \n";
	konten +="-Masukkan NPM pada kolom NPM kemudian klik Search untuk mendpatkan sekaligus mengecek status siswa\n";
	konten +="-NPM yang dimasukkan pada halaman PENILAIAN harus sesuai dengan NPM yang ada pada Data Mahasiswa karena data akan tersinkron\n\n";
	konten +="BATASAN \n\nJumlah Data Admin dibatasi sebanyak 3, dengan 2 data akun pendaftaran baru \n";
	konten +="Jumlah Data Mahasiswa dan Penilaian yang dapat diinput dibatasi sebanyak 100 data.";
	
	bersihkan(hw);
	CreateWindow("static", "INFORMASI PENGGUNAAN", WS_VISIBLE | WS_CHILD | SS_CENTER,30,10,900,24,hw, NULL, NULL, NULL);
	CreateWindow("static", konten.c_str(),
	 WS_VISIBLE | WS_CHILD | SS_LEFT,30,34,900,320,hw, NULL, NULL, NULL);
}

//PROSES PERMINTAAN YANG DIJALANKAN
LRESULT CALLBACK proses(HWND hw, UINT pesan, WPARAM wp, LPARAM lp)
{
	 switch(pesan)
	 {
	 	case WM_CREATE:
	 	{
			//TENTUKAN DATA LOGIN ADMIN DEFAULT
			vecAdmin.push_back({"admin", "admin"});
		 	_menu(hw);
		 	_masuk(hw);
	 		break;
	 	}
	 	
	 	case WM_COMMAND:
	 		switch(wp)
	 		{
	 			case ADMIN_KELUAR:
	 				statusLogin = false;
		 			_menu(hw);
		 			SendMessage(hw, WM_COMMAND, ADMIN_MASUK, 0);
	 				break;
	 				
	 			case ADMIN_MASUK:
		 			_masuk(hw);
	 				break;
	 				
	 			case PROSES_MASUK:
		 			_cekMasuk(hw);
	 				break;
	 				
	 			case ADMIN_DAFTAR:
	 				_daftar(hw);
	 				break;
	 				
	 			case PROSES_DAFTAR:
		 			_cekDaftar(hw);
	 				break;
	 				
	 			case MAHASISWA_TAMBAH:
		 			_mahasiswaTambah(hw);
	 				break;
	 				
	 			case MAHASISWA_SIMPAN:
		 			_mahasiswaSimpan(hw);
	 				break;
	 				
	 			case MAHASISWA_DATA:
		 			_mahasiswaData(hw);
	 				break;
	 				
	 			case MAHASISWA_BEDIT:
		 			_mahasiswaUbah(hw);
	 				break;
	 				
	 			case MAHASISWA_PEMBARUAN:
		 			_mahasiswaPembaruan(hw);
	 				break;
	 				
	 			case MAHASISWA_BDEL:
		 			_mahasiswaDelete(hw);
	 				break;
	 				
	 			case PENILAIAN_TAMBAH:
		 			_nilaiTambah(hw);
	 				break;
	 				
	 			case PENILAIAN_CARI:
		 			_nilaiCari(hw);
	 				break;
	 				
	 			case PENILAIAN_SIMPAN:
		 			_nilaiSimpan(hw);
	 				break;
	 				
	 			case PENILAIAN_DATA:
		 			_nilaiData(hw);
	 				break;
	 				
	 			case PENILAIAN_BEDIT:
		 			_nilaiUbah(hw);
	 				break;
	 				
	 			case PENILAIAN_PEMBARUAN:
		 			_nilaiPembaruan(hw);
	 				break;
	 				
	 			case PENILAIAN_BDEL:
		 			_nilaiDelete(hw);
	 				break;
	 				
	 			case PRINT_MAHASISWA:
		 			_printMahasiswa(hw);
	 				break;
	 				
	 			case PRINT_PENILAIAN:
		 			_printNilai(hw);
	 				break;
	 			
	 			case INFORMASI_TIM:
	 				_tim(hw);
	 				break;
	 			
	 			case INFORMASI_PENGGUNAAN:
	 				_tutorial(hw);
	 				break;
	 				
	 			case TUTUP:
	 				DestroyWindow(hw);
	 				break;
			}
	 		break;
	 		
	 	case WM_DESTROY:
	 		PostQuitMessage(0);
	 		break;
	 		
	 	default:
	 		DefWindowProc(hw, pesan, wp, lp);
	 		break;
	 }
}
