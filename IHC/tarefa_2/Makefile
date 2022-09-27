tarefa.pdf: tarefa.tex
	docker run --rm -it --user="$$(id -u):$$(id -g)" --net=none -v "$$(pwd):/tmp" leplusorg/latex latexmk -outdir=/tmp -pdf /tmp/$<

clean:
	@rm -f *.aux *.log *.dvi *.fls *.fdb_latexmk
