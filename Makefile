nothing:

all: card matching puyo route swap tree

card:
	cd Card && tps statement
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
	cmsImportTask -c 22 ./Matching/ -u

matching-check:
	cd Matching && > solution/check.txt
	cd Matching && tps invoke solution/100pt.cpp | tee -a solution/check.txt
	cd Matching && tps invoke solution/xiplus.cpp | tee -a solution/check.txt

puyo:
	cd Puyo && tps statement
	cmsImportTask -c 22 ./Puyo/ -u

puyo-check:
	cd Puyo && > solution/check.txt
	cd Puyo && tps invoke solution/ac.cpp | tee -a solution/check.txt

route:
	cd Route && tps statement
	cmsImportTask -c 22 ./Route/ -u

route-check:
	cd Route && > solution/check.txt
	cd Route && tps invoke solution/ac.cpp | tee -a solution/check.txt
	cd Route && tps invoke solution/xiplus.cpp | tee -a solution/check.txt

swap:
	cd Swap && tps statement
	cmsImportTask -c 22 ./Swap/ -u

swap-check:
	cd Swap && > solution/check.txt
	cd Swap && tps invoke solution/100pt.cpp | tee -a solution/check.txt
	cd Swap && tps invoke solution/subtask1.cpp | tee -a solution/check.txt
	cd Swap && tps invoke solution/subtask2.cpp | tee -a solution/check.txt
	cd Swap && tps invoke solution/subtask3.cpp | tee -a solution/check.txt

tree:
	cd Tree && tps statement
	cmsImportTask -c 22 ./Tree/ -u

tree-check:
	cd Tree && > solution/check.txt
	cd Tree && tps invoke solution/100pt.cpp | tee -a solution/check.txt
	cd Tree && tps invoke solution/subtask1.cpp | tee -a solution/check.txt
	cd Tree && tps invoke solution/subtask2.cpp | tee -a solution/check.txt

import:
	cmsImportTask -c 22 ./Card/ -u
	cmsImportTask -c 22 ./Matching/ -u
	cmsImportTask -c 22 ./Puyo/ -u
	cmsImportTask -c 22 ./Route/ -u
	cmsImportTask -c 22 ./Swap/ -u
	cmsImportTask -c 22 ./Tree/ -u
