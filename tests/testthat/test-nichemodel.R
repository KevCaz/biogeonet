context("Testing nicheModel")

# this far from being exhaustive

test_that("checking simple values", {
  expect_equal(all(nicheModel(10, 0, 1) == 0), TRUE)
  expect_equal(all(nicheModel(10, 0.2, 2) <= 0), TRUE)
  expect_equal(all(nicheModel(10, 0.2, 3) >= 0), TRUE)
})

test_that("checking errors", {
  expect_error(nicheModel(10, .2, 5))
  expect_error(nicheModel(10, 1, 3))
})
