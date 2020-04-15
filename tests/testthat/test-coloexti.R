context("Testing colonization and extinction")

test_that("checking simple values", {
  expect_equal(extinction(0, 1, 0, 1, 1), 1)
  expect_equal(colonization(10, 1, 10, 2), 1)
})

test_that("checking errors", {
  expect_error(extinction(0, 1, 1, 0, 1))
})
