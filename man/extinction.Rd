% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{extinction}
\alias{extinction}
\title{Extinction rate for a given set of biotic interactions.}
\usage{
extinction(inter, basexti, mn, mx, shape)
}
\arguments{
\item{inter}{a real number giving the sum of interactions.}

\item{basexti}{extinction rate without interaction.}

\item{mn, mx}{a real number coefficient by which \code{basexti} should be multiply to obtain the minimum and maximum rate of extinction.}

\item{shape}{a positive real number controlling the impact of biotic interactions: the larger the value the stronger the impact of interactions.}
}
\value{
Returns the extinction rate associated with a given biotic environment.
}
\description{
This function returns the extinction associated with a given biotic environment.
}
\references{
Cazelles, K., Mouquet, N., Mouillot, D. & Gravel, D. On the integration of
biotic interaction and environmental constraints at the biogeographical scale.
(equation 5).
}
