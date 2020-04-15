#include <Rcpp.h>
using namespace Rcpp;

//' @name colonization
//' @title Colonisation rate in a given abtiotic environment.
//' @description This function returns a colonisation rate in a given abtiotic enviromemnt.
//' This colonisation function is hump-shaped and its parameters allow for controlling
//' the height and the width of the hump.
//'
//' @author
//' Kevin Cazelles
//'
//' @param envir a real number giving the abiotic value.
//' @param maxcolo extinction rate associated with the optimum value, it controls the height of the hump.
//' @param opti a real number giving the optimum value, i.e the abiotic values at which the colonisation rate is maximal.
//' @param width a real number controlling the width of the hump, the larger the wider the hump.
//'
//' @return Returns the colonisation rate associated with a given biotic environment.
//'
//' @references
//' Cazelles, K., Mouquet, N., Mouillot, D. & Gravel, D. On the integration of
//' biotic interaction and environmental constraints at the biogeographical scale.
//' (equation 9).
//' @export
// [[Rcpp::export]]
double colonization(double envir, double maxcolo, double opti, double width){
	double val = 0;
	val = maxcolo*exp(-((envir-opti)/width)*((envir-opti)/width));
	return val;
}
