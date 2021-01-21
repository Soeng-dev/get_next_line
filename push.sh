#!/bin/bash
git add $1
git commit -m "$2"
git log > ./git_log
if grep $2 git_log
then
	git push
	soekim
	innoacaGit*sy*0902
else
	echo "git commit error"
fi
rm git_log
