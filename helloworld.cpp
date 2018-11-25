#include<iostream>
using namespace std;

//common variables that is used through out the program

int i,j,k,l;
int vib,vib1, nx,nx1,vibcation,vibanion,hx1,hx2;

const int Nx = 2;
const int Ny = 1;
const int wvib = 1400;
int kount = 0;
int kount1p = 0;
int kount2p = 0;
int  kount_ct = 0;
int kountstates = 0;
const int vibmax = 1;
int lattice[Nx][Ny];
int indexoneparticle[Nx*Ny][3];
int indextwoparticle[Nx*Ny][2][Nx*Ny][2];
int index_ct_state[40][40][40][40];
int H1p[10][10];

void indexlattice()                                    // I am indexing the lattice here 
{
	for (i = 1; i <= Nx; i++) {
		for (j = 1; j <= Ny; j++) {
			kount += 1;
			lattice[i][j] = kount;
			//cout << "kount = " << kount << endl;
			cout << "lattice[" << i<<j << "]=" << lattice[i][j] << endl;
		}
	}
}



void index_one_particle_states()                           // I am indexing the one particle states here
{
	for (i = 1; i <= Nx; i++) {
		for (j = 1; j <= Ny; j++) {
		//	cout << "lattice[" << i << j << "]=" << lattice[i][j] << endl;
			nx = lattice[i][j];
			for (vib = 0; vib <= vibmax; vib++) {
			//	cout << "lattice[" << i << j << "]=" << lattice[i][j] << endl;
			//	cout << "vib = " << vib << endl;
			//	cout << "nx = " << nx << endl;
				kountstates += 1;
				kount1p += 1;
				indexoneparticle[nx][vib] = kountstates;
				//cout << "kountstates = " << kountstates << endl;
				cout << "indexoneparticle[" << nx << vib << "]=" << indexoneparticle[nx][vib] << endl;
			}
		}
	}
}

void index_two_particle_states()                           // I am indexing the two particle states here
{
	for (i = 1; i <= Nx; i++) {
		for (j = 1; j <= Ny; j++) {
			for (vib = 0; vib <= vibmax; vib++) {
				nx = lattice[i][j];
				for (k = 1; k <= Nx; k++) {
					for (l = 1; l <= Ny; l++) {
						for (vib1 = 1; vib1 <= vibmax; vib1++) {
							nx1 = lattice[k][l];
							if (nx1 == nx) 
							{
								continue;
							}
							else if ((vib+vib1)>vibmax)
							{
								continue;
							}
							else 
							{
								kountstates += 1;
								kount2p += 1;
								//	cout << "nx = " << nx << ";	vib = " << vib << ";	nx1 = " << nx1 << ";	vib1 = " << vib1 << endl;
								indextwoparticle[nx][vib][nx1][vib1] = kountstates;
							}
							//cout << "kountstates = " << kountstates << endl;
							cout << "indextwoparticle[" << nx << vib << nx1 << vib1 << "]=" << indextwoparticle[nx][vib][nx1][vib1] << endl;
							
						}
					}
				}
			}
		}
	}
}

void index_ct()                           // I am indexing the charge transfer states here
{
	for (i = 1; i <= Nx; i++) {
		for (j = 1; j <= Ny; j++) {
			for (vibcation = 0; vibcation <= vibmax; vibcation++) {
				nx = lattice[i][j];
				for (k = 1; k <= Nx; k++) {
					for (l = 1; l <= Ny; l++) {
						for (vibanion = 0; vibanion <= vibmax; vibanion++) {
							nx1 = lattice[k][l];
							if (nx1 == nx)
							{
								continue;
							}
							else if ((vibcation + vibanion) > vibmax)
							{
								continue;
							}
							else
							{
								kount_ct += 1;
							//	cout << "lattice[" << i << j << "]=" << lattice[i][j] << endl;
							//    cout << "nx = " << nx << ";	vibcation = " << vibcation << ";	nx1 = " << nx1 << ";	vibanion = " << vibanion << endl;
								index_ct_state[nx][vibcation][nx1][vibanion] = kount_ct;
							}
							//	cout << "kount_ct = " << kount_ct << endl;
							//  cout << "index_ct_state[" << nx << vibcation << nx1 << vibanion << "]=" << index_ct_state[nx][vibcation][nx1][vibanion] << endl;
							
						}
					}
				}
			}
		}
	}
}


void one_particle_hamiltonian()
{
	for (i = 1; i <= Nx; i++) 
	{
		for (j = 1; j <= Ny; j++) 
		{
			nx = lattice[i][j];
			for (vib = 0; vib <= vibmax; vib++)
			{
				hx1 = indexoneparticle[nx][vib];
				H1p[hx1][hx1] = vib;			
				for (i = 1; i <= Nx; i++)
				{
					for (j = 1; j <= Ny; j++)
					{
						nx = lattice[i][j];
						for (vib = 0; vib <= vibmax; vib++)
						{
		            }
	}
}
			}
		}
	}
}




int main()
{
	
    indexlattice();
    index_one_particle_states();
	index_two_particle_states();
	index_ct();
	cout << "kount1p = " << kount1p << endl;
	cout << "kount2p = " << kount2p << endl;
}



