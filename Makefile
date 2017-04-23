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
	Rscript --no-site-file  --no-init-file $(rscr) `pwd` 1

$(md): $(rdm)
	Rscript --no-site-file  --no-init-file $(rscr) `pwd` 0

clean:
	rm -rf man/* NAMESPACES
