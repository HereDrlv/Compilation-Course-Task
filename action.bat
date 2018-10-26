flex lex.l
bison -d parser.y
gcc -o a lex.yy.c parser.tab.c ast.c