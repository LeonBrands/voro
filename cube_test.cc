// Single Voronoi cell example code
//
// Author   : Chris H. Rycroft (LBL / UC Berkeley)
// Email    : chr@alum.mit.edu
// Date     : October 19th 2007

#include "container.cc"

int main() {
	double x,y,z,rsq,r;
	voronoicell v;

	// Initialize the Voronoi cell to be a cube of side length 2, centered on
	// the origin
	v.init(-1,1,-1,1,-1,1);
	
	ofstream file;
	
	// Cut the cell by 100000 random planes which are all a distance 1 away
	// from the origin, to make an approximation to a sphere
	for(int i=0;i<100000;i++) {
		if (i%10000==0) cout << i << " " << v.p << endl;
		x=double(2*rand()-1)/RAND_MAX;
		y=double(2*rand()-1)/RAND_MAX;
		z=double(2*rand()-1)/RAND_MAX;
		rsq=x*x+y*y+z*z;
		if(rsq>0.01&&rsq<1) {
			r=1/sqrt(rsq);x*=r;y*=r;z*=r;
			v.plane(x,y,z,1);
			//v.relcheck();
			//v.duplicatecheck();
		}
	//	v.perturb(0.0001);
	}

	// Output the Voronoi cell to a file, in the gnuplot format
	file.open("test",ofstream::out|ofstream::trunc);
	v.dumpgnuplot(file,0.0,0.0,0.0);
	file.close();
}