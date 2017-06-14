library(biogeonet)
library(Matrix)
context("Testing getEigenElements*")

mat <- rbind(
  c(.5, 0, .5),
  c(.5, .5, 0),
  c(0, .5, .5))
mats <- as(mat, "sparseMatrix")

res1 <- getEigenElements(mat)
res2 <- getEigenElementsSp(mats)

test_that("checking errors", {
  expect_error(getEigenElementsSp(mat), "Not an S4 object.")
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
})
