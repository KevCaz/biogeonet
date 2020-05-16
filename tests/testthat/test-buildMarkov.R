context("Testing buildMarkov")

nbsp <- 5
set.seed(42)

web <- nicheModel(nbsp, 0.2, 3)
colo <- runif(nbsp)
mark <- buildMarkov(nbsp, colo, web, .2, 0.01, 0.5, 2)

test_that("checking simple values", {
  expect_equal(all(abs(colSums(mark$markov))<10^-12), TRUE)
})

test_that("checking errors", {
  expect_error(buildMarkov(nbsp, colo, web, .2, 0.5, 0.1, 2))
})

sprich <- mark$speciesRichness
sppres <- mark$speciesPresence
test_that("species richness and presence", {
  expect_equal(sprich[c(1, length(sprich))], c(0, 5))
  expect_true(all(apply(sppres, 1, sum) == 2^(nbsp-1)))
})