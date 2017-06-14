biogeonet
=========

R (Rcpp) implementation for Cazelles *et al.* 2016 <DOI:10.1111/ecog.01714>

    ## Loading biogeonet

Installation
------------

To get the current development version of this repository from R, use the [*devtools*](http://cran.r-project.org/web/packages/devtools/index.html) package like so:

``` r
if (!require("devtools'")) install.packages("devtools")
devtools::install_github("KevCaz/biogeonet")
library(biogeonet)
```

Current Status
--------------

[![Travis](https://travis-ci.org/KevCaz/recruitR.svg?branch=master)](https://travis-ci.org/KevCaz/biogeonet) [![Build status](https://ci.appveyor.com/api/projects/status/sk3sbvusvcyy0at0?svg=true)](https://ci.appveyor.com/project/KevCaz/biogeonet/build/1.0.7) [![codecov](https://codecov.io/gh/KevCaz/biogeonet/branch/master/graphs/badge.svg)](https://codecov.io/gh/KevCaz/biogeonet) ![](https://img.shields.io/badge/licence-GPL%3E=2-8f10cb.svg)

About the paper
---------------

-   **Reference**:

Cazelles, K., Mouquet, N., Mouillot, D. & Gravel, D. On the integration of biotic interaction and environmental constraints at the biogeographical scale. Ecography (Cop.). 39, 921–931 (2015). [DOI:10.1111/ecog.01714](http://onlinelibrary.wiley.com/doi/10.1111/ecog.01714/abstract).

-   **Abstract**:

> Biogeography is primarily concerned with the spatial distribution of biodiversity, including performing scenarios in a changing environment. The efforts deployed to develop species distribution models have resulted in predictive tools, but have mostly remained correlative and have largely ignored biotic interactions. Here we build upon the theory of island biogeography as a first approximation to the assembly dynamics of local communities embedded within a metacommunity context. We include all types of interactions and introduce environmental constraints on colonization and extinction dynamics. We develop a probabilistic framework based on Markov chains and derive probabilities for the realization of species assemblages, rather than single species occurrences. We consider the expected distribution of species richness under different types of ecological interactions. We also illustrate the potential of our framework by studying the interplay between different ecological requirements, interactions and the distribution of biodiversity along an environmental gradient. Our framework supports the idea that the future research in biogeography requires a coherent integration of several ecological concepts into a single theory in order to perform conceptual and methodological innovations, such as the switch from single-species distribution to community distribution

Examples
--------

### Niche model

``` r
nicheModel(5, .2, 1)
#>            [,1]       [,2]       [,3]       [,4]       [,5]
#> [1,] -0.6551532  0.4809696  0.5797243  0.0000000  0.5927752
#> [2,] -0.1456578 -0.5918119  0.0000000  0.0000000  0.9419722
#> [3,] -0.9182947  0.0000000  0.0000000  0.6489161  0.4918560
#> [4,]  0.0000000  0.0000000 -0.2001309 -0.1712266  0.8546011
#> [5,] -0.7979611 -0.7656937 -0.7393156 -0.4017819 -0.8812419
```

### Colonization

``` r
par(las=1)
seqx <- seq(0,10,.01)
valy <- sapply(seqx, FUN=colonization, 1, 5, 2)
plot(seqx, valy, type="l")
```

![](inst/unnamed-chunk-3-1.png)

### Solving the Markov chain

``` r
mat <- rbind(c(.4, 0, .6), c(.3, .4, .3), c(.4, .1, .5))
res <- solveMarkov(mat)
```

TODO
----

-   \[ \] Convert all the C/C++ code to RCPP (should not be that difficult);
-   \[ \] write a minimal documentation including the simulations (or the exact way of how to proceed with a number of species lower that what it was in the paper) presented within the paper;
-   \[X\] use ~RcppEigen or~ Armadillo to solve the Markov chain.
