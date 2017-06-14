#include <RcppArmadillo.h>
// it pulls Rcpp in

//' @name solveMarkov
//' @title Markov transition matrix solver.
//' the probability of presence associated with all species in the network.
//' @description Solve the Markov transition matrix and return the eigen vector giving
//' the probability of presence associated with all the networks's species.
//'
//' @author
//' Kevin Cazelles
//'
// ' @param markov A transition matrix of a markov chain.
// ' @param continuous Logical. Is \code{markov} a continuous-time Markov chain? Deafult is set to \code{FALSE}.
// '
//' @return Returns the eigen values associated to the vector and eigen values
//' transition matrix of the markov chain to be solved.
//
// [[Rcpp::depends(RcppArmadillo)]]
//
// [[Rcpp::export]]
Rcpp::List solveMarkov(arma::mat markov, bool continuous = false) {

  arma::cx_vec eigval;
  arma::cx_mat eigvec;
  eig_gen(eigval, eigvec, markov);
  // Rcpp::Rcout << eigval << std::endl;

  return Rcpp::List::create(Rcpp::Named("eigval") = eigval, Rcpp::Named("eigvec") = eigvec);
}
