#!/bin/sh

###############################################

## A PARAMETRER (direc : par rapport au dossier courant)
direc="./"
new_name="FieldCompare"

empty_direc="BlankPlugin"

###############################################

plug="Plugin/"
new_direc="$direc$new_name$plug"

echo " "
echo "	Dossier du Plugin :"
echo $PWD/$new_direc

if [ -d "$PWD/$new_direc" ]; then
	echo " "
	echo "	Dossier déjà existant, rien n'a été écrit !!!"
	echo " "
else
	cp -r $empty_direc $new_direc
	cd $new_direc
	cd OnlinePlugin
	mv Blank $new_name
	cd $new_name
	cd applications
	item="Item"
	echo `sed -e "s/Blank/$new_name/"  TreeAppApplication_Blank.coffee>tmp.coffee`
	echo `sed -e "s/BlankItem/$new_name$item/"  tmp.coffee>TreeAppApplication_$new_name.coffee`
	rm TreeAppApplication_Blank.coffee
	rm tmp.coffee
	cd ../img
	mv Blank.png $new_name.png
	cd ../TreeItem
	echo `sed -e "s/Blank/$new_name/"  BlankItem.coffee>tmp.coffee`
	echo `sed -e "s/BlankItem/$new_name$item/"  tmp.coffee>$new_name$item.coffee`
	rm BlankItem.coffee
	rm tmp.coffee
	cd ../../../ServerPlugin/src
	up="Updater"
	new_name_maj=`echo $new_name$up | tr '[a-z]' '[A-Z]'`
	echo `sed -e "s/BlankUpdater/$new_name$up/"  BlankUpdater.cpp>$new_name$up.cpp`
	echo `sed -e "s/BlankUpdater/$new_name$up/"  BlankUpdater.h>test.h`
	echo `sed -e "s/BLANKUPDATER/$new_name_maj/"  test.h>$new_name$up.h`
	rm Blank* test.h
	echo `sed -e "s/BlankUpdater/$new_name$up/"  main.cpp>tmp.cpp`
	rm main.cpp
	echo `sed -e "s/BlankItem/$new_name$item/"  tmp.cpp>main.cpp`
	rm tmp.cpp
	echo "	Dossier créé."
	echo " "
fi
