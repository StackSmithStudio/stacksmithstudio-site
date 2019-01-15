#!/bin/sh
set -e

export GATSBY_DIR="/site"
export PATH="$PATH:/usr/local/bin/gatsby"

cd /site
pwd

echo "yarn"
yarn --pure-lockfile

echo "gatsby build"
yarn build
echo "copying "
mv $GATSBY_DIR/public/* /webapp/
