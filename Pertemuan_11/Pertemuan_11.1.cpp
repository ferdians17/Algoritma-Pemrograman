#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream gas("hallo.txt");
	char lanjut = 'y';
	string isi;
	
	if( gas.is_open() )
	{
		gas << "isi awal" << endl;
		
		while( lanjut == 'y' || lanjut == 'Y' )
		{
			cout << "Apa yang akan Anda tulis? :";
			cin >> isi;
			gas << isi << endl;
			
			cout << "lanjutkan (y)? :";
			cin >> lanjut;
		}
		gas.close();
	}
	else cout << "Berkas tidak dapat dibuka!";
	
	return 0;
}
