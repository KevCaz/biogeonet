#include <RcppArmadillo.h>
// it pulls Rcpp in

//' @name getEigenElements
//' @title Markov transition matrix solver.
//' @description Solve the Markov transition matrix and return the eigen vector giving
//' the probability of presence associated with all the networks's species.
//'
//' @author
//' Kevin Cazelles
//'
//' @param markov A transition matrix of a markov chain.
//'
//' @return Returns the eigen values associated to the vector and eigen values
//' transition matrix of the markov chain to be solved.
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
