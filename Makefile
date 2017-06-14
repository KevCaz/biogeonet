rfun := $(wildcard R/*.R)
rman := $(wildcard man/*.Rd)
rtes := $(wildcard tests/testthat/*.R)
rsrc := $(wildcard src/*.cpp)
rdm = README.Rmd
md = README.md
chk = record_updates.txt
rscr = ../pkg2date.R


all: $(md) $(chk)

$(chk): $(rfun) $(rtes) $(rman) $(rsrc)
	Rscript --no-init-file $(rscr) 1

$(md): $(rdm)
	Rscript --no-init-file $(rscr) 0

check:
	Rscript --no-init-file -e 'cat("##-- checking ....\n"); devtools::check(".")'

clean:
	rm -rf man/* NAMESPACES
