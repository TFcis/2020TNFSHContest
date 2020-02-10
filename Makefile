nothing:

all: card matching puyo route swap tree

card:
	cd Card && tps statement
	cmsImportTask -c 22 ./Card/ -u

matching:
	cd Matching && tps statement
	cmsImportTask -c 22 ./Matching/ -u

puyo:
	cd Puyo && tps statement
	cmsImportTask -c 22 ./Puyo/ -u

route:
	cd Route && tps statement
	cmsImportTask -c 22 ./Route/ -u

swap:
	cd Swap && tps statement
	cmsImportTask -c 22 ./Swap/ -u

tree:
	cd Tree && tps statement
	cmsImportTask -c 22 ./Tree/ -u
