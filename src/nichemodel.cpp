#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

//' @name nicheModel
//' @title Generate an interaction network using the niche model.
//' @description This function returns an interaction network using the model
//' proposed by Williams & Martinez (2000), the sign of coefficients can be
//' modified to simulate different kind of network.
//'
//' @author
//' Kevin Cazelles
//'
//' @param nbsp an integer, the number of species.
//' @param connec a real number giving the connectance of the network to be generated (between 0 and .5).
//' @param mode an integer used to select the sign used in the network (1- for predation; 2-competition;  3-nutualism)  a real number giving the optimum value, i.e the abiotic values at which the colonisation rate is maximal.
//'
//' @return Returns a numeric matrix describing the interaction network.
//'
//' @references
//' Williams, R. J. & Martinez, N. D. Simple rules yield complex food webs.
//' Nature 404, 180-183 (2000).
//'
//' @export
// [[Rcpp::export]]
NumericMatrix nicheModel(int nbsp, double connec, int mode){
	if (mode<=0 || mode>3) {
		stop("'mode' could only takes value in {1,2,3}");
	}
	if (connec<0 || connec>0.5) {
		stop("'mode' could only takes value in {1,2,3}");
	}
	NumericMatrix metaweb(nbsp, nbsp);
	NumericVector niche(nbsp);
	niche = runif(nbsp, 0, 1);
	sort(niche.begin(), niche.end());
	double c, r, rg1, rg2, beta;
	int i, j;
	beta = 1/(2*connec)-1;
  //
	for(i = 0; i < nbsp; i++) {
		r = rbeta(1,1,beta)[0]*niche[i];
		c = runif(1,.5*r,niche[i])[0];
		rg1 = c-.5*r;
		rg2 = c+.5*r;
		for(j = 0; j < nbsp; j++) {
			if (niche[j]>rg1) {
				if (niche[j]<rg2) {
					metaweb(i, j) = runif(1,0,1)[0];
					metaweb(j, i) = runif(1,0,1)[0];
					if (mode<3) {
						metaweb(i, j) *= -1;
						if (mode==2 & i!=j) {
							metaweb(j, i) *= -1;
						}
					}
				}
			}
		}
	}
  return metaweb;
}
