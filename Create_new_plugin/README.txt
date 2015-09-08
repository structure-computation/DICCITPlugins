
Pour faire les liens vers un nouveau plugin, le rajouter dans :
- Un GlobalManagerPlugin (fichiers Launcher.h et main.cpp du ServerPlugin de GlobalManagerPlugin)
- le dossier "plugins" de LMTLabs (lien symbolique vers le dossier du plugin, sans "Plugin dans le nom : "ln -s ../../(n fois)/NomPlugin Nom")
- launch_ecosystem_mechanics.coffee, dans LMTLabs/src

