#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main ()
{
	int numcols=0, numrows=0, count=0, photostart=0;
	double xoverlap=1,yoverlap=1;
	char fileformat='o';
	string filename;
	ofstream outstream;
	cout<<"Welcome to the AISOS GIGAmacro camera position approximator for use with Agisoft Photoscan!\nCurrently, it works only with 1x zoom.\n\n";
	cout<<"Choose file format (z for zstacked, u for unstacked): ";
	while (fileformat!='u'&&fileformat!='z')
	{
		cin>>fileformat;
		if (fileformat!='u'&&fileformat!='z')
		{
			cout<<"Please enter u or z\n";
		}
	}
	if (fileformat=='u')
	{
		cout<<"Enter photo start number: ";
		cin>>photostart;
	}
	cout<<"Enter percent column (x) overlap in decimal form: ";
	cin>>xoverlap;
	cout<<"Enter percent row (y) overlap in decimal form: ";
	cin>>yoverlap;
	cout<<"Enter number of cols: ";
	cin>>numcols;
	cout<<"Enter number of rows: ";
	cin>>numrows;
	cout<<"Please enter an output file name including extension \".txt\": ";
	cin>>filename;
	cout<<"\n";
	outstream.open(filename.c_str());
	outstream<<"#Cameras ("<<numcols*numrows<<")\n\"# PhotoID, X, Y, Z, Omega, Phi, Kappa\"\n";
	for (int i=0;i<numcols;i++)
	{
		for (int j=0;j<numrows;j++)
		{
			if (fileformat=='z')
			{
				outstream<<"col_";
				outstream<<setfill('0')<<setw(4)<<i+1;
				outstream<<"_row_";
				outstream<<setfill('0')<<setw(4)<<j+1;
				outstream<<"_zstacked.jpg\t";
			}
			else
			{
				outstream<<setfill('0')<<setw(5)<<count+photostart;
				outstream<<".jpg\t";
				count++;
			}
			outstream<<(-3.10048*(1.0-xoverlap)*i)<<"\t"<<(-2.07768*(1.0-yoverlap)*j)<<"\t"<<"0\t-180\t0\t0\n";
		}
	}
	cout<<"DONE!";
	outstream.close();
	return 0;
}

