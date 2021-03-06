% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{buildMarkov}
\alias{buildMarkov}
\title{Generates the transition matrix for a given probability and  an interaction network using the niche model.}
\usage{
buildMarkov(nbsp, colo, metaweb, basexti, mn, mx, shape)
}
\arguments{
\item{nbsp}{an integer giving the number of species.}

\item{colo}{a vector giving the colonization rates of all species.}

\item{metaweb}{a matrix describing the interaction network.}

\item{basexti}{extinction rate without interaction.}

\item{mn, mx}{a real number giving the minimum and maximum rate of extinction.}

\item{shape}{a positive real number controlling the impact of biotic interactions: the larger the value the stronger the impact of interactions.}
}
\value{
A list including:
\itemize{
\item \code{makov}: the transition of the Markov chain to be solved.
\item \code{speciesRichness}: species richness for all states.
\item \code{speciesPresence}: matrix of presence for every species in all states.
}
}
\description{
Generates the transition matrix for a given probability and  an interaction network using the niche model.
}
\references{
Cazelles, K., Mouquet, N., Mouillot, D. & Gravel, D. On the integration of
biotic interaction and environmental constraints at the biogeographical scale.
}
