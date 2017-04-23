#include <Rcpp.h>
using namespace Rcpp;

//' @name extinction
//' @title Extinction rate for a given set of biotic interactions.
//' @description This function returns the extinction associated with a given biotic environment.
//'
//' @author
//' Kevin Cazelles
//'
//' @param inter a real number giving the sum of interactions.
//' @param basexti extinction rate without interaction.
//' @param mn a real number giving the minimum rate of extnction.
//' @param mx a real number giving the maximum rate of extnction.
//' @param shape a positive real number controling the impact of biotic interactions: the larger the value the stronger the impact of interactions.
//'
//' @return Returns the extinction rate associated with a given biotic environment.
//'
//' @references
//' Cazelles, K., Mouquet, N., Mouillot, D. & Gravel, D. On the integration of
//' biotic interaction and environmental constraints at the biogeographical scale.
//' (equation 5).
//' @export
// [[Rcpp::export]]
double extinction(double inter, double basexti, double mn, double mx, double shape){
	double val = 0;
	if (mn>=mx) {
		stop("'mx' should be larger than 'mn'");
	}
  val = 1/( (1/(basexti*(mx-mn))) + ( (1/(basexti*(1-mn)))-(1/(basexti*(mx-mn))) )*exp(shape*inter)) ;
	val += basexti*mn ;
	return val;
}
