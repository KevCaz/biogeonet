#include <RcppArmadillo.h>
// it pulls Rcpp in

//' @name getEigenElements
//' @title Markov transition matrix solver.
//' @description Solve the Markov transition matrix and return the eigen vector giving
//' the probability of presence associated with all the network's species.
//'
//' @author
//' Kevin Cazelles
//'
//' @param markov A transition matrix of a Markov chain.
//'
//' @return Returns the eigen values associated to the vector and eigen values
//' transition matrix of the Markov chain to be solved.
//'
//' @export
//
// [[Rcpp::depends(RcppArmadillo)]]
//
// [[Rcpp::export]]
Rcpp::List getEigenElements(arma::mat markov) {
  arma::cx_vec eigval;
  arma::cx_mat eigvec;
  eig_gen(eigval, eigvec, markov);
  return Rcpp::List::create(Rcpp::Named("eigval") = eigval, Rcpp::Named("eigvec") = eigvec);
}


//' @name getEigenElementsSp
//' @title Markov transition matrix solver for sparse transition matriices.
//' @description Solve the Markov transition matrix and return the eigen vector giving
//' the probability of presence associated with all the network's species.
//'
//' @author
//' Kevin Cazelles
//'
//' @param smarkov A sparse transition matrix of a Markov chain.
//'
//' @return Returns the eigen values associated to the vector and eigen values
//' transition matrix of the markov chain to be solved.
//'
//' @export
//
// [[Rcpp::depends(RcppArmadillo)]]
//
// [[Rcpp::export]]
Rcpp::List getEigenElementsSp(arma::sp_mat smarkov) {
  arma::cx_vec eigval;
  arma::cx_mat eigvec;
  // Return only the eigen value/vector that have the largest real part
  // 1 for discrete-time MC and 0 for continuous-time MC
  eigs_gen(eigval, eigvec, smarkov, 1, "lr");
  return Rcpp::List::create(Rcpp::Named("eigval") = eigval, Rcpp::Named("eigvec") = eigvec);
}
