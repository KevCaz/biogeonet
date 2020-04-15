#' solveMarkov
#'
#' Compute the communities probabilities associated at equilibrium for a given
#' transition matrix.
#'
#' @param markov a transition matrix
#' @param sparse a logical. Should a sparse matrix be used? Default value is \code{TRUE} (See details).
#' @param continuous a logical. Is `markov` a continuous time Markov chain?
#' Default is set to `FALSE`.
#'
#' @return
#' A vector of probabilities
#'
#' @details
#' If `sparse` is `TRUE`, then only the larger eigen values is
#' returned (function `eigs_gen()` in the armadillo C++ library requires
#' the number of eigen values to be computed and is currently set to 1 in
#' `getEigenElementsSp()`).
#'
#' @importClassesFrom Matrix dgCMatrix
#'
#' @export

solveMarkov <- function(markov, sparse = TRUE, continuous = FALSE) {
    if (continuous)
        val <- 0 else val <- 1

    csm <- colSums(markov)
    stopifnot(all(abs(csm - val) < 10^-12))
    ##
    if (sparse) {
        smarkov <- Matrix::Matrix(markov, sparse = TRUE)
        res <- getEigenElementsSp(smarkov)$eigvec
    } else {
        tmp <- getEigenElements(markov)$eigvec
        res <- tmp[, ncol(tmp)]
    }
    ##
    as.numeric(res)^2
}
