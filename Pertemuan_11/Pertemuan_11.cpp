#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream gas("hallo.txt");
	string baris;
	
	if( gas.is_open() )
	{
		while( getline(gas, baris) ) cout << baris << endl;
		gas.close();
	}
	else cout << "Berkas tidak dapat dibuka!";
	
	return 0;
}
