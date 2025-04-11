#!/bin/bash
echo "Enter Name of the project to create"
read projectname

echo "Creating $projectname"
echo

mkdir $projectname
cp Template/Makefile $projectname
cp -a Template/.vscode $projectname
cp Template/main.c $projectname

cd $projectname
mkdir include
