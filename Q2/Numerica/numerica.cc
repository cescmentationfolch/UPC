/*USO
  compilar con:  g++ numerica.cc -std=c++11 -o numerica
  ejecutar con: ./numerica <nombre de fichero entrada> <nombre de fichero salida>
  el nombre de fichero de salida por defecto es sortida.txt

  Es buena idea comprobar los resultados con otros programas

  Me comprometo a ir a la FMESTA Gran de la mejor generacion
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<long double> VD;
typedef vector<int> vi;
int n,m;
long double t;
vector<VD> inversa;
long double eps = 1e-13;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define sz(x) (x).size()


int matInv(vector<vector<long double>>& A) {
    vi col(n);
	vector<vector<long double>> tmp(n, vector<long double>(n));
	rep(i,0,n) tmp[i][i] = 1, col[i] = i;

	rep(i,0,n) {
		int r = i, c = i;
		rep(j,i,n) rep(k,i,n)
			if (fabs(A[j][k]) > fabs(A[r][c]))
				r = j, c = k;
		if (fabs(A[r][c]) < 1e-12) return i;
		A[i].swap(A[r]); tmp[i].swap(tmp[r]);
		rep(j,0,n)
			swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
		swap(col[i], col[c]);
		long double v = A[i][i];
		rep(j,i+1,n) {
			long double f = A[j][i] / v;
			A[j][i] = 0;
			rep(k,i+1,n) A[j][k] -= f*A[i][k];
			rep(k,0,n) tmp[j][k] -= f*tmp[i][k];
		}
		rep(j,i+1,n) A[i][j] /= v;
		rep(j,0,n) tmp[i][j] /= v;
		A[i][i] = 1;
	}

	/// forget A at this point, just eliminate tmp backward
	for (int i = n-1; i > 0; --i) rep(j,0,i) {
		long double v = A[j][i];
		rep(k,0,n) tmp[j][k] -= v*tmp[i][k];
	}

	rep(i,0,n) rep(j,0,n) A[col[i]][col[j]] = tmp[i][j];
	return n;
}




int lu(vector<VD>& a, int& n, vector<int>& perm, long double tol){
    int contperm = 1; //mirem la paritat de les permutacions
    for (int i = 0; i < n; ++i) { //i indica la diagonal
        long double actumax = -1;
        int posmax = i;
        for (int j = i; j < n; ++j) { //mirem el maxim de les files per cada columna
            long double maxfila = -1;
            for (int k = i; k < n; ++k) {
                if (maxfila < abs(a[j][k])) maxfila = abs(a[j][k]); //mirem el maxim de la fila
                //guardem a max fila el valor
            }
            if (actumax < abs(a[j][i])/maxfila) {
                actumax = abs(a[j][i])/maxfila;
                posmax = j;
            } //guardem la posicio maxima per fer el swap
        }
        swap(a[i],a[posmax]);
        swap(perm[i],perm[posmax]);
        if (i != posmax) contperm *= -1; //hem fet una permutacio

        for (int j = i+1; j < n; ++j) {
            long double m = a[j][i]/a[i][i];
            for (int k = i; k < n; ++k) a[j][k] -= m*a[i][k];
            a[j][i] = m;
        } //dividim totes pel maxim
    }
    //tenemos el sistema resuelto, miramos que la diagonal sea mayor que la tolerancia
    for (int i = 0; i < n; ++i){
        if (abs(a[i][i]) < tol) return 0;
    }
    return contperm;
}

void resol (vector<VD>& a, VD& x, VD& b, int& n, vector<int>& perm){
    for (int i = 0; i < n; ++i) {
        x[i] = b[perm[i]];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i-1; j >= 0; --j) x[i]-=a[i][j]*x[j];
    }
    for (int i = n-1; i >= 0; --i) {
        for (int j = i+1; j < n; ++j) x[i]-=a[i][j]*x[j];
        x[i] /= a[i][i];
    }
}


int sistema(vector<VD>& a, VD& x, VD& b, int& n, double tol, vector<int>& perm){
    int i = lu(a, n, perm, tol);
    if (i == 0) return 0;
    resol(a,x,b,n,perm);
    return i;
}

int main(int argc, char** argv){
    cout.precision(14);
    string tmp = "Sortida.txt";
    char* input = argv[1];
    char* output = &tmp[0];
    if(argc == 1) return cout << "Especifica el nombre del Archivo" << endl, 0;
    if(argc == 3) output = argv[2];
    ifstream inp(argv[1]);
    ofstream outp(output);
    outp.precision(14);
    //freopen(argv[1],"r",stdin);
    //freopen(output,"w",stdout);
    inp >> n >> m;
    vector <vector<long double> >a(n,vector<long double> (n,0));
    inversa = vector<vector<long double> >(n,VD (2*n,0));
    for(int i = 0; i < n ; ++i) inversa[i][i+n] = 1;
    for (int i = 0; i < m; ++i) {
        int x, y;
        inp >> x >> y;
        long double num;
        inp >> num;
        a[x][y] = inversa[x][y] = num;
    }
    auto orig = a;
    outp << "Estas son las normas de la matriz" <<endl;
    long double Asub1 = 0, Asubinf = 0;
    for (int i = 0; i < n; ++i){
        long double msub1 = 0;
        for (int j = 0; j < n; ++j){
            msub1 += abs(a[j][i]);
        }
        Asub1 = max(Asub1,msub1);
    }
    outp << "la norma sub1 de la matriz A es: " << scientific << Asub1 << endl;

    for (int i = 0; i < n; ++i){
        long double msubinf = 0;
        for (int j = 0; j < n; ++j){
            msubinf += abs(a[i][j]);
        }
        Asubinf = max(Asubinf,msubinf);
    }
    outp << "la norma subinf de la matriz A es: " << scientific << Asubinf << endl;
    outp << endl;
    vector <long double> b(n,0);
    int k;
    inp >> k;
    for (int i = 0; i < k; ++i) {
        int x,y;
        inp >> x;
        inp >> b[x];
    }
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) perm[i]=i;

    vector<long double> x(n,0);
    if (sistema(a ,x ,b ,n ,1e-13, perm) == 0) {
        outp << "Singular\n";
        return 0;
    }
    auto inv = orig;
    matInv(inv);


    outp << endl;
    outp << endl <<"Estas son las normas del vector x: \n";

    //norma sub 1
    long double sub1 = 0,sub2 = 0, subinf = 0, det = 1, traza = 0;
    for (int i = 0; i < n; ++i) {
        sub1 += abs(x[i]);
    }
    outp << "la norma sub1 es: " << scientific << sub1 <<endl;
    //

    //norma sub 2
    for (int i = 0; i < n; ++i) {
        sub2 += x[i]*x[i];
    }
    outp << "la norma sub2 es: " << scientific << sqrt(sub2) <<endl;
    //

    //norma sub infinito
    for (int i = 0; i < n; ++i) {
        subinf = max(abs(x[i]),subinf);
    }
    outp << "la norma subinf es: " << scientific << subinf <<endl;
    //
    outp << endl;
    outp << "Aquí estan los determinantes y trazas: \n";
    for(int i = 0; i < n; ++i){
        traza += a[i][i];
        det *= a[i][i];
    }
    outp << "El determinante de A es: " << det <<'\n' << "la traza de A es: " << traza << endl;

    //inversa
    outp <<"-----------------------------------------------\n";
    outp << "Matriz Inversa\n";
    outp << "Estas son las normas de la matriz inversa" <<endl;
    long double Ainvsub1 = 0, Ainvsubinf = 0, Ainvtraza = 0;
    for (int i = 0; i < n; ++i){
        long double msub1 = 0;
        for (int j = 0; j < n; ++j){
            msub1 += abs(inv[j][i]);
        }
        Ainvsub1 = max(Ainvsub1,msub1);
    }
    outp << "la norma sub1 de la matriz A-1 es: " << scientific << Ainvsub1 << endl;

    for (int i = 0; i < n; ++i){
        long double msubinf = 0;
        for (int j = 0; j < n; ++j){
            msubinf += abs(inv[i][j]);
        }
        Ainvsubinf = max(Ainvsubinf,msubinf);
    }
    outp << "la norma subinf de la matriz A-1 es: " << scientific << Ainvsubinf << endl;
    outp << endl;

    //traza de a-1
    long double da = 1;
    for(int i = 0; i < n; ++i){
        Ainvtraza += inversa[i][i];
    }

    outp << "la traza de la matriz A-1 es: " << Ainvtraza << endl;
    outp << "el determinante de la matriz A-1 es: " << 1/det << endl;
    //mu sub 1
    outp << "el nombre de condicio sub 1 es: " << Ainvsub1*Asub1 <<endl;
    outp << "el nombre de condicio sub infinit es: " << Ainvsubinf*Asubinf <<endl;

    //solucio sistema
    outp << "\n------------------------------------------------\n\nla solucio del sistema es:\n";
    for (int i = 0; i < n; ++i) {
        outp << scientific <<"el valor X" << i << " es: " << x[i] << endl;
    }
    outp << endl;
    outp << "el vector de permutacion es (indexada a 0): ";

    int mperm[n][n];
    memset(mperm, 0, sizeof(mperm));
    for (int i = 0; i < n; ++i) {
        outp << perm[i] << ' ';
        mperm[i][perm[i]] = 1;
    }
    outp << endl;
    outp << "La matriz de permutacion correspondiente es: \n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            outp << mperm[i][j] << ' ';
        }
        outp << endl;
    }

    outp << "---------------------------------------------------\n La matriz L + U es: \n";

    for(auto i : a) {
        for(auto j : i) outp << j << ' ';
        outp << endl << endl;
    }


    outp << "---------------------------------------------------\n La matriz inversa es: \n";
    for(auto i : inv) {
        for(auto j : i) outp << j << ' ';
        outp << endl << endl;
    }

}
