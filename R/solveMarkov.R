#' solveMarkov
#'
#' Compute the communities probabilities associated at equilibrium for a givem
#' transition matrix.
#'
#' @author
#' Kevin Cazelles
#'
#' @param markov a transition matrix
#' @param sparse a logical. Should a sparse matrix be used? Default value is \code{TRUE} (See details).
#' @param continuous a logical. Do \code{markov} a continuous time markov chain?
#' Default is set to \code{FALSE}.
#'
#' @return
#' A vector of probabilities
#'
#' @details
#' If \code{sparse} is \code{TRUE}, then only the larger eigen values is returned
#' (function \code{eigs_gen()}' in the armadillo C++ library requires the number
#' of eigen values to be computed and is currently set to 1 in
#' \code{getEigenElementsSp()}).
#'
#' @export

solveMarkov <- function(markov, sparse = TRUE, continuous = FALSE) {
    if (continuous) 
        val <- 0 else val <- 1
    
    csm <- colSums(markov)
    stopifnot(all(abs(csm - val) < 10^-12))
    ## 
    if (sparse) {
        smarkov <- as(markov, "sparseMatrix")
        res <- getEigenElementsSp(smarkov)$eigvec
    } else {
        tmp <- getEigenElements(markov)$eigvec
        res <- tmp[, ncol(tmp)]
    }
    ## 
    return(as.numeric(res)^2)
}
