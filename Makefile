nothing:

all: card matching puyo route swap circle merge-pdf

card:
	cd Card && tps statement
	cd Card && tps gen --no-gen
	cmsImportTask -c 22 ./Card/ -u

card-check:
	cd Card && > solution/check.txt
	cd Card && tps invoke solution/100pt.cpp | tee -a solution/check.txt
	cd Card && tps invoke solution/jump_table.cpp | tee -a solution/check.txt
	cd Card && tps invoke solution/subtask1.cpp | tee -a solution/check.txt
	cd Card && tps invoke solution/subtask2.cpp | tee -a solution/check.txt
	cd Card && tps invoke solution/subtask3.cpp | tee -a solution/check.txt
	cd Card && tps invoke solution/subtask4.cpp | tee -a solution/check.txt
	cd Card && tps invoke solution/subtask5.cpp | tee -a solution/check.txt

matching:
	cd Matching && tps statement
	cd Matching && tps gen
	cmsImportTask -c 22 ./Matching/ -u

matching-check:
	cd Matching && > solution/check.txt
	cd Matching && tps invoke solution/100pt.cpp | tee -a solution/check.txt
	cd Matching && tps invoke solution/Yazmau-WA.cpp | tee -a solution/check.txt
	cd Matching && tps invoke solution/xiplus.cpp | tee -a solution/check.txt
	cd Matching && tps invoke solution/xiplus-WA.cpp | tee -a solution/check.txt

puyo:
	cd Puyo && tps statement
	cd Puyo && tps gen
	cmsImportTask -c 22 ./Puyo/ -u

puyo-check:
	cd Puyo && > solution/check.txt
	cd Puyo && tps invoke solution/ac.cpp | tee -a solution/check.txt
	cd Puyo && tps invoke solution/subtask2.cpp | tee -a solution/check.txt

route:
	cd Route && tps statement
	cd Route && tps gen
	cmsImportTask -c 22 ./Route/ -u

route-check:
	cd Route && > solution/check.txt
	cd Route && tps invoke solution/ac.cpp | tee -a solution/check.txt
	cd Route && tps invoke solution/xiplus.cpp | tee -a solution/check.txt

swap:
	cd Swap && tps statement
	cd Swap && tps gen --no-gen
	cmsImportTask -c 22 ./Swap/ -u

swap-check:
	cd Swap && > solution/check.txt
	cd Swap && tps invoke solution/100pt.cpp | tee -a solution/check.txt
	cd Swap && tps invoke solution/subtask1.cpp | tee -a solution/check.txt
	cd Swap && tps invoke solution/subtask2.cpp | tee -a solution/check.txt
	cd Swap && tps invoke solution/subtask3.cpp | tee -a solution/check.txt

circle:
	cd Circle && tps statement
	cd Circle && tps gen --no-gen
	cmsImportTask -c 22 ./Circle/ -u

circle-check:
	cd Circle && > solution/check.txt
	cd Circle && tps invoke solution/100pt.cpp | tee -a solution/check.txt
	cd Circle && tps invoke solution/subtask1.cpp | tee -a solution/check.txt
	cd Circle && tps invoke solution/subtask2.cpp | tee -a solution/check.txt

import:
	cmsImportTask -c 22 ./Card/ -u
	cmsImportTask -c 22 ./Matching/ -u
	cmsImportTask -c 22 ./Puyo/ -u
	cmsImportTask -c 22 ./Route/ -u
	cmsImportTask -c 22 ./Swap/ -u
	cmsImportTask -c 22 ./Circle/ -u

merge-pdf:
	pdfunite Matching/statement/problem.pdf Route/statement/problem.pdf Puyo/statement/problem.pdf Card/statement/problem.pdf Circle/statement/problem.pdf Swap/statement/problem.pdf problems.pdf
	mkdir -p Matching/attachments
	cp problems.pdf Matching/attachments
	cmsImportTask -c 22 ./Matching/ -u

statement:
	cd Card && tps statement
	cd Circle && tps statement
	cd Matching && tps statement
	cd Puyo && tps statement
	cd Route && tps statement
	cd Swap && tps statement
