#include <Rcpp.h>
using namespace Rcpp;
using namespace std;


//' @name extinction
//' @title Extinction rate for a given set of biotic interactions.
//' @description This function returns the extinction associated with a given biotic environment.
//'
//' @param inter a real number giving the sum of interactions.
//' @param basexti extinction rate without interaction.
//' @param mn,mx a real number coefficient by which `basexti` should be multiply to obtain the minimum and maximum rate of extinction.
//' @param shape a positive real number controlling the impact of biotic interactions: the larger the value the stronger the impact of interactions.
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
		if (mn >= mx) {
				stop("'mx' should be larger than 'mn'");
		}
		return basexti*mn + 1/( (1/(basexti*(mx-mn))) + ( (1/(basexti*(1-mn)))-(1/(basexti*(mx-mn))) )*exp(shape*inter));
}


//' @name colonization
//' @title Colonisation rate in a given abtiotic environment.
//' @description This function returns a colonisation rate in a given abtiotic environment.
//' This colonisation function is hump-shaped and its parameters allow for controlling
//' the height and the width of the hump.
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
		return maxcolo*exp(-((envir-opti)/width)*((envir-opti)/width));
}


// count number of bit > 1 3
int countBit1(int x) {
		int n = 0;
		while (x != 0) {
				n += (x & 1);
				x = (x >> 1);
		}
		return n;
}

IntegerVector countBit1State(int n) {
	int i;
	IntegerVector out(n);
	for (i=0; i<n; i++) {
		out(i) = countBit1(i);
	}
	return out;
}

// is bite b = 1 in x
bool isIt1(int x, int b) {
	return (x & (1 << b)) ? true : false;
}

//
IntegerVector isIt1State(int n, int b) {
	int i;
	IntegerVector out(n);
	for (i=0; i<n; i++) {
		out(i) = isIt1(i, b);
	}
	return out;
}


//' @name buildMarkov
//' @title Generates the transition matrix for a given probability and  an interaction network using the niche model.
//' @description Generates the transition matrix for a given probability and  an interaction network using the niche model.
//'
//' @param nbsp an integer giving the number of species.
//' @param colo a vector giving the colonization rates of all species.
//' @param metaweb a matrix describing the interaction network.
//' @param basexti extinction rate without interaction.
//' @param mn,mx a real number giving the minimum and maximum rate of extinction.
//' @param shape a positive real number controlling the impact of biotic interactions: the larger the value the stronger the impact of interactions.
//'
//' @return A list including:
//' * `makov`: the transition of the Markov chain to be solved.
//' * `speciesRichness`: species richness for all states.
//' * `speciesPresence`: matrix of presence for every species in all states.
//'
//' @references
//' Cazelles, K., Mouquet, N., Mouillot, D. & Gravel, D. On the integration of
//' biotic interaction and environmental constraints at the biogeographical scale.
//' @export
// [[Rcpp::export]]
List buildMarkov(int nbsp, NumericVector colo, NumericMatrix metaweb, double basexti, double mn, double mx, double shape){

		int i, j, k, l, m, com, state;
		double inter, sum;
		state = (1<<nbsp); // Number of states
		NumericMatrix markov(state, state);
		IntegerMatrix presence(nbsp, state);
		// Writing the transition matrix
		for (i=0; i<state; i++) {
				for (j=0; j<state; j++) {
						markov(i, j) = 0;
						if (i != j) {
								com = i^j;
								if ((com & (com - 1)) == 0) { // if com is 2^something, i.e only 1 event has occured (0 for multiple events).
										k = -1;
										l = 0;
										while (l == 0) {
												k++;
												l = (com>>k) & 1;
										}
										// k identifies the species (the bit) whose status has changed.
										if (((j>>k) & 1) == 1) { // if at the kth rank j==1 species was present at t and went extincted during dt.
												inter = 0;
												for (m=0; m<nbsp; m++) {
														inter += ((j>>m)&1)*metaweb(k,m); //l'etat de l,ile a t est donner par les especes de j
												}
												markov(i, j) = extinction(inter, basexti, mn, mx, shape);
										} else { //species k colonizes
												markov(i, j) = colo(k);
										}
								}
						}
				}
		}
		// Diagonal terms
		for (j=0; j<state; j++) {
				sum = 0;
				for (i=0; i<state; i++) {
						sum += markov(i, j);
				}
				markov(j, j) = -sum;
		}
		//
		for (i=0; i<nbsp; i++) {
			presence(i, _) = isIt1State(state, i);
		}
		//
		return List::create(
			_["markov"] = markov,
			_["speciesRichness"] = countBit1State(state),
			_["speciesPresence"] = presence
		);

}




