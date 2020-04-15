#include <Rcpp.h>
using namespace Rcpp;
using namespace std;
#include "called.h"

//' @name buildMarkov
//' @title Generates the transition matrix for a given probability and  an interaction network using the niche model.
//' @description Generates the transition matrix for a given probability and  an interaction network using the niche model.
//'
//' @author
//' Kevin Cazelles
//'
//' @param nbsp an integer giving the number of species.
//' @param colo a vector giving the colonization rates of all species.
//' @param metaweb a matrix describing the interaction network.
//' @param basexti extinction rate without interaction.
//' @param mn a real number giving the minimum rate of extinction.
//' @param mx a real number giving the maximum rate of extinction.
//' @param shape a positive real number controlling the impact of biotic interactions: the larger the value the stronger the impact of interactions.
//'
//' @return Returns the transition matrix of the Markov chain to be solved.
//'
//' @references
//' Cazelles, K., Mouquet, N., Mouillot, D. & Gravel, D. On the integration of
//' biotic interaction and environmental constraints at the biogeographical scale.
//' @export
// [[Rcpp::export]]
NumericMatrix buildMarkov(int nbsp, NumericVector colo, NumericMatrix metaweb, double basexti, double mn, double mx, double shape){

  int i, j, k, l, m, com, state;
  double inter, sum;
  state = (1<<nbsp); // Number of states
  NumericMatrix markov(state, state);
  // Writing the transition matrix
  for (i=0; i<state; i++) {
    for (j=0; j<state; j++) {
      markov(i,j) = 0;
      if (i!=j){
        com = i^j;
        if ((com&(com-1))==0) {  // if com is 2^something, i.e only 1 event has occured (0 for multiple events).
          k = -1;
          l = 0;
          while (l==0) {
            k++;
            l = (com>>k)&1;
          }
          // k identifies the species (the bit) whose status has changed.
          if (((j>>k)&1)==1) {  // if at the kth rank j==1 species was present at t and went extincted during dt.
            inter = 0;
            for (m=0; m<nbsp; m++) {
                inter += ((j>>m)&1)*metaweb(k,m); //l'etat de l,ile a t est donner par les especes de j
            }
            markov(i,j) = extinction(inter, basexti, mn, mx, shape);
          } else { //species k colonizes
            markov(i,j) = colo(k);
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
  return markov;
}
