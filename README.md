# biogeonet
[![R-CMD-check](https://github.com/KevCaz/biogeonet/workflows/R-CMD-check/badge.svg)](https://github.com/KevCaz/biogeonet/actions)
[![Codecov test coverage](https://codecov.io/gh/KevCaz/biogeonet/branch/master/graph/badge.svg)](https://codecov.io/gh/KevCaz/biogeonet?branch=master)


Functions to reproduce the analysis in Cazelles *et al.* 2016 [DOI:10.1111/ecog.01714](http://onlinelibrary.wiley.com/doi/10.1111/ecog.01714/abstract).


## Installation

To get the current development version of this repository from R, use the
[`remotes`](https://CRAN.R-project.org/package=remotes) package like so:

```r
if (!require("remotes'")) install.packages("remotes")
remotes::install_github("KevCaz/biogeonet")
library(biogeonet)
```


## About the paper

### Reference

- Cazelles, K., Mouquet, N., Mouillot, D. & Gravel, D. On the integration of biotic interaction and environmental constraints at the biogeographical scale. Ecography (Cop.). 39, 921–931 (2016). [DOI:10.1111/ecog.01714](http://onlinelibrary.wiley.com/doi/10.1111/ecog.01714/abstract)

### Abstract

> Biogeography is primarily concerned with the spatial distribution of biodiversity, including performing scenarios in a changing environment. The efforts deployed to develop species distribution models have resulted in predictive tools, but have mostly remained correlative and have largely ignored biotic interactions. Here we build upon the theory of island biogeography as a first approximation to the assembly dynamics of local communities embedded within a metacommunity context. We include all types of interactions and introduce environmental constraints on colonization and extinction dynamics. We develop a probabilistic framework based on Markov chains and derive probabilities for the realization of species assemblages, rather than single species occurrences. We consider the expected distribution of species richness under different types of ecological interactions. We also illustrate the potential of our framework by studying the interplay between different ecological requirements, interactions and the distribution of biodiversity along an environmental gradient. Our framework supports the idea that the future research in biogeography requires a coherent integration of several ecological concepts into a single theory in order to perform conceptual and methodological innovations, such as the switch from single-species distribution to community distribution



