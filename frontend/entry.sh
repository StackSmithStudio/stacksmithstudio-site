#!/bin/sh
set -e

export GATSBY_DIR="/site"
export PATH="$PATH:/usr/local/bin/gatsby"

# Initialize Gatsby or run NPM install if needed
if [ ! -f "$GATSBY_DIR/package.json" ]
then
  echo "Initializing Gatsby..."
  gatsby new $GATSBY_DIR

else
  if [ ! -e "$GATSBY_DIR/node_modules/" ]
  then
    echo "Node modules is empty. Running npm install..."
    yarn install
  fi
fi

echo "about to run gatsby"

# Decide what to do
if  [ "$1" == "develop" ]
then
  echo "gatsby develop"
  cd $GATSBY_DIR
  rm -rf $GATSBY_DIR/public
  yarn develop --host 0.0.0.0

elif  [ "$1" == "build" ]
then
  echo "gatsby build"
  rm -rf $GATSBY_DIR/public
  cd $GATSBY_DIR
  yarn build
  rm -rf /webapp/*
  mv $GATSBY_DIR/public/* /webapp/

elif  [ "$1" == "stage" ]
then
  echo "gatsby stage"
  rm -rf $GATSBY_DIR/public
  cd $GATSBY_DIR
  yarn build
  gatsby serve --port 8000

else
  echo "gatsby exec"
  exec $@

fi