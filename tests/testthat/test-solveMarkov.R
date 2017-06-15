library(biogeonet)
context("Testing getEigenElements* and solveMarkov")

mat <- mat2 <- rbind(
  c(.5, 0, .5),
  c(.5, .5, 0),
  c(0, .5, .5))
mat2[1,2] <- mat2[2,3] <- mat2[3,1] <- -1
mats <- Matrix::Matrix(mat, sparse = TRUE)


res1 <- getEigenElements(mat)
res2 <- getEigenElementsSp(mats)
res3 <- solveMarkov(mat)
res4 <- solveMarkov(mat, sparse=FALSE)
##
res6 <- solveMarkov(mat2, sparse=FALSE, continuous = TRUE)

test_that("checking errors", {
  expect_error(getEigenElementsSp(mat), "Not an S4 object.")
  expect_error(solveMarkov(mat, continuous = TRUE), "all(abs(csm - val) < 10^-12) is not TRUE", fixed=TRUE)
})

test_that("checking simple values", {
  expect_equal(length(res1), 2)
  expect_equal(length(res2), 2)
  expect_equal(dim(res1$eigval), c(3,1))
  expect_equal(dim(res1$eigvec), c(3,3))
  expect_equal(dim(res2$eigval), c(1,1))
  expect_equal(dim(res2$eigvec), c(3,1))
  expect_equal(as.numeric(res1$eigval[3]), 1)
  expect_equal(as.numeric(res2$eigval[1]), 1)
  expect_equal(sum(res3), 1)
  expect_equal(sum(res4), 1)
  expect_equal(sum(res6), 1)
  expect_true(all(round(res3,12) == round(1/3,12)))
  expect_true(all(round(res4,12) == round(1/3,12)))
  expect_true(all(round(res6,12) == round(1/3,12)))
})
